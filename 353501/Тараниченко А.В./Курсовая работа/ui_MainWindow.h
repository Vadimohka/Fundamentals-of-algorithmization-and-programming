/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "SizeFitGraphicsView.hpp"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewGame;
    QAction *actionGameHelp;
    QAction *actionAbout;
    QAction *actionContact;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *message;
    QLabel *colorMessage;
    SizeFitGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuGame;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(400, 300);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        actionNewGame = new QAction(MainWindow);
        actionNewGame->setObjectName("actionNewGame");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icons/add-new-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewGame->setIcon(icon);
        actionGameHelp = new QAction(MainWindow);
        actionGameHelp->setObjectName("actionGameHelp");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/question.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGameHelp->setIcon(icon1);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionContact = new QAction(MainWindow);
        actionContact->setObjectName("actionContact");
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName("horizontalLayout");
        message = new QLabel(centralWidget);
        message->setObjectName("message");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        message->setFont(font);
        message->setLayoutDirection(Qt::LeftToRight);
        message->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(message);


        verticalLayout->addLayout(horizontalLayout);

        colorMessage = new QLabel(centralWidget);
        colorMessage->setObjectName("colorMessage");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorMessage->sizePolicy().hasHeightForWidth());
        colorMessage->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(colorMessage, 0, Qt::AlignHCenter);

        graphicsView = new SizeFitGraphicsView(centralWidget);
        graphicsView->setObjectName("graphicsView");

        verticalLayout->addWidget(graphicsView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 400, 22));
        menuGame = new QMenu(menuBar);
        menuGame->setObjectName("menuGame");
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuGame->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuGame->addAction(actionNewGame);
        menuHelp->addAction(actionGameHelp);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionContact);
        mainToolBar->addAction(actionNewGame);
        mainToolBar->addAction(actionGameHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Connected Four", nullptr));
        actionNewGame->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        actionGameHelp->setText(QCoreApplication::translate("MainWindow", "Game Help", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionContact->setText(QCoreApplication::translate("MainWindow", "Contact", nullptr));
        message->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        colorMessage->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        menuGame->setTitle(QCoreApplication::translate("MainWindow", "Game", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
