/********************************************************************************
** Form generated from reading UI file 'SubFive.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBFIVE_H
#define UI_SUBFIVE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubFive
{
public:
    QGridLayout *gridLayout;
    QPushButton *openBtn;
    QLineEdit *inp;
    QPushButton *saveBtn;
    QTableWidget *out;

    void setupUi(QWidget *SubFive)
    {
        if (SubFive->objectName().isEmpty())
            SubFive->setObjectName("SubFive");
        SubFive->resize(400, 333);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SubFive->sizePolicy().hasHeightForWidth());
        SubFive->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SubFive);
        gridLayout->setObjectName("gridLayout");
        openBtn = new QPushButton(SubFive);
        openBtn->setObjectName("openBtn");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openBtn->setIcon(icon);

        gridLayout->addWidget(openBtn, 1, 1, 1, 1);

        inp = new QLineEdit(SubFive);
        inp->setObjectName("inp");

        gridLayout->addWidget(inp, 0, 0, 1, 2);

        saveBtn = new QPushButton(SubFive);
        saveBtn->setObjectName("saveBtn");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveBtn->setIcon(icon1);

        gridLayout->addWidget(saveBtn, 1, 0, 1, 1);

        out = new QTableWidget(SubFive);
        if (out->columnCount() < 1)
            out->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        out->setHorizontalHeaderItem(0, __qtablewidgetitem);
        out->setObjectName("out");

        gridLayout->addWidget(out, 2, 0, 1, 2);


        retranslateUi(SubFive);

        QMetaObject::connectSlotsByName(SubFive);
    } // setupUi

    void retranslateUi(QWidget *SubFive)
    {
        SubFive->setWindowTitle(QCoreApplication::translate("SubFive", "Form", nullptr));
        openBtn->setText(QCoreApplication::translate("SubFive", "Open", nullptr));
        saveBtn->setText(QCoreApplication::translate("SubFive", "Append", nullptr));
        QTableWidgetItem *___qtablewidgetitem = out->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SubFive", "Lines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubFive: public Ui_SubFive {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBFIVE_H
