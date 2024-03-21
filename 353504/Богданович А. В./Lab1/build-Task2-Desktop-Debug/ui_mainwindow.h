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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_moveUp;
    QPushButton *pushButton_moveDown;
    QPushButton *pushButton_moveRight;
    QPushButton *pushButton_moveLeft;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QGraphicsView *graphicsView;
    QLabel *areaLabel;
    QLabel *perimeterLabel;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QCheckBox *checkBox;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1850, 1030);
        MainWindow->setMinimumSize(QSize(1850, 1030));
        MainWindow->setMaximumSize(QSize(1850, 1030));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(1360, 70, 400, 30));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(1360, 30, 81, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1360, 120, 400, 40));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8(""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(1360, 300, 101, 21));
        label_2->setFont(font);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(1360, 330, 111, 21));
        label_3->setFont(font);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(1360, 360, 141, 21));
        label_4->setFont(font);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(1520, 360, 21, 21));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(1670, 360, 21, 21));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(1400, 530, 100, 100));
        QFont font1;
        font1.setPointSize(36);
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(1620, 530, 100, 100));
        pushButton_3->setFont(font1);
        pushButton_moveUp = new QPushButton(centralwidget);
        pushButton_moveUp->setObjectName("pushButton_moveUp");
        pushButton_moveUp->setGeometry(QRect(1510, 530, 100, 100));
        pushButton_moveUp->setFont(font1);
        pushButton_moveDown = new QPushButton(centralwidget);
        pushButton_moveDown->setObjectName("pushButton_moveDown");
        pushButton_moveDown->setGeometry(QRect(1510, 640, 100, 100));
        pushButton_moveDown->setFont(font1);
        pushButton_moveRight = new QPushButton(centralwidget);
        pushButton_moveRight->setObjectName("pushButton_moveRight");
        pushButton_moveRight->setGeometry(QRect(1620, 640, 100, 100));
        pushButton_moveRight->setFont(font1);
        pushButton_moveLeft = new QPushButton(centralwidget);
        pushButton_moveLeft->setObjectName("pushButton_moveLeft");
        pushButton_moveLeft->setGeometry(QRect(1400, 640, 100, 100));
        pushButton_moveLeft->setFont(font1);
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(1450, 750, 100, 100));
        pushButton_8->setFont(font1);
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(1570, 750, 100, 100));
        pushButton_9->setFont(font1);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(30, 30, 1300, 950));
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        areaLabel = new QLabel(centralwidget);
        areaLabel->setObjectName("areaLabel");
        areaLabel->setGeometry(QRect(1520, 300, 181, 17));
        areaLabel->setFont(font);
        perimeterLabel = new QLabel(centralwidget);
        perimeterLabel->setObjectName("perimeterLabel");
        perimeterLabel->setGeometry(QRect(1520, 330, 191, 17));
        perimeterLabel->setFont(font);
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setGeometry(QRect(1550, 360, 81, 26));
        spinBox->setFont(font);
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setGeometry(QRect(1710, 360, 81, 26));
        spinBox_2->setFont(font);
        spinBox_2->setMinimum(-1000);
        spinBox_2->setMaximum(1000);
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(1360, 180, 400, 40));
        pushButton_4->setFont(font);
        pushButton_4->setStyleSheet(QString::fromUtf8(""));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(1360, 240, 400, 40));
        pushButton_5->setFont(font);
        pushButton_5->setStyleSheet(QString::fromUtf8(""));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(1360, 910, 400, 40));
        pushButton_6->setFont(font);
        pushButton_6->setStyleSheet(QString::fromUtf8(""));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");
        checkBox->setGeometry(QRect(1360, 490, 251, 23));
        checkBox->setFont(font);
        checkBox->setTristate(false);
        radioButton = new QRadioButton(centralwidget);
        radioButton->setObjectName("radioButton");
        radioButton->setGeometry(QRect(1360, 410, 281, 23));
        radioButton->setFont(font);
        radioButton->setChecked(true);
        radioButton_2 = new QRadioButton(centralwidget);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setGeometry(QRect(1360, 440, 331, 23));
        radioButton_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1850, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Task 2", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "\320\232\321\200\321\203\320\263", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "\320\242\321\200\320\260\320\277\320\265\321\206\320\270\321\217", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt;\">\320\244\320\270\320\263\321\203\321\200\321\213</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214: ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\246\320\265\320\275\321\202\321\200 \320\274\320\260\321\201\321\201: ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">X</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:16pt; font-weight:700;\">Y</span></p></body></html>", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "\342\237\262", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "\342\237\263", nullptr));
        pushButton_moveUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        pushButton_moveDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        pushButton_moveRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        pushButton_moveLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        areaLabel->setText(QString());
        perimeterLabel->setText(QString());
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\262\320\265\321\201\321\202\320\270 \320\272\320\260\320\274\320\265\321\200\321\203 \320\275\320\260 \321\204\320\270\320\263\321\203\321\200\321\203", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \321\206\320\265\320\275\321\202\321\200 \320\274\320\260\321\201\321\201", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\277\320\276 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\260\320\274", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\272\320\260\321\200\320\260\320\275\320\264\320\260\321\210\320\276\320\274 \320\275\320\260 \320\272\320\260\320\275\320\262\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
