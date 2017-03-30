#include "ffmpegdecoder.h"

FfmpegDecoder::FfmpegDecoder(QObject *parent) :
    QObject(parent)
{
    av_register_all();
    avformat_network_init();
    _pCodecCtx = NULL;
    _pCodec = NULL;
    _pFrame = NULL;
    _pFrameRGB = NULL;
    _isDecoding = false;
    _yuvBuffer = NULL;
    _videoIndex = -1;
    _imageRGB = NULL;
    _pTimer = new QTimer(this);
    _pTimer->setSingleShot(false);

    this->setConnection();
}

FfmpegDecoder::~FfmpegDecoder()
{

}

void FfmpegDecoder::openFile(QString fileName)
{
    _pFormatCtx = avformat_alloc_context();
    _pFrame = avcodec_alloc_frame();
    _pFrameRGB = avcodec_alloc_frame();

    if (avformat_open_input(&_pFormatCtx, fileName.toStdString().c_str(), NULL, NULL) != 0) {
        qDebug()<<"无法打开文件\n";
        return;
    }
    if (av_find_stream_info(_pFormatCtx) < 0)
    {
        qDebug()<<"Couldn't find stream information.\n";
        return;
    }
    _videoIndex = -1;
    for (int i = 0; i < _pFormatCtx->nb_streams; i++)
    {
        if (_pFormatCtx->streams[i]->codec->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            _videoIndex = i;
            break;
        }
    }

    if (_videoIndex == -1)
    {
        qDebug()<<"Didn't find a video stream.\n";
        this->closeFile();
        return;
    }
    _pCodecCtx = _pFormatCtx->streams[_videoIndex]->codec;
    _pCodec = avcodec_find_decoder(_pCodecCtx->codec_id);
    if (_pCodec == NULL)
    {
        qDebug()<<"Codec not found.\n";
        this->closeFile();
        return;
    }
    if (avcodec_open(_pCodecCtx, _pCodec) < 0)
    {
        qDebug()<<"Could not open codec.\n";
        this->closeFile();
        return;
    }

    if ( _yuvBuffer != NULL ) {
        delete [] _yuvBuffer;
        _yuvBuffer = NULL;
    }
    _yuvBuffer = new unsigned char[avpicture_get_size(PIX_FMT_RGB24, _pCodecCtx->width, _pCodecCtx->height)];

    avpicture_fill((AVPicture*)_pFrameRGB, _yuvBuffer, PIX_FMT_RGB24, _pCodecCtx->width, _pCodecCtx->height);
    int size = _pCodecCtx->width * _pCodecCtx->height;
    av_new_packet(&_packet, size);

    if ( _imageRGB != NULL ) {
        cvReleaseImage(&_imageRGB);
        _imageRGB = NULL;
    }
    _imageRGB = cvCreateImage(cvSize(_pCodecCtx->width, _pCodecCtx->height), IPL_DEPTH_8U, 3);

    _isDecoding = true;
    float fps = _pFormatCtx->streams[0]->avg_frame_rate.num/(float)_pFormatCtx->streams[0]->avg_frame_rate.den;

    _pTimer->start(round(1000/fps));
}

void FfmpegDecoder::closeFile()
{
    _isDecoding = false;

    if ( _yuvBuffer != NULL ) {
        delete [] _yuvBuffer;
        _yuvBuffer = NULL;
    }

    av_free(_pFrameRGB);
    if ( _pCodecCtx != NULL ) {
        avcodec_close(_pCodecCtx);
        _pCodecCtx = NULL;
    }

    if ( _pFormatCtx != NULL ) {
        avformat_close_input(&_pFormatCtx);
        _pFormatCtx = NULL;
    }

    av_free_packet(&_packet);

    _pTimer->stop();
    emit fileClosed();
}

void FfmpegDecoder::decodeFile()
{
    if ( _isDecoding ) {
        static struct SwsContext *img_convert_ctx;
        int ret, got_picture;
        int size = _pCodecCtx->width * _pCodecCtx->height * 3;
        while ( true ) {
            ret = av_read_frame(_pFormatCtx, &_packet);
            if ( ret >= 0 ) {
                if (_packet.stream_index == _videoIndex) {
                    ret = avcodec_decode_video2(_pCodecCtx, _pFrame, &got_picture, &_packet);
                    if (ret < 0)
                    {
                        qDebug()<<"解码错误\n";
                        this->closeFile();
                        return;
                    }
                    if (got_picture)
                    {
                        img_convert_ctx = sws_getContext(_pCodecCtx->width, _pCodecCtx->height, _pCodecCtx->pix_fmt, _pCodecCtx->width, _pCodecCtx->height, PIX_FMT_RGB24, SWS_BICUBIC, NULL, NULL, NULL);
                        sws_scale(img_convert_ctx, (const uint8_t* const*)_pFrame->data, _pFrame->linesize, 0, _pCodecCtx->height, _pFrameRGB->data, _pFrameRGB->linesize);
                        sws_freeContext(img_convert_ctx);
                        memcpy(_imageRGB->imageData, _pFrameRGB->data[0], size);

                        _passedTime = clock() - _currentTime;
                        _currentTime += _passedTime;
                        QImage image((uchar*)_imageRGB->imageData, _imageRGB->width, _imageRGB->height, QImage::Format_RGB888);
                        emit updatePreview(image);
                        emit imageCaptured(_imageRGB, _passedTime);
                        break;
                    }
                }
            }
            else {
                this->closeFile();
            }
            av_free_packet(&_packet);
        }
    }
}

void FfmpegDecoder::setConnection()
{
    connect( _pTimer, SIGNAL(timeout()), this, SLOT(decodeFile()) );
}
