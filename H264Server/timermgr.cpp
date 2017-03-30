#include "timermgr.h"

TimerMgr* TimerMgr::_timerMgr = NULL;

TimerMgr::TimerMgr(QObject *parent) :
    QObject(parent)
{
}

TimerMgr::~TimerMgr()
{
    for ( int i=0; i < _timerInfo.size(); i++ )
    {
        delete _timerInfo[i].timer;
    }
    _timerInfo.clear();
}

TimerMgr* TimerMgr::getInstant()
{
    if ( _timerMgr == NULL )
    {
        _timerMgr = new TimerMgr();
    }
    return _timerMgr;
}

int TimerMgr::addTimer(QString name)
{
    for( int i=0; i < _timerInfo.size(); i++ )
    {
        if ( name == _timerInfo[i].name )
        {
            qDebug()<<name<<" had been created.";
            return -1;
        }
    }

    TimerInfo info;
    info.name = name;
    info.timer = new QTimer(this);
    _timerInfo.append(info);
    qDebug()<<"add timer: "<<name;
    return 0;
}

QTimer *TimerMgr::getTimer(QString name)
{
    for ( int i=0; i < _timerInfo.size(); i++ )
    {
        if ( _timerInfo[i].name == name )
        {
            return _timerInfo[i].timer;
        }
    }
    return NULL;
}

int TimerMgr::startTimer(QString name, int mse)
{
    for ( int i=0; i < _timerInfo.size(); i++ )
    {
        if ( _timerInfo[i].name == name )
        {
            _timerInfo[i].timer->start(mse);
            return 0;
        }
    }
    return -1;
}

int TimerMgr::stopTimer(QString name)
{
    for ( int i=0; i < _timerInfo.size(); i++ )
    {
        if ( _timerInfo[i].name == name )
        {
            _timerInfo[i].timer->stop();
            return 0;
        }
    }
    return -1;
}
