/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *OpenButton;
    QLabel *label;
    QLabel *foldersCount;
    QLabel *label_2;
    QLabel *filesCount;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(200, 153);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        OpenButton = new QPushButton(centralwidget);
        OpenButton->setObjectName("OpenButton");
        OpenButton->setGeometry(QRect(60, 10, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 50, 91, 16));
        foldersCount = new QLabel(centralwidget);
        foldersCount->setObjectName("foldersCount");
        foldersCount->setGeometry(QRect(100, 50, 58, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 71, 16));
        filesCount = new QLabel(centralwidget);
        filesCount->setObjectName("filesCount");
        filesCount->setGeometry(QRect(90, 80, 58, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 200, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        OpenButton->setText(QCoreApplication::translate("MainWindow", "OPEN FILE", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Folders count:", nullptr));
        foldersCount->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "Files count:", nullptr));
        filesCount->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
