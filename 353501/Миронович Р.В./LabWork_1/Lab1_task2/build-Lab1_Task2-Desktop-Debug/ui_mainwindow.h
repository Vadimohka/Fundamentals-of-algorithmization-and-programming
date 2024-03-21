/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListView *Background;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *ClearButton;
    QCheckBox *checkBox;
    QRadioButton *CircleButton;
    QRadioButton *TriangleButton;
    QRadioButton *HexagonButton;
    QRadioButton *SqauerButton;
    QRadioButton *RectangleButton;
    QRadioButton *RhombusButton;
    QRadioButton *PolylineButton;
    QRadioButton *Star5Button;
    QRadioButton *Star6Button;
    QRadioButton *Star8Button;
    QRadioButton *MoveButton;
    QRadioButton *DrawButton;
    QPushButton *LeftRotateButton;
    QPushButton *RightRotateButton;
    QPushButton *PlusButton;
    QPushButton *MinusButton;
    QRadioButton *Star7Button;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QStatusBar *statusbar;
    QButtonGroup *Rotate;
    QButtonGroup *Figure;
    QButtonGroup *Size;
    QButtonGroup *Mode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1400, 750);
        MainWindow->setMinimumSize(QSize(1400, 750));
        MainWindow->setMaximumSize(QSize(1400, 750));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QListView(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setEnabled(true);
        Background->setGeometry(QRect(1080, 0, 321, 711));
        Background->setAcceptDrops(false);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1180, 420, 171, 16));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1160, 450, 171, 16));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(1170, 480, 201, 16));
        ClearButton = new QPushButton(centralwidget);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(1080, 620, 201, 91));
        ClearButton->setStyleSheet(QString::fromUtf8("background-color:rgb(255, 0, 0);\n"
"color : rgb(0, 0, 0)"));
        ClearButton->setIconSize(QSize(16, 16));
        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setEnabled(false);
        checkBox->setGeometry(QRect(1080, 230, 321, 16));
        checkBox->setCheckable(true);
        checkBox->setAutoRepeat(false);
        checkBox->setAutoExclusive(false);
        checkBox->setTristate(false);
        CircleButton = new QRadioButton(centralwidget);
        Figure = new QButtonGroup(MainWindow);
        Figure->setObjectName(QString::fromUtf8("Figure"));
        Figure->addButton(CircleButton);
        CircleButton->setObjectName(QString::fromUtf8("CircleButton"));
        CircleButton->setGeometry(QRect(1080, 200, 321, 20));
        CircleButton->setChecked(true);
        CircleButton->setAutoExclusive(true);
        TriangleButton = new QRadioButton(centralwidget);
        Figure->addButton(TriangleButton);
        TriangleButton->setObjectName(QString::fromUtf8("TriangleButton"));
        TriangleButton->setGeometry(QRect(1080, 20, 341, 21));
        TriangleButton->setChecked(false);
        HexagonButton = new QRadioButton(centralwidget);
        Figure->addButton(HexagonButton);
        HexagonButton->setObjectName(QString::fromUtf8("HexagonButton"));
        HexagonButton->setGeometry(QRect(1080, 80, 301, 16));
        SqauerButton = new QRadioButton(centralwidget);
        Figure->addButton(SqauerButton);
        SqauerButton->setObjectName(QString::fromUtf8("SqauerButton"));
        SqauerButton->setGeometry(QRect(1080, 110, 321, 16));
        RectangleButton = new QRadioButton(centralwidget);
        Figure->addButton(RectangleButton);
        RectangleButton->setObjectName(QString::fromUtf8("RectangleButton"));
        RectangleButton->setGeometry(QRect(1080, 50, 301, 16));
        RhombusButton = new QRadioButton(centralwidget);
        Figure->addButton(RhombusButton);
        RhombusButton->setObjectName(QString::fromUtf8("RhombusButton"));
        RhombusButton->setGeometry(QRect(1080, 140, 281, 16));
        PolylineButton = new QRadioButton(centralwidget);
        Figure->addButton(PolylineButton);
        PolylineButton->setObjectName(QString::fromUtf8("PolylineButton"));
        PolylineButton->setGeometry(QRect(1080, 170, 341, 20));
        Star5Button = new QRadioButton(centralwidget);
        Figure->addButton(Star5Button);
        Star5Button->setObjectName(QString::fromUtf8("Star5Button"));
        Star5Button->setGeometry(QRect(1080, 360, 311, 20));
        Star6Button = new QRadioButton(centralwidget);
        Figure->addButton(Star6Button);
        Star6Button->setObjectName(QString::fromUtf8("Star6Button"));
        Star6Button->setGeometry(QRect(1080, 330, 331, 20));
        Star8Button = new QRadioButton(centralwidget);
        Figure->addButton(Star8Button);
        Star8Button->setObjectName(QString::fromUtf8("Star8Button"));
        Star8Button->setGeometry(QRect(1080, 270, 401, 16));
        MoveButton = new QRadioButton(centralwidget);
        Mode = new QButtonGroup(MainWindow);
        Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->addButton(MoveButton);
        MoveButton->setObjectName(QString::fromUtf8("MoveButton"));
        MoveButton->setGeometry(QRect(1290, 670, 121, 31));
        DrawButton = new QRadioButton(centralwidget);
        Mode->addButton(DrawButton);
        DrawButton->setObjectName(QString::fromUtf8("DrawButton"));
        DrawButton->setGeometry(QRect(1290, 630, 111, 31));
        DrawButton->setChecked(true);
        LeftRotateButton = new QPushButton(centralwidget);
        Rotate = new QButtonGroup(MainWindow);
        Rotate->setObjectName(QString::fromUtf8("Rotate"));
        Rotate->addButton(LeftRotateButton);
        LeftRotateButton->setObjectName(QString::fromUtf8("LeftRotateButton"));
        LeftRotateButton->setGeometry(QRect(1260, 560, 141, 31));
        RightRotateButton = new QPushButton(centralwidget);
        Rotate->addButton(RightRotateButton);
        RightRotateButton->setObjectName(QString::fromUtf8("RightRotateButton"));
        RightRotateButton->setGeometry(QRect(1080, 560, 181, 31));
        PlusButton = new QPushButton(centralwidget);
        Size = new QButtonGroup(MainWindow);
        Size->setObjectName(QString::fromUtf8("Size"));
        Size->addButton(PlusButton);
        PlusButton->setObjectName(QString::fromUtf8("PlusButton"));
        PlusButton->setGeometry(QRect(1080, 590, 181, 31));
        PlusButton->setAutoDefault(false);
        MinusButton = new QPushButton(centralwidget);
        Size->addButton(MinusButton);
        MinusButton->setObjectName(QString::fromUtf8("MinusButton"));
        MinusButton->setGeometry(QRect(1260, 590, 141, 31));
        Star7Button = new QRadioButton(centralwidget);
        Figure->addButton(Star7Button);
        Star7Button->setObjectName(QString::fromUtf8("Star7Button"));
        Star7Button->setGeometry(QRect(1080, 300, 351, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1080, 410, 121, 31));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1080, 440, 66, 32));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(1080, 470, 81, 31));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(1160, 530, 191, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1400, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        ClearButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 \321\202\320\276\321\207\320\272\321\203(\320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214)", nullptr));
        CircleButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        TriangleButton->setText(QCoreApplication::translate("MainWindow", "\320\242\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        HexagonButton->setText(QCoreApplication::translate("MainWindow", "\320\250\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        SqauerButton->setText(QCoreApplication::translate("MainWindow", "\320\232\320\262\320\260\320\264\321\200\320\260\321\202", nullptr));
        RectangleButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", nullptr));
        RhombusButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\276\320\274\320\261", nullptr));
        PolylineButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\320\273\320\272\320\260", nullptr));
        Star5Button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(5)", nullptr));
        Star6Button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(6)", nullptr));
        Star8Button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(8)", nullptr));
        MoveButton->setText(QCoreApplication::translate("MainWindow", "\320\224\320\262\320\270\320\263\320\260\321\202\321\214", nullptr));
        DrawButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\270\321\201\320\276\320\262\320\260\321\202\321\214", nullptr));
        LeftRotateButton->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        RightRotateButton->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        PlusButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        MinusButton->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        Star7Button->setText(QCoreApplication::translate("MainWindow", "\320\227\320\262\320\265\320\267\320\264\320\260(7)", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\276\321\200\320\264\320\270\320\275\320\260\321\202\321\213:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\237\320\273\320\276\321\211\320\260\320\264\321\214:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\274\320\265\321\202\321\200:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\260\321\202\321\214/\320\270\320\267\320\274\320\265\320\275\321\217\321\202\321\214 \321\200\320\260\320\267\320\274\320\265\321\200", nullptr));
        menu->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
