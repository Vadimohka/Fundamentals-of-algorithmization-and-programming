#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Главное меню");
    client = new Client_Part;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete puzzleWidget;
    delete client;
}

void MainWindow::on_bnt_select15_clicked()
{
    hide();
    puzzleWidget = new Puzzle15(4, this, client, _nickname);
    puzzleWidget->show();
}

void MainWindow::on_bnt_select8_clicked()
{
    hide();
    puzzleWidget = new Puzzle15(3, this, client, _nickname);
    puzzleWidget->show();
}


void MainWindow::on_bnt_select24_clicked()
{
    hide();
    puzzleWidget = new Puzzle15(5, this, client, _nickname);
    puzzleWidget->show();
}


void MainWindow::on_bnt_select35_clicked()
{
    hide();
    puzzleWidget = new Puzzle15(6, this, client, _nickname);
    puzzleWidget->show();
}

void MainWindow::on_bnt_connect_to_server_clicked()
{
    dataInput = new DataInput;
    dataInput->setWindowModality(Qt::ApplicationModal);
    dataInput->show();
    connect(dataInput, &DataInput::formClosed, [=](const QString& name, const QString& IP, const QString& port) {
        client->connectToServer(IP, port.toInt());
        _nickname = name;
    });
}

void MainWindow::on_bnt_closeApp_clicked()
{
    close();
}

