#ifndef NETWORKSETTING_H
#define NETWORKSETTING_H

#include <QString>
#include <QDialog>

struct NetWorkParam
{
    int lostRate;
    int bandWidth;
};

namespace Ui {
class NetworkSetting;
}

class NetworkSetting : public QDialog
{
    Q_OBJECT

public:
    explicit NetworkSetting(QWidget *parent = 0);
    ~NetworkSetting();

signals:
    void setNetWorkPara(NetWorkParam param);

private slots:
    void slideBarChange(int value);
    void textChange(QString percent);
    void changeSettings();

private:
    void setConnection();

private:
    Ui::NetworkSetting *ui;
};

#endif // NETWORKSETTING_H
