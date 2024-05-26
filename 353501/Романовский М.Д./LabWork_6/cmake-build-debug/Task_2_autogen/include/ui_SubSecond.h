/********************************************************************************
** Form generated from reading UI file 'SubSecond.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBSECOND_H
#define UI_SUBSECOND_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubSecond
{
public:
    QGridLayout *gridLayout;
    QTableWidget *mainTable;
    QPushButton *saveBtn;
    QPushButton *openBtn;
    QLabel *label;
    QSpinBox *countInp;

    void setupUi(QWidget *SubSecond)
    {
        if (SubSecond->objectName().isEmpty())
            SubSecond->setObjectName("SubSecond");
        SubSecond->resize(400, 333);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SubSecond->sizePolicy().hasHeightForWidth());
        SubSecond->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SubSecond);
        gridLayout->setObjectName("gridLayout");
        mainTable = new QTableWidget(SubSecond);
        if (mainTable->columnCount() < 1)
            mainTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        mainTable->setObjectName("mainTable");

        gridLayout->addWidget(mainTable, 2, 0, 1, 2);

        saveBtn = new QPushButton(SubSecond);
        saveBtn->setObjectName("saveBtn");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveBtn->setIcon(icon);

        gridLayout->addWidget(saveBtn, 0, 0, 1, 1);

        openBtn = new QPushButton(SubSecond);
        openBtn->setObjectName("openBtn");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openBtn->setIcon(icon1);

        gridLayout->addWidget(openBtn, 0, 1, 1, 1);

        label = new QLabel(SubSecond);
        label->setObjectName("label");

        gridLayout->addWidget(label, 1, 0, 1, 1);

        countInp = new QSpinBox(SubSecond);
        countInp->setObjectName("countInp");

        gridLayout->addWidget(countInp, 1, 1, 1, 1);


        retranslateUi(SubSecond);

        QMetaObject::connectSlotsByName(SubSecond);
    } // setupUi

    void retranslateUi(QWidget *SubSecond)
    {
        SubSecond->setWindowTitle(QCoreApplication::translate("SubSecond", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = mainTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SubSecond", "Value", nullptr));
        saveBtn->setText(QCoreApplication::translate("SubSecond", "Save", nullptr));
        openBtn->setText(QCoreApplication::translate("SubSecond", "Open", nullptr));
        label->setText(QCoreApplication::translate("SubSecond", "Number Of Elements", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubSecond: public Ui_SubSecond {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBSECOND_H
