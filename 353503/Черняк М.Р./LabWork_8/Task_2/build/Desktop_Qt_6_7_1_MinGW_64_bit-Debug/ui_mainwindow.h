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
#include <QtWidgets/QHeaderView>
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
    QSpinBox *elem;
    QPushButton *pushBtn;
    QTreeWidget *tree;
    QPushButton *randBtn;
    QPushButton *popBtn;
    QPushButton *clearBtn;
    QPushButton *arrBtn;
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
        elem = new QSpinBox(centralwidget);
        elem->setObjectName("elem");
        elem->setMaximum(999999999);

        gridLayout->addWidget(elem, 9, 0, 1, 2);

        pushBtn = new QPushButton(centralwidget);
        pushBtn->setObjectName("pushBtn");

        gridLayout->addWidget(pushBtn, 5, 0, 1, 1);

        tree = new QTreeWidget(centralwidget);
        tree->setObjectName("tree");

        gridLayout->addWidget(tree, 3, 0, 1, 2);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(randBtn->sizePolicy().hasHeightForWidth());
        randBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(randBtn, 4, 0, 1, 1);

        popBtn = new QPushButton(centralwidget);
        popBtn->setObjectName("popBtn");

        gridLayout->addWidget(popBtn, 5, 1, 1, 1);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");
        sizePolicy.setHeightForWidth(clearBtn->sizePolicy().hasHeightForWidth());
        clearBtn->setSizePolicy(sizePolicy);

        gridLayout->addWidget(clearBtn, 4, 1, 1, 1);

        arrBtn = new QPushButton(centralwidget);
        arrBtn->setObjectName("arrBtn");

        gridLayout->addWidget(arrBtn, 0, 0, 1, 2);

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
        pushBtn->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = tree->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "Value", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Tree", nullptr));
        randBtn->setText(QCoreApplication::translate("MainWindow", "Randomize", nullptr));
        popBtn->setText(QCoreApplication::translate("MainWindow", "Pop", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        arrBtn->setText(QCoreApplication::translate("MainWindow", "Array Mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
