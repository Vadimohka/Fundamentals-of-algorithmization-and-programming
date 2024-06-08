/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeWidget *treeWidget;
    QSpinBox *keyInsert;
    QLineEdit *valueInsert;
    QPushButton *insertButton;
    QPushButton *removeButton;
    QLabel *label;
    QLabel *label_2;
    QPushButton *searchButton;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QPushButton *searchButton_2;
    QPushButton *searchButton_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 454);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeWidget = new QTreeWidget(centralwidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName("treeWidget");
        treeWidget->setGeometry(QRect(10, 60, 331, 311));
        keyInsert = new QSpinBox(centralwidget);
        keyInsert->setObjectName("keyInsert");
        keyInsert->setGeometry(QRect(530, 100, 81, 26));
        keyInsert->setMaximum(1000000000);
        valueInsert = new QLineEdit(centralwidget);
        valueInsert->setObjectName("valueInsert");
        valueInsert->setGeometry(QRect(402, 100, 121, 25));
        insertButton = new QPushButton(centralwidget);
        insertButton->setObjectName("insertButton");
        insertButton->setGeometry(QRect(660, 60, 88, 25));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(660, 100, 88, 25));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 80, 66, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 80, 66, 17));
        searchButton = new QPushButton(centralwidget);
        searchButton->setObjectName("searchButton");
        searchButton->setGeometry(QRect(660, 140, 88, 25));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(360, 310, 431, 25));
        lineEdit->setReadOnly(true);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(370, 290, 71, 17));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(405, 210, 241, 25));
        searchButton_2 = new QPushButton(centralwidget);
        searchButton_2->setObjectName("searchButton_2");
        searchButton_2->setGeometry(QRect(660, 210, 88, 25));
        searchButton_3 = new QPushButton(centralwidget);
        searchButton_3->setObjectName("searchButton_3");
        searchButton_3->setGeometry(QRect(440, 360, 261, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 30, 66, 17));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        insertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", nullptr));
        searchButton_2->setText(QCoreApplication::translate("MainWindow", "\321\201\320\276\320\262\320\265\321\200\321\210\320\270\321\202\321\214", nullptr));
        searchButton_3->setText(QCoreApplication::translate("MainWindow", "\320\277\320\276\320\273\321\203\321\207\320\270\321\202\321\214 \320\272\320\276\320\273-\320\262\320\276 \320\273\320\270\321\201\321\202\320\276\320\262 \320\264\320\265\321\200\320\265\320\262\320\260", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\321\200\320\265\320\262\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
