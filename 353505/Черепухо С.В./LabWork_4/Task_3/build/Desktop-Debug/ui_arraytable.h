/********************************************************************************
** Form generated from reading UI file 'arraytable.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ARRAYTABLE_H
#define UI_ARRAYTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ArrayTable
{
public:
    QHBoxLayout *horizontalLayout_4;
    QTableWidget *tableWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *randPushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *indexLabel;
    QSpinBox *indexSpinBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *valueLabel;
    QDoubleSpinBox *valueSpinBox;
    QHBoxLayout *horizontalLayout;
    QLabel *sizeLabel;
    QSpinBox *sizeSpinBox;

    void setupUi(QWidget *ArrayTable)
    {
        if (ArrayTable->objectName().isEmpty())
            ArrayTable->setObjectName("ArrayTable");
        ArrayTable->resize(491, 714);
        QSizePolicy sizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ArrayTable->sizePolicy().hasHeightForWidth());
        ArrayTable->setSizePolicy(sizePolicy);
        horizontalLayout_4 = new QHBoxLayout(ArrayTable);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        tableWidget = new QTableWidget(ArrayTable);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(tableWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        randPushButton = new QPushButton(ArrayTable);
        randPushButton->setObjectName("randPushButton");

        verticalLayout->addWidget(randPushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        indexLabel = new QLabel(ArrayTable);
        indexLabel->setObjectName("indexLabel");
        indexLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(indexLabel);

        indexSpinBox = new QSpinBox(ArrayTable);
        indexSpinBox->setObjectName("indexSpinBox");

        horizontalLayout_2->addWidget(indexSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        valueLabel = new QLabel(ArrayTable);
        valueLabel->setObjectName("valueLabel");
        valueLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(valueLabel);

        valueSpinBox = new QDoubleSpinBox(ArrayTable);
        valueSpinBox->setObjectName("valueSpinBox");

        horizontalLayout_3->addWidget(valueSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        sizeLabel = new QLabel(ArrayTable);
        sizeLabel->setObjectName("sizeLabel");
        sizeLabel->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(sizeLabel);

        sizeSpinBox = new QSpinBox(ArrayTable);
        sizeSpinBox->setObjectName("sizeSpinBox");
        sizeSpinBox->setMaximum(10000);

        horizontalLayout->addWidget(sizeSpinBox);


        verticalLayout->addLayout(horizontalLayout);


        horizontalLayout_4->addLayout(verticalLayout);


        retranslateUi(ArrayTable);

        QMetaObject::connectSlotsByName(ArrayTable);
    } // setupUi

    void retranslateUi(QWidget *ArrayTable)
    {
        ArrayTable->setWindowTitle(QCoreApplication::translate("ArrayTable", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ArrayTable", "Number", nullptr));
        randPushButton->setText(QCoreApplication::translate("ArrayTable", "Randomise values", nullptr));
        indexLabel->setText(QCoreApplication::translate("ArrayTable", "Index", nullptr));
        valueLabel->setText(QCoreApplication::translate("ArrayTable", "Value", nullptr));
        sizeLabel->setText(QCoreApplication::translate("ArrayTable", "Array's size:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ArrayTable: public Ui_ArrayTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ARRAYTABLE_H
