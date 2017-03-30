#include "networksetting.h"
#include "ui_networksetting.h"

NetworkSetting::NetworkSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NetworkSetting)
{
    ui->setupUi(this);

    ui->hsLostRate->setMaximum(1000);
    ui->hsLostRate->setMinimum(0);
    ui->hsLostRate->setValue(0);
    ui->lbLostRate->setText("Packet Lost Rate: 0%");
    ui->lbBandWidth->setText("Band width (kb/s): ");
    this->setConnection();
}

NetworkSetting::~NetworkSetting()
{
    delete ui;
}

void NetworkSetting::slideBarChange(int value)
{
    QString string;
    string.setNum(value/10.0);
    ui->lePercent->setText(string);
}

void NetworkSetting::textChange(QString percent)
{
    int number;
    number = percent.toFloat()*10;
    ui->hsLostRate->setValue(number);
}

void NetworkSetting::changeSettings()
{
    NetWorkParam param;
    param.bandWidth = 0;
    param.lostRate = ui->hsLostRate->value();
    int bandWidth = ui->leBandWidth->text().toInt()*1024;
    if ( bandWidth != 0 )
    {
        param.bandWidth = bandWidth;
    }
    emit setNetWorkPara(param);
}

void NetworkSetting::setConnection()
{
    connect( ui->hsLostRate, SIGNAL(sliderMoved(int)), this, SLOT(slideBarChange(int)) );
    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(changeSettings()) );
    connect( ui->lePercent, SIGNAL(textChanged(QString)), this, SLOT(textChange(QString)) );
}
