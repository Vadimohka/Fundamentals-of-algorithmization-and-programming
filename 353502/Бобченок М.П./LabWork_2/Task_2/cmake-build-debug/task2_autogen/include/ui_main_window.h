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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QTableWidget *tableWidget;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QPushButton *addButton;
    QSpinBox *numOfStudent;
    QPushButton *changeButton;
    QLabel *label;
    QLineEdit *fio;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *group;
    QLineEdit *speciality;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *math;
    QLineEdit *programming;
    QLineEdit *philosophi;
    QPushButton *findStudent;
    QPushButton *showBadStudent;
    QPushButton *gradeSortButton;
    QPushButton *groupSortButton;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2560, 1600);
        tableWidget = new QTableWidget(main_window);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(430, 130, 1401, 1000));
        tableWidget->setShowGrid(true);
        tableWidget->setRowCount(0);
        tableWidget->setColumnCount(7);
        tableWidget->horizontalHeader()->setMinimumSectionSize(23);
        tableWidget->horizontalHeader()->setDefaultSectionSize(198);
        saveButton = new QPushButton(main_window);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(30, 840, 88, 25));
        loadButton = new QPushButton(main_window);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(140, 840, 88, 25));
        addButton = new QPushButton(main_window);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(30, 410, 88, 25));
        numOfStudent = new QSpinBox(main_window);
        numOfStudent->setObjectName(QString::fromUtf8("numOfStudent"));
        numOfStudent->setGeometry(QRect(140, 450, 44, 26));
        numOfStudent->setMaximum(92);
        changeButton = new QPushButton(main_window);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));
        changeButton->setGeometry(QRect(30, 450, 88, 25));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 140, 111, 17));
        fio = new QLineEdit(main_window);
        fio->setObjectName(QString::fromUtf8("fio"));
        fio->setGeometry(QRect(180, 140, 221, 25));
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 170, 111, 17));
        label_3 = new QLabel(main_window);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 200, 111, 17));
        group = new QLineEdit(main_window);
        group->setObjectName(QString::fromUtf8("group"));
        group->setGeometry(QRect(180, 170, 221, 25));
        speciality = new QLineEdit(main_window);
        speciality->setObjectName(QString::fromUtf8("speciality"));
        speciality->setGeometry(QRect(180, 200, 221, 25));
        label_4 = new QLabel(main_window);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 250, 61, 17));
        label_5 = new QLabel(main_window);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(30, 290, 141, 17));
        label_6 = new QLabel(main_window);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(30, 320, 141, 17));
        label_7 = new QLabel(main_window);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(30, 350, 141, 17));
        math = new QLineEdit(main_window);
        math->setObjectName(QString::fromUtf8("math"));
        math->setGeometry(QRect(180, 290, 221, 25));
        programming = new QLineEdit(main_window);
        programming->setObjectName(QString::fromUtf8("programming"));
        programming->setGeometry(QRect(180, 320, 221, 25));
        philosophi = new QLineEdit(main_window);
        philosophi->setObjectName(QString::fromUtf8("philosophi"));
        philosophi->setGeometry(QRect(180, 350, 221, 25));
        findStudent = new QPushButton(main_window);
        findStudent->setObjectName(QString::fromUtf8("findStudent"));
        findStudent->setGeometry(QRect(30, 560, 131, 25));
        showBadStudent = new QPushButton(main_window);
        showBadStudent->setObjectName(QString::fromUtf8("showBadStudent"));
        showBadStudent->setGeometry(QRect(30, 610, 131, 25));
        gradeSortButton = new QPushButton(main_window);
        gradeSortButton->setObjectName(QString::fromUtf8("gradeSortButton"));
        gradeSortButton->setGeometry(QRect(30, 650, 131, 25));
        groupSortButton = new QPushButton(main_window);
        groupSortButton->setObjectName(QString::fromUtf8("groupSortButton"));
        groupSortButton->setGeometry(QRect(30, 690, 131, 25));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("main_window", "\320\244\320\230\320\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("main_window", "\320\241\320\237\320\225\320\246\320\230\320\220\320\233\320\254\320\235\320\236\320\241\320\242\320\254", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("main_window", "\320\223\320\240\320\243\320\237\320\237\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("main_window", "\320\241\320\240\320\225\320\224\320\235\320\257\320\257 \320\236\320\246\320\225\320\235\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("main_window", "\320\234\320\220\320\242\320\225\320\234\320\220\320\242\320\230\320\232\320\220", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("main_window", "\320\237\320\240\320\236\320\223\320\240\320\220\320\234\320\234\320\230\320\240\320\236\320\222\320\220\320\235\320\230\320\225", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("main_window", "\320\244\320\230\320\233\320\236\320\241\320\236\320\244\320\230\320\257", nullptr));
        saveButton->setText(QCoreApplication::translate("main_window", "save", nullptr));
        loadButton->setText(QCoreApplication::translate("main_window", "load", nullptr));
        addButton->setText(QCoreApplication::translate("main_window", "add", nullptr));
        changeButton->setText(QCoreApplication::translate("main_window", "change", nullptr));
        label->setText(QCoreApplication::translate("main_window", "\320\244\320\230\320\236", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "\320\223\321\200\321\203\320\277\320\277\320\260", nullptr));
        label_3->setText(QCoreApplication::translate("main_window", "\320\241\320\277\320\265\321\206\320\270\320\260\320\273\321\214\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("main_window", "\320\236\321\206\320\265\320\275\320\272\320\270", nullptr));
        label_5->setText(QCoreApplication::translate("main_window", "\320\234\320\260\321\202\320\265\320\274\320\260\321\202\320\270\320\272\320\260", nullptr));
        label_6->setText(QCoreApplication::translate("main_window", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_7->setText(QCoreApplication::translate("main_window", "\320\244\320\270\320\273\320\276\321\201\320\276\321\204\320\270\321\217", nullptr));
        math->setInputMask(QCoreApplication::translate("main_window", "9", nullptr));
        math->setText(QString());
        programming->setInputMask(QCoreApplication::translate("main_window", "9", nullptr));
        philosophi->setInputMask(QCoreApplication::translate("main_window", "9", nullptr));
        findStudent->setText(QCoreApplication::translate("main_window", "find student", nullptr));
        showBadStudent->setText(QCoreApplication::translate("main_window", "show bad student", nullptr));
        gradeSortButton->setText(QCoreApplication::translate("main_window", "sort by grade", nullptr));
        groupSortButton->setText(QCoreApplication::translate("main_window", "sort by group", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
