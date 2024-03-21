/********************************************************************************
** Form generated from reading UI file 'triangledialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIANGLEDIALOG_H
#define UI_TRIANGLEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_TriangleDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;

    void setupUi(QDialog *TriangleDialog)
    {
        if (TriangleDialog->objectName().isEmpty())
            TriangleDialog->setObjectName("TriangleDialog");
        TriangleDialog->resize(550, 133);
        buttonBox = new QDialogButtonBox(TriangleDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(180, 80, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(TriangleDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 421, 31));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        lineEdit = new QLineEdit(TriangleDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(410, 35, 113, 25));
        label_2 = new QLabel(TriangleDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 80, 201, 17));

        retranslateUi(TriangleDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, TriangleDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, TriangleDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(TriangleDialog);
    } // setupUi

    void retranslateUi(QDialog *TriangleDialog)
    {
        TriangleDialog->setWindowTitle(QCoreApplication::translate("TriangleDialog", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        label->setText(QCoreApplication::translate("TriangleDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\200\320\260\320\267\320\274\320\265\321\200 \321\201\321\202\320\276\321\200\320\276\320\275\321\213 \321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272\320\260:", nullptr));
        label_2->setText(QCoreApplication::translate("TriangleDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\200\320\260\320\267\320\274\320\265\321\200 - 750", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TriangleDialog: public Ui_TriangleDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIANGLEDIALOG_H
