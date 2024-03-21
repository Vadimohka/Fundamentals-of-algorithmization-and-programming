/********************************************************************************
** Form generated from reading UI file 'squaredialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQUAREDIALOG_H
#define UI_SQUAREDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_SquareDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *SquareDialog)
    {
        if (SquareDialog->objectName().isEmpty())
            SquareDialog->setObjectName("SquareDialog");
        SquareDialog->resize(450, 162);
        buttonBox = new QDialogButtonBox(SquareDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(90, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(SquareDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 20, 351, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lineEdit = new QLineEdit(SquareDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(160, 60, 113, 25));
        label_2 = new QLabel(SquareDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 100, 221, 17));

        retranslateUi(SquareDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, SquareDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, SquareDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(SquareDialog);
    } // setupUi

    void retranslateUi(QDialog *SquareDialog)
    {
        SquareDialog->setWindowTitle(QCoreApplication::translate("SquareDialog", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        label->setText(QCoreApplication::translate("SquareDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\264\320\273\320\270\320\275\321\203 \321\201\321\202\320\276\321\200\320\276\320\275\321\213 \320\272\320\262\320\260\320\264\321\200\320\260\321\202\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("SquareDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 1000", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SquareDialog: public Ui_SquareDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQUAREDIALOG_H
