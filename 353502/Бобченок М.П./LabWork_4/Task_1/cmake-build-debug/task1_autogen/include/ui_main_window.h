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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QSpinBox *columnsNum;
    QPushButton *quickSort;
    QPushButton *heapSort;
    QPushButton *mergeSort;
    QPushButton *restart;
    QSlider *speed;
    QPushButton *interpolationSort;
    QLabel *label;
    QLabel *time;

    void setupUi(QWidget *main_window)
    {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2509, 1600);
        graphicsView = new QGraphicsView(main_window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 2560, 1600));
        columnsNum = new QSpinBox(main_window);
        columnsNum->setObjectName(QString::fromUtf8("columnsNum"));
        columnsNum->setGeometry(QRect(1720, 620, 71, 26));
        columnsNum->setMinimum(10);
        columnsNum->setMaximum(150);
        quickSort = new QPushButton(main_window);
        quickSort->setObjectName(QString::fromUtf8("quickSort"));
        quickSort->setGeometry(QRect(1720, 300, 141, 31));
        heapSort = new QPushButton(main_window);
        heapSort->setObjectName(QString::fromUtf8("heapSort"));
        heapSort->setGeometry(QRect(1720, 340, 141, 31));
        mergeSort = new QPushButton(main_window);
        mergeSort->setObjectName(QString::fromUtf8("mergeSort"));
        mergeSort->setGeometry(QRect(1720, 380, 141, 31));
        restart = new QPushButton(main_window);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setGeometry(QRect(1720, 530, 141, 31));
        speed = new QSlider(main_window);
        speed->setObjectName(QString::fromUtf8("speed"));
        speed->setGeometry(QRect(1720, 580, 141, 16));
        speed->setMinimum(0);
        speed->setMaximum(999999);
        speed->setOrientation(Qt::Horizontal);
        interpolationSort = new QPushButton(main_window);
        interpolationSort->setObjectName(QString::fromUtf8("interpolationSort"));
        interpolationSort->setGeometry(QRect(1720, 420, 141, 31));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1720, 480, 51, 17));
        time = new QLabel(main_window);
        time->setObjectName(QString::fromUtf8("time"));
        time->setGeometry(QRect(1770, 480, 91, 17));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window)
    {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        quickSort->setText(QCoreApplication::translate("main_window", "quickSort", nullptr));
        heapSort->setText(QCoreApplication::translate("main_window", "heapSort", nullptr));
        mergeSort->setText(QCoreApplication::translate("main_window", "mergeSort", nullptr));
        restart->setText(QCoreApplication::translate("main_window", "restart", nullptr));
        interpolationSort->setText(QCoreApplication::translate("main_window", "interpolationSort", nullptr));
        label->setText(QCoreApplication::translate("main_window", "time - ", nullptr));
        time->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class main_window: public Ui_main_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
