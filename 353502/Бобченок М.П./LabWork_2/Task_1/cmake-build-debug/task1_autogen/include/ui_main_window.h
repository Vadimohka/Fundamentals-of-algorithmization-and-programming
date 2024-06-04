/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QTableWidget *tableWidget;
    QSpinBox *day;
    QSpinBox *month;
    QSpinBox *year;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *addButton;
    QPushButton *birthdayButton;
    QLabel *bld;
    QLabel *bithday;
    QSpinBox *changeBox;
    QPushButton *changeButton;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2560, 1600);
        tableWidget = new QTableWidget(main_window);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(180, 130, 1205, 1000));
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(6);
        tableWidget->horizontalHeader()->setMinimumSectionSize(23);
        tableWidget->horizontalHeader()->setDefaultSectionSize(198);
        day = new QSpinBox(main_window);
        day->setObjectName(QString::fromUtf8("day"));
        day->setGeometry(QRect(60, 130, 80, 30));
        day->setMinimum(1);
        day->setMaximum(31);
        month = new QSpinBox(main_window);
        month->setObjectName(QString::fromUtf8("month"));
        month->setGeometry(QRect(60, 170, 80, 30));
        month->setMinimum(1);
        month->setMaximum(31);
        year = new QSpinBox(main_window);
        year->setObjectName(QString::fromUtf8("year"));
        year->setGeometry(QRect(60, 210, 80, 30));
        year->setMinimum(1);
        year->setMaximum(9999);
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 130, 31, 17));
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 170, 51, 17));
        label_3 = new QLabel(main_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 210, 41, 17));
        saveButton = new QPushButton(main_window);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(60, 510, 88, 25));
        loadButton = new QPushButton(main_window);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(60, 550, 88, 25));
        addButton = new QPushButton(main_window);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(60, 310, 88, 25));
        birthdayButton = new QPushButton(main_window);
        birthdayButton->setObjectName(QString::fromUtf8("birthdayButton"));
        birthdayButton->setGeometry(QRect(60, 350, 88, 25));
        bld = new QLabel(main_window);
        bld->setObjectName(QString::fromUtf8("bld"));
        bld->setGeometry(QRect(1410, 130, 66, 17));
        bithday = new QLabel(main_window);
        bithday->setObjectName(QString::fromUtf8("bithday"));
        bithday->setGeometry(QRect(1480, 130, 101, 17));
        changeBox = new QSpinBox(main_window);
        changeBox->setObjectName(QString::fromUtf8("changeBox"));
        changeBox->setGeometry(QRect(100, 430, 44, 26));
        changeBox->setMaximum(92);
        changeButton = new QPushButton(main_window);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));
        changeButton->setGeometry(QRect(60, 390, 88, 25));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("main_window", "DATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("main_window", "IS LEAP", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("main_window", "NEXT DAY", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("main_window", "DAY OF WEEK", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("main_window", "DAYS TO THE NEXT DATE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("main_window", "DAYS TO THE BIRTHDAY", nullptr));
        label->setText(QCoreApplication::translate("main_window", "day", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "month", nullptr));
        label_3->setText(QCoreApplication::translate("main_window", "year", nullptr));
        saveButton->setText(QCoreApplication::translate("main_window", "save", nullptr));
        loadButton->setText(QCoreApplication::translate("main_window", "load", nullptr));
        addButton->setText(QCoreApplication::translate("main_window", "add", nullptr));
        birthdayButton->setText(QCoreApplication::translate("main_window", "set birthday", nullptr));
        bld->setText(QCoreApplication::translate("main_window", "birthday - ", nullptr));
        bithday->setText(QString());
        changeButton->setText(QCoreApplication::translate("main_window", "change", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
