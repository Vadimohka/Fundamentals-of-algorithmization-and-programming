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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *heapSortButton;
    QRadioButton *mergeSortButton;
    QRadioButton *quickSortButton;
    QRadioButton *interpolationSortButton;
    QRadioButton *binSearchButton;
    QPushButton *startSort;
    QLabel *label_2;
    QLineEdit *lineSpeed;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QPushButton *addElement;
    QPushButton *deleteButton;
    QPushButton *deleteAllButton;
    QLineEdit *lineElement;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(894, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        heapSortButton = new QRadioButton(centralwidget);
        heapSortButton->setObjectName("heapSortButton");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        heapSortButton->setFont(font);
        heapSortButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(heapSortButton);

        mergeSortButton = new QRadioButton(centralwidget);
        mergeSortButton->setObjectName("mergeSortButton");
        mergeSortButton->setFont(font);
        mergeSortButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(mergeSortButton);

        quickSortButton = new QRadioButton(centralwidget);
        quickSortButton->setObjectName("quickSortButton");
        quickSortButton->setFont(font);
        quickSortButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(quickSortButton);

        interpolationSortButton = new QRadioButton(centralwidget);
        interpolationSortButton->setObjectName("interpolationSortButton");
        interpolationSortButton->setFont(font);
        interpolationSortButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(interpolationSortButton);

        binSearchButton = new QRadioButton(centralwidget);
        binSearchButton->setObjectName("binSearchButton");
        binSearchButton->setFont(font);
        binSearchButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(binSearchButton);

        startSort = new QPushButton(centralwidget);
        startSort->setObjectName("startSort");
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        startSort->setFont(font1);
        startSort->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(startSort);


        gridLayout->addLayout(horizontalLayout, 4, 0, 1, 3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 6, 0, 1, 1);

        lineSpeed = new QLineEdit(centralwidget);
        lineSpeed->setObjectName("lineSpeed");
        QFont font2;
        font2.setPointSize(12);
        lineSpeed->setFont(font2);
        lineSpeed->setReadOnly(true);

        gridLayout->addWidget(lineSpeed, 6, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setFont(font1);

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName("spinBox");
        spinBox->setFont(font2);
        spinBox->setCursor(QCursor(Qt::UpArrowCursor));
        spinBox->setStyleSheet(QString::fromUtf8(""));
        spinBox->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox->setMinimum(-99);
        spinBox->setMaximum(99);

        horizontalLayout_2->addWidget(spinBox);

        addElement = new QPushButton(centralwidget);
        addElement->setObjectName("addElement");
        addElement->setFont(font1);
        addElement->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(addElement);

        deleteButton = new QPushButton(centralwidget);
        deleteButton->setObjectName("deleteButton");
        deleteButton->setFont(font1);
        deleteButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(deleteButton);

        deleteAllButton = new QPushButton(centralwidget);
        deleteAllButton->setObjectName("deleteAllButton");
        deleteAllButton->setFont(font1);
        deleteAllButton->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(deleteAllButton);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 3);

        lineElement = new QLineEdit(centralwidget);
        lineElement->setObjectName("lineElement");
        lineElement->setFont(font2);
        lineElement->setReadOnly(true);

        gridLayout->addWidget(lineElement, 3, 0, 1, 2);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setInteractive(true);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 3);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setFont(font2);
        spinBox_2->setCursor(QCursor(Qt::UpArrowCursor));
        spinBox_2->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBox_2->setProperty("showGroupSeparator", QVariant(false));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(200);
        spinBox_2->setSingleStep(1);
        spinBox_2->setValue(1);

        horizontalLayout_3->addWidget(spinBox_2);


        gridLayout->addLayout(horizontalLayout_3, 3, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 894, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SORT", nullptr));
        heapSortButton->setText(QCoreApplication::translate("MainWindow", "Heap Sort", nullptr));
        mergeSortButton->setText(QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        quickSortButton->setText(QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        interpolationSortButton->setText(QCoreApplication::translate("MainWindow", "interpolation Sort", nullptr));
        binSearchButton->setText(QCoreApplication::translate("MainWindow", "BinSearch", nullptr));
        startSort->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\270: ", nullptr));
        lineSpeed->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202: ", nullptr));
        spinBox->setSuffix(QString());
        addElement->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\266\320\274\320\270 \320\264\320\273\321\217 \320\264\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\270\320\271 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        deleteAllButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\320\276\321\201\321\202\321\214 \320\262\320\270\320\267\321\203\320\260\320\273\320\270\320\267\320\260\321\206\320\270\320\270: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
