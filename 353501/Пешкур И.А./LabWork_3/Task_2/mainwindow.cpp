#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAnswer_clicked()
{

    Answer ans;
    ans.setModal( true );
    ans.setAnswer( makeAnswer( ui -> spinBoxM -> value() , ui -> spinBoxN -> value() ) );
    ans.exec();

}

long long MainWindow :: makeAnswer( long long M , long long N )
{

    if( M == 0 )
        return N + 1;
    if( N == 0 )
        return makeAnswer( M - 1 , 1 );

    return makeAnswer( M - 1 , makeAnswer( M , N - 1 ) );

}
