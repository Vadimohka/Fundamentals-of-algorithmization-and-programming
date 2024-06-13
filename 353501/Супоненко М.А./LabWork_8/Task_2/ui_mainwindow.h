/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *arrayHeapLayout;
    QLineEdit *arrayValueInput;
    QPushButton *arrayInsertButton;
    QPushButton *arrayExtractButton;
    QPushButton *arrayGetMaxButton;
    QTextEdit *arrayOutput;
    QHBoxLayout *listHeapLayout;
    QLineEdit *listValueInput;
    QPushButton *listInsertButton;
    QPushButton *listExtractButton;
    QPushButton *listGetMaxButton;
    QTextEdit *listOutput;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 400);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        arrayHeapLayout = new QHBoxLayout();
        arrayHeapLayout->setObjectName(QString::fromUtf8("arrayHeapLayout"));
        arrayValueInput = new QLineEdit(centralWidget);
        arrayValueInput->setObjectName(QString::fromUtf8("arrayValueInput"));

        arrayHeapLayout->addWidget(arrayValueInput);

        arrayInsertButton = new QPushButton(centralWidget);
        arrayInsertButton->setObjectName(QString::fromUtf8("arrayInsertButton"));

        arrayHeapLayout->addWidget(arrayInsertButton);

        arrayExtractButton = new QPushButton(centralWidget);
        arrayExtractButton->setObjectName(QString::fromUtf8("arrayExtractButton"));

        arrayHeapLayout->addWidget(arrayExtractButton);

        arrayGetMaxButton = new QPushButton(centralWidget);
        arrayGetMaxButton->setObjectName(QString::fromUtf8("arrayGetMaxButton"));

        arrayHeapLayout->addWidget(arrayGetMaxButton);


        verticalLayout->addLayout(arrayHeapLayout);

        arrayOutput = new QTextEdit(centralWidget);
        arrayOutput->setObjectName(QString::fromUtf8("arrayOutput"));
        arrayOutput->setReadOnly(true);

        verticalLayout->addWidget(arrayOutput);

        listHeapLayout = new QHBoxLayout();
        listHeapLayout->setObjectName(QString::fromUtf8("listHeapLayout"));
        listValueInput = new QLineEdit(centralWidget);
        listValueInput->setObjectName(QString::fromUtf8("listValueInput"));

        listHeapLayout->addWidget(listValueInput);

        listInsertButton = new QPushButton(centralWidget);
        listInsertButton->setObjectName(QString::fromUtf8("listInsertButton"));

        listHeapLayout->addWidget(listInsertButton);

        listExtractButton = new QPushButton(centralWidget);
        listExtractButton->setObjectName(QString::fromUtf8("listExtractButton"));

        listHeapLayout->addWidget(listExtractButton);

        listGetMaxButton = new QPushButton(centralWidget);
        listGetMaxButton->setObjectName(QString::fromUtf8("listGetMaxButton"));

        listHeapLayout->addWidget(listGetMaxButton);


        verticalLayout->addLayout(listHeapLayout);

        listOutput = new QTextEdit(centralWidget);
        listOutput->setObjectName(QString::fromUtf8("listOutput"));
        listOutput->setReadOnly(true);

        verticalLayout->addWidget(listOutput);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Binary Heaps", nullptr));
        arrayValueInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "Array Heap: Enter value", nullptr));
        arrayInsertButton->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        arrayExtractButton->setText(QCoreApplication::translate("MainWindow", "Extract Max", nullptr));
        arrayGetMaxButton->setText(QCoreApplication::translate("MainWindow", "Get Max", nullptr));
        listValueInput->setPlaceholderText(QCoreApplication::translate("MainWindow", "List Heap: Enter value", nullptr));
        listInsertButton->setText(QCoreApplication::translate("MainWindow", "Insert", nullptr));
        listExtractButton->setText(QCoreApplication::translate("MainWindow", "Extract Max", nullptr));
        listGetMaxButton->setText(QCoreApplication::translate("MainWindow", "Get Max", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
