/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QGridLayout *gridLayout;
    QLineEdit *value;
    QSpinBox *key;
    QTableWidget *entries;
    QLabel *label_3;
    QPushButton *setBtn;
    QPushButton *randBtn;
    QFrame *line;
    QPushButton *delBtn;
    QPushButton *getBtn;
    QPushButton *even;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *clearBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1167, 644);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        value = new QLineEdit(centralwidget);
        value->setObjectName("value");

        gridLayout->addWidget(value, 13, 4, 1, 1);

        key = new QSpinBox(centralwidget);
        key->setObjectName("key");
        key->setMaximum(999999999);

        gridLayout->addWidget(key, 12, 4, 1, 1);

        entries = new QTableWidget(centralwidget);
        if (entries->columnCount() < 3)
            entries->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        entries->setObjectName("entries");
        entries->setEditTriggers(QAbstractItemView::NoEditTriggers);
        entries->setSelectionMode(QAbstractItemView::NoSelection);
        entries->horizontalHeader()->setCascadingSectionResizes(false);
        entries->horizontalHeader()->setDefaultSectionSize(380);
        entries->horizontalHeader()->setStretchLastSection(false);

        gridLayout->addWidget(entries, 1, 1, 1, 4);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 12, 1, 1, 1);

        setBtn = new QPushButton(centralwidget);
        setBtn->setObjectName("setBtn");

        gridLayout->addWidget(setBtn, 7, 2, 1, 1);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");

        gridLayout->addWidget(randBtn, 7, 4, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 14, 1, 1, 4);

        delBtn = new QPushButton(centralwidget);
        delBtn->setObjectName("delBtn");

        gridLayout->addWidget(delBtn, 8, 1, 1, 1);

        getBtn = new QPushButton(centralwidget);
        getBtn->setObjectName("getBtn");

        gridLayout->addWidget(getBtn, 7, 1, 1, 1);

        even = new QPushButton(centralwidget);
        even->setObjectName("even");

        gridLayout->addWidget(even, 8, 4, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 13, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");

        gridLayout->addLayout(horizontalLayout, 3, 1, 1, 4);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 8, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1167, 21));
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
        QTableWidgetItem *___qtablewidgetitem = entries->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Cell", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = entries->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = entries->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        setBtn->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        randBtn->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        getBtn->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        even->setText(QCoreApplication::translate("MainWindow", "Del even keys", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
