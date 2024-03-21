/********************************************************************************
** Form generated from reading UI file 'stardialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARDIALOG_H
#define UI_STARDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StarDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QLabel *label_4;
    QLabel *label_5;

    void setupUi(QDialog *StarDialog)
    {
        if (StarDialog->objectName().isEmpty())
            StarDialog->setObjectName("StarDialog");
        StarDialog->resize(400, 430);
        buttonBox = new QDialogButtonBox(StarDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 360, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(StarDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 20, 251, 21));
        QFont font;
        font.setPointSize(16);
        label->setFont(font);
        label_2 = new QLabel(StarDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 120, 251, 21));
        label_2->setFont(font);
        lineEdit = new QLineEdit(StarDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(130, 60, 113, 25));
        lineEdit_2 = new QLineEdit(StarDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(130, 160, 113, 25));
        label_3 = new QLabel(StarDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 220, 221, 21));
        label_3->setFont(font);
        layoutWidget = new QWidget(StarDialog);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(170, 250, 37, 86));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(layoutWidget);
        radioButton->setObjectName("radioButton");
        QFont font1;
        font1.setPointSize(12);
        radioButton->setFont(font1);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(layoutWidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setFont(font1);

        verticalLayout->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(layoutWidget);
        radioButton_3->setObjectName("radioButton_3");
        radioButton_3->setFont(font1);

        verticalLayout->addWidget(radioButton_3);

        label_4 = new QLabel(StarDialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(90, 90, 211, 17));
        label_5 = new QLabel(StarDialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(90, 190, 211, 17));

        retranslateUi(StarDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, StarDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, StarDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(StarDialog);
    } // setupUi

    void retranslateUi(QDialog *StarDialog)
    {
        StarDialog->setWindowTitle(QCoreApplication::translate("StarDialog", "\320\227\320\262\320\265\320\267\320\264\320\260", nullptr));
        label->setText(QCoreApplication::translate("StarDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\262\321\213\320\271 \321\200\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_2->setText(QCoreApplication::translate("StarDialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\262\321\202\320\276\321\200\320\276\320\271 \321\200\320\260\320\264\320\270\321\203\321\201:", nullptr));
        label_3->setText(QCoreApplication::translate("StarDialog", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\276\320\275\321\206\320\276\320\262:", nullptr));
        radioButton->setText(QCoreApplication::translate("StarDialog", "5", nullptr));
        radioButton_2->setText(QCoreApplication::translate("StarDialog", "6", nullptr));
        radioButton_3->setText(QCoreApplication::translate("StarDialog", "8", nullptr));
        label_4->setText(QCoreApplication::translate("StarDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\275\320\270\320\265 - 500", nullptr));
        label_5->setText(QCoreApplication::translate("StarDialog", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\267\320\275\320\260\321\207\320\275\320\270\320\265 - 500", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StarDialog: public Ui_StarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARDIALOG_H
