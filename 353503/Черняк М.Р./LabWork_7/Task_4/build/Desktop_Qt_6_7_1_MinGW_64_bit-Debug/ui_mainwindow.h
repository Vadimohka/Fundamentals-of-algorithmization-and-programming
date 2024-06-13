/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *runs;
    QSpinBox *size;
    QLabel *label_2;
    QWidget *chartContainer;
    QCheckBox *total;
    QPushButton *calc;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1117, 894);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        runs = new QSpinBox(centralwidget);
        runs->setObjectName("runs");
        runs->setMinimum(1);
        runs->setMaximum(256);
        runs->setValue(64);

        gridLayout->addWidget(runs, 0, 3, 1, 1);

        size = new QSpinBox(centralwidget);
        size->setObjectName("size");
        size->setMinimum(16);
        size->setMaximum(4096);
        size->setValue(255);

        gridLayout->addWidget(size, 0, 1, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        chartContainer = new QWidget(centralwidget);
        chartContainer->setObjectName("chartContainer");

        gridLayout->addWidget(chartContainer, 2, 0, 1, 1);

        total = new QCheckBox(centralwidget);
        total->setObjectName("total");
        total->setLayoutDirection(Qt::RightToLeft);
        total->setChecked(true);
        total->setTristate(false);

        gridLayout->addWidget(total, 3, 3, 1, 1);

        calc = new QPushButton(centralwidget);
        calc->setObjectName("calc");
        QFont font;
        font.setPointSize(16);
        calc->setFont(font);

        gridLayout->addWidget(calc, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1117, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "Table Size:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Runs: ", nullptr));
        total->setText(QCoreApplication::translate("MainWindow", "Total Collisions", nullptr));
        calc->setText(QCoreApplication::translate("MainWindow", "Build chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
