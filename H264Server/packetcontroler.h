#ifndef PACKETCONTROLER_H
#define PACKETCONTROLER_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QDebug>

#include "networksetting.h"
#include "timermgr.h"

class PacketControler : public QObject
{
    Q_OBJECT
public:
    explicit PacketControler(QObject *parent = 0);
    bool ableToSend(int length);

signals:
    void bitRate(int rate);

public slots:
    void setNetWorkPara(NetWorkParam param);

private slots:
    void resetCounter();

private:
    void setConnection();

private:
    int _lostRate;  // rate of lost packet
    int _bandWidth; // bytes can be send in a second
    int _rate;
    int _byteCounter;

    QTimer* _timer;
};

#endif // PACKETCONTROLER_H
