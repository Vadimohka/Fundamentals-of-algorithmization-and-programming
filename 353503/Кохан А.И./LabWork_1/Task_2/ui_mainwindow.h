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
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRect;
    QAction *actionSquare;
    QAction *actionRomb;
    QAction *actionHexagon;
    QAction *actionEllipse;
    QAction *actionCircle;
    QAction *actionTriangle3;
    QAction *actionTriangle90;
    QAction *actionStar5;
    QAction *actionStar6;
    QAction *actionStar8;
    QAction *actionMove;
    QAction *actionDelete;
    QAction *actionBroom;
    QAction *actionRestart;
    QAction *actionRotation;
    QAction *actionScale;
    QAction *actionLine;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QLabel *label;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1032, 704);
        QIcon icon;
        icon.addFile(QString::fromUtf8("img/1708699880134.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionRect = new QAction(MainWindow);
        actionRect->setObjectName("actionRect");
        actionRect->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/img/1708263724802.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRect->setIcon(icon1);
        actionRect->setMenuRole(QAction::NoRole);
        actionSquare = new QAction(MainWindow);
        actionSquare->setObjectName("actionSquare");
        actionSquare->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/img/1708263849499.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSquare->setIcon(icon2);
        actionSquare->setMenuRole(QAction::NoRole);
        actionRomb = new QAction(MainWindow);
        actionRomb->setObjectName("actionRomb");
        actionRomb->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/img/1708264518923.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRomb->setIcon(icon3);
        actionRomb->setMenuRole(QAction::NoRole);
        actionHexagon = new QAction(MainWindow);
        actionHexagon->setObjectName("actionHexagon");
        actionHexagon->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/img/1708289087609.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHexagon->setIcon(icon4);
        actionHexagon->setMenuRole(QAction::NoRole);
        actionEllipse = new QAction(MainWindow);
        actionEllipse->setObjectName("actionEllipse");
        actionEllipse->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/img/1708289543129.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEllipse->setIcon(icon5);
        actionEllipse->setMenuRole(QAction::NoRole);
        actionCircle = new QAction(MainWindow);
        actionCircle->setObjectName("actionCircle");
        actionCircle->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/img/1708264066922.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon6);
        actionCircle->setMenuRole(QAction::NoRole);
        actionTriangle3 = new QAction(MainWindow);
        actionTriangle3->setObjectName("actionTriangle3");
        actionTriangle3->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/img/img/1708262878181.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTriangle3->setIcon(icon7);
        actionTriangle3->setMenuRole(QAction::NoRole);
        actionTriangle90 = new QAction(MainWindow);
        actionTriangle90->setObjectName("actionTriangle90");
        actionTriangle90->setCheckable(true);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/img/img/1708262890015.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTriangle90->setIcon(icon8);
        actionTriangle90->setMenuRole(QAction::NoRole);
        actionStar5 = new QAction(MainWindow);
        actionStar5->setObjectName("actionStar5");
        actionStar5->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/img/img/1708264768701.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStar5->setIcon(icon9);
        actionStar5->setMenuRole(QAction::NoRole);
        actionStar6 = new QAction(MainWindow);
        actionStar6->setObjectName("actionStar6");
        actionStar6->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/img/img/1708264839442.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStar6->setIcon(icon10);
        actionStar6->setMenuRole(QAction::NoRole);
        actionStar8 = new QAction(MainWindow);
        actionStar8->setObjectName("actionStar8");
        actionStar8->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/img/img/1708264942133.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStar8->setIcon(icon11);
        actionStar8->setMenuRole(QAction::NoRole);
        actionMove = new QAction(MainWindow);
        actionMove->setObjectName("actionMove");
        actionMove->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/img/img/free-icon-drag-drop-12596584.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon12);
        actionMove->setMenuRole(QAction::NoRole);
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionDelete->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/img/img/1708442512972.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDelete->setIcon(icon13);
        actionDelete->setMenuRole(QAction::NoRole);
        actionBroom = new QAction(MainWindow);
        actionBroom->setObjectName("actionBroom");
        actionBroom->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/img/img/1708524572361.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBroom->setIcon(icon14);
        actionBroom->setMenuRole(QAction::NoRole);
        actionRestart = new QAction(MainWindow);
        actionRestart->setObjectName("actionRestart");
        actionRestart->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/img/img/1708526228922.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRestart->setIcon(icon15);
        actionRestart->setMenuRole(QAction::NoRole);
        actionRotation = new QAction(MainWindow);
        actionRotation->setObjectName("actionRotation");
        actionRotation->setCheckable(true);
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/img/img/1708536360819.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotation->setIcon(icon16);
        actionRotation->setMenuRole(QAction::NoRole);
        actionScale = new QAction(MainWindow);
        actionScale->setObjectName("actionScale");
        actionScale->setCheckable(true);
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/img/img/368b0b60811931bbd7903b72eb04da24.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon17);
        actionScale->setMenuRole(QAction::NoRole);
        actionLine = new QAction(MainWindow);
        actionLine->setObjectName("actionLine");
        actionLine->setCheckable(true);
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/img/img/1708638238299.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLine->setIcon(icon18);
        actionLine->setMenuRole(QAction::NoRole);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionRect);
        toolBar->addAction(actionSquare);
        toolBar->addAction(actionRomb);
        toolBar->addAction(actionHexagon);
        toolBar->addAction(actionEllipse);
        toolBar->addAction(actionCircle);
        toolBar->addAction(actionTriangle3);
        toolBar->addAction(actionTriangle90);
        toolBar->addAction(actionStar5);
        toolBar->addAction(actionStar6);
        toolBar->addAction(actionStar8);
        toolBar->addAction(actionLine);
        toolBar->addSeparator();
        toolBar->addAction(actionMove);
        toolBar->addAction(actionRotation);
        toolBar->addAction(actionScale);
        toolBar->addAction(actionRestart);
        toolBar->addAction(actionDelete);
        toolBar->addAction(actionBroom);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Paint", nullptr));
        actionRect->setText(QCoreApplication::translate("MainWindow", "Rect", nullptr));
#if QT_CONFIG(tooltip)
        actionRect->setToolTip(QCoreApplication::translate("MainWindow", "Rectangle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionSquare->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        actionRomb->setText(QCoreApplication::translate("MainWindow", "Romb", nullptr));
        actionHexagon->setText(QCoreApplication::translate("MainWindow", "Hexagon", nullptr));
#if QT_CONFIG(tooltip)
        actionHexagon->setToolTip(QCoreApplication::translate("MainWindow", "Hexagon", nullptr));
#endif // QT_CONFIG(tooltip)
        actionEllipse->setText(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
#if QT_CONFIG(tooltip)
        actionEllipse->setToolTip(QCoreApplication::translate("MainWindow", "Ellipse", nullptr));
#endif // QT_CONFIG(tooltip)
        actionCircle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
#if QT_CONFIG(tooltip)
        actionCircle->setToolTip(QCoreApplication::translate("MainWindow", "Circle", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTriangle3->setText(QCoreApplication::translate("MainWindow", "Triangle3", nullptr));
#if QT_CONFIG(tooltip)
        actionTriangle3->setToolTip(QCoreApplication::translate("MainWindow", "Triangle-3", nullptr));
#endif // QT_CONFIG(tooltip)
        actionTriangle90->setText(QCoreApplication::translate("MainWindow", "Triangle90", nullptr));
        actionStar5->setText(QCoreApplication::translate("MainWindow", "Star5", nullptr));
#if QT_CONFIG(tooltip)
        actionStar5->setToolTip(QCoreApplication::translate("MainWindow", "Star-5", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStar6->setText(QCoreApplication::translate("MainWindow", "Star6", nullptr));
#if QT_CONFIG(tooltip)
        actionStar6->setToolTip(QCoreApplication::translate("MainWindow", "Star-6", nullptr));
#endif // QT_CONFIG(tooltip)
        actionStar8->setText(QCoreApplication::translate("MainWindow", "Star8", nullptr));
#if QT_CONFIG(tooltip)
        actionStar8->setToolTip(QCoreApplication::translate("MainWindow", "Star-8", nullptr));
#endif // QT_CONFIG(tooltip)
        actionMove->setText(QCoreApplication::translate("MainWindow", "Move", nullptr));
#if QT_CONFIG(tooltip)
        actionMove->setToolTip(QCoreApplication::translate("MainWindow", "Move Item", nullptr));
#endif // QT_CONFIG(tooltip)
        actionDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
#if QT_CONFIG(tooltip)
        actionDelete->setToolTip(QCoreApplication::translate("MainWindow", "Delete item", nullptr));
#endif // QT_CONFIG(tooltip)
        actionBroom->setText(QCoreApplication::translate("MainWindow", "Broom", nullptr));
#if QT_CONFIG(tooltip)
        actionBroom->setToolTip(QCoreApplication::translate("MainWindow", "Delete all", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRestart->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
#if QT_CONFIG(tooltip)
        actionRestart->setToolTip(QCoreApplication::translate("MainWindow", "Restart drawing", nullptr));
#endif // QT_CONFIG(tooltip)
        actionRotation->setText(QCoreApplication::translate("MainWindow", "Rotation", nullptr));
#if QT_CONFIG(tooltip)
        actionRotation->setToolTip(QCoreApplication::translate("MainWindow", "Rotation item", nullptr));
#endif // QT_CONFIG(tooltip)
        actionScale->setText(QCoreApplication::translate("MainWindow", "Scale", nullptr));
#if QT_CONFIG(tooltip)
        actionScale->setToolTip(QCoreApplication::translate("MainWindow", "Scaling item", nullptr));
#endif // QT_CONFIG(tooltip)
        actionLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
#if QT_CONFIG(tooltip)
        actionLine->setToolTip(QCoreApplication::translate("MainWindow", "Line", nullptr));
#endif // QT_CONFIG(tooltip)
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
