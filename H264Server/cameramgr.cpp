#include "cameramgr.h"

CameraMgr::CameraMgr(QObject *parent) :
    QObject(parent)
{
    _camera = NULL;
    _imageBRG = NULL;
    _imageBRG = NULL;
    _frameRate = 25;

    TimerMgr* timerMgr = TimerMgr::getInstant();
    timerMgr->addTimer("capImgTimer");
    // 从摄像头抓取数据的计时器
    _timer = timerMgr->getTimer("capImgTimer");
    this->setConnection();
}

CameraMgr::~CameraMgr()
{
    _timer->stop();
    if ( _camera != NULL )
    {
        cvReleaseCapture(&_camera);
        _camera = NULL;
    }
}

void CameraMgr::setDevice(int device)
{
    if ( _camera != NULL )
    {
        cvReleaseCapture(&_camera);
        _camera = NULL;
    }

    _camera = cvCreateCameraCapture(device);
}

void CameraMgr::start()
{
    if ( _camera != NULL )
    {
        _timer->start(1000/_frameRate);
    }
}

void CameraMgr::stop()
{
    if ( _camera != NULL )
    {
        _timer->stop();
    }
}

void CameraMgr::changeDevice(QAction *action)
{
    int deviceId = action->data().toInt();
    this->setDevice(deviceId);
}

void CameraMgr::setFrameRate(unsigned int frameRate)
{
    _frameRate = frameRate;
}

void CameraMgr::imageCapture()
{
    _imageBRG = cvQueryFrame(_camera);
    _passedTime = clock() - _currentTime;
    _currentTime += _passedTime;
    cvCvtColor(_imageBRG, _imageBRG, CV_BGR2RGB);
    QImage image((uchar*)_imageBRG->imageData, _imageBRG->width, _imageBRG->height, QImage::Format_RGB888);
    emit updatePreview(image);
    emit imageCaptured(_imageBRG, _passedTime);
}

void CameraMgr::setConnection()
{
    connect( _timer, SIGNAL(timeout()), this, SLOT(imageCapture()) );
}
