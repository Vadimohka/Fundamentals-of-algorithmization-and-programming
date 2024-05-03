/********************************************************************************
** Form generated from reading UI file 'ura.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URA_H
#define UI_URA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Ura
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *Ura)
    {
        if (Ura->objectName().isEmpty())
            Ura->setObjectName(QString::fromUtf8("Ura"));
        Ura->resize(400, 300);
        label = new QLabel(Ura);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 80, 191, 17));
        label_2 = new QLabel(Ura);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 90, 101, 17));

        retranslateUi(Ura);

        QMetaObject::connectSlotsByName(Ura);
    } // setupUi

    void retranslateUi(QDialog *Ura)
    {
        Ura->setWindowTitle(QCoreApplication::translate("Ura", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Ura", "Vse zapisalos v file \"Order\"!!!", nullptr));
        label_2->setText(QCoreApplication::translate("Ura", "VSe zapisano v", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ura: public Ui_Ura {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URA_H
