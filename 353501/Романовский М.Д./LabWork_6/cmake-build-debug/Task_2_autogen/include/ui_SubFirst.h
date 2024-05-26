/********************************************************************************
** Form generated from reading UI file 'SubFirst.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBFIRST_H
#define UI_SUBFIRST_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubFirst
{
public:
    QGridLayout *gridLayout;
    QPushButton *saveBtn;
    QPushButton *openBtn;
    QLineEdit *inp;
    QLabel *out;

    void setupUi(QWidget *SubFirst)
    {
        if (SubFirst->objectName().isEmpty())
            SubFirst->setObjectName("SubFirst");
        SubFirst->resize(400, 333);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SubFirst->sizePolicy().hasHeightForWidth());
        SubFirst->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SubFirst);
        gridLayout->setObjectName("gridLayout");
        saveBtn = new QPushButton(SubFirst);
        saveBtn->setObjectName("saveBtn");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveBtn->setIcon(icon);

        gridLayout->addWidget(saveBtn, 1, 0, 1, 1);

        openBtn = new QPushButton(SubFirst);
        openBtn->setObjectName("openBtn");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openBtn->setIcon(icon1);

        gridLayout->addWidget(openBtn, 1, 1, 1, 1);

        inp = new QLineEdit(SubFirst);
        inp->setObjectName("inp");

        gridLayout->addWidget(inp, 0, 0, 1, 2);

        out = new QLabel(SubFirst);
        out->setObjectName("out");
        out->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(out, 2, 0, 1, 2);


        retranslateUi(SubFirst);

        QMetaObject::connectSlotsByName(SubFirst);
    } // setupUi

    void retranslateUi(QWidget *SubFirst)
    {
        SubFirst->setWindowTitle(QCoreApplication::translate("SubFirst", "Form", nullptr));
        saveBtn->setText(QCoreApplication::translate("SubFirst", "Save", nullptr));
        openBtn->setText(QCoreApplication::translate("SubFirst", "Open", nullptr));
        out->setText(QCoreApplication::translate("SubFirst", "Open file to view", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubFirst: public Ui_SubFirst {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBFIRST_H
