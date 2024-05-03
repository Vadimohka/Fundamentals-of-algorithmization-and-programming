/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonBirth;
    QTableWidget *tableWidget;
    QPushButton *pushButtonPrevDay;
    QPushButton *pushButtonNextDay;
    QPushButton *pushButtonEnterValue;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QTextEdit *textEditBirth;
    QPushButton *pushButtonWriteDown;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1035, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonBirth = new QPushButton(centralwidget);
        pushButtonBirth->setObjectName(QString::fromUtf8("pushButtonBirth"));
        pushButtonBirth->setGeometry(QRect(650, 220, 251, 31));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 5)
            tableWidget->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 600, 561));
        pushButtonPrevDay = new QPushButton(centralwidget);
        pushButtonPrevDay->setObjectName(QString::fromUtf8("pushButtonPrevDay"));
        pushButtonPrevDay->setGeometry(QRect(770, 190, 131, 25));
        pushButtonNextDay = new QPushButton(centralwidget);
        pushButtonNextDay->setObjectName(QString::fromUtf8("pushButtonNextDay"));
        pushButtonNextDay->setGeometry(QRect(650, 190, 121, 25));
        pushButtonEnterValue = new QPushButton(centralwidget);
        pushButtonEnterValue->setObjectName(QString::fromUtf8("pushButtonEnterValue"));
        pushButtonEnterValue->setGeometry(QRect(620, 0, 231, 31));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(650, 350, 251, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(650, 310, 251, 31));
        textEditBirth = new QTextEdit(centralwidget);
        textEditBirth->setObjectName(QString::fromUtf8("textEditBirth"));
        textEditBirth->setGeometry(QRect(650, 260, 251, 31));
        pushButtonWriteDown = new QPushButton(centralwidget);
        pushButtonWriteDown->setObjectName(QString::fromUtf8("pushButtonWriteDown"));
        pushButtonWriteDown->setGeometry(QRect(620, 40, 231, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1035, 22));
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
        pushButtonBirth->setText(QCoreApplication::translate("MainWindow", "Set birthday day", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Month", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Year", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Days till birth", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Is Leap???", nullptr));
        pushButtonPrevDay->setText(QCoreApplication::translate("MainWindow", "Show prev day", nullptr));
        pushButtonNextDay->setText(QCoreApplication::translate("MainWindow", "Show next day", nullptr));
        pushButtonEnterValue->setText(QCoreApplication::translate("MainWindow", "Make path to file", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add date", nullptr));
        pushButtonWriteDown->setText(QCoreApplication::translate("MainWindow", "Write down to file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
