/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QPushButton *forwardButton;
    QPushButton *pushButton;
    QSpinBox *spinBox;
    QPushButton *backButton;
    QLabel *label_2;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(1453, 561);
        gridLayoutWidget_2 = new QWidget(Widget);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 20, 1249, 341));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget_2);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        tableWidget = new QTableWidget(gridLayoutWidget_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName("tableWidget");

        gridLayout->addWidget(tableWidget, 1, 0, 1, 3);

        forwardButton = new QPushButton(gridLayoutWidget_2);
        forwardButton->setObjectName("forwardButton");

        gridLayout->addWidget(forwardButton, 2, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 1, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget_2);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);

        gridLayout->addWidget(spinBox, 0, 2, 1, 1);

        backButton = new QPushButton(gridLayoutWidget_2);
        backButton->setObjectName("backButton");

        gridLayout->addWidget(backButton, 2, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 3, 0, 1, 3);

        graphicsView = new QGraphicsView(gridLayoutWidget_2);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 3, 4, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\272\320\276\320\273\320\265\321\206:", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Widget", "\320\241 \320\272\320\260\320\272\320\276\320\263\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Widget", "\320\235\320\260 \320\272\320\260\320\272\320\276\320\271", nullptr));
        forwardButton->setText(QCoreApplication::translate("Widget", ">>", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\320\237\321\203\321\201\320\272", nullptr));
        backButton->setText(QCoreApplication::translate("Widget", "<<", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\320\235\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276 \321\205\320\276\320\264\320\276\320\262: 1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
