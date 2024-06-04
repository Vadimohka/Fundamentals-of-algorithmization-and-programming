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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_window
{
public:
    QGraphicsView *graphicsView;
    QPushButton *triangle;
    QPushButton *circle;
    QPushButton *rect;
    QPushButton *rhombus;
    QPushButton *star;
    QPushButton *hecsaedr;
    QPushButton *drawing;
    QLineEdit *numOfCorners;
    QLabel *label;
    QLabel *label_2;
    QLabel *perimetr;
    QLabel *square;
    QPushButton *exit;

    void setupUi(QWidget *main_window) {
        if (main_window->objectName().isEmpty())
            main_window->setObjectName(QString::fromUtf8("main_window"));
        main_window->resize(2560, 1600);
        graphicsView = new QGraphicsView(main_window);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 150, 2560, 1450));
        graphicsView->setAutoFillBackground(false);
        triangle = new QPushButton(main_window);
        triangle->setObjectName(QString::fromUtf8("triangle"));
        triangle->setGeometry(QRect(0, 0, 100, 100));
        circle = new QPushButton(main_window);
        circle->setObjectName(QString::fromUtf8("circle"));
        circle->setGeometry(QRect(100, 0, 100, 100));
        rect = new QPushButton(main_window);
        rect->setObjectName(QString::fromUtf8("rect"));
        rect->setGeometry(QRect(200, 0, 100, 100));
        rhombus = new QPushButton(main_window);
        rhombus->setObjectName(QString::fromUtf8("rhombus"));
        rhombus->setGeometry(QRect(300, 0, 100, 100));
        star = new QPushButton(main_window);
        star->setObjectName(QString::fromUtf8("star"));
        star->setGeometry(QRect(1150, 0, 100, 100));
        hecsaedr = new QPushButton(main_window);
        hecsaedr->setObjectName(QString::fromUtf8("hecsaedr"));
        hecsaedr->setGeometry(QRect(1250, 0, 100, 100));
        drawing = new QPushButton(main_window);
        drawing->setObjectName(QString::fromUtf8("drawing"));
        drawing->setGeometry(QRect(400, 0, 100, 100));
        numOfCorners = new QLineEdit(main_window);
        numOfCorners->setObjectName(QString::fromUtf8("numOfCorners"));
        numOfCorners->setGeometry(QRect(1200, 110, 113, 25));
        numOfCorners->setInputMask(QString::fromUtf8("99"));
        label = new QLabel(main_window);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(640, 10, 81, 31));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setScaledContents(false);
        label_2 = new QLabel(main_window);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(640, 60, 81, 31));
        label_2->setFont(font);
        label_2->setScaledContents(false);
        perimetr = new QLabel(main_window);
        perimetr->setObjectName(QString::fromUtf8("perimetr"));
        perimetr->setGeometry(QRect(720, 10, 221, 31));
        perimetr->setFont(font);
        perimetr->setScaledContents(false);
        square = new QLabel(main_window);
        square->setObjectName(QString::fromUtf8("square"));
        square->setGeometry(QRect(720, 60, 241, 31));
        square->setFont(font);
        square->setScaledContents(false);
        exit = new QPushButton(main_window);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(2460, 0, 100, 100));

        retranslateUi(main_window);

        QMetaObject::connectSlotsByName(main_window);
    } // setupUi

    void retranslateUi(QWidget *main_window) {
        main_window->setWindowTitle(QCoreApplication::translate("main_window", "main_window", nullptr));
        triangle->setText(QCoreApplication::translate("main_window", "Triangle", nullptr));
        circle->setText(QCoreApplication::translate("main_window", "Circle", nullptr));
        rect->setText(QCoreApplication::translate("main_window", "Rectangle", nullptr));
        rhombus->setText(QCoreApplication::translate("main_window", "Rhombus", nullptr));
        star->setText(QCoreApplication::translate("main_window", "Star", nullptr));
        hecsaedr->setText(QCoreApplication::translate("main_window", "Hecsaedr", nullptr));
        drawing->setText(QCoreApplication::translate("main_window", "Drawing", nullptr));
        numOfCorners->setPlaceholderText(QCoreApplication::translate("main_window", "\320\247\320\270\321\201\320\273\320\276 \321\203\320\263\320\273\320\276\320\262", nullptr));
        label->setText(QCoreApplication::translate("main_window", "perimetr - ", nullptr));
        label_2->setText(QCoreApplication::translate("main_window", "square -", nullptr));
        perimetr->setText(QString());
        square->setText(QString());
        exit->setText(QCoreApplication::translate("main_window", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class main_window : public Ui_main_window {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
