#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QActionGroup>
#include <QMainWindow>
#include <QFileDialog>
#include <QByteArray>
#include <QCamera>
#include <QAction>
#include <QLabel>
#include <QList>
#include <QTime>

#include "cameramgr.h"
#include "codecsetting.h"
#include "networksetting.h"
#include "listener.h"
#include "videowidget.h"
#include "ffmpegdecoder.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void stopCoding();
    void openFile(QString fileName);
    void closeFile();
    void iniCoder();

private slots:
    void startSever();
    void startDevice();
    void stopSever();
    void stopDevice();
    void updatePreview(QImage image);
    void bitRate(int rate);
    void fileClosed();
    void on_actionOpen_File_triggered();

private:
    void setConnection();
    void getDeviceList();

private:
    Ui::MainWindow *ui;

    CameraMgr* _cameraMgr;
    QThread* _enCodeThread;

    FfmpegDecoder* _ffmpegDecoder;
    QThread* _decoderThread;

    H264Coder* _coder;
    CodecSetting* _codecSetting;
    NetworkSetting* _networkSetting;
    Listener* _listener;
    videoWidget* _videoWidget;
};

#endif // MAINWINDOW_H
