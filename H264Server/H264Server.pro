#-------------------------------------------------
#
# Project created by QtCreator 2014-07-09T10:29:37
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += thread

INCLUDEPATH += "C:\IDE\X264\include"
INCLUDEPATH += "C:\IDE\opencv\build\include"
INCLUDEPATH += "C:\IDE\opencv\build\include\opencv"
INCLUDEPATH += "C:\IDE\opencv\build\include\opencv2"
INCLUDEPATH += "C:\IDE\ffmpeg\include"

LIBS += -L"C:\IDE\X264\lib" -llibx264-142
LIBS += -L"C:\IDE\opencv\build\x86\vc10\lib" -lopencv_core2410d
LIBS += -L"C:\IDE\opencv\build\x86\vc10\lib" -lopencv_highgui2410d
LIBS += -L"C:\IDE\opencv\build\x86\vc10\lib" -lopencv_imgproc2410d
LIBS += -L"C:\IDE\opencv\build\x86\vc10\lib" -lopencv_video2410d
LIBS += -L"C:\IDE\opencv\build\x86\vc10\lib" -lopencv_videostab2410d
LIBS += -L"C:\IDE\ffmpeg\lib" -lavcodec
LIBS += -L"C:\IDE\ffmpeg\lib" -lavdevice
LIBS += -L"C:\IDE\ffmpeg\lib" -lavfilter
LIBS += -L"C:\IDE\ffmpeg\lib" -lavformat
LIBS += -L"C:\IDE\ffmpeg\lib" -lavutil
LIBS += -L"C:\IDE\ffmpeg\lib" -lpostproc
LIBS += -L"C:\IDE\ffmpeg\lib" -lswresample
LIBS += -L"C:\IDE\ffmpeg\lib" -lswscale

TARGET = H264Server
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    h264sender.cpp \
    cameramgr.cpp \
    h264coder.cpp \
    codecsetting.cpp \
    networksetting.cpp \
    listener.cpp \
    packetcontroler.cpp \
    timermgr.cpp \
    videowidget.cpp \
    ffmpegdecoder.cpp

HEADERS  += mainwindow.h \
    h264sender.h \
    cameramgr.h \
    h264coder.h \
    codecsetting.h \
    networksetting.h \
    listener.h \
    packetcontroler.h \
    timermgr.h \
    videowidget.h \
    ffmpegdecoder.h

FORMS    += mainwindow.ui \
    codecsetting.ui \
    networksetting.ui \
    videowidget.ui
