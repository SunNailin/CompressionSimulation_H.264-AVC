#ifndef TIMERMGR_H
#define TIMERMGR_H

#include <QObject>
#include <QTimer>
#include <QVector>
#include <QString>
#include <QDebug>

struct TimerInfo
{
    QString name;
    QTimer* timer;
};

class TimerMgr : public QObject
{
    Q_OBJECT
public:
    explicit TimerMgr(QObject *parent = 0);
    ~TimerMgr();
    static TimerMgr* getInstant();
    int addTimer(QString name);
    QTimer* getTimer(QString name);
    int startTimer(QString name, int mse);
    int stopTimer(QString name);

signals:

public slots:

private:
    static TimerMgr* _timerMgr;
    QVector<TimerInfo> _timerInfo;
};

#endif // TIMERMGR_H
