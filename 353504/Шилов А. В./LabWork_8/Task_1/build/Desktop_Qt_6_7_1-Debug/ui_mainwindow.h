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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTreeView *treeView;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbl_key;
    QSpinBox *spb_val;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbl_value;
    QLineEdit *lineEditText;
    QPushButton *bnt_add_item;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbl_del;
    QSpinBox *spb_delValue;
    QPushButton *bnt_remove;
    QHBoxLayout *horizontalLayout_4;
    QLabel *lbl_find;
    QSpinBox *spb_findValue;
    QPushButton *bnt_search;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QSpinBox *el_1;
    QLabel *label_3;
    QSpinBox *el_2;
    QPushButton *bnt_cnt_of_list;
    QPushButton *bnt_pre;
    QPushButton *bnt_post;
    QPushButton *bnt_in;
    QPushButton *bnt_add_subtree;
    QPushButton *bnt_remove_subtree;
    QTreeView *treeView_2;
    QLabel *label;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbl_key_2;
    QSpinBox *spb_val_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbl_value_2;
    QLineEdit *lineEditText_2;
    QPushButton *bnt_add_item_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1095, 722);
        QFont font;
        font.setFamilies({QString::fromUtf8("Ubuntu")});
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(true);
        MainWindow->setFont(font);
        MainWindow->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"font: 700 italic 15pt \"Ubuntu\";"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(740, 0, 341, 451));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(120, 0, 505, 451));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        lbl_key = new QLabel(layoutWidget);
        lbl_key->setObjectName("lbl_key");
        lbl_key->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout->addWidget(lbl_key);

        spb_val = new QSpinBox(layoutWidget);
        spb_val->setObjectName("spb_val");
        spb_val->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout->addWidget(spb_val);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lbl_value = new QLabel(layoutWidget);
        lbl_value->setObjectName("lbl_value");
        lbl_value->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_2->addWidget(lbl_value);

        lineEditText = new QLineEdit(layoutWidget);
        lineEditText->setObjectName("lineEditText");

        horizontalLayout_2->addWidget(lineEditText);


        verticalLayout->addLayout(horizontalLayout_2);

        bnt_add_item = new QPushButton(layoutWidget);
        bnt_add_item->setObjectName("bnt_add_item");
        bnt_add_item->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_add_item);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        lbl_del = new QLabel(layoutWidget);
        lbl_del->setObjectName("lbl_del");
        lbl_del->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_3->addWidget(lbl_del);

        spb_delValue = new QSpinBox(layoutWidget);
        spb_delValue->setObjectName("spb_delValue");
        spb_delValue->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_3->addWidget(spb_delValue);

        bnt_remove = new QPushButton(layoutWidget);
        bnt_remove->setObjectName("bnt_remove");
        bnt_remove->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_3->addWidget(bnt_remove);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        lbl_find = new QLabel(layoutWidget);
        lbl_find->setObjectName("lbl_find");
        lbl_find->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_4->addWidget(lbl_find);

        spb_findValue = new QSpinBox(layoutWidget);
        spb_findValue->setObjectName("spb_findValue");
        spb_findValue->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_4->addWidget(spb_findValue);

        bnt_search = new QPushButton(layoutWidget);
        bnt_search->setObjectName("bnt_search");
        bnt_search->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_4->addWidget(bnt_search);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_7->addWidget(label_2);

        el_1 = new QSpinBox(layoutWidget);
        el_1->setObjectName("el_1");
        el_1->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_7->addWidget(el_1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_7->addWidget(label_3);

        el_2 = new QSpinBox(layoutWidget);
        el_2->setObjectName("el_2");
        el_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_7->addWidget(el_2);


        verticalLayout->addLayout(horizontalLayout_7);

        bnt_cnt_of_list = new QPushButton(layoutWidget);
        bnt_cnt_of_list->setObjectName("bnt_cnt_of_list");
        bnt_cnt_of_list->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_cnt_of_list);

        bnt_pre = new QPushButton(layoutWidget);
        bnt_pre->setObjectName("bnt_pre");
        bnt_pre->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_pre);

        bnt_post = new QPushButton(layoutWidget);
        bnt_post->setObjectName("bnt_post");
        bnt_post->setMinimumSize(QSize(438, 31));
        bnt_post->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_post);

        bnt_in = new QPushButton(layoutWidget);
        bnt_in->setObjectName("bnt_in");
        bnt_in->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_in);

        bnt_add_subtree = new QPushButton(layoutWidget);
        bnt_add_subtree->setObjectName("bnt_add_subtree");
        bnt_add_subtree->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_add_subtree);

        bnt_remove_subtree = new QPushButton(layoutWidget);
        bnt_remove_subtree->setObjectName("bnt_remove_subtree");
        bnt_remove_subtree->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout->addWidget(bnt_remove_subtree);

        treeView_2 = new QTreeView(centralwidget);
        treeView_2->setObjectName("treeView_2");
        treeView_2->setGeometry(QRect(740, 500, 341, 181));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(860, 470, 111, 17));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Ubuntu Sans")});
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(120, 520, 441, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        lbl_key_2 = new QLabel(layoutWidget1);
        lbl_key_2->setObjectName("lbl_key_2");
        lbl_key_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_5->addWidget(lbl_key_2);

        spb_val_2 = new QSpinBox(layoutWidget1);
        spb_val_2->setObjectName("spb_val_2");
        spb_val_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_5->addWidget(spb_val_2);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        lbl_value_2 = new QLabel(layoutWidget1);
        lbl_value_2->setObjectName("lbl_value_2");
        lbl_value_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        horizontalLayout_6->addWidget(lbl_value_2);

        lineEditText_2 = new QLineEdit(layoutWidget1);
        lineEditText_2->setObjectName("lineEditText_2");

        horizontalLayout_6->addWidget(lineEditText_2);


        verticalLayout_2->addLayout(horizontalLayout_6);

        bnt_add_item_2 = new QPushButton(layoutWidget1);
        bnt_add_item_2->setObjectName("bnt_add_item_2");
        bnt_add_item_2->setStyleSheet(QString::fromUtf8("font: 14pt \"Ubuntu Sans\";"));

        verticalLayout_2->addWidget(bnt_add_item_2);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lbl_key->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">\320\232\320\273\321\216\321\207</p></body></html>", nullptr));
        lbl_value->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\241\321\202\321\200\320\276\320\272\320\260 \321\202\320\265\320\272\321\201\321\202\320\260</p></body></html>", nullptr));
        bnt_add_item->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
        lbl_del->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203:</p></body></html>", nullptr));
        bnt_remove->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        lbl_find->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\235\320\260\320\271\321\202\320\270 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203:</p></body></html>", nullptr));
        bnt_search->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\271\321\202\320\270", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\232\320\273\321\216\321\207 1:</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\320\232\320\273\321\216\321\207 2:</p></body></html>", nullptr));
        bnt_cnt_of_list->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\275\320\260\320\270\320\274\320\265\320\275\321\214\321\210\320\270\320\271 \320\272\320\273\321\216\321\207", nullptr));
        bnt_pre->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\272\320\273\321\216\321\207\320\270 \321\201 \320\275\320\260\321\207\320\260\320\273\320\260", nullptr));
#if QT_CONFIG(tooltip)
        bnt_post->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        bnt_post->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\272\320\273\321\216\321\207\320\270 \321\201 \320\272\320\276\320\275\321\206\320\260", nullptr));
        bnt_in->setText(QCoreApplication::translate("MainWindow", "\320\222\321\213\320\262\320\265\321\201\321\202\320\270 \320\272\320\273\321\216\321\207\320\270 \320\262 \320\277\320\276\321\200\321\217\320\264\320\272\320\265 \320\262\320\276\320\267\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\217", nullptr));
        bnt_add_subtree->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\277\320\276\320\264\320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        bnt_remove_subtree->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276\320\264\320\264\320\265\321\200\320\265\320\262\320\276", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\264\320\264\320\265\321\200\320\265\320\262\320\276:", nullptr));
        lbl_key_2->setText(QCoreApplication::translate("MainWindow", "\320\232\320\273\321\216\321\207", nullptr));
        lbl_value_2->setText(QCoreApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 \321\202\320\265\320\272\321\201\321\202\320\260", nullptr));
        bnt_add_item_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
