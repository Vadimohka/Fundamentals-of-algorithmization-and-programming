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
    QListWidget *deqEls;
    QPushButton *randBtn;
    QPushButton *popFront;
    QFrame *line_2;
    QPushButton *clearBtn;
    QPushButton *popBack;
    QPushButton *pushBack;
    QSpinBox *inp;
    QLabel *label;
    QFrame *line;
    QPushButton *pushFront;
    QPushButton *removeDuplicates;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(567, 643);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        deqEls = new QListWidget(centralwidget);
        deqEls->setObjectName("deqEls");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(deqEls->sizePolicy().hasHeightForWidth());
        deqEls->setSizePolicy(sizePolicy);

        gridLayout->addWidget(deqEls, 1, 0, 1, 2);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");

        gridLayout->addWidget(randBtn, 2, 0, 1, 1);

        popFront = new QPushButton(centralwidget);
        popFront->setObjectName("popFront");

        gridLayout->addWidget(popFront, 4, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line_2, 3, 0, 1, 2);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 2, 1, 1, 1);

        popBack = new QPushButton(centralwidget);
        popBack->setObjectName("popBack");

        gridLayout->addWidget(popBack, 4, 1, 1, 1);

        pushBack = new QPushButton(centralwidget);
        pushBack->setObjectName("pushBack");

        gridLayout->addWidget(pushBack, 7, 1, 1, 1);

        inp = new QSpinBox(centralwidget);
        inp->setObjectName("inp");
        inp->setMinimum(-8000);
        inp->setMaximum(8000);

        gridLayout->addWidget(inp, 6, 0, 1, 2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 9, 0, 1, 2);

        pushFront = new QPushButton(centralwidget);
        pushFront->setObjectName("pushFront");

        gridLayout->addWidget(pushFront, 7, 0, 1, 1);

        removeDuplicates = new QPushButton(centralwidget);
        removeDuplicates->setObjectName("removeDuplicates");

        gridLayout->addWidget(removeDuplicates, 8, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 567, 21));
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
        randBtn->setText(QCoreApplication::translate("MainWindow", "Random", nullptr));
        popFront->setText(QCoreApplication::translate("MainWindow", "Pop Front", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        popBack->setText(QCoreApplication::translate("MainWindow", "Pop Back", nullptr));
        pushBack->setText(QCoreApplication::translate("MainWindow", "Push Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Elems:", nullptr));
        pushFront->setText(QCoreApplication::translate("MainWindow", "Push Front", nullptr));
        removeDuplicates->setText(QCoreApplication::translate("MainWindow", "Delete duplications", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
