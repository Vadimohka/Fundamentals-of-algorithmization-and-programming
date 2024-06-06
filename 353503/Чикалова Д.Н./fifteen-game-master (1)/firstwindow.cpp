#include "firstwindow.h"
#include "ui_firstwindow.h"
#include <QMessageBox>

FirstWindow::FirstWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    sFirstWindow=new MainWindow();
    //connect(sWindow,&MainWindow::firstWindow,this,&FirstWindow::show)

}

FirstWindow::~FirstWindow()
{
    delete ui;
}
void FirstWindow::on_pushButton_clicked(){
    sFirstWindow->show();
    this->close();
}





void FirstWindow::on_pushButton_3_clicked()
{
    //об авторе
    QMessageBox::information(this, "about author", "Игру разработала ученица 1 курса ,группы 353503, Чикалова Дарья Николаевна");
    //t->show();
}

