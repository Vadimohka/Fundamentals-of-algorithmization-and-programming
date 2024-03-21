/********************************************************************************
** Form generated from reading UI file 'circledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLEDIALOG_H
#define UI_CIRCLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CircleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QCheckBox *checkBox;
    QLabel *label_2;

    void setupUi(QDialog *CircleDialog)
    {
        if (CircleDialog->objectName().isEmpty())
            CircleDialog->setObjectName("CircleDialog");
        CircleDialog->resize(470, 185);
        buttonBox = new QDialogButtonBox(CircleDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(110, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(CircleDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 311, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lineEdit = new QLineEdit(CircleDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(330, 30, 113, 25));
        checkBox = new QCheckBox(CircleDialog);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(20, 80, 171, 23));
        checkBox->setFont(font);
        label_2 = new QLabel(CircleDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 60, 211, 17));

        retranslateUi(CircleDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, CircleDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, CircleDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(CircleDialog);
    } // setupUi

    void retranslateUi(QDialog *CircleDialog)
    {
        CircleDialog->setWindowTitle(QCoreApplication::translate("CircleDialog", "\320\232\321\200\321\203\320\263", nullptr));
        label->setText(QCoreApplication::translate("CircleDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\264\320\270\321\203\321\201 \320\272\321\200\321\203\320\263\320\260:", nullptr));
        checkBox->setText(QCoreApplication::translate("CircleDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\276\321\201\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("CircleDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 850", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CircleDialog: public Ui_CircleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLEDIALOG_H
