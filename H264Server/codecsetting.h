#ifndef CODECSETTING_H
#define CODECSETTING_H

#include <QDialog>
#include <QVariant>
#include <QDebug>

#include <stdint.h>
extern "C"
{
#include "x264_config.h"
#include "x264.h"
}

namespace Ui {
class CodecSetting;
}

class CodecSetting : public QDialog
{
    Q_OBJECT

public:
    explicit CodecSetting(QWidget *parent = 0);
    ~CodecSetting();

signals:
    void setParam(x264_param_t param);
    void setFrameRate(unsigned int framRate);

private slots:
    void paramSetting();

private:
    void setConnection();
    void iniModular();

private:
    Ui::CodecSetting *ui;
};

#endif // CODECSETTING_H
