/********************************************************************************
** Form generated from reading UI file 'basa.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASA_H
#define UI_BASA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Basa
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Basa)
    {
        if (Basa->objectName().isEmpty())
            Basa->setObjectName("Basa");
        Basa->resize(1410, 1499);
        centralwidget = new QWidget(Basa);
        centralwidget->setObjectName("centralwidget");
        Basa->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Basa);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1410, 22));
        Basa->setMenuBar(menubar);
        statusbar = new QStatusBar(Basa);
        statusbar->setObjectName("statusbar");
        Basa->setStatusBar(statusbar);

        retranslateUi(Basa);

        QMetaObject::connectSlotsByName(Basa);
    } // setupUi

    void retranslateUi(QMainWindow *Basa)
    {
        Basa->setWindowTitle(QCoreApplication::translate("Basa", "Basa", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Basa: public Ui_Basa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASA_H
