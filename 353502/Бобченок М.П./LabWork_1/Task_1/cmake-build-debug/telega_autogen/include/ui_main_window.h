/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QPushButton *Left;
    QPushButton *Right;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2560, 1600);
        graphicsView = new QGraphicsView(main_window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 2560, 1600));
        Left = new QPushButton(main_window);
        Left->setObjectName(QString::fromUtf8("Left"));
        Left->setGeometry(QRect(1100, 1300, 150, 150));
        Right = new QPushButton(main_window);
        Right->setObjectName(QString::fromUtf8("Right"));
        Right->setGeometry(QRect(1350, 1300, 150, 150));
        Right->setIconSize(QSize(16, 16));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        Left->setText(QCoreApplication::translate("main_window", "<", nullptr));
        Right->setText(QCoreApplication::translate("main_window", ">", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
