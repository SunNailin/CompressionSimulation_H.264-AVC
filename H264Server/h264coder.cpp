#include "h264coder.h"

H264Coder::H264Coder(QObject *parent) :
    QObject(parent)
{
    _hX264 = NULL;
    _imageRGB = NULL;
    _imageYUV420 = NULL;
    this->defaultSetting();

    // for test
//    _sender.addDest(QHostAddress("127.0.0.1"), 8001);
}

H264Coder::~H264Coder()
{
    if ( _hX264 != NULL )
    {
        x264_picture_clean(&_picInput);
        x264_encoder_close(_hX264);
        _hX264 = NULL;
    }
    if ( _imageRGB != NULL )
    {
        cvReleaseImage(&_imageRGB);
        _imageRGB = NULL;
    }
    if ( _imageYUV420 != NULL )
    {
        cvReleaseImage(&_imageYUV420);
        _imageYUV420 = NULL;
    }
}

H264Sender *H264Coder::getSender()
{
    return &_sender;
}

PacketControler *H264Coder::getPacketControler()
{
    return &_packetControler;
}

void H264Coder::iniX264()
{
    _param = _paramWillSet;
    if ( _hX264 != NULL )
    {
        x264_encoder_close(_hX264);
        x264_picture_clean(&_picInput);
        _hX264 = NULL;
    }
    if ( _imageRGB != NULL )
    {
        cvReleaseImage(&_imageRGB);
        _imageRGB = NULL;
    }
    if ( _imageYUV420 != NULL )
    {
        cvReleaseImage(&_imageYUV420);
        _imageYUV420 = NULL;
    }
    _imageRGB = cvCreateImage(cvSize(_param.i_width, _param.i_height), IPL_DEPTH_8U, 3);
    _imageYUV420 = cvCreateImage(cvSize(_param.i_width, _param.i_height*3/2), IPL_DEPTH_8U, 1);
    _hX264 = x264_encoder_open(&_param);
    if ( _hX264 == NULL )
    {
        qDebug()<<"open X264 handle faile!";
        exit(-1);
    }
    x264_picture_init(&_picInput);
    x264_picture_alloc(&_picInput, X264_CSP_I420, _param.i_width, _param.i_height);
}

void H264Coder::paramSetting(x264_param_t param)
{
    _paramWillSet = param;
}

void H264Coder::imageCaptured(IplImage *image, unsigned int time)
{
    // Do nothing if no body want the data
    if ( _sender.destNumber() == 0 )
        return;

    int size = _param.i_width * _param.i_height;
    int tempSize = 0;
    x264_nal_t* nal_t;
    int i_nal;
    cvResize(image, _imageRGB, CV_INTER_LINEAR);    // resize image;
    cvCvtColor(_imageRGB, _imageYUV420, CV_RGB2YUV_I420);
    memcpy(_picInput.img.plane[0], _imageYUV420->imageData, size);
    memcpy(_picInput.img.plane[1], _imageYUV420->imageData+size, size/4);
    memcpy(_picInput.img.plane[2], _imageYUV420->imageData+size*5/4, size/4);
    tempSize = x264_encoder_encode(_hX264, &nal_t, &i_nal, &_picInput, &_picOutput);
    _picInput.i_pts++;      // don't know its use
    if ( tempSize > 0 )
    {
        for(int i=0; i<i_nal; i++)
        {
            // just the first packet change the timeStamp. for the settings, there will be
            // a type 6 and a type 7 nalu before the i frame under normal case. But there
            // may have exceptions, int that case, the code behind may doing wrong.
            if ( _packetControler.ableToSend(nal_t[i].i_payload) == true )
            {
                if ( i == 0 )
                {
                    _sender.sendPacket((char*)nal_t[i].p_payload, nal_t[i].i_payload, time*90); // _passedTime*90000/1000;
                }
                else
                {
                    _sender.sendPacket((char*)nal_t[i].p_payload, nal_t[i].i_payload, 0);
                }
            }
        }
    }
}

void H264Coder::stopCoding()
{
    _sender.clean();
}

void H264Coder::defaultSetting()
{
    x264_param_default(&_paramWillSet);
//    x264_param_default_preset(&_paramWillSet, "veryfast", "zerolatency");
//    _paramWillSet.rc.i_lookahead = 10;    // buffer size?
    _paramWillSet.i_width = 640;
    _paramWillSet.i_height = 480;
    _paramWillSet.i_csp = X264_CSP_I420;
    _paramWillSet.i_threads = X264_SYNC_LOOKAHEAD_AUTO;
    _paramWillSet.b_repeat_headers = 1;     // 关键帧前面是否放sps跟pps帧，0 否 1，放
}
