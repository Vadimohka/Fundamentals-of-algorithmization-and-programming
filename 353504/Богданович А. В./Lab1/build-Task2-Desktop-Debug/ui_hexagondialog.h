/********************************************************************************
** Form generated from reading UI file 'hexagondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HEXAGONDIALOG_H
#define UI_HEXAGONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_HexagonDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *HexagonDialog)
    {
        if (HexagonDialog->objectName().isEmpty())
            HexagonDialog->setObjectName("HexagonDialog");
        HexagonDialog->resize(400, 175);
        buttonBox = new QDialogButtonBox(HexagonDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 130, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(HexagonDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 20, 181, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lineEdit = new QLineEdit(HexagonDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(140, 60, 113, 25));
        label_2 = new QLabel(HexagonDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 90, 221, 17));

        retranslateUi(HexagonDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, HexagonDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, HexagonDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(HexagonDialog);
    } // setupUi

    void retranslateUi(QDialog *HexagonDialog)
    {
        HexagonDialog->setWindowTitle(QCoreApplication::translate("HexagonDialog", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        label->setText(QCoreApplication::translate("HexagonDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\264\320\270\321\203\321\201: ", nullptr));
        label_2->setText(QCoreApplication::translate("HexagonDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 - 500", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HexagonDialog: public Ui_HexagonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HEXAGONDIALOG_H
