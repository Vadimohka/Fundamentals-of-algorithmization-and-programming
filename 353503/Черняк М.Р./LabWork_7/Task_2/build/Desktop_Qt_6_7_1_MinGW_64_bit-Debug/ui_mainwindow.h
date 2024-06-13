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
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *value;
    QTreeWidget *tree;
    QLabel *label_3;
    QPushButton *randBtn;
    QLabel *label_4;
    QLabel *count;
    QFrame *line;
    QLineEdit *valStart;
    QPushButton *balanceBtn;
    QPushButton *delBtn;
    QPushButton *clearBtn;
    QHBoxLayout *horizontalLayout;
    QPushButton *getBtn;
    QPushButton *setBtn;
    QSpinBox *key;
    QPushButton *enter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(828, 725);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        value = new QLineEdit(centralwidget);
        value->setObjectName("value");

        gridLayout->addWidget(value, 10, 1, 1, 1);

        tree = new QTreeWidget(centralwidget);
        tree->setObjectName("tree");

        gridLayout->addWidget(tree, 1, 0, 1, 2);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 9, 0, 1, 1);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(randBtn->sizePolicy().hasHeightForWidth());
        randBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(randBtn, 5, 0, 1, 1);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 10, 0, 1, 1);

        count = new QLabel(centralwidget);
        count->setObjectName("count");

        gridLayout->addWidget(count, 18, 0, 1, 2);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 14, 0, 1, 2);

        valStart = new QLineEdit(centralwidget);
        valStart->setObjectName("valStart");

        gridLayout->addWidget(valStart, 15, 0, 1, 2);

        balanceBtn = new QPushButton(centralwidget);
        balanceBtn->setObjectName("balanceBtn");

        gridLayout->addWidget(balanceBtn, 13, 0, 1, 2);

        delBtn = new QPushButton(centralwidget);
        delBtn->setObjectName("delBtn");

        gridLayout->addWidget(delBtn, 5, 1, 1, 1);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        sizePolicy.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(clearBtn, 6, 0, 1, 2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        getBtn = new QPushButton(centralwidget);
        getBtn->setObjectName("getBtn");

        horizontalLayout->addWidget(getBtn);

        setBtn = new QPushButton(centralwidget);
        setBtn->setObjectName("setBtn");

        horizontalLayout->addWidget(setBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        key = new QSpinBox(centralwidget);
        key->setObjectName("key");
        key->setMaximum(999999999);

        gridLayout->addWidget(key, 9, 1, 1, 1);

        enter = new QPushButton(centralwidget);
        enter->setObjectName("enter");

        gridLayout->addWidget(enter, 16, 0, 1, 2);

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
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Key", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Tree", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        randBtn->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        count->setText(QString());
        valStart->setText(QCoreApplication::translate("MainWindow", "Value starts with...", nullptr));
        balanceBtn->setText(QCoreApplication::translate("MainWindow", "Balance", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        getBtn->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        setBtn->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        enter->setText(QCoreApplication::translate("MainWindow", "Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
