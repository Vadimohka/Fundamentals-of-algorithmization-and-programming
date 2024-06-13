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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QListWidget *demoMethodsList;
    QLabel *label;
    QPushButton *popButton;
    QSpinBox *insertedElComboBox;
    QPushButton *frontButton;
    QPushButton *backButton;
    QPushButton *sizeButton;
    QPushButton *emptyButton;
    QWidget *tab_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QListWidget *queue1Widget;
    QPushButton *fillButton;
    QPushButton *makeMinButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(854, 728);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 851, 681));
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayoutWidget = new QWidget(tab);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(0, 0, 851, 651));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        demoMethodsList = new QListWidget(gridLayoutWidget);
        demoMethodsList->setObjectName("demoMethodsList");

        gridLayout->addWidget(demoMethodsList, 0, 0, 1, 4);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 2, 1, 1);

        popButton = new QPushButton(gridLayoutWidget);
        popButton->setObjectName("popButton");

        gridLayout->addWidget(popButton, 2, 1, 1, 1);

        insertedElComboBox = new QSpinBox(gridLayoutWidget);
        insertedElComboBox->setObjectName("insertedElComboBox");

        gridLayout->addWidget(insertedElComboBox, 2, 3, 1, 1);

        frontButton = new QPushButton(gridLayoutWidget);
        frontButton->setObjectName("frontButton");

        gridLayout->addWidget(frontButton, 1, 0, 1, 1);

        backButton = new QPushButton(gridLayoutWidget);
        backButton->setObjectName("backButton");

        gridLayout->addWidget(backButton, 1, 1, 1, 1);

        sizeButton = new QPushButton(gridLayoutWidget);
        sizeButton->setObjectName("sizeButton");

        gridLayout->addWidget(sizeButton, 1, 2, 1, 1);

        emptyButton = new QPushButton(gridLayoutWidget);
        emptyButton->setObjectName("emptyButton");

        gridLayout->addWidget(emptyButton, 1, 3, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayoutWidget_2 = new QWidget(tab_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(0, 0, 851, 651));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        queue1Widget = new QListWidget(gridLayoutWidget_2);
        queue1Widget->setObjectName("queue1Widget");

        gridLayout_2->addWidget(queue1Widget, 0, 0, 1, 1);

        fillButton = new QPushButton(gridLayoutWidget_2);
        fillButton->setObjectName("fillButton");

        gridLayout_2->addWidget(fillButton, 1, 0, 1, 2);

        makeMinButton = new QPushButton(gridLayoutWidget_2);
        makeMinButton->setObjectName("makeMinButton");

        gridLayout_2->addWidget(makeMinButton, 2, 0, 1, 1);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 854, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\201\321\202\320\260\320\262\320\273\321\217\320\265\320\274\321\213\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202:", nullptr));
        popButton->setText(QCoreApplication::translate("MainWindow", "Pop", nullptr));
        frontButton->setText(QCoreApplication::translate("MainWindow", "Front", nullptr));
        backButton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "Size", nullptr));
        emptyButton->setText(QCoreApplication::translate("MainWindow", "Empty?", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        fillButton->setText(QCoreApplication::translate("MainWindow", "Fill queue with rand numbers", nullptr));
        makeMinButton->setText(QCoreApplication::translate("MainWindow", "Make min element at front", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
