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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBoxFood1;
    QSpinBox *spinBoxTable;
    QLabel *label_3;
    QSpinBox *spinBoxAmmount1;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QComboBox *comboBoxOrder;
    QComboBox *comboBoxFood2;
    QSpinBox *spinBoxAmmount2;
    QPushButton *pushButton_2;
    QPushButton *pushButtonRead;
    QPushButton *pushButton_4;
    QPushButton *pushButtonSortByPriceUp;
    QPushButton *pushButtonSortByPriceDown;
    QPushButton *pushButtonDeleteOrder;
    QComboBox *comboBoxOrder2;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *labelMostPopularDish;
    QPushButton *pushButtonWrite;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1276, 686);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 3)
            tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 661, 671));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(710, 310, 151, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(710, 340, 111, 21));
        comboBoxFood1 = new QComboBox(centralwidget);
        comboBoxFood1->setObjectName(QString::fromUtf8("comboBoxFood1"));
        comboBoxFood1->setGeometry(QRect(820, 340, 101, 25));
        spinBoxTable = new QSpinBox(centralwidget);
        spinBoxTable->setObjectName(QString::fromUtf8("spinBoxTable"));
        spinBoxTable->setGeometry(QRect(820, 310, 101, 26));
        spinBoxTable->setMinimum(1);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(710, 380, 81, 17));
        spinBoxAmmount1 = new QSpinBox(centralwidget);
        spinBoxAmmount1->setObjectName(QString::fromUtf8("spinBoxAmmount1"));
        spinBoxAmmount1->setGeometry(QRect(820, 370, 101, 26));
        spinBoxAmmount1->setMinimum(1);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(710, 410, 211, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(710, 500, 111, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(710, 470, 151, 17));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(710, 530, 81, 17));
        comboBoxOrder = new QComboBox(centralwidget);
        comboBoxOrder->setObjectName(QString::fromUtf8("comboBoxOrder"));
        comboBoxOrder->setGeometry(QRect(820, 470, 101, 25));
        comboBoxFood2 = new QComboBox(centralwidget);
        comboBoxFood2->setObjectName(QString::fromUtf8("comboBoxFood2"));
        comboBoxFood2->setGeometry(QRect(820, 500, 101, 25));
        spinBoxAmmount2 = new QSpinBox(centralwidget);
        spinBoxAmmount2->setObjectName(QString::fromUtf8("spinBoxAmmount2"));
        spinBoxAmmount2->setGeometry(QRect(820, 530, 101, 26));
        spinBoxAmmount2->setMinimum(1);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(710, 570, 211, 41));
        pushButtonRead = new QPushButton(centralwidget);
        pushButtonRead->setObjectName(QString::fromUtf8("pushButtonRead"));
        pushButtonRead->setGeometry(QRect(710, 10, 211, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(710, 60, 211, 41));
        pushButtonSortByPriceUp = new QPushButton(centralwidget);
        pushButtonSortByPriceUp->setObjectName(QString::fromUtf8("pushButtonSortByPriceUp"));
        pushButtonSortByPriceUp->setGeometry(QRect(940, 310, 181, 25));
        pushButtonSortByPriceDown = new QPushButton(centralwidget);
        pushButtonSortByPriceDown->setObjectName(QString::fromUtf8("pushButtonSortByPriceDown"));
        pushButtonSortByPriceDown->setGeometry(QRect(940, 340, 181, 25));
        pushButtonDeleteOrder = new QPushButton(centralwidget);
        pushButtonDeleteOrder->setObjectName(QString::fromUtf8("pushButtonDeleteOrder"));
        pushButtonDeleteOrder->setGeometry(QRect(950, 570, 210, 41));
        comboBoxOrder2 = new QComboBox(centralwidget);
        comboBoxOrder2->setObjectName(QString::fromUtf8("comboBoxOrder2"));
        comboBoxOrder2->setGeometry(QRect(1060, 530, 101, 25));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(950, 530, 151, 17));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(940, 370, 141, 17));
        labelMostPopularDish = new QLabel(centralwidget);
        labelMostPopularDish->setObjectName(QString::fromUtf8("labelMostPopularDish"));
        labelMostPopularDish->setGeometry(QRect(1070, 370, 66, 17));
        pushButtonWrite = new QPushButton(centralwidget);
        pushButtonWrite->setObjectName(QString::fromUtf8("pushButtonWrite"));
        pushButtonWrite->setGeometry(QRect(930, 10, 211, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1276, 22));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Table", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Food", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Table number", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Type of food", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Ammount", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Add order", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Type of food", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Order number", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Ammount", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Add new food to order", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("MainWindow", "Choose file", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Show Menu", nullptr));
        pushButtonSortByPriceUp->setText(QCoreApplication::translate("MainWindow", "Sort by total price( up )", nullptr));
        pushButtonSortByPriceDown->setText(QCoreApplication::translate("MainWindow", "Sort by total price( down )", nullptr));
        pushButtonDeleteOrder->setText(QCoreApplication::translate("MainWindow", "Delete order", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Order number", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Most popular dish:", nullptr));
        labelMostPopularDish->setText(QString());
        pushButtonWrite->setText(QCoreApplication::translate("MainWindow", "Write down to file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
