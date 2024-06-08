/********************************************************************************
** Form generated from reading UI file 'PlayerMenu.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLAYERMENU_H
#define UI_PLAYERMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include "ClickableLabel.hpp"

QT_BEGIN_NAMESPACE

class Ui_PlayerMenu
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *player1Label;
    QHBoxLayout *horizontalLayout;
    QLabel *player1NameLabel;
    QLineEdit *player1Name;
    QHBoxLayout *horizontalLayout_3;
    QLabel *player1ColorLabel;
    ClickableLabel *player1Color;
    QVBoxLayout *verticalLayout_2;
    QLabel *player2Label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *player2NameLabel;
    QLineEdit *player2Name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *player2ColorLabel;
    ClickableLabel *player2Color;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *PlayerMenu)
    {
        if (PlayerMenu->objectName().isEmpty())
            PlayerMenu->setObjectName("PlayerMenu");
        PlayerMenu->resize(400, 300);
        verticalLayout_3 = new QVBoxLayout(PlayerMenu);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        player1Label = new QLabel(PlayerMenu);
        player1Label->setObjectName("player1Label");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        player1Label->setFont(font);
        player1Label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(player1Label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        player1NameLabel = new QLabel(PlayerMenu);
        player1NameLabel->setObjectName("player1NameLabel");

        horizontalLayout->addWidget(player1NameLabel);

        player1Name = new QLineEdit(PlayerMenu);
        player1Name->setObjectName("player1Name");

        horizontalLayout->addWidget(player1Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        player1ColorLabel = new QLabel(PlayerMenu);
        player1ColorLabel->setObjectName("player1ColorLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(player1ColorLabel->sizePolicy().hasHeightForWidth());
        player1ColorLabel->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(player1ColorLabel);

        player1Color = new ClickableLabel(PlayerMenu);
        player1Color->setObjectName("player1Color");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(player1Color->sizePolicy().hasHeightForWidth());
        player1Color->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(player1Color);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        player2Label = new QLabel(PlayerMenu);
        player2Label->setObjectName("player2Label");
        player2Label->setFont(font);
        player2Label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(player2Label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        player2NameLabel = new QLabel(PlayerMenu);
        player2NameLabel->setObjectName("player2NameLabel");

        horizontalLayout_2->addWidget(player2NameLabel);

        player2Name = new QLineEdit(PlayerMenu);
        player2Name->setObjectName("player2Name");

        horizontalLayout_2->addWidget(player2Name);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        player2ColorLabel = new QLabel(PlayerMenu);
        player2ColorLabel->setObjectName("player2ColorLabel");
        sizePolicy.setHeightForWidth(player2ColorLabel->sizePolicy().hasHeightForWidth());
        player2ColorLabel->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(player2ColorLabel);

        player2Color = new ClickableLabel(PlayerMenu);
        player2Color->setObjectName("player2Color");
        sizePolicy1.setHeightForWidth(player2Color->sizePolicy().hasHeightForWidth());
        player2Color->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(player2Color);


        verticalLayout_2->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(verticalLayout_2);

        buttonBox = new QDialogButtonBox(PlayerMenu);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setEnabled(true);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_3->addWidget(buttonBox);


        retranslateUi(PlayerMenu);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PlayerMenu, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PlayerMenu, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PlayerMenu);
    } // setupUi

    void retranslateUi(QDialog *PlayerMenu)
    {
        PlayerMenu->setWindowTitle(QCoreApplication::translate("PlayerMenu", "Player Menu", nullptr));
        player1Label->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player1NameLabel->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player1ColorLabel->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player1Color->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player2Label->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player2NameLabel->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player2ColorLabel->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
        player2Color->setText(QCoreApplication::translate("PlayerMenu", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PlayerMenu: public Ui_PlayerMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLAYERMENU_H
