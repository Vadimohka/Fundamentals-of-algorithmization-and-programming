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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpinBox *key;
    QPushButton *randBtn;
    QFrame *line;
    QPushButton *clearBtn;
    QLabel *label_3;
    QLineEdit *value;
    QTableWidget *entries;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QPushButton *getBtn;
    QPushButton *setBtn;
    QPushButton *delBtn;
    QLabel *label;
    QLabel *smalles;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(464, 756);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        key = new QSpinBox(centralwidget);
        key->setObjectName("key");
        key->setMaximum(999999999);

        gridLayout->addWidget(key, 6, 1, 1, 1);

        randBtn = new QPushButton(centralwidget);
        randBtn->setObjectName("randBtn");

        gridLayout->addWidget(randBtn, 0, 0, 1, 1);

        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        gridLayout->addWidget(line, 8, 0, 1, 2);

        clearBtn = new QPushButton(centralwidget);
        clearBtn->setObjectName("clearBtn");

        gridLayout->addWidget(clearBtn, 0, 1, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 6, 0, 1, 1);

        value = new QLineEdit(centralwidget);
        value->setObjectName("value");

        gridLayout->addWidget(value, 7, 1, 1, 1);

        entries = new QTableWidget(centralwidget);
        if (entries->columnCount() < 3)
            entries->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        entries->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        entries->setObjectName("entries");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(entries->sizePolicy().hasHeightForWidth());
        entries->setSizePolicy(sizePolicy);
        entries->setEditTriggers(QAbstractItemView::NoEditTriggers);
        entries->setSelectionMode(QAbstractItemView::NoSelection);

        gridLayout->addWidget(entries, 1, 0, 1, 2);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 7, 0, 1, 1);

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

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 9, 0, 1, 1);

        smalles = new QLabel(centralwidget);
        smalles->setObjectName("smalles");

        gridLayout->addWidget(smalles, 9, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 464, 23));
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
        randBtn->setText(QCoreApplication::translate("MainWindow", "Randomize", nullptr));
        clearBtn->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cluch", nullptr));
        QTableWidgetItem *___qtablewidgetitem = entries->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "HashCell", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = entries->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Key", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = entries->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Value", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Znachenie", nullptr));
        getBtn->setText(QCoreApplication::translate("MainWindow", "Get", nullptr));
        setBtn->setText(QCoreApplication::translate("MainWindow", "Set", nullptr));
        delBtn->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "MALENKI KLUCH:", nullptr));
        smalles->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
