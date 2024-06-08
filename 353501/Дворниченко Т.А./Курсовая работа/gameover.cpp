#include "gameover.h"
#include "ui_gameover.h"

GameOverWindow::GameOverWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameOverWindow)
{
    ui->setupUi(this);


}

GameOverWindow::~GameOverWindow()
{
    delete ui;
}

void GameOverWindow::on_pushButton_clicked(){

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());


}

void GameOverWindow::on_pushButton_2_clicked(){
    qApp->quit();

}
