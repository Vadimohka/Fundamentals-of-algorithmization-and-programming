#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    ui;
}

void MainWindow::on_pushFront_clicked() {
    int temp = QRandomGenerator::global()->bounded(-RAND_BOUNDS, RAND_BOUNDS);
    if (temp == 0) {
        ++temp;
    }
    _mainQ.push_front(temp);
    ui->mainList->insertItem(0, QString::number(_mainQ.front()));
    updateInfo();
}


void MainWindow::on_popFront_clicked()
{
    _mainQ.pop_front();
    ui->mainList->takeItem(0);
    updateInfo();
}


void MainWindow::on_pushBack_clicked()
{
    int temp = QRandomGenerator::global()->bounded(-RAND_BOUNDS, RAND_BOUNDS);
    if (temp == 0) {
        ++temp;
    }
    _mainQ.push_back(temp);
    ui->mainList->addItem(QString::number(_mainQ.back()));
    updateInfo();
}


void MainWindow::on_popBack_clicked()
{
    _mainQ.pop_back();
    ui->mainList->takeItem(ui->mainList->count() - 1);
    updateInfo();
}


void MainWindow::on_clear_clicked()
{
    _mainQ.clear();
    ui->mainList->clear();
    updateInfo();
}


void MainWindow::on_func_clicked()
{
    _mainQ.devide(_posQ, _negQ);
    ui->mainList->clear();
    updateInfo();
    for (int i = 0; i < _posQ.size(); ++i) {
        ui->posList->addItem(QString::number(_posQ.front()));
        _posQ.emplace_back(_posQ.front());
        _posQ.pop_front();
    }
    for (int i = 0; i < _negQ.size(); ++i) {
        ui->negList->addItem(QString::number(_negQ.front()));
        _negQ.emplace_back(_negQ.front());
        _negQ.pop_front();
    }
}


void MainWindow::updateInfo() {
    ui->emptyString->setText(_mainQ.empty() ? "True" : "False");
    ui->sizeString->setText(QString::number(_mainQ.size()));
}

