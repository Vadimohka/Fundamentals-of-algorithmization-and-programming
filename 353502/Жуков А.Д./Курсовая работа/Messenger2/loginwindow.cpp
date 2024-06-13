#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <string>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
    , dataSender(new DataSender)
{
    ui->setupUi(this);
    dataSender->connectSocket();

    connect(dataSender, &DataSender::updateRegistrationStatus, ui->statusLabel, &QLabel::setText);
    connect(dataSender, &DataSender::loginSucceed, this, &LoginWindow::loginSucceedSlot);
    //emit loginSucceedSlot();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_registerButton_clicked()
{
    //ПРОВЕРОЧКИ
    QString login = ui->loginInput->text();
    QString password = ui->passwordInput->text();
    dataSender->registerUser(login, password);
}


void LoginWindow::on_loginButton_clicked()
{
    //ПРОВЕРОЧКИ
    QString login = ui->loginInput->text();
    QString password = ui->passwordInput->text();
    dataSender->logInUser(login, password);
}

void LoginWindow::loginSucceedSlot(QString uid)
{
    dataSender->disconnectSocket();
    emit userLoggedIn(uid, ui->loginInput->text());
    emit openWindow();
    this->close();
}

