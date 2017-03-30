#ifndef CameraMgr_H
#define CameraMgr_H

#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QHostAddress>
#include <QMessageBox>
#include <QByteArray>
#include <QAction>
#include <QCamera>
#include <QObject>
#include <QThread>
#include <QDebug>
#include <QTimer>
#include <QImage>

#include <cv.h>
#include <highgui.h>
#include <imgproc/imgproc_c.h>

#include <stdio.h>
#include <stdlib.h>

#include "h264coder.h"
#include "timermgr.h"

class CameraMgr : public QObject
{
    Q_OBJECT
public:
    explicit CameraMgr(QObject *parent = 0);
    ~CameraMgr();
    void setDevice(int device);
    void start();
    void stop();

signals:
    void updatePreview(QImage image);
    void imageCaptured(IplImage* image, unsigned int time);

public slots:
    void changeDevice(QAction* action);
    void setFrameRate(unsigned int frameRate);

private slots:
    void imageCapture();

private:
    void setConnection();

private:
    CvCapture* _camera;
    IplImage* _imageBRG;    // I don't know if I have to release memory. This may cause memory leak

    QTimer* _timer;
    unsigned _frameRate;

    time_t _currentTime;
    time_t _passedTime;
};

#endif // CameraMgr_H
