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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *fileOpen;
    QAction *fileSave;
    QWidget *centralwidget;
    QDateEdit *dateAddField;
    QLabel *dateEnterText;
    QTableWidget *datesTable;
    QPushButton *dateAddButton;
    QLineEdit *dateEditNumber;
    QLabel *dateEditRowTExt;
    QDateEdit *dateEditField;
    QPushButton *dateEditButton;
    QLabel *dateBirthdayText;
    QDateEdit *dateBirthdayField;
    QLabel *birthdayDaysCounterLabel;
    QLabel *fileText;
    QPushButton *fileOpen_2;
    QPushButton *fileSave_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(742, 319);
        fileOpen = new QAction(MainWindow);
        fileOpen->setObjectName("fileOpen");
        fileSave = new QAction(MainWindow);
        fileSave->setObjectName("fileSave");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        dateAddField = new QDateEdit(centralwidget);
        dateAddField->setObjectName("dateAddField");
        dateAddField->setGeometry(QRect(620, 30, 110, 22));
        dateAddField->setCalendarPopup(false);
        dateEnterText = new QLabel(centralwidget);
        dateEnterText->setObjectName("dateEnterText");
        dateEnterText->setGeometry(QRect(620, 10, 111, 16));
        datesTable = new QTableWidget(centralwidget);
        if (datesTable->columnCount() < 6)
            datesTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        datesTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        datesTable->setObjectName("datesTable");
        datesTable->setGeometry(QRect(10, 10, 601, 281));
        datesTable->setMaximumSize(QSize(601, 16777215));
        dateAddButton = new QPushButton(centralwidget);
        dateAddButton->setObjectName("dateAddButton");
        dateAddButton->setGeometry(QRect(620, 60, 111, 18));
        dateEditNumber = new QLineEdit(centralwidget);
        dateEditNumber->setObjectName("dateEditNumber");
        dateEditNumber->setGeometry(QRect(620, 100, 113, 20));
        dateEditRowTExt = new QLabel(centralwidget);
        dateEditRowTExt->setObjectName("dateEditRowTExt");
        dateEditRowTExt->setGeometry(QRect(620, 80, 111, 16));
        dateEditField = new QDateEdit(centralwidget);
        dateEditField->setObjectName("dateEditField");
        dateEditField->setGeometry(QRect(620, 130, 110, 22));
        dateEditButton = new QPushButton(centralwidget);
        dateEditButton->setObjectName("dateEditButton");
        dateEditButton->setGeometry(QRect(620, 160, 111, 18));
        dateBirthdayText = new QLabel(centralwidget);
        dateBirthdayText->setObjectName("dateBirthdayText");
        dateBirthdayText->setGeometry(QRect(620, 180, 111, 16));
        dateBirthdayField = new QDateEdit(centralwidget);
        dateBirthdayField->setObjectName("dateBirthdayField");
        dateBirthdayField->setGeometry(QRect(620, 200, 110, 22));
        dateBirthdayField->setCalendarPopup(false);
        birthdayDaysCounterLabel = new QLabel(centralwidget);
        birthdayDaysCounterLabel->setObjectName("birthdayDaysCounterLabel");
        birthdayDaysCounterLabel->setGeometry(QRect(620, 230, 111, 21));
        fileText = new QLabel(centralwidget);
        fileText->setObjectName("fileText");
        fileText->setGeometry(QRect(620, 250, 111, 16));
        fileOpen_2 = new QPushButton(centralwidget);
        fileOpen_2->setObjectName("fileOpen_2");
        fileOpen_2->setGeometry(QRect(620, 270, 51, 21));
        fileSave_2 = new QPushButton(centralwidget);
        fileSave_2->setObjectName("fileSave_2");
        fileSave_2->setGeometry(QRect(680, 270, 51, 21));
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
        fileOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        fileSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        dateAddField->setDisplayFormat(QCoreApplication::translate("MainWindow", "d/M/yyyy", nullptr));
        dateEnterText->setText(QCoreApplication::translate("MainWindow", "Enter Date(d/m/y):", nullptr));
        QTableWidgetItem *___qtablewidgetitem = datesTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = datesTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Next Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = datesTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Previous Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = datesTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Is Leap", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = datesTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Week Number", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = datesTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        dateAddButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        dateEditRowTExt->setText(QCoreApplication::translate("MainWindow", "Row number:", nullptr));
        dateEditField->setDisplayFormat(QCoreApplication::translate("MainWindow", "d/M/yyyy", nullptr));
        dateEditButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        dateBirthdayText->setText(QCoreApplication::translate("MainWindow", "Birthday date(d/m):", nullptr));
        dateBirthdayField->setDisplayFormat(QCoreApplication::translate("MainWindow", "d/M", nullptr));
        fileText->setText(QCoreApplication::translate("MainWindow", "File:", nullptr));
        fileOpen_2->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        fileSave_2->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
