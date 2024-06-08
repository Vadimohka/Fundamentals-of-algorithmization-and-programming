#include "about_dialog.h"
#include "ui_about_dialog.h"
#include <QDesktopWidget>
#include <QFile>

About_Dialog::About_Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About_Dialog)
{
    ui->setupUi(this);


    this->setFixedSize(350,530);

    this->setWindowTitle("Mario: About");

    this->mainVBox = new QVBoxLayout;

    this->logo = new QPixmap(":/images/AD_Mario_Logo_Bar.png");
    logoLbl = new QLabel;
    logoLbl->setPixmap(*logo);
    logoLbl->setContentsMargins(0,0,0,2);

    this->spacerBar = new QPixmap(":/images/AD_Spacer_Bar.png");
    this->spacerLabel = new QLabel;
    spacerLabel->setPixmap(*spacerBar);
    spacerLabel->setContentsMargins(55,8,0,3);

    this->schoolInfo = new QLabel;
    this->classInfo = new QLabel;
    this->groupMember1 = new QLabel;


    this->setLayout(mainVBox);
    mainVBox->setAlignment(Qt::AlignTop | Qt::AlignCenter);

    mainVBox->addWidget(logoLbl);
    logoLbl->show();

    mainVBox->addWidget(schoolInfo);
    mainVBox->addWidget(classInfo);
    mainVBox->addWidget(spacerLabel);
    mainVBox->addWidget(groupMember1);


    schoolInfo->show();
    schoolInfo->setAlignment(Qt::AlignCenter);
    schoolInfo->setText("Kryto 2024");
    schoolInfo->setTextFormat(Qt::RichText);
    schoolInfo->setTextInteractionFlags(Qt::TextBrowserInteraction);
    schoolInfo->setOpenExternalLinks(true);
    schoolInfo->setContentsMargins(0,0,14,0);


    groupMember1->show();
    groupMember1->setAlignment(Qt::AlignCenter);
    groupMember1->setText("Vooitenkoo  : <a href = \"https://github.com/vooitenkoo\"> GitHub </a> ");
    groupMember1->setTextFormat(Qt::RichText);
    groupMember1->setTextInteractionFlags(Qt::TextBrowserInteraction);
    groupMember1->setOpenExternalLinks(true);
    groupMember1->setContentsMargins(14,0,0,0);

}

About_Dialog::~About_Dialog()
{
    delete ui;
}
