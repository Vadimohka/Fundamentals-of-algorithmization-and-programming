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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Floor2Number;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *outfloor;
    QPushButton *Floor3Button;
    QPushButton *Floor2Button;
    QPushButton *Floor1Button;
    QPushButton *outelevator;
    QPushButton *inelevator;
    QPushButton *onfloor;
    QPushButton *callElevator;
    QLabel *Hint;
    QLabel *Floor1Number;
    QLabel *Floor3Number;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1038, 618);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Floor2Number = new QLabel(centralwidget);
        Floor2Number->setObjectName("Floor2Number");
        Floor2Number->setGeometry(QRect(40, 160, 101, 131));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 450, 1021, 156));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        outfloor = new QPushButton(gridLayoutWidget);
        outfloor->setObjectName("outfloor");

        gridLayout->addWidget(outfloor, 1, 1, 1, 1);

        Floor3Button = new QPushButton(gridLayoutWidget);
        Floor3Button->setObjectName("Floor3Button");

        gridLayout->addWidget(Floor3Button, 0, 0, 1, 1);

        Floor2Button = new QPushButton(gridLayoutWidget);
        Floor2Button->setObjectName("Floor2Button");

        gridLayout->addWidget(Floor2Button, 1, 0, 1, 1);

        Floor1Button = new QPushButton(gridLayoutWidget);
        Floor1Button->setObjectName("Floor1Button");

        gridLayout->addWidget(Floor1Button, 3, 0, 1, 1);

        outelevator = new QPushButton(gridLayoutWidget);
        outelevator->setObjectName("outelevator");

        gridLayout->addWidget(outelevator, 1, 2, 1, 1);

        inelevator = new QPushButton(gridLayoutWidget);
        inelevator->setObjectName("inelevator");

        gridLayout->addWidget(inelevator, 0, 2, 1, 1);

        onfloor = new QPushButton(gridLayoutWidget);
        onfloor->setObjectName("onfloor");

        gridLayout->addWidget(onfloor, 0, 1, 1, 1);

        callElevator = new QPushButton(gridLayoutWidget);
        callElevator->setObjectName("callElevator");

        gridLayout->addWidget(callElevator, 3, 1, 1, 1);

        Hint = new QLabel(centralwidget);
        Hint->setObjectName("Hint");
        Hint->setGeometry(QRect(280, 20, 751, 401));
        Hint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Floor1Number = new QLabel(centralwidget);
        Floor1Number->setObjectName("Floor1Number");
        Floor1Number->setGeometry(QRect(40, 310, 101, 131));
        Floor3Number = new QLabel(centralwidget);
        Floor3Number->setObjectName("Floor3Number");
        Floor3Number->setGeometry(QRect(40, 0, 101, 131));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1038, 23));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Floor2Number->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        outfloor->setText(QCoreApplication::translate("MainWindow", "\320\243\320\271\321\202\320\270 \321\201 \321\215\321\202\320\260\320\266\320\260", nullptr));
        Floor3Button->setText(QCoreApplication::translate("MainWindow", "3 \321\215\321\202\320\260\320\266", nullptr));
        Floor2Button->setText(QCoreApplication::translate("MainWindow", "2 \321\215\321\202\320\260\320\266", nullptr));
        Floor1Button->setText(QCoreApplication::translate("MainWindow", "1 \321\215\321\202\320\260\320\266", nullptr));
        outelevator->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\271\321\202\320\270 \320\270\320\267 \320\273\320\270\321\204\321\202\320\260", nullptr));
        inelevator->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\271\321\202\320\270 \320\262 \320\273\320\270\321\204\321\202", nullptr));
        onfloor->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\271\321\202\320\270 \320\275\320\260 \321\215\321\202\320\260\320\266", nullptr));
        callElevator->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\267\320\262\320\260\321\202\321\214 \320\273\320\270\321\204\321\202", nullptr));
        Hint->setText(QString());
        Floor1Number->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        Floor3Number->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
