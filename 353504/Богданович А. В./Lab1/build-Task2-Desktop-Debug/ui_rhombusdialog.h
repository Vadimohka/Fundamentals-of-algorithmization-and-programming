/********************************************************************************
** Form generated from reading UI file 'rhombusdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RHOMBUSDIALOG_H
#define UI_RHOMBUSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_RhombusDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *RhombusDialog)
    {
        if (RhombusDialog->objectName().isEmpty())
            RhombusDialog->setObjectName("RhombusDialog");
        RhombusDialog->resize(470, 280);
        buttonBox = new QDialogButtonBox(RhombusDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RhombusDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 461, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(RhombusDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 140, 461, 21));
        label_2->setFont(font);
        lineEdit = new QLineEdit(RhombusDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(170, 60, 113, 25));
        lineEdit_2 = new QLineEdit(RhombusDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(170, 170, 113, 25));
        label_3 = new QLabel(RhombusDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 90, 231, 17));
        label_4 = new QLabel(RhombusDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(110, 200, 231, 17));

        retranslateUi(RhombusDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RhombusDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RhombusDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RhombusDialog);
    } // setupUi

    void retranslateUi(QDialog *RhombusDialog)
    {
        RhombusDialog->setWindowTitle(QCoreApplication::translate("RhombusDialog", "\320\240\320\276\320\274\320\261", nullptr));
        label->setText(QCoreApplication::translate("RhombusDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\263\320\276\321\200\320\270\320\267\320\276\320\275\320\260\321\202\320\273\321\214\320\275\320\276\320\271 \320\264\320\270\320\260\320\263\320\276\320\275\320\260\320\273\320\270: ", nullptr));
        label_2->setText(QCoreApplication::translate("RhombusDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \320\262\320\265\321\200\321\202\320\270\320\272\320\260\320\273\321\214\320\275\320\276\320\271 \320\264\320\270\320\260\320\263\320\276\320\275\320\260\320\273\320\270: ", nullptr));
        label_3->setText(QCoreApplication::translate("RhombusDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
        label_4->setText(QCoreApplication::translate("RhombusDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RhombusDialog: public Ui_RhombusDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RHOMBUSDIALOG_H
