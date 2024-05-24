#include "my_dialog_3.h"

my_dialog_3::my_dialog_3(QWidget *parent):
    QDialog(parent, Qt::WindowTitleHint | Qt::CustomizeWindowHint)
{

    setFixedSize(180,90);
    setWindowTitle("   Выбор жених или невеста");
    setModal(true);
    setWindowFlags(windowFlags() | Qt::MSWindowsOwnDC);

    close_dialog1 = new QPushButton("Закрыть",this);
    close_dialog1->setGeometry(10,50,160,30);
    connect(close_dialog1,SIGNAL(clicked(bool)),SLOT(close()));

    men_btn = new QPushButton("Женихов",this);
    men_btn->setGeometry(10,10,70,30);
    connect(men_btn,&QPushButton::clicked,this,&my_dialog_3::nextPageRequested1);

    women_btn = new QPushButton("Невест", this);
    women_btn->setGeometry(100,10,70,30);
    connect(women_btn,&QPushButton::clicked,this,&my_dialog_3::nextPageRequested2);

}
