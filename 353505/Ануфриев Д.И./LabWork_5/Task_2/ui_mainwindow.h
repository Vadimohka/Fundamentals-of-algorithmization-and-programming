/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_str;
    QLabel *label;
    QPushButton *pushButton_pe;
    QPushButton *pushButton_equal;
    QLineEdit *lineEdit_pe;
    QLineEdit *lineEdit_equal;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_size;
    QLabel *label_eq;
    QLineEdit *lineEdit_str1;
    QLineEdit *lineEdit_str2;
    QLineEdit *lineEdit_ans;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton_memcpy;
    QPushButton *pushButton_memmove;
    QPushButton *pushButton_strncpy;
    QPushButton *pushButton_strcpy;
    QPushButton *pushButton_memcmp;
    QPushButton *pushButton_strncat;
    QPushButton *pushButton_strcat;
    QPushButton *pushButton_strcmp;
    QPushButton *pushButton_strncmp;
    QPushButton *strxfrm;
    QPushButton *pushButton_strcoll;
    QPushButton *pushButton_strtok;
    QPushButton *pushButton_strlen;
    QPushButton *pushButton_strmemset;
    QSpinBox *spinBox;
    QLabel *label_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lineEdit_str = new QLineEdit(centralwidget);
        lineEdit_str->setObjectName(QString::fromUtf8("lineEdit_str"));
        lineEdit_str->setGeometry(QRect(180, 10, 113, 21));
        lineEdit_str->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 10, 101, 16));
        pushButton_pe = new QPushButton(centralwidget);
        pushButton_pe->setObjectName(QString::fromUtf8("pushButton_pe"));
        pushButton_pe->setGeometry(QRect(340, 40, 80, 20));
        pushButton_equal = new QPushButton(centralwidget);
        pushButton_equal->setObjectName(QString::fromUtf8("pushButton_equal"));
        pushButton_equal->setGeometry(QRect(340, 70, 80, 20));
        lineEdit_pe = new QLineEdit(centralwidget);
        lineEdit_pe->setObjectName(QString::fromUtf8("lineEdit_pe"));
        lineEdit_pe->setGeometry(QRect(180, 40, 113, 21));
        lineEdit_equal = new QLineEdit(centralwidget);
        lineEdit_equal->setObjectName(QString::fromUtf8("lineEdit_equal"));
        lineEdit_equal->setGeometry(QRect(180, 70, 113, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 40, 121, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 70, 71, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 10, 54, 14));
        label_size = new QLabel(centralwidget);
        label_size->setObjectName(QString::fromUtf8("label_size"));
        label_size->setGeometry(QRect(470, 10, 54, 14));
        label_eq = new QLabel(centralwidget);
        label_eq->setObjectName(QString::fromUtf8("label_eq"));
        label_eq->setGeometry(QRect(470, 100, 54, 14));
        lineEdit_str1 = new QLineEdit(centralwidget);
        lineEdit_str1->setObjectName(QString::fromUtf8("lineEdit_str1"));
        lineEdit_str1->setGeometry(QRect(170, 230, 113, 21));
        lineEdit_str2 = new QLineEdit(centralwidget);
        lineEdit_str2->setObjectName(QString::fromUtf8("lineEdit_str2"));
        lineEdit_str2->setGeometry(QRect(170, 270, 113, 21));
        lineEdit_ans = new QLineEdit(centralwidget);
        lineEdit_ans->setObjectName(QString::fromUtf8("lineEdit_ans"));
        lineEdit_ans->setGeometry(QRect(170, 310, 113, 21));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 240, 54, 14));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 280, 121, 16));
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 320, 54, 14));
        pushButton_memcpy = new QPushButton(centralwidget);
        pushButton_memcpy->setObjectName(QString::fromUtf8("pushButton_memcpy"));
        pushButton_memcpy->setGeometry(QRect(300, 220, 80, 20));
        pushButton_memmove = new QPushButton(centralwidget);
        pushButton_memmove->setObjectName(QString::fromUtf8("pushButton_memmove"));
        pushButton_memmove->setGeometry(QRect(300, 250, 80, 20));
        pushButton_strncpy = new QPushButton(centralwidget);
        pushButton_strncpy->setObjectName(QString::fromUtf8("pushButton_strncpy"));
        pushButton_strncpy->setGeometry(QRect(300, 310, 80, 20));
        pushButton_strcpy = new QPushButton(centralwidget);
        pushButton_strcpy->setObjectName(QString::fromUtf8("pushButton_strcpy"));
        pushButton_strcpy->setGeometry(QRect(300, 280, 80, 20));
        pushButton_memcmp = new QPushButton(centralwidget);
        pushButton_memcmp->setObjectName(QString::fromUtf8("pushButton_memcmp"));
        pushButton_memcmp->setGeometry(QRect(300, 410, 80, 20));
        pushButton_strncat = new QPushButton(centralwidget);
        pushButton_strncat->setObjectName(QString::fromUtf8("pushButton_strncat"));
        pushButton_strncat->setGeometry(QRect(300, 380, 80, 20));
        pushButton_strcat = new QPushButton(centralwidget);
        pushButton_strcat->setObjectName(QString::fromUtf8("pushButton_strcat"));
        pushButton_strcat->setGeometry(QRect(300, 350, 80, 20));
        pushButton_strcmp = new QPushButton(centralwidget);
        pushButton_strcmp->setObjectName(QString::fromUtf8("pushButton_strcmp"));
        pushButton_strcmp->setGeometry(QRect(300, 440, 80, 20));
        pushButton_strncmp = new QPushButton(centralwidget);
        pushButton_strncmp->setObjectName(QString::fromUtf8("pushButton_strncmp"));
        pushButton_strncmp->setGeometry(QRect(450, 250, 80, 20));
        strxfrm = new QPushButton(centralwidget);
        strxfrm->setObjectName(QString::fromUtf8("strxfrm"));
        strxfrm->setGeometry(QRect(450, 280, 80, 20));
        pushButton_strcoll = new QPushButton(centralwidget);
        pushButton_strcoll->setObjectName(QString::fromUtf8("pushButton_strcoll"));
        pushButton_strcoll->setGeometry(QRect(450, 220, 80, 20));
        pushButton_strtok = new QPushButton(centralwidget);
        pushButton_strtok->setObjectName(QString::fromUtf8("pushButton_strtok"));
        pushButton_strtok->setGeometry(QRect(450, 310, 80, 20));
        pushButton_strlen = new QPushButton(centralwidget);
        pushButton_strlen->setObjectName(QString::fromUtf8("pushButton_strlen"));
        pushButton_strlen->setGeometry(QRect(450, 380, 80, 20));
        pushButton_strmemset = new QPushButton(centralwidget);
        pushButton_strmemset->setObjectName(QString::fromUtf8("pushButton_strmemset"));
        pushButton_strmemset->setGeometry(QRect(450, 350, 80, 20));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(160, 350, 42, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(63, 350, 71, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 19));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Your string:", nullptr));
        pushButton_pe->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        pushButton_equal->setText(QCoreApplication::translate("MainWindow", "Process", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Operator +=", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Operator =", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        label_size->setText(QString());
        label_eq->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "str1", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "str2(if need)", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ans", nullptr));
        pushButton_memcpy->setText(QCoreApplication::translate("MainWindow", "memcpy", nullptr));
        pushButton_memmove->setText(QCoreApplication::translate("MainWindow", "memmove", nullptr));
        pushButton_strncpy->setText(QCoreApplication::translate("MainWindow", "strncpy", nullptr));
        pushButton_strcpy->setText(QCoreApplication::translate("MainWindow", "strcpy", nullptr));
        pushButton_memcmp->setText(QCoreApplication::translate("MainWindow", "memcmp", nullptr));
        pushButton_strncat->setText(QCoreApplication::translate("MainWindow", "strncat", nullptr));
        pushButton_strcat->setText(QCoreApplication::translate("MainWindow", "strcat", nullptr));
        pushButton_strcmp->setText(QCoreApplication::translate("MainWindow", "strcmp", nullptr));
        pushButton_strncmp->setText(QCoreApplication::translate("MainWindow", "strncmp", nullptr));
        strxfrm->setText(QCoreApplication::translate("MainWindow", "strxfrm", nullptr));
        pushButton_strcoll->setText(QCoreApplication::translate("MainWindow", "strcoll", nullptr));
        pushButton_strtok->setText(QCoreApplication::translate("MainWindow", "strtok", nullptr));
        pushButton_strlen->setText(QCoreApplication::translate("MainWindow", "strlen", nullptr));
        pushButton_strmemset->setText(QCoreApplication::translate("MainWindow", "strmemset", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "n(if need)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
