/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *genWareText;
    QLabel *genCodeText;
    QLineEdit *CodeField;
    QLabel *genNameText;
    QLineEdit *NameField;
    QLabel *genPriceText;
    QLineEdit *PriceField;
    QPushButton *AddButton;
    QPushButton *File1OpenButton;
    QListWidget *genList;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *NumberField;
    QLineEdit *CustomerField;
    QLineEdit *CodeField_1;
    QLabel *label_6;
    QLineEdit *AmountField;
    QListWidget *genList_2;
    QPushButton *File2OpenButton;
    QPushButton *AddButton_1;
    QLineEdit *DateField;
    QPushButton *SortByPriceButton;
    QPushButton *SortByNumberButton;
    QLabel *label_7;
    QLineEdit *NakladField;
    QPushButton *NakladButton;
    QListWidget *genList_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1173, 755);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        genWareText = new QLabel(centralwidget);
        genWareText->setObjectName("genWareText");
        genWareText->setGeometry(QRect(90, 10, 101, 31));
        QFont font;
        font.setPointSize(12);
        genWareText->setFont(font);
        genCodeText = new QLabel(centralwidget);
        genCodeText->setObjectName("genCodeText");
        genCodeText->setGeometry(QRect(10, 60, 91, 21));
        CodeField = new QLineEdit(centralwidget);
        CodeField->setObjectName("CodeField");
        CodeField->setGeometry(QRect(140, 60, 141, 21));
        genNameText = new QLabel(centralwidget);
        genNameText->setObjectName("genNameText");
        genNameText->setGeometry(QRect(10, 90, 111, 16));
        NameField = new QLineEdit(centralwidget);
        NameField->setObjectName("NameField");
        NameField->setGeometry(QRect(140, 90, 141, 21));
        genPriceText = new QLabel(centralwidget);
        genPriceText->setObjectName("genPriceText");
        genPriceText->setGeometry(QRect(10, 120, 71, 21));
        PriceField = new QLineEdit(centralwidget);
        PriceField->setObjectName("PriceField");
        PriceField->setGeometry(QRect(140, 120, 141, 21));
        AddButton = new QPushButton(centralwidget);
        AddButton->setObjectName("AddButton");
        AddButton->setGeometry(QRect(160, 160, 91, 21));
        File1OpenButton = new QPushButton(centralwidget);
        File1OpenButton->setObjectName("File1OpenButton");
        File1OpenButton->setGeometry(QRect(350, 310, 141, 21));
        genList = new QListWidget(centralwidget);
        genList->setObjectName("genList");
        genList->setGeometry(QRect(300, 20, 261, 281));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(740, 10, 81, 21));
        label->setFont(font);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(610, 50, 63, 20));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(610, 80, 63, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(610, 110, 81, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(610, 140, 101, 21));
        NumberField = new QLineEdit(centralwidget);
        NumberField->setObjectName("NumberField");
        NumberField->setGeometry(QRect(700, 50, 141, 21));
        CustomerField = new QLineEdit(centralwidget);
        CustomerField->setObjectName("CustomerField");
        CustomerField->setGeometry(QRect(700, 110, 141, 21));
        CodeField_1 = new QLineEdit(centralwidget);
        CodeField_1->setObjectName("CodeField_1");
        CodeField_1->setGeometry(QRect(700, 140, 141, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(610, 170, 91, 21));
        AmountField = new QLineEdit(centralwidget);
        AmountField->setObjectName("AmountField");
        AmountField->setGeometry(QRect(700, 170, 141, 21));
        genList_2 = new QListWidget(centralwidget);
        genList_2->setObjectName("genList_2");
        genList_2->setGeometry(QRect(870, 20, 261, 281));
        File2OpenButton = new QPushButton(centralwidget);
        File2OpenButton->setObjectName("File2OpenButton");
        File2OpenButton->setGeometry(QRect(940, 310, 111, 21));
        AddButton_1 = new QPushButton(centralwidget);
        AddButton_1->setObjectName("AddButton_1");
        AddButton_1->setGeometry(QRect(690, 210, 83, 29));
        DateField = new QLineEdit(centralwidget);
        DateField->setObjectName("DateField");
        DateField->setGeometry(QRect(700, 80, 141, 21));
        SortByPriceButton = new QPushButton(centralwidget);
        SortByPriceButton->setObjectName("SortByPriceButton");
        SortByPriceButton->setGeometry(QRect(20, 260, 261, 41));
        SortByNumberButton = new QPushButton(centralwidget);
        SortByNumberButton->setObjectName("SortByNumberButton");
        SortByNumberButton->setGeometry(QRect(610, 260, 251, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 460, 361, 31));
        NakladField = new QLineEdit(centralwidget);
        NakladField->setObjectName("NakladField");
        NakladField->setGeometry(QRect(40, 490, 113, 28));
        NakladButton = new QPushButton(centralwidget);
        NakladButton->setObjectName("NakladButton");
        NakladButton->setGeometry(QRect(40, 540, 191, 31));
        genList_3 = new QListWidget(centralwidget);
        genList_3->setObjectName("genList_3");
        genList_3->setGeometry(QRect(450, 340, 521, 381));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        genWareText->setText(QCoreApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\321\213:", nullptr));
        genCodeText->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 \321\202\320\276\320\262\320\260\321\200\320\260:", nullptr));
        genNameText->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", nullptr));
        genPriceText->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260:", nullptr));
        AddButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        File1OpenButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\321\213:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\321\207\320\270\320\272:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\264 \321\202\320\276\320\262\320\260\321\200\320\260:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        File2OpenButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        AddButton_1->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        SortByPriceButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\276\320\262\320\260\321\200\321\213 \320\277\320\276 \321\206\320\265\320\275\320\265", nullptr));
        SortByNumberButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\267\320\260\320\272\320\260\320\267\321\213 \320\277\320\276 \320\275\320\276\320\274\320\265\321\200\321\203", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260 \320\264\320\273\321\217 \321\201\320\276\321\201\321\202\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \320\275\320\260\320\272\320\273\320\260\320\264\320\275\320\276\320\271:", nullptr));
        NakladButton->setText(QCoreApplication::translate("MainWindow", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\275\320\260\320\272\320\273\320\260\320\264\320\275\321\203\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
