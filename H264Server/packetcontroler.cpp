#include "packetcontroler.h"

PacketControler::PacketControler(QObject *parent) :
    QObject(parent)
{
    _lostRate = 0;
    _rate = 0;
    TimerMgr* timerMgr = TimerMgr::getInstant();
    timerMgr->addTimer("packetConTimer");
    // 控制流量的计时器，定时时间为1秒，超时后将清除目前统计的已发送的字节长度
    _timer = timerMgr->getTimer("packetConTimer");
    QDateTime dateTime;
    qsrand( dateTime.toTime_t());

    this->setConnection();
}

bool PacketControler::ableToSend(int length)
{
    if ( _rate != 0 )
    {
        int index = qrand()%_rate;
        if ( index == 0 )
        {
            return false;
        }
    }

    _byteCounter += length*8;
    if ( _bandWidth != 0 )
    {
        if ( _byteCounter >= _bandWidth )
        {
            qDebug()<<"out of bit";
            return false;
        }
    }
    return true;
}

void PacketControler::setNetWorkPara(NetWorkParam param)
{
    _lostRate = param.lostRate;
    _bandWidth = param.bandWidth;
    if ( _lostRate == 0 )
    {
        _rate = 0;
    }
    else
    {
        _rate = 1000/_lostRate;
    }
    if ( _bandWidth != 0 )
    {
        _byteCounter = 0;
    }
}

void PacketControler::resetCounter()
{
    emit bitRate(_byteCounter);
    _byteCounter = 0;
}

void PacketControler::setConnection()
{
    connect( _timer, SIGNAL(timeout()), this, SLOT(resetCounter()) );
}
