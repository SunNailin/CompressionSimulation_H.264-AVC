/********************************************************************************
** Form generated from reading UI file 'networksetting.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NETWORKSETTING_H
#define UI_NETWORKSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_NetworkSetting
{
public:
    QGridLayout *gridLayout;
    QLabel *lbLostRate;
    QLineEdit *lePercent;
    QLabel *lbPercent;
    QSlider *hsLostRate;
    QLabel *lbBandWidth;
    QLineEdit *leBandWidth;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NetworkSetting)
    {
        if (NetworkSetting->objectName().isEmpty())
            NetworkSetting->setObjectName(QStringLiteral("NetworkSetting"));
        NetworkSetting->resize(320, 93);
        gridLayout = new QGridLayout(NetworkSetting);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lbLostRate = new QLabel(NetworkSetting);
        lbLostRate->setObjectName(QStringLiteral("lbLostRate"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbLostRate->sizePolicy().hasHeightForWidth());
        lbLostRate->setSizePolicy(sizePolicy);
        lbLostRate->setMinimumSize(QSize(40, 20));

        gridLayout->addWidget(lbLostRate, 0, 0, 1, 1);

        lePercent = new QLineEdit(NetworkSetting);
        lePercent->setObjectName(QStringLiteral("lePercent"));
        lePercent->setMaximumSize(QSize(30, 20));

        gridLayout->addWidget(lePercent, 0, 1, 1, 1);

        lbPercent = new QLabel(NetworkSetting);
        lbPercent->setObjectName(QStringLiteral("lbPercent"));
        lbPercent->setMaximumSize(QSize(20, 20));

        gridLayout->addWidget(lbPercent, 0, 2, 1, 1);

        hsLostRate = new QSlider(NetworkSetting);
        hsLostRate->setObjectName(QStringLiteral("hsLostRate"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(hsLostRate->sizePolicy().hasHeightForWidth());
        hsLostRate->setSizePolicy(sizePolicy1);
        hsLostRate->setMinimumSize(QSize(200, 20));
        hsLostRate->setMaximumSize(QSize(200, 20));
        hsLostRate->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(hsLostRate, 0, 3, 1, 1);

        lbBandWidth = new QLabel(NetworkSetting);
        lbBandWidth->setObjectName(QStringLiteral("lbBandWidth"));
        sizePolicy.setHeightForWidth(lbBandWidth->sizePolicy().hasHeightForWidth());
        lbBandWidth->setSizePolicy(sizePolicy);
        lbBandWidth->setMinimumSize(QSize(105, 20));

        gridLayout->addWidget(lbBandWidth, 1, 0, 1, 3);

        leBandWidth = new QLineEdit(NetworkSetting);
        leBandWidth->setObjectName(QStringLiteral("leBandWidth"));
        leBandWidth->setMinimumSize(QSize(200, 20));
        leBandWidth->setMaximumSize(QSize(200, 20));

        gridLayout->addWidget(leBandWidth, 1, 3, 1, 1);

        buttonBox = new QDialogButtonBox(NetworkSetting);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 3, 1, 1);


        retranslateUi(NetworkSetting);
        QObject::connect(buttonBox, SIGNAL(accepted()), NetworkSetting, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NetworkSetting, SLOT(reject()));

        QMetaObject::connectSlotsByName(NetworkSetting);
    } // setupUi

    void retranslateUi(QDialog *NetworkSetting)
    {
        NetworkSetting->setWindowTitle(QApplication::translate("NetworkSetting", "\347\275\221\347\273\234\350\256\276\347\275\256", 0));
        lbLostRate->setText(QApplication::translate("NetworkSetting", "\344\270\242\345\214\205\347\216\207\357\274\232", 0));
        lePercent->setText(QApplication::translate("NetworkSetting", "0", 0));
        lbPercent->setText(QApplication::translate("NetworkSetting", "%", 0));
        lbBandWidth->setText(QApplication::translate("NetworkSetting", "\347\275\221\347\273\234\345\270\246\345\256\275(kb/s)\357\274\232", 0));
        leBandWidth->setText(QApplication::translate("NetworkSetting", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class NetworkSetting: public Ui_NetworkSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NETWORKSETTING_H
