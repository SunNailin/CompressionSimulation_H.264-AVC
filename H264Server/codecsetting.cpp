#include "codecsetting.h"
#include "ui_codecsetting.h"

CodecSetting::CodecSetting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CodecSetting)
{
    ui->setupUi(this);

    this->iniModular();
    this->setConnection();
}

CodecSetting::~CodecSetting()
{
    delete ui;
}

void CodecSetting::paramSetting()
{
    x264_param_t param;
    QString prefile, tune;
    prefile.clear();
    tune.clear();

    x264_param_default(&param);

    param.i_csp = X264_CSP_I420;
    param.i_threads = X264_SYNC_LOOKAHEAD_AUTO;
    param.b_repeat_headers = 1;     // 关键帧前面是否放sps跟pps帧，0 否 1，放

    // get parameter from ui
    // set codeRate
    if ( ui->cbCodeRate->itemData(ui->cbCodeRate->currentIndex()).toString() != "default" )
    {
        prefile = ui->cbCodeRate->itemData(ui->cbCodeRate->currentIndex()).toString();
    }
    // set source type
    if ( ui->cbSource->itemData(ui->cbSource->currentIndex()).toString() != "default" )
    {
        tune = ui->cbSource->itemData(ui->cbSource->currentIndex()).toString();
    }
    x264_param_default_preset(&param, prefile.toStdString().c_str(), tune.toStdString().c_str());

    // set frame rate
    if ( ui->leFrameRate->text().isEmpty() == false )
    {
        emit setFrameRate(ui->leFrameRate->text().toInt());
    }

    // set max I frame
    if ( ui->leMaxFrame->text().isEmpty() == false )
    {
        param.i_keyint_max = ui->leMaxFrame->text().toInt();
    }

    // set min I frame
    if ( ui->leMinFrame->text().isEmpty() == false )
    {
        param.i_keyint_min = ui->leMinFrame->text().toInt();
    }

    // set frame reference
    if ( ui->leFrameRef->text().isEmpty() == false )
    {
        param.i_frame_reference = ui->leFrameRef->text().toInt();
    }

    // set B frame number between I and P frame
    if ( ui->leBFrame->text().isEmpty() == false )
    {
        param.i_bframe = ui->leBFrame->text().toInt();
    }

    // set B frame bias
    if ( ui->leBframeBias->text().isEmpty() == false )
    {
        param.i_bframe_bias = ui->leBframeBias->text().toInt();
    }

    // set rate control lookhead
    if ( ui->leRcLookahead->text().isEmpty() == false )
    {
        param.rc.i_lookahead = ui->leRcLookahead->text().toInt();
    }

    // set source size
    if ( (ui->leHeight->text().isEmpty() == false) && (ui->leWidth->text().isEmpty() == false) )
    {
        param.i_width = ui->leWidth->text().toInt();
        param.i_height = ui->leHeight->text().toInt();
    }

    // set alpha filter
    if ( ui->leAlpha->text().isEmpty() == false )
    {
        param.i_deblocking_filter_alphac0 = ui->leAlpha->text().toInt();
    }

    // set beta filter
    if ( ui->leBeta->text().isEmpty() == false )
    {
        param.i_deblocking_filter_beta = ui->leBeta->text().toInt();
    }

    // set constant qp
    if ( ui->leQpConstant->text().isEmpty() == false )
    {
        param.rc.i_qp_constant = ui->leQpConstant->text().toInt();
    }

    // set max qp
    if ( ui->leQpMax->text().isEmpty() == false )
    {
        param.rc.i_qp_max = ui->leQpMax->text().toInt();
    }

    // set min qp
    if ( ui->leQpMin->text().isEmpty() == false )
    {
        param.rc.i_qp_min = ui->leQpMin->text().toInt();
    }

    // set qp step
    if ( ui->leQpStep->text().isEmpty() == false )
    {
        param.rc.i_qp_step = ui->leQpStep->text().toInt();
    }

    // set means bit rate
    if ( ui->leRateMeans->text().isEmpty() == false )
    {
        param.rc.i_bitrate = ui->leRateMeans->text().toInt();
    }

    // set rate tolerance
    if ( ui->leRateTol->text().isEmpty() == false )
    {
        param.rc.f_rate_tolerance = ui->leRateTol->text().toFloat();
    }

    // set max bit rate
    if ( ui->leVbvRate->text().isEmpty() == false )
    {
        param.rc.i_vbv_max_bitrate = ui->leVbvRate->text().toInt();
    }

    // set vbv buffer size
    if ( ui->leVbvBuf->text().isEmpty() == false )
    {
        param.rc.i_vbv_buffer_size = ui->leVbvBuf->text().toInt();
    }

    // set vbv ini
    if ( ui->leVbvinit->text().isEmpty() == false )
    {
        param.rc.f_vbv_buffer_init = ui->leVbvinit->text().toFloat();
    }

    // set scene cut threshold
    if ( ui->leScutThres->text().isEmpty() == false )
    {
        param.i_scenecut_threshold = ui->leScutThres->text().toInt();
    }

    // set rf constant
    if ( ui->leRfConstant->text().isEmpty() == false )
    {
        param.rc.f_rf_constant = ui->leRfConstant->text().toFloat();
    }

    // set rf constant max
    if ( ui->leRfMax->text().isEmpty() == false )
    {
        param.rc.f_rf_constant_max = ui->leRfConstant->text().toFloat();
    }

    // set B frame adaptive
    param.i_bframe_adaptive = ui->cbBframeAdapt->currentIndex();

    // set B frame pyramid
    param.i_bframe_pyramid = ui->cbBframePyr->currentIndex();

    // set rate control method
    param.rc.i_rc_method = ui->cbRcMethod->currentIndex();

    // set deBlock filter
    param.b_deblocking_filter = ui->cbDeblock->currentIndex();

    // send parameter
    emit setParam(param);
}

void CodecSetting::setConnection()
{
    connect( ui->buttonBox, SIGNAL(accepted()), this, SLOT(paramSetting()) );
}

void CodecSetting::iniModular()
{
    // set combine box of codec rate
    ui->cbCodeRate->addItem(tr("默认"), QVariant("default"));
    ui->cbCodeRate->addItem(tr("极快"), QVariant("ultrafast"));
    ui->cbCodeRate->addItem(tr("超快"), QVariant("superfast"));
    ui->cbCodeRate->addItem(tr("非常快"), QVariant("veryfast"));
    ui->cbCodeRate->addItem(tr("很快"), QVariant("faster"));
    ui->cbCodeRate->addItem(tr("快"), QVariant("fast"));
    ui->cbCodeRate->addItem(tr("中等"), QVariant("medium"));
    ui->cbCodeRate->addItem(tr("慢"), QVariant("slow"));
    ui->cbCodeRate->addItem(tr("很慢"), QVariant("slower"));
    ui->cbCodeRate->addItem(tr("非常慢"), QVariant("veryslow"));
    ui->cbCodeRate->addItem(tr("超慢"), QVariant("placebo"));
    ui->cbCodeRate->setCurrentIndex(0);

    // set combine box of source type
    ui->cbSource->addItem(tr("默认"), QVariant("default"));
    ui->cbSource->addItem(tr("电影"), QVariant("film"));
    ui->cbSource->addItem(tr("动画"), QVariant("animation"));
    ui->cbSource->addItem(tr("胶片"), QVariant("grain"));
    ui->cbSource->addItem(tr("静态图"), QVariant("stillimage"));
    ui->cbSource->addItem(tr("psnr"), QVariant("psnr"));
    ui->cbSource->addItem(tr("ssim"), QVariant("ssim"));
    ui->cbSource->addItem(tr("快速解码"), QVariant("fastdecode"));
    ui->cbSource->addItem(tr("低时延"), QVariant("zerolatency"));
    ui->cbSource->setCurrentIndex(0);

    // set combine box of i_bframe_adaptive
    ui->cbBframeAdapt->addItem(tr("关闭"));
    ui->cbBframeAdapt->addItem(tr("快速"));
    ui->cbBframeAdapt->addItem(tr("最优"));
    ui->cbBframeAdapt->setCurrentIndex(1);

    // set combine box of i_bframe_pyramid
    ui->cbBframePyr->addItem(tr("关闭"));
    ui->cbBframePyr->addItem(tr("限制"));
    ui->cbBframePyr->addItem(tr("普通"));
    ui->cbBframePyr->setCurrentIndex(2);

    // set combine box of b_deblocking_filter
    ui->cbDeblock->addItem(tr("关闭"));
    ui->cbDeblock->addItem(tr("开启"));
    ui->cbDeblock->setCurrentIndex(1);

    // set combine box of i_rc_method
    ui->cbRcMethod->addItem(tr("恒定量化"));
    ui->cbRcMethod->addItem(tr("恒定质量"));
    ui->cbRcMethod->addItem(tr("恒定码率"));
    ui->cbRcMethod->setCurrentIndex(1);
}
