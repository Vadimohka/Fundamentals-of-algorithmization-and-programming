/********************************************************************************
** Form generated from reading UI file 'nichevo.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NICHEVO_H
#define UI_NICHEVO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Nichevo
{
public:
    QLabel *label;

    void setupUi(QDialog *Nichevo)
    {
        if (Nichevo->objectName().isEmpty())
            Nichevo->setObjectName(QString::fromUtf8("Nichevo"));
        Nichevo->resize(400, 300);
        label = new QLabel(Nichevo);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 130, 171, 17));

        retranslateUi(Nichevo);

        QMetaObject::connectSlotsByName(Nichevo);
    } // setupUi

    void retranslateUi(QDialog *Nichevo)
    {
        Nichevo->setWindowTitle(QCoreApplication::translate("Nichevo", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Nichevo", "Nichevo ne proizoshlo((", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Nichevo: public Ui_Nichevo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NICHEVO_H
