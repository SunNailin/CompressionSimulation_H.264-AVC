/********************************************************************************
** Form generated from reading UI file 'codecsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODECSETTING_H
#define UI_CODECSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CodecSetting
{
public:
    QGridLayout *gridLayout_5;
    QGroupBox *gbFrame;
    QGridLayout *gridLayout_2;
    QLabel *lbFrameRate;
    QLineEdit *leFrameRate;
    QLabel *lbMaxFrame;
    QLineEdit *leMaxFrame;
    QLabel *lbMinFrame;
    QLineEdit *leMinFrame;
    QLabel *lbFrameRef;
    QLineEdit *leFrameRef;
    QLabel *lbScutThres;
    QLineEdit *leScutThres;
    QLabel *lbBFrame;
    QLineEdit *leBFrame;
    QLabel *lbBframeAdapt;
    QComboBox *cbBframeAdapt;
    QLabel *lbBframePyr;
    QComboBox *cbBframePyr;
    QLabel *lbBframeBias;
    QLineEdit *leBframeBias;
    QLabel *lbRcLookahead;
    QLineEdit *leRcLookahead;
    QGroupBox *gbSource;
    QGridLayout *gridLayout;
    QLabel *lbCodeRate;
    QComboBox *cbCodeRate;
    QLabel *lbSource;
    QComboBox *cbSource;
    QLabel *lbWidth;
    QLineEdit *leWidth;
    QLabel *lbHeight;
    QLineEdit *leHeight;
    QGroupBox *gbRate;
    QGridLayout *gridLayout_3;
    QLabel *lbRcMethod;
    QComboBox *cbRcMethod;
    QLabel *lbQpConstant;
    QLineEdit *leQpConstant;
    QLabel *lbQpMax;
    QLineEdit *leQpMax;
    QLabel *lbQpMin;
    QLineEdit *leQpMin;
    QLabel *lbQpStep;
    QLineEdit *leQpStep;
    QLabel *lbRateMeans;
    QLineEdit *leRateMeans;
    QLabel *lbRateTol;
    QLineEdit *leRateTol;
    QLabel *lbVbvRate;
    QLineEdit *leVbvRate;
    QLabel *lbVbvBuf;
    QLineEdit *leVbvBuf;
    QLabel *lbVbvinit;
    QLineEdit *leVbvinit;
    QLabel *lbRfConstant;
    QLineEdit *leRfConstant;
    QLabel *lbRfMax;
    QLineEdit *leRfMax;
    QGroupBox *gbFilter;
    QGridLayout *gridLayout_4;
    QLabel *lbDeblock;
    QComboBox *cbDeblock;
    QLabel *lbAlpha;
    QLineEdit *leAlpha;
    QLabel *lbBeta;
    QLineEdit *leBeta;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CodecSetting)
    {
        if (CodecSetting->objectName().isEmpty())
            CodecSetting->setObjectName(QStringLiteral("CodecSetting"));
        CodecSetting->resize(577, 385);
        gridLayout_5 = new QGridLayout(CodecSetting);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gbFrame = new QGroupBox(CodecSetting);
        gbFrame->setObjectName(QStringLiteral("gbFrame"));
        gridLayout_2 = new QGridLayout(gbFrame);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lbFrameRate = new QLabel(gbFrame);
        lbFrameRate->setObjectName(QStringLiteral("lbFrameRate"));
        lbFrameRate->setMaximumSize(QSize(100, 20));

        gridLayout_2->addWidget(lbFrameRate, 0, 0, 1, 1);

        leFrameRate = new QLineEdit(gbFrame);
        leFrameRate->setObjectName(QStringLiteral("leFrameRate"));
        leFrameRate->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leFrameRate, 0, 1, 1, 1);

        lbMaxFrame = new QLabel(gbFrame);
        lbMaxFrame->setObjectName(QStringLiteral("lbMaxFrame"));
        lbMaxFrame->setMaximumSize(QSize(100, 20));

        gridLayout_2->addWidget(lbMaxFrame, 1, 0, 1, 1);

        leMaxFrame = new QLineEdit(gbFrame);
        leMaxFrame->setObjectName(QStringLiteral("leMaxFrame"));
        leMaxFrame->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leMaxFrame, 1, 1, 1, 1);

        lbMinFrame = new QLabel(gbFrame);
        lbMinFrame->setObjectName(QStringLiteral("lbMinFrame"));
        lbMinFrame->setMaximumSize(QSize(100, 20));

        gridLayout_2->addWidget(lbMinFrame, 2, 0, 1, 1);

        leMinFrame = new QLineEdit(gbFrame);
        leMinFrame->setObjectName(QStringLiteral("leMinFrame"));
        leMinFrame->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leMinFrame, 2, 1, 1, 1);

        lbFrameRef = new QLabel(gbFrame);
        lbFrameRef->setObjectName(QStringLiteral("lbFrameRef"));

        gridLayout_2->addWidget(lbFrameRef, 3, 0, 1, 1);

        leFrameRef = new QLineEdit(gbFrame);
        leFrameRef->setObjectName(QStringLiteral("leFrameRef"));
        leFrameRef->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leFrameRef, 3, 1, 1, 1);

        lbScutThres = new QLabel(gbFrame);
        lbScutThres->setObjectName(QStringLiteral("lbScutThres"));

        gridLayout_2->addWidget(lbScutThres, 4, 0, 1, 1);

        leScutThres = new QLineEdit(gbFrame);
        leScutThres->setObjectName(QStringLiteral("leScutThres"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leScutThres->sizePolicy().hasHeightForWidth());
        leScutThres->setSizePolicy(sizePolicy);
        leScutThres->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leScutThres, 4, 1, 1, 1);

        lbBFrame = new QLabel(gbFrame);
        lbBFrame->setObjectName(QStringLiteral("lbBFrame"));
        lbBFrame->setMaximumSize(QSize(100, 20));

        gridLayout_2->addWidget(lbBFrame, 5, 0, 1, 1);

        leBFrame = new QLineEdit(gbFrame);
        leBFrame->setObjectName(QStringLiteral("leBFrame"));
        leBFrame->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leBFrame, 5, 1, 1, 1);

        lbBframeAdapt = new QLabel(gbFrame);
        lbBframeAdapt->setObjectName(QStringLiteral("lbBframeAdapt"));

        gridLayout_2->addWidget(lbBframeAdapt, 6, 0, 1, 1);

        cbBframeAdapt = new QComboBox(gbFrame);
        cbBframeAdapt->setObjectName(QStringLiteral("cbBframeAdapt"));
        sizePolicy.setHeightForWidth(cbBframeAdapt->sizePolicy().hasHeightForWidth());
        cbBframeAdapt->setSizePolicy(sizePolicy);
        cbBframeAdapt->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(cbBframeAdapt, 6, 1, 1, 1);

        lbBframePyr = new QLabel(gbFrame);
        lbBframePyr->setObjectName(QStringLiteral("lbBframePyr"));

        gridLayout_2->addWidget(lbBframePyr, 7, 0, 1, 1);

        cbBframePyr = new QComboBox(gbFrame);
        cbBframePyr->setObjectName(QStringLiteral("cbBframePyr"));
        sizePolicy.setHeightForWidth(cbBframePyr->sizePolicy().hasHeightForWidth());
        cbBframePyr->setSizePolicy(sizePolicy);
        cbBframePyr->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(cbBframePyr, 7, 1, 1, 1);

        lbBframeBias = new QLabel(gbFrame);
        lbBframeBias->setObjectName(QStringLiteral("lbBframeBias"));

        gridLayout_2->addWidget(lbBframeBias, 8, 0, 1, 1);

        leBframeBias = new QLineEdit(gbFrame);
        leBframeBias->setObjectName(QStringLiteral("leBframeBias"));
        leBframeBias->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leBframeBias, 8, 1, 1, 1);

        lbRcLookahead = new QLabel(gbFrame);
        lbRcLookahead->setObjectName(QStringLiteral("lbRcLookahead"));

        gridLayout_2->addWidget(lbRcLookahead, 9, 0, 1, 1);

        leRcLookahead = new QLineEdit(gbFrame);
        leRcLookahead->setObjectName(QStringLiteral("leRcLookahead"));
        leRcLookahead->setMaximumSize(QSize(80, 20));

        gridLayout_2->addWidget(leRcLookahead, 9, 1, 1, 1);


        gridLayout_5->addWidget(gbFrame, 0, 0, 2, 1);

        gbSource = new QGroupBox(CodecSetting);
        gbSource->setObjectName(QStringLiteral("gbSource"));
        gridLayout = new QGridLayout(gbSource);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbCodeRate = new QLabel(gbSource);
        lbCodeRate->setObjectName(QStringLiteral("lbCodeRate"));
        lbCodeRate->setMaximumSize(QSize(60, 20));

        gridLayout->addWidget(lbCodeRate, 0, 0, 1, 1);

        cbCodeRate = new QComboBox(gbSource);
        cbCodeRate->setObjectName(QStringLiteral("cbCodeRate"));
        cbCodeRate->setMaximumSize(QSize(80, 20));

        gridLayout->addWidget(cbCodeRate, 0, 1, 1, 1);

        lbSource = new QLabel(gbSource);
        lbSource->setObjectName(QStringLiteral("lbSource"));
        lbSource->setMaximumSize(QSize(60, 20));
        lbSource->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lbSource, 1, 0, 1, 1);

        cbSource = new QComboBox(gbSource);
        cbSource->setObjectName(QStringLiteral("cbSource"));
        cbSource->setMaximumSize(QSize(80, 20));

        gridLayout->addWidget(cbSource, 1, 1, 1, 1);

        lbWidth = new QLabel(gbSource);
        lbWidth->setObjectName(QStringLiteral("lbWidth"));
        lbWidth->setMaximumSize(QSize(60, 20));

        gridLayout->addWidget(lbWidth, 2, 0, 1, 1);

        leWidth = new QLineEdit(gbSource);
        leWidth->setObjectName(QStringLiteral("leWidth"));
        leWidth->setMaximumSize(QSize(80, 20));

        gridLayout->addWidget(leWidth, 2, 1, 1, 1);

        lbHeight = new QLabel(gbSource);
        lbHeight->setObjectName(QStringLiteral("lbHeight"));
        lbHeight->setMaximumSize(QSize(60, 20));

        gridLayout->addWidget(lbHeight, 3, 0, 1, 1);

        leHeight = new QLineEdit(gbSource);
        leHeight->setObjectName(QStringLiteral("leHeight"));
        leHeight->setMaximumSize(QSize(80, 20));

        gridLayout->addWidget(leHeight, 3, 1, 1, 1);


        gridLayout_5->addWidget(gbSource, 0, 1, 1, 1);

        gbRate = new QGroupBox(CodecSetting);
        gbRate->setObjectName(QStringLiteral("gbRate"));
        gridLayout_3 = new QGridLayout(gbRate);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lbRcMethod = new QLabel(gbRate);
        lbRcMethod->setObjectName(QStringLiteral("lbRcMethod"));

        gridLayout_3->addWidget(lbRcMethod, 0, 0, 1, 1);

        cbRcMethod = new QComboBox(gbRate);
        cbRcMethod->setObjectName(QStringLiteral("cbRcMethod"));
        cbRcMethod->setMinimumSize(QSize(80, 20));
        cbRcMethod->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(cbRcMethod, 0, 1, 1, 1);

        lbQpConstant = new QLabel(gbRate);
        lbQpConstant->setObjectName(QStringLiteral("lbQpConstant"));

        gridLayout_3->addWidget(lbQpConstant, 1, 0, 1, 1);

        leQpConstant = new QLineEdit(gbRate);
        leQpConstant->setObjectName(QStringLiteral("leQpConstant"));
        leQpConstant->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leQpConstant, 1, 1, 1, 1);

        lbQpMax = new QLabel(gbRate);
        lbQpMax->setObjectName(QStringLiteral("lbQpMax"));
        lbQpMax->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(lbQpMax, 2, 0, 1, 1);

        leQpMax = new QLineEdit(gbRate);
        leQpMax->setObjectName(QStringLiteral("leQpMax"));
        leQpMax->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leQpMax, 2, 1, 1, 1);

        lbQpMin = new QLabel(gbRate);
        lbQpMin->setObjectName(QStringLiteral("lbQpMin"));
        lbQpMin->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(lbQpMin, 3, 0, 1, 1);

        leQpMin = new QLineEdit(gbRate);
        leQpMin->setObjectName(QStringLiteral("leQpMin"));
        leQpMin->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leQpMin, 3, 1, 1, 1);

        lbQpStep = new QLabel(gbRate);
        lbQpStep->setObjectName(QStringLiteral("lbQpStep"));

        gridLayout_3->addWidget(lbQpStep, 4, 0, 1, 1);

        leQpStep = new QLineEdit(gbRate);
        leQpStep->setObjectName(QStringLiteral("leQpStep"));
        leQpStep->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leQpStep, 4, 1, 1, 1);

        lbRateMeans = new QLabel(gbRate);
        lbRateMeans->setObjectName(QStringLiteral("lbRateMeans"));
        lbRateMeans->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(lbRateMeans, 5, 0, 1, 1);

        leRateMeans = new QLineEdit(gbRate);
        leRateMeans->setObjectName(QStringLiteral("leRateMeans"));
        leRateMeans->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leRateMeans, 5, 1, 1, 1);

        lbRateTol = new QLabel(gbRate);
        lbRateTol->setObjectName(QStringLiteral("lbRateTol"));

        gridLayout_3->addWidget(lbRateTol, 6, 0, 1, 1);

        leRateTol = new QLineEdit(gbRate);
        leRateTol->setObjectName(QStringLiteral("leRateTol"));
        leRateTol->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leRateTol, 6, 1, 1, 1);

        lbVbvRate = new QLabel(gbRate);
        lbVbvRate->setObjectName(QStringLiteral("lbVbvRate"));
        lbVbvRate->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(lbVbvRate, 7, 0, 1, 1);

        leVbvRate = new QLineEdit(gbRate);
        leVbvRate->setObjectName(QStringLiteral("leVbvRate"));
        leVbvRate->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leVbvRate, 7, 1, 1, 1);

        lbVbvBuf = new QLabel(gbRate);
        lbVbvBuf->setObjectName(QStringLiteral("lbVbvBuf"));

        gridLayout_3->addWidget(lbVbvBuf, 8, 0, 1, 1);

        leVbvBuf = new QLineEdit(gbRate);
        leVbvBuf->setObjectName(QStringLiteral("leVbvBuf"));
        leVbvBuf->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leVbvBuf, 8, 1, 1, 1);

        lbVbvinit = new QLabel(gbRate);
        lbVbvinit->setObjectName(QStringLiteral("lbVbvinit"));

        gridLayout_3->addWidget(lbVbvinit, 9, 0, 1, 1);

        leVbvinit = new QLineEdit(gbRate);
        leVbvinit->setObjectName(QStringLiteral("leVbvinit"));
        leVbvinit->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leVbvinit, 9, 1, 1, 1);

        lbRfConstant = new QLabel(gbRate);
        lbRfConstant->setObjectName(QStringLiteral("lbRfConstant"));

        gridLayout_3->addWidget(lbRfConstant, 10, 0, 1, 1);

        leRfConstant = new QLineEdit(gbRate);
        leRfConstant->setObjectName(QStringLiteral("leRfConstant"));
        leRfConstant->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leRfConstant, 10, 1, 1, 1);

        lbRfMax = new QLabel(gbRate);
        lbRfMax->setObjectName(QStringLiteral("lbRfMax"));

        gridLayout_3->addWidget(lbRfMax, 11, 0, 1, 1);

        leRfMax = new QLineEdit(gbRate);
        leRfMax->setObjectName(QStringLiteral("leRfMax"));
        leRfMax->setMaximumSize(QSize(80, 20));

        gridLayout_3->addWidget(leRfMax, 11, 1, 1, 1);


        gridLayout_5->addWidget(gbRate, 0, 2, 2, 1);

        gbFilter = new QGroupBox(CodecSetting);
        gbFilter->setObjectName(QStringLiteral("gbFilter"));
        gridLayout_4 = new QGridLayout(gbFilter);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lbDeblock = new QLabel(gbFilter);
        lbDeblock->setObjectName(QStringLiteral("lbDeblock"));

        gridLayout_4->addWidget(lbDeblock, 0, 0, 1, 1);

        cbDeblock = new QComboBox(gbFilter);
        cbDeblock->setObjectName(QStringLiteral("cbDeblock"));
        cbDeblock->setMinimumSize(QSize(80, 20));
        cbDeblock->setMaximumSize(QSize(80, 20));

        gridLayout_4->addWidget(cbDeblock, 0, 1, 1, 1);

        lbAlpha = new QLabel(gbFilter);
        lbAlpha->setObjectName(QStringLiteral("lbAlpha"));

        gridLayout_4->addWidget(lbAlpha, 1, 0, 1, 1);

        leAlpha = new QLineEdit(gbFilter);
        leAlpha->setObjectName(QStringLiteral("leAlpha"));
        leAlpha->setMaximumSize(QSize(80, 20));

        gridLayout_4->addWidget(leAlpha, 1, 1, 1, 1);

        lbBeta = new QLabel(gbFilter);
        lbBeta->setObjectName(QStringLiteral("lbBeta"));

        gridLayout_4->addWidget(lbBeta, 2, 0, 1, 1);

        leBeta = new QLineEdit(gbFilter);
        leBeta->setObjectName(QStringLiteral("leBeta"));
        leBeta->setMaximumSize(QSize(80, 20));

        gridLayout_4->addWidget(leBeta, 2, 1, 1, 1);


        gridLayout_5->addWidget(gbFilter, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(CodecSetting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_5->addWidget(buttonBox, 2, 2, 1, 1);


        retranslateUi(CodecSetting);
        QObject::connect(buttonBox, SIGNAL(accepted()), CodecSetting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CodecSetting, SLOT(reject()));

        QMetaObject::connectSlotsByName(CodecSetting);
    } // setupUi

    void retranslateUi(QDialog *CodecSetting)
    {
        CodecSetting->setWindowTitle(QApplication::translate("CodecSetting", "\347\274\226\347\240\201\350\256\276\347\275\256", 0));
        gbFrame->setTitle(QApplication::translate("CodecSetting", "\345\270\247\351\200\211\351\241\271", 0));
        lbFrameRate->setText(QApplication::translate("CodecSetting", "\345\270\247\351\200\237\347\216\207\357\274\232", 0));
        leFrameRate->setText(QString());
        lbMaxFrame->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247IDR\345\270\247\351\227\264\351\232\224\357\274\232", 0));
        leMaxFrame->setText(QString());
        lbMinFrame->setText(QApplication::translate("CodecSetting", "\346\234\200\345\260\217IDR\345\270\247\351\227\264\351\232\224\357\274\232", 0));
        leMinFrame->setText(QString());
        lbFrameRef->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247\345\217\202\350\200\203\345\270\247\346\225\260\357\274\232", 0));
        lbScutThres->setText(QApplication::translate("CodecSetting", "\345\234\272\346\231\257\345\210\207\346\215\242\351\227\250\351\231\220\357\274\232", 0));
        lbBFrame->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247B\345\270\247\346\225\260\351\207\217\357\274\232", 0));
        leBFrame->setText(QString());
        lbBframeAdapt->setText(QApplication::translate("CodecSetting", "\350\207\252\351\200\202\345\272\224B\345\270\247\347\255\226\347\225\245\357\274\232", 0));
        lbBframePyr->setText(QApplication::translate("CodecSetting", "\345\217\202\350\200\203B\345\270\247\347\255\226\347\225\245\357\274\232", 0));
        lbBframeBias->setText(QApplication::translate("CodecSetting", "B\345\270\247\346\217\222\345\205\245\345\200\276\345\220\221\357\274\232", 0));
        lbRcLookahead->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247\347\274\223\345\206\262\345\270\247\346\225\260\357\274\232", 0));
        gbSource->setTitle(QApplication::translate("CodecSetting", "\346\272\220\350\256\276\347\275\256", 0));
        lbCodeRate->setText(QApplication::translate("CodecSetting", "\347\274\226\347\240\201\351\200\237\345\272\246\357\274\232", 0));
        lbSource->setText(QApplication::translate("CodecSetting", "\350\247\206\351\242\221\346\272\220\357\274\232", 0));
        lbWidth->setText(QApplication::translate("CodecSetting", "\350\247\206\351\242\221\345\256\275\345\272\246\357\274\232", 0));
        leWidth->setText(QApplication::translate("CodecSetting", "640", 0));
        lbHeight->setText(QApplication::translate("CodecSetting", "\350\247\206\351\242\221\351\253\230\345\272\246\357\274\232", 0));
        leHeight->setText(QApplication::translate("CodecSetting", "480", 0));
        gbRate->setTitle(QApplication::translate("CodecSetting", "\347\240\201\347\216\207\346\216\247\345\210\266", 0));
        lbRcMethod->setText(QApplication::translate("CodecSetting", "\347\240\201\346\216\247\346\226\271\345\274\217\357\274\232", 0));
        lbQpConstant->setText(QApplication::translate("CodecSetting", "\345\233\272\345\256\232\351\207\217\345\214\226\345\200\274\357\274\232", 0));
        lbQpMax->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247\351\207\217\345\214\226\345\200\274\357\274\232", 0));
        lbQpMin->setText(QApplication::translate("CodecSetting", "\346\234\200\345\260\217\351\207\217\345\214\226\345\200\274\357\274\232", 0));
        lbQpStep->setText(QApplication::translate("CodecSetting", "\351\207\217\345\214\226\346\255\245\351\225\277\357\274\232", 0));
        lbRateMeans->setText(QApplication::translate("CodecSetting", "\345\271\263\345\235\207\347\240\201\347\216\207\357\274\232", 0));
        lbRateTol->setText(QApplication::translate("CodecSetting", "\347\240\201\347\216\207\345\201\217\345\267\256\357\274\232", 0));
        lbVbvRate->setText(QApplication::translate("CodecSetting", "VBV\347\240\201\347\216\207\357\274\232", 0));
        lbVbvBuf->setText(QApplication::translate("CodecSetting", "VBV\347\274\223\345\206\262\357\274\232", 0));
        lbVbvinit->setText(QApplication::translate("CodecSetting", "VBV\345\210\235\345\247\213\345\241\253\345\205\205\357\274\232", 0));
        lbRfConstant->setText(QApplication::translate("CodecSetting", "\345\233\272\345\256\232\350\264\250\351\207\217\345\200\274\357\274\232", 0));
        lbRfMax->setText(QApplication::translate("CodecSetting", "\346\234\200\345\244\247\350\264\250\351\207\217\345\200\274\357\274\232", 0));
        gbFilter->setTitle(QApplication::translate("CodecSetting", "\346\273\244\346\263\242\345\231\250", 0));
        lbDeblock->setText(QApplication::translate("CodecSetting", "\345\216\273\345\235\227\346\273\244\346\263\242\345\231\250\357\274\232", 0));
        lbAlpha->setText(QApplication::translate("CodecSetting", "alpha\345\216\273\345\235\227\357\274\232", 0));
        lbBeta->setText(QApplication::translate("CodecSetting", "Bate\345\216\273\345\235\227\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class CodecSetting: public Ui_CodecSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODECSETTING_H
