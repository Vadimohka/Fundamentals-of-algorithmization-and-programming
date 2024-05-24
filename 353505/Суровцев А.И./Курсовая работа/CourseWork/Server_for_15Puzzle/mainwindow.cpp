#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    _server = nullptr;
    setWindowTitle("Окно сервера");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_btnStartServer_clicked()
{
    if (_server == nullptr) {
        auto port =ui->spnServerPort->value();
        _server = new TcpServer(port);
        connect(_server, &TcpServer::newClientConnected, this, &MainWindow::newClinetConnected);
        connect(_server, &TcpServer::dataReceived, this, &MainWindow::clientDataReceived);
        connect(_server, &TcpServer::clientDisconnect, this, &MainWindow::clientDisconnected);

    }
    auto state = (_server->isStarted())? "1" : "0";
    ui->lblConnectionStatus->setProperty("state", state);
    style()->polish(ui->lblConnectionStatus);
}

void MainWindow::newClinetConnected()
{
    ui->lstConsole->addItem("New Client connected");
}

void MainWindow::clientDisconnected()
{
    ui->lstConsole->addItem("Client Disconnected");
}

void MainWindow::clientDataReceived(QString message)
{
    ui->lstConsole->addItem(message);
}
