/********************************************************************************
** Form generated from reading UI file 'errormenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORMENU_H
#define UI_ERRORMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ErrorMenu
{
public:
    QLabel *label;

    void setupUi(QDialog *ErrorMenu)
    {
        if (ErrorMenu->objectName().isEmpty())
            ErrorMenu->setObjectName(QString::fromUtf8("ErrorMenu"));
        ErrorMenu->resize(400, 300);
        label = new QLabel(ErrorMenu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 120, 66, 17));

        retranslateUi(ErrorMenu);

        QMetaObject::connectSlotsByName(ErrorMenu);
    } // setupUi

    void retranslateUi(QDialog *ErrorMenu)
    {
        ErrorMenu->setWindowTitle(QCoreApplication::translate("ErrorMenu", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("ErrorMenu", "Gavno", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorMenu: public Ui_ErrorMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORMENU_H
