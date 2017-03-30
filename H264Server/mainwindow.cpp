#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    _cameraMgr = new CameraMgr(this);
    _codecSetting = new CodecSetting(this);
    _networkSetting = new NetworkSetting(this);
    _coder = new H264Coder;
    _listener = new Listener(this);
    _enCodeThread = new QThread(this);
    _videoWidget = new videoWidget;
    _ffmpegDecoder = new FfmpegDecoder;
    _decoderThread = new QThread(this);

    _coder->moveToThread(_enCodeThread);
    _enCodeThread->start();

    _ffmpegDecoder->moveToThread(_decoderThread);
    _decoderThread->start();

    this->setCentralWidget(_videoWidget);
    this->getDeviceList();
    this->setConnection();
}

MainWindow::~MainWindow()
{
    delete ui;

    _enCodeThread->quit();
    _enCodeThread->wait();

    _decoderThread->quit();
    _decoderThread->wait();

    delete _ffmpegDecoder;
    delete _coder;
    delete _listener;
    delete _videoWidget;
}

void MainWindow::startSever()
{
    emit iniCoder();

    TimerMgr::getInstant()->getTimer("packetConTimer")->start(1000);
    _listener->setWorkingState(true);

    ui->statusBar->showMessage(tr("工作中"));
}

void MainWindow::startDevice()
{
    ui->actionStop_Device->setEnabled(true);
    ui->actionStart_Device->setEnabled(false);
    ui->menuDevice_List->setEnabled(false);
    ui->actionOpen_File->setEnabled(false);

    _cameraMgr->start();
    this->startSever();
}

void MainWindow::stopSever()
{
    _listener->setWorkingState(false);
    emit stopCoding();
    ui->statusBar->showMessage(tr("待机中……"));
}

void MainWindow::stopDevice()
{
    ui->actionStop_Device->setEnabled(false);
    ui->actionStart_Device->setEnabled(true);
    ui->menuDevice_List->setEnabled(true);
    ui->actionOpen_File->setEnabled(true);

    _cameraMgr->stop();
    this->stopSever();
}

void MainWindow::updatePreview(QImage image)
{
    _videoWidget->setImg(image);
    _videoWidget->update();
}

void MainWindow::bitRate(int rate)
{
    QString string;
    string.setNum(rate/1000.0);
    string += "  kb/s";
    ui->statusBar->showMessage(string);
}

void MainWindow::fileClosed()
{
    ui->actionStart_Device->setEnabled(true);
    ui->menuDevice_List->setEnabled(true);
    this->stopSever();
}

void MainWindow::setConnection()
{
    qRegisterMetaType<x264_param_t>("x264_param_t");
    qRegisterMetaType<NetWorkParam>("NetWorkParam");

    connect( ui->actionStart_Device, SIGNAL(triggered()), this, SLOT(startDevice()) );
    connect( ui->actionStop_Device, SIGNAL(triggered()), this, SLOT(stopDevice()) );
    connect( ui->actionCodec_settings, SIGNAL(triggered()), _codecSetting, SLOT(show()) );
    connect( ui->actionNetwork_settings, SIGNAL(triggered()), _networkSetting, SLOT(show()) );
    connect( _cameraMgr, SIGNAL(updatePreview(QImage)), this, SLOT(updatePreview(QImage)) );
    connect( _cameraMgr, SIGNAL(imageCaptured(IplImage*,unsigned int)), _coder, SLOT(imageCaptured(IplImage*,unsigned int)) );
    connect( this, SIGNAL(iniCoder()), _coder, SLOT(iniX264()) );
    connect( _listener, SIGNAL(addDest(QHostAddress,quint16)), _coder->getSender(), SLOT(addDest(QHostAddress,quint16)) );
    connect( _listener, SIGNAL(delDest(QHostAddress,quint16)), _coder->getSender(), SLOT(delDest(QHostAddress,quint16)) );
    connect( _codecSetting, SIGNAL(setParam(x264_param_t)), _coder, SLOT(paramSetting(x264_param_t)) );
    connect( _codecSetting, SIGNAL(setFrameRate(uint)), _cameraMgr, SLOT(setFrameRate(uint)) );
    connect( _networkSetting, SIGNAL(setNetWorkPara(NetWorkParam)), _coder->getPacketControler(), SLOT(setNetWorkPara(NetWorkParam)) );
    connect( this, SIGNAL(stopCoding()), _coder, SLOT(stopCoding()) );
    connect( _coder->getPacketControler(), SIGNAL(bitRate(int)), this, SLOT(bitRate(int)) );
    connect( this, SIGNAL(openFile(QString)), _ffmpegDecoder, SLOT(openFile(QString)) );
    connect( this, SIGNAL(closeFile()), _ffmpegDecoder, SLOT(closeFile()) );
    connect( _ffmpegDecoder, SIGNAL(updatePreview(QImage)), this, SLOT(updatePreview(QImage)) );
    connect( _ffmpegDecoder, SIGNAL(imageCaptured(IplImage*,uint)), _coder, SLOT(imageCaptured(IplImage*,uint)) );
    connect( _ffmpegDecoder, SIGNAL(fileClosed()), this, SLOT(fileClosed()) );
}

void MainWindow::getDeviceList()
{
    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    QList<QByteArray> availableDevices = QCamera::availableDevices();
    QByteArray deviceName;
    for ( int i=0; i<availableDevices.length(); i++ )
    {
        deviceName = availableDevices[i];
        QString description = QCamera::deviceDescription(deviceName);
        QAction *videoDeviceAction = new QAction(description, videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant(i));
        if ( i == 0 )
        {
            videoDeviceAction->setChecked(true);
        }
        ui->menuDevice_List->addAction(videoDeviceAction);
    }

    _cameraMgr->setDevice(0);
    connect(videoDevicesGroup, SIGNAL(triggered(QAction*)), _cameraMgr, SLOT(changeDevice(QAction*)));
}

void MainWindow::on_actionOpen_File_triggered()
{
    if ( ui->actionOpen_File->isChecked() ) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("打开视频文件"));
        if ( !fileName.isEmpty() ) {
            ui->actionStart_Device->setEnabled(false);
            ui->menuDevice_List->setEnabled(false);
            emit openFile(fileName);
            this->startSever();
        }
        else {
            ui->actionOpen_File->setEnabled(false);
        }
    }
    else {
        emit closeFile();
    }
}
