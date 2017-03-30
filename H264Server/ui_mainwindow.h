/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionStart_Device;
    QAction *actionStop_Device;
    QAction *actionCodec_settings;
    QAction *actionNetwork_settings;
    QAction *action_DeviceList;
    QAction *actionOpen_File;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuDevice;
    QMenu *menuDevice_List;
    QMenu *menuSettings;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionStart_Device = new QAction(MainWindow);
        actionStart_Device->setObjectName(QStringLiteral("actionStart_Device"));
        actionStop_Device = new QAction(MainWindow);
        actionStop_Device->setObjectName(QStringLiteral("actionStop_Device"));
        actionStop_Device->setEnabled(false);
        actionCodec_settings = new QAction(MainWindow);
        actionCodec_settings->setObjectName(QStringLiteral("actionCodec_settings"));
        actionNetwork_settings = new QAction(MainWindow);
        actionNetwork_settings->setObjectName(QStringLiteral("actionNetwork_settings"));
        action_DeviceList = new QAction(MainWindow);
        action_DeviceList->setObjectName(QStringLiteral("action_DeviceList"));
        actionOpen_File = new QAction(MainWindow);
        actionOpen_File->setObjectName(QStringLiteral("actionOpen_File"));
        actionOpen_File->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuDevice = new QMenu(menuBar);
        menuDevice->setObjectName(QStringLiteral("menuDevice"));
        menuDevice_List = new QMenu(menuDevice);
        menuDevice_List->setObjectName(QStringLiteral("menuDevice_List"));
        menuSettings = new QMenu(menuBar);
        menuSettings->setObjectName(QStringLiteral("menuSettings"));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menuDevice->menuAction());
        menuBar->addAction(menuSettings->menuAction());
        menuDevice->addAction(actionStart_Device);
        menuDevice->addAction(actionStop_Device);
        menuDevice->addSeparator();
        menuDevice->addAction(menuDevice_List->menuAction());
        menuSettings->addAction(actionCodec_settings);
        menuSettings->addAction(actionNetwork_settings);
        menu->addAction(actionOpen_File);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\256\236\346\227\266\350\247\206\351\242\221\346\234\215\345\212\241\345\231\250", 0));
        actionStart_Device->setText(QApplication::translate("MainWindow", "\345\220\257\345\212\250\350\256\276\345\244\207", 0));
        actionStop_Device->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242\350\256\276\345\244\207", 0));
        actionCodec_settings->setText(QApplication::translate("MainWindow", "\347\274\226\347\240\201\350\256\276\347\275\256", 0));
        actionNetwork_settings->setText(QApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", 0));
        action_DeviceList->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250", 0));
        actionOpen_File->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", 0));
        menuDevice->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207", 0));
        menuDevice_List->setTitle(QApplication::translate("MainWindow", "\350\256\276\345\244\207\345\210\227\350\241\250", 0));
        menuSettings->setTitle(QApplication::translate("MainWindow", "\350\256\276\347\275\256", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
