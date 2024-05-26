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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameInp;
    QLabel *label_2;
    QSpinBox *ageInp;
    QLabel *label_3;
    QDoubleSpinBox *bragsPerDayInp;
    QLabel *label_4;
    QLineEdit *creditRatingInp;
    QLabel *label_5;
    QCheckBox *evilInp;
    QLabel *label_6;
    QDoubleSpinBox *networth0Inp;
    QLabel *label_7;
    QDoubleSpinBox *networth1Inp;
    QLabel *label_8;
    QDoubleSpinBox *networth2Inp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(442, 332);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameInp = new QLineEdit(centralwidget);
        nameInp->setObjectName("nameInp");

        formLayout->setWidget(0, QFormLayout::FieldRole, nameInp);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        ageInp = new QSpinBox(centralwidget);
        ageInp->setObjectName("ageInp");

        formLayout->setWidget(1, QFormLayout::FieldRole, ageInp);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        bragsPerDayInp = new QDoubleSpinBox(centralwidget);
        bragsPerDayInp->setObjectName("bragsPerDayInp");

        formLayout->setWidget(2, QFormLayout::FieldRole, bragsPerDayInp);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        creditRatingInp = new QLineEdit(centralwidget);
        creditRatingInp->setObjectName("creditRatingInp");

        formLayout->setWidget(3, QFormLayout::FieldRole, creditRatingInp);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        evilInp = new QCheckBox(centralwidget);
        evilInp->setObjectName("evilInp");

        formLayout->setWidget(4, QFormLayout::FieldRole, evilInp);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        networth0Inp = new QDoubleSpinBox(centralwidget);
        networth0Inp->setObjectName("networth0Inp");
        networth0Inp->setMinimum(1.000000000000000);
        networth0Inp->setMaximum(1000000.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, networth0Inp);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        networth1Inp = new QDoubleSpinBox(centralwidget);
        networth1Inp->setObjectName("networth1Inp");
        networth1Inp->setMinimum(1.000000000000000);
        networth1Inp->setMaximum(1000000.000000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, networth1Inp);

        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        networth2Inp = new QDoubleSpinBox(centralwidget);
        networth2Inp->setObjectName("networth2Inp");
        networth2Inp->setMinimum(1.000000000000000);
        networth2Inp->setMaximum(1000000.000000000000000);

        formLayout->setWidget(7, QFormLayout::FieldRole, networth2Inp);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 442, 22));
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
        label->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Age", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Brags Per Day", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Credit Rating", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "is Evil", nullptr));
        evilInp->setText(QString());
        label_6->setText(QCoreApplication::translate("MainWindow", "Pre Last Year Net Worth (millions)", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Last Year Net Worth (millions)", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "This Year Net Worth (millions)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
