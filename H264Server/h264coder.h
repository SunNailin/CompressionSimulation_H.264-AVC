#ifndef H264CODER_H
#define H264CODER_H

#include <QMessageBox>
#include <QObject>
#include <QImage>

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
extern "C"
{
#include "x264_config.h"
#include "x264.h"
}

#include <cv.h>
#include <highgui.h>
#include <imgproc/imgproc_c.h>

#include "h264sender.h"
#include "packetcontroler.h"

class H264Coder : public QObject
{
    Q_OBJECT
public:
    explicit H264Coder(QObject *parent = 0);
    ~H264Coder();
    H264Sender* getSender();
    PacketControler* getPacketControler();

signals:

public slots:
    void iniX264();
    void paramSetting(x264_param_t param);
    void imageCaptured(IplImage* image, unsigned int time);
    void stopCoding();

private:
    void defaultSetting();

private:
    x264_t* _hX264;
    x264_param_t _param;
    x264_param_t _paramWillSet;
    x264_picture_t _picInput;
    x264_picture_t _picOutput;

    H264Sender _sender;
    PacketControler _packetControler;

    IplImage* _imageRGB;
    IplImage* _imageYUV420;
    bool _isParamIni;

};

#endif // H264CODER_H
