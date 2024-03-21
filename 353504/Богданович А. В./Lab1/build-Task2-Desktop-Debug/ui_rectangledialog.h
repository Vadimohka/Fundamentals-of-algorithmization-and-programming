/********************************************************************************
** Form generated from reading UI file 'rectangledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLEDIALOG_H
#define UI_RECTANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_RectangleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *RectangleDialog)
    {
        if (RectangleDialog->objectName().isEmpty())
            RectangleDialog->setObjectName("RectangleDialog");
        RectangleDialog->resize(400, 194);
        buttonBox = new QDialogButtonBox(RectangleDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 150, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RectangleDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 20, 181, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(RectangleDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 90, 181, 21));
        label_2->setFont(font);
        lineEdit = new QLineEdit(RectangleDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(240, 20, 113, 25));
        lineEdit_2 = new QLineEdit(RectangleDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(240, 90, 113, 25));
        label_3 = new QLabel(RectangleDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(160, 50, 231, 17));
        label_4 = new QLabel(RectangleDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(160, 120, 231, 17));

        retranslateUi(RectangleDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RectangleDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RectangleDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RectangleDialog);
    } // setupUi

    void retranslateUi(QDialog *RectangleDialog)
    {
        RectangleDialog->setWindowTitle(QCoreApplication::translate("RectangleDialog", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        label->setText(QCoreApplication::translate("RectangleDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203: ", nullptr));
        label_2->setText(QCoreApplication::translate("RectangleDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\210\320\270\321\200\320\270\320\275\321\203: ", nullptr));
        label_3->setText(QCoreApplication::translate("RectangleDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
        label_4->setText(QCoreApplication::translate("RectangleDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 850", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RectangleDialog: public Ui_RectangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLEDIALOG_H
