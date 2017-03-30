#ifndef FFMPEGDECODER_H
#define FFMPEGDECODER_H

#include <QObject>
#include <QTimer>
#include <QImage>
#include <QDebug>

#include <cv.h>
#include <highgui.h>
#include <imgproc/imgproc_c.h>

extern "C"
{
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

class FfmpegDecoder : public QObject
{
    Q_OBJECT
public:
    explicit FfmpegDecoder(QObject *parent = 0);
    ~FfmpegDecoder();

signals:
    void updatePreview(QImage image);
    void imageCaptured(IplImage* image, unsigned int time);
    void fileClosed();

public slots:
    void openFile(QString fileName);
    void closeFile();

private slots:
    void decodeFile();

private:
    void setConnection();

private:
    AVFormatContext* _pFormatCtx;
    AVCodecContext* _pCodecCtx;
    AVCodec* _pCodec;
    AVFrame* _pFrame;
    AVFrame* _pFrameRGB;
    AVPacket _packet;
    QTimer* _pTimer;
    int _videoIndex;
    unsigned char* _yuvBuffer;
    bool _isDecoding;
    IplImage* _imageRGB;
    time_t _currentTime;
    time_t _passedTime;
};

#endif // FFMPEGDECODER_H
