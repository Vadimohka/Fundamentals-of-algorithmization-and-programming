#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "move_rec.h"
#include "soldier.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Rectungle = new Move_rec(this);
    //Rectungle -> move(430, 390);
    sold =new soldier(this);
    sold -> move(430, 290);

    uphand = new upperhand(this);
    uphand -> move(430, 390);

    lowhand = new lowwerhand(this);
    lowhand -> move(430,590);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
}

void MainWindow::on_pushButton_clicked()
{
    sold -> left(50, 500);
    uphand -> left(50, 500);
    lowhand -> left(50, 500);
}



void MainWindow::on_pushButton_2_clicked()
{
    sold -> right(50, 500);
    uphand -> right(50, 500);
    lowhand -> right(50, 500);
}


void MainWindow::on_pushButton_3_clicked()
{
    uphand -> salute();
    lowhand -> salute();
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer -> start(2000);

    //timer -> start(3000);
    //QTimer::singleShot(2000, this);
    //uphand -> returnSalute();

}

void MainWindow::slotTimerAlarm(){
    //update();
    uphand -> returnSalute();
    lowhand ->returnSalute();
    timer -> stop();

}

