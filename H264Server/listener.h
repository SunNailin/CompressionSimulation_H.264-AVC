#ifndef LISTENER_H
#define LISTENER_H

#include <QHostAddress>
#include <QUdpSocket>
#include <QByteArray>
#include <QObject>
#include <QDebug>
#include <QTimer>
#include <QVector>

#include "timermgr.h"

struct DestInfo
{
    QHostAddress addr;
    quint16 port;
    bool isActive;
};

class Listener : public QObject
{
    Q_OBJECT
public:
    explicit Listener(QObject *parent = 0);
    ~Listener();
    void setListenPort(quint16 port);
    void setWorkingState(bool flag);

signals:
    void addDest(QHostAddress addr, quint16 port);
    void delDest(QHostAddress addr, quint16 port);

public slots:

private slots:
    void readDatagrams();
    void checkEndState();

private:
    void setConnection();
    void processData(QByteArray byteArray, QHostAddress addr, quint16 port);

private:
    QUdpSocket* _udpSocket;
    quint16 _port;
    QVector<DestInfo> _destInfoVector;
    QTimer* _timer;
    bool _isWorking;
};

#endif // LISTENER_H
