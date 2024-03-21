/********************************************************************************
** Form generated from reading UI file 'trapezoiddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAPEZOIDDIALOG_H
#define UI_TRAPEZOIDDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TrapezoidDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QDialog *TrapezoidDialog)
    {
        if (TrapezoidDialog->objectName().isEmpty())
            TrapezoidDialog->setObjectName("TrapezoidDialog");
        TrapezoidDialog->resize(400, 383);
        buttonBox = new QDialogButtonBox(TrapezoidDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 330, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(TrapezoidDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 391, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lineEdit = new QLineEdit(TrapezoidDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 50, 113, 25));
        label_2 = new QLabel(TrapezoidDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 120, 391, 21));
        label_2->setFont(font);
        lineEdit_2 = new QLineEdit(TrapezoidDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(140, 160, 113, 25));
        label_3 = new QLabel(TrapezoidDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 230, 391, 21));
        label_3->setFont(font);
        lineEdit_3 = new QLineEdit(TrapezoidDialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(140, 270, 113, 25));
        label_4 = new QLabel(TrapezoidDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 80, 221, 17));
        label_5 = new QLabel(TrapezoidDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 190, 221, 17));
        label_6 = new QLabel(TrapezoidDialog);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(90, 300, 221, 17));

        retranslateUi(TrapezoidDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TrapezoidDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TrapezoidDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TrapezoidDialog);
    } // setupUi

    void retranslateUi(QDialog *TrapezoidDialog)
    {
        TrapezoidDialog->setWindowTitle(QCoreApplication::translate("TrapezoidDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("TrapezoidDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203 \320\262\320\265\321\200\321\205\320\275\320\265\320\263\320\276 \320\276\321\201\320\275\320\276\320\262\320\275\320\260\320\275\320\270\321\217: ", nullptr));
        label_2->setText(QCoreApplication::translate("TrapezoidDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203 \320\275\320\270\320\266\320\275\320\265\320\263\320\276 \320\276\321\201\320\275\320\276\320\262\320\275\320\260\320\275\320\270\321\217: ", nullptr));
        label_3->setText(QCoreApplication::translate("TrapezoidDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203 \320\262\321\213\321\201\320\276\321\202\321\213: ", nullptr));
        label_4->setText(QCoreApplication::translate("TrapezoidDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
        label_5->setText(QCoreApplication::translate("TrapezoidDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
        label_6->setText(QCoreApplication::translate("TrapezoidDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 850", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TrapezoidDialog: public Ui_TrapezoidDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAPEZOIDDIALOG_H
