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
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *popFront;
    QPushButton *pushFront;
    QListWidget *deqEls;
    QPushButton *pushBack;
    QPushButton *popBack;
    QFrame *line;
    QSpinBox *inp;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(868, 603);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 2);

        popFront = new QPushButton(centralwidget);
        popFront->setObjectName("popFront");

        gridLayout->addWidget(popFront, 3, 0, 1, 1);

        pushFront = new QPushButton(centralwidget);
        pushFront->setObjectName("pushFront");

        gridLayout->addWidget(pushFront, 6, 0, 1, 1);

        deqEls = new QListWidget(centralwidget);
        deqEls->setObjectName("deqEls");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deqEls->sizePolicy().hasHeightForWidth());
        deqEls->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deqEls, 2, 0, 1, 2);

        pushBack = new QPushButton(centralwidget);
        pushBack->setObjectName("pushBack");

        gridLayout->addWidget(pushBack, 6, 1, 1, 1);

        popBack = new QPushButton(centralwidget);
        popBack->setObjectName("popBack");

        gridLayout->addWidget(popBack, 3, 1, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 0, 2, 7, 1);

        inp = new QSpinBox(centralwidget);
        inp->setObjectName("inp");
        inp->setMinimum(-8000);
        inp->setMaximum(8000);

        gridLayout->addWidget(inp, 4, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 868, 21));
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
        label->setText(QCoreApplication::translate("MainWindow", "Deque", nullptr));
        popFront->setText(QCoreApplication::translate("MainWindow", "Pop Front", nullptr));
        pushFront->setText(QCoreApplication::translate("MainWindow", "Push Front", nullptr));
        pushBack->setText(QCoreApplication::translate("MainWindow", "Push Back", nullptr));
        popBack->setText(QCoreApplication::translate("MainWindow", "Pop Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
