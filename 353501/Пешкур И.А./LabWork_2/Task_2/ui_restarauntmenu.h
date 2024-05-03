/********************************************************************************
** Form generated from reading UI file 'restarauntmenu.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESTARAUNTMENU_H
#define UI_RESTARAUNTMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_RestarauntMenu
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *RestarauntMenu)
    {
        if (RestarauntMenu->objectName().isEmpty())
            RestarauntMenu->setObjectName(QString::fromUtf8("RestarauntMenu"));
        RestarauntMenu->resize(590, 608);
        tableWidget = new QTableWidget(RestarauntMenu);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 571, 621));

        retranslateUi(RestarauntMenu);

        QMetaObject::connectSlotsByName(RestarauntMenu);
    } // setupUi

    void retranslateUi(QDialog *RestarauntMenu)
    {
        RestarauntMenu->setWindowTitle(QCoreApplication::translate("RestarauntMenu", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("RestarauntMenu", "Food name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("RestarauntMenu", "Price", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RestarauntMenu: public Ui_RestarauntMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESTARAUNTMENU_H
