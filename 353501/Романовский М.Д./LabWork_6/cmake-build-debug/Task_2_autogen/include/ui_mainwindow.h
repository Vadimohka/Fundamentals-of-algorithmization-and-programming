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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *selector;
    QWidget *root;
    QHBoxLayout *horizontalLayout_2;
    QLabel *defaultSubtask;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(938, 597);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        selector = new QListWidget(centralwidget);
        new QListWidgetItem(selector);
        new QListWidgetItem(selector);
        new QListWidgetItem(selector);
        new QListWidgetItem(selector);
        new QListWidgetItem(selector);
        selector->setObjectName("selector");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(selector->sizePolicy().hasHeightForWidth());
        selector->setSizePolicy(sizePolicy);
        selector->setEditTriggers(QAbstractItemView::NoEditTriggers);

        horizontalLayout->addWidget(selector);

        root = new QWidget(centralwidget);
        root->setObjectName("root");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(root->sizePolicy().hasHeightForWidth());
        root->setSizePolicy(sizePolicy1);
        horizontalLayout_2 = new QHBoxLayout(root);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        defaultSubtask = new QLabel(root);
        defaultSubtask->setObjectName("defaultSubtask");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(defaultSubtask->sizePolicy().hasHeightForWidth());
        defaultSubtask->setSizePolicy(sizePolicy2);
        defaultSubtask->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(defaultSubtask);


        horizontalLayout->addWidget(root);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 938, 22));
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

        const bool __sortingEnabled = selector->isSortingEnabled();
        selector->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = selector->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Paragraph Writer", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = selector->item(1);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Array viewer", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = selector->item(2);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "Text Buisenessman", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = selector->item(3);
        ___qlistwidgetitem3->setText(QCoreApplication::translate("MainWindow", "Binary Buisenessman", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = selector->item(4);
        ___qlistwidgetitem4->setText(QCoreApplication::translate("MainWindow", "Paragraph Appender", nullptr));
        selector->setSortingEnabled(__sortingEnabled);

        defaultSubtask->setText(QCoreApplication::translate("MainWindow", "Select Sub Task to Start", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
