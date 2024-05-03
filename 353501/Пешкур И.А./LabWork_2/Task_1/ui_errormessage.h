/********************************************************************************
** Form generated from reading UI file 'errormessage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORMESSAGE_H
#define UI_ERRORMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_errorMessage
{
public:
    QLabel *label;

    void setupUi(QDialog *errorMessage)
    {
        if (errorMessage->objectName().isEmpty())
            errorMessage->setObjectName(QString::fromUtf8("errorMessage"));
        errorMessage->resize(400, 300);
        label = new QLabel(errorMessage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 130, 66, 17));

        retranslateUi(errorMessage);

        QMetaObject::connectSlotsByName(errorMessage);
    } // setupUi

    void retranslateUi(QDialog *errorMessage)
    {
        errorMessage->setWindowTitle(QCoreApplication::translate("errorMessage", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("errorMessage", "gavno", nullptr));
    } // retranslateUi

};

namespace Ui {
    class errorMessage: public Ui_errorMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORMESSAGE_H
