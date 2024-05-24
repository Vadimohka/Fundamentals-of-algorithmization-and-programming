#include "datainput.h"
#include "ui_datainput.h"

DataInput::DataInput(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DataInput)
{
    ui->setupUi(this);
    setFixedSize(400, 300);
    setWindowTitle("Окно для подлючения к серверу");
    ui->bnt_connect->setEnabled(false);
    ui->bnt_connect->setStyleSheet("background-color: gray;");
    connect(ui->lnl_nik, &QLineEdit::textChanged, this, &DataInput::checkInputs);
    connect(ui->lnl_ip, &QLineEdit::textChanged, this, &DataInput::checkInputs);
    connect(ui->lnl_port, &QLineEdit::textChanged, this, &DataInput::checkInputs);
}

DataInput::~DataInput()
{
    delete ui;
}

QString DataInput::getPort()
{
    return port;
}

QString DataInput::getIP()
{
    return IP;
}

QString DataInput::getName()
{
    return name;
}

void DataInput::on_lnl_ip_textChanged(const QString &arg1)
{
    QString state = "0";
    QString expectedMask = "\\d{3}\\.\\d{3}\\.\\d{3}\\.\\d{3}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->lnl_ip->text()=="...") {
        state = "2";
    }
    else {
        QHostAddress address(arg1);
        if (QAbstractSocket::IPv4Protocol == address.protocol()) {
            state = "1";
        }
        else {
            state = "0";
        }
    }
    ui->lnl_ip->setProperty("state", state);
    style()->polish(ui->lnl_ip);
}

void DataInput::on_bnt_connect_clicked()
{
    name = ui->lnl_nik->text();
    IP = ui->lnl_ip->text();
    port = ui->lnl_port->text();
    emit formClosed(name, IP, port);
    close();
}


void DataInput::on_lnl_port_textChanged(const QString &arg1)
{
    QString state1 = "0";
    QString expectedMask = "\\d{5}";
    QRegularExpression regex(expectedMask);
    QRegularExpressionMatch match = regex.match(arg1);
    if (ui->lnl_port->text().isEmpty()) {
        state1 = "2";
    }
    else if (match.hasMatch()) {
        state1 = "1";
    }
    else {
        state1 = "0";
    }
    ui->lnl_port->setProperty("state1", state1);
    style()->polish(ui->lnl_port);
}

void DataInput::checkInputs()
{
    QString name = ui->lnl_nik->text();
    QString IP = ui->lnl_ip->text();
    QString port = ui->lnl_port->text();

    bool allFieldsFilled = !name.isEmpty() && !IP.isEmpty() && !port.isEmpty();

    ui->bnt_connect->setEnabled(allFieldsFilled);
    if (allFieldsFilled) ui->bnt_connect->setStyleSheet("background-color: white;");
    else ui->bnt_connect->setStyleSheet("background-color: gray;");
}
