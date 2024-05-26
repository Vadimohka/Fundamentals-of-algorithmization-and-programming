/********************************************************************************
** Form generated from reading UI file 'SubThird.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBTHIRD_H
#define UI_SUBTHIRD_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubThird
{
public:
    QGridLayout *gridLayout;
    QPushButton *saveBtn;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *nameInp;
    QLabel *label_2;
    QSpinBox *ageInp;
    QLabel *label_3;
    QDoubleSpinBox *bragsPerDayInp;
    QLabel *label_4;
    QLineEdit *creditRatingInp;
    QLabel *label_5;
    QCheckBox *evilInp;
    QLabel *label_6;
    QDoubleSpinBox *networth0Inp;
    QLabel *label_7;
    QDoubleSpinBox *networth1Inp;
    QLabel *label_8;
    QDoubleSpinBox *networth2Inp;
    QPushButton *openBtn;
    QTableWidget *mainTable;

    void setupUi(QWidget *SubThird)
    {
        if (SubThird->objectName().isEmpty())
            SubThird->setObjectName("SubThird");
        SubThird->resize(880, 553);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(SubThird->sizePolicy().hasHeightForWidth());
        SubThird->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SubThird);
        gridLayout->setObjectName("gridLayout");
        saveBtn = new QPushButton(SubThird);
        saveBtn->setObjectName("saveBtn");
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("document-save");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        saveBtn->setIcon(icon);

        gridLayout->addWidget(saveBtn, 3, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label = new QLabel(SubThird);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        nameInp = new QLineEdit(SubThird);
        nameInp->setObjectName("nameInp");
        nameInp->setMaxLength(250);

        formLayout->setWidget(0, QFormLayout::FieldRole, nameInp);

        label_2 = new QLabel(SubThird);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        ageInp = new QSpinBox(SubThird);
        ageInp->setObjectName("ageInp");
        ageInp->setValue(42);

        formLayout->setWidget(1, QFormLayout::FieldRole, ageInp);

        label_3 = new QLabel(SubThird);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        bragsPerDayInp = new QDoubleSpinBox(SubThird);
        bragsPerDayInp->setObjectName("bragsPerDayInp");
        bragsPerDayInp->setValue(50.000000000000000);

        formLayout->setWidget(2, QFormLayout::FieldRole, bragsPerDayInp);

        label_4 = new QLabel(SubThird);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        creditRatingInp = new QLineEdit(SubThird);
        creditRatingInp->setObjectName("creditRatingInp");

        formLayout->setWidget(3, QFormLayout::FieldRole, creditRatingInp);

        label_5 = new QLabel(SubThird);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        evilInp = new QCheckBox(SubThird);
        evilInp->setObjectName("evilInp");

        formLayout->setWidget(4, QFormLayout::FieldRole, evilInp);

        label_6 = new QLabel(SubThird);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        networth0Inp = new QDoubleSpinBox(SubThird);
        networth0Inp->setObjectName("networth0Inp");
        networth0Inp->setMinimum(1.000000000000000);
        networth0Inp->setMaximum(1000000.000000000000000);
        networth0Inp->setValue(80.000000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, networth0Inp);

        label_7 = new QLabel(SubThird);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        networth1Inp = new QDoubleSpinBox(SubThird);
        networth1Inp->setObjectName("networth1Inp");
        networth1Inp->setMinimum(1.000000000000000);
        networth1Inp->setMaximum(1000000.000000000000000);
        networth1Inp->setValue(150.000000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, networth1Inp);

        label_8 = new QLabel(SubThird);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        networth2Inp = new QDoubleSpinBox(SubThird);
        networth2Inp->setObjectName("networth2Inp");
        networth2Inp->setMinimum(1.000000000000000);
        networth2Inp->setMaximum(1000000.000000000000000);
        networth2Inp->setValue(400.000000000000000);

        formLayout->setWidget(7, QFormLayout::FieldRole, networth2Inp);


        gridLayout->addLayout(formLayout, 2, 0, 1, 2);

        openBtn = new QPushButton(SubThird);
        openBtn->setObjectName("openBtn");
        QIcon icon1;
        iconThemeName = QString::fromUtf8("document-open");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Normal, QIcon::Off);
        }
        openBtn->setIcon(icon1);

        gridLayout->addWidget(openBtn, 3, 1, 1, 1);

        mainTable = new QTableWidget(SubThird);
        if (mainTable->columnCount() < 8)
            mainTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        mainTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        mainTable->setObjectName("mainTable");
        mainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mainTable->setSelectionMode(QAbstractItemView::NoSelection);
        mainTable->setSelectionBehavior(QAbstractItemView::SelectRows);

        gridLayout->addWidget(mainTable, 4, 0, 1, 2);


        retranslateUi(SubThird);

        QMetaObject::connectSlotsByName(SubThird);
    } // setupUi

    void retranslateUi(QWidget *SubThird)
    {
        SubThird->setWindowTitle(QCoreApplication::translate("SubThird", "Form", nullptr));
        saveBtn->setText(QCoreApplication::translate("SubThird", "Append", nullptr));
        label->setText(QCoreApplication::translate("SubThird", "Name", nullptr));
        nameInp->setText(QCoreApplication::translate("SubThird", "Melon Tusk", nullptr));
        label_2->setText(QCoreApplication::translate("SubThird", "Age", nullptr));
        label_3->setText(QCoreApplication::translate("SubThird", "Brags Per Day", nullptr));
        label_4->setText(QCoreApplication::translate("SubThird", "Credit Rating", nullptr));
        creditRatingInp->setText(QCoreApplication::translate("SubThird", "D", nullptr));
        label_5->setText(QCoreApplication::translate("SubThird", "is Evil", nullptr));
        evilInp->setText(QString());
        label_6->setText(QCoreApplication::translate("SubThird", "Pre Last Year Net Worth (millions)", nullptr));
        label_7->setText(QCoreApplication::translate("SubThird", "Last Year Net Worth (millions)", nullptr));
        label_8->setText(QCoreApplication::translate("SubThird", "This Year Net Worth (millions)", nullptr));
        openBtn->setText(QCoreApplication::translate("SubThird", "Open", nullptr));
        QTableWidgetItem *___qtablewidgetitem = mainTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("SubThird", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = mainTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("SubThird", "Age", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = mainTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("SubThird", "Brags Per Day", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = mainTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("SubThird", "Credit Rating", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = mainTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("SubThird", "Is Evil", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = mainTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("SubThird", "NetWorth(pre-last year)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = mainTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("SubThird", "NetWorth(last year)", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = mainTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("SubThird", "NetWorth(this year)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SubThird: public Ui_SubThird {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBTHIRD_H
