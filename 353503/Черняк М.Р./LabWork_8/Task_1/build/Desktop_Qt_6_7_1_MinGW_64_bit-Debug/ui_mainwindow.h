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
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *clearBtn;
    QTreeWidget *tree;
    QHBoxLayout *horizontalLayout;
    QPushButton *getBtn;
    QPushButton *setBtn;
    QPushButton *delBtn;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *key;
    QLabel *label_3;
    QLineEdit *value;
    QSpinBox *key1;
    QPushButton *balanceBtn;
    QSpinBox *key2;
    QLabel *label;
    QPushButton *lcaBtn;
    QPushButton *randBtn;
    QLabel *answ;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(828, 756);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(clearBtn, 3, 1, 1, 1);

        tree = new QTreeWidget(centralwidget);
        tree->setObjectName("tree");

        gridLayout->addWidget(tree, 1, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        getBtn = new QPushButton(centralwidget);
        getBtn->setObjectName("getBtn");

        horizontalLayout->addWidget(getBtn);

        setBtn = new QPushButton(centralwidget);
        setBtn->setObjectName("setBtn");

        horizontalLayout->addWidget(setBtn);

        delBtn = new QPushButton(centralwidget);
        delBtn->setObjectName("delBtn");

        horizontalLayout->addWidget(delBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 11, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

        key = new QSpinBox(centralwidget);
        key->setObjectName("key");
        key->setMaximum(999999999);

        gridLayout->addWidget(key, 6, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        value = new QLineEdit(centralwidget);
        value->setObjectName("value");

        gridLayout->addWidget(value, 7, 1, 1, 1);

        key1 = new QSpinBox(centralwidget);
        key1->setObjectName("key1");
        key1->setMaximum(999999999);

        gridLayout->addWidget(key1, 10, 0, 1, 1);

        balanceBtn = new QPushButton(centralwidget);
        balanceBtn->setObjectName("balanceBtn");

        gridLayout->addWidget(balanceBtn, 8, 0, 1, 2);

        key2 = new QSpinBox(centralwidget);
        key2->setObjectName("key2");
        key2->setMaximum(999999999);

        gridLayout->addWidget(key2, 12, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 9, 0, 1, 1);

        lcaBtn = new QPushButton(centralwidget);
        lcaBtn->setObjectName("lcaBtn");

        gridLayout->addWidget(lcaBtn, 13, 0, 1, 2);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");
        sizePolicy.setHeightForWidth(randBtn->sizePolicy().hasHeightForWidth());
        randBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(randBtn, 3, 0, 1, 1);

        answ = new QLabel(centralwidget);
        answ->setObjectName("answ");

        gridLayout->addWidget(answ, 14, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 828, 21));
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
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Key", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Tree", nullptr));
        getBtn->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        setBtn->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Node2 key:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        balanceBtn->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Node1 key:", nullptr));
        lcaBtn->setText(QCoreApplication::translate("MainWindow", "FInd LCA", nullptr));
        randBtn->setText(QCoreApplication::translate("MainWindow", "Randomize", nullptr));
        answ->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
