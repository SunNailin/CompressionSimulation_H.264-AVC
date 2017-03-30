#include "listener.h"

Listener::Listener(QObject *parent) :
    QObject(parent)
{
    _udpSocket = new QUdpSocket(this);
    _port = 52749;
    _udpSocket->bind(_port, QUdpSocket::ShareAddress);
    _isWorking = false;

    TimerMgr* timerMgr = TimerMgr::getInstant();
    timerMgr->addTimer("clientUpdate");
    // 监听接收端是否在线的计时器，如果超时则清楚接收端的IP，不会再向
    // 其发送数据
    _timer = timerMgr->getTimer("clientUpdate");

    this->setConnection();
}

Listener::~Listener()
{

}

void Listener::setListenPort(quint16 port)
{
    _udpSocket->bind(port, QUdpSocket::ShareAddress);
}

void Listener::setWorkingState(bool flag)
{
    _isWorking = flag;
    if ( _isWorking )
    {
        _timer->start(40000);
    }
    else
    {
        _timer->stop();
        _destInfoVector.clear();
    }
}

void Listener::readDatagrams()
{
    while ( _udpSocket->hasPendingDatagrams() )
    {
        QByteArray datagram;
        datagram.resize(_udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        _udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        if ( _isWorking )
        {
            this->processData(datagram, sender, senderPort);
        }
    }
}

void Listener::checkEndState()
{
    for ( int i=0; i<_destInfoVector.size(); i++ )
    {
        if ( _destInfoVector[i].isActive == false )
        {
            emit delDest(_destInfoVector[i].addr, _destInfoVector[i].port+1);
            _destInfoVector.remove(i);
            i--;
            continue;
        }
        _destInfoVector[i].isActive = false;
    }
}

void Listener::setConnection()
{
    connect( _udpSocket, SIGNAL(readyRead()), this, SLOT(readDatagrams()) );
    connect( _timer, SIGNAL(timeout()), this, SLOT(checkEndState()) );
}

void Listener::processData(QByteArray byteArray, QHostAddress addr, quint16 port)
{
    char* data = byteArray.data();
    if ( data[0] == 1 )     // 1 means to setup a new connection
    {
        _udpSocket->writeDatagram(byteArray, addr, port);
        DestInfo dest;
        dest.addr = addr;
        dest.port = port;

        // if find same dest, set its flag active
        for ( int i=0; i<_destInfoVector.size(); i++ )
        {
            if ( (addr == _destInfoVector[i].addr) && (port == _destInfoVector[i].port) )
            {
                _destInfoVector[i].isActive = true;
                qDebug()<<"repeat apply detect: "<<addr<<"port: "<<port;
                return;
            }
        }
        dest.isActive = true;
        _destInfoVector.append(dest);
        emit addDest(addr, port+1);     // use port+1 to send stream data
    }
    else if ( data[0] == 2 )    // heart beat
    {
        for ( int i=0; i<_destInfoVector.size(); i++ )
        {
            if ( addr == _destInfoVector[i].addr && port == _destInfoVector[i].port )
            {
                _destInfoVector[i].isActive = true;
                break;
            }
        }
    }
}
