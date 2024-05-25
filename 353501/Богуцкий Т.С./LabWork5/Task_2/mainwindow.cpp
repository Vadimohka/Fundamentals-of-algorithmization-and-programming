#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _mainStr("Hello,")
    , _addStr(" World!")
{
    ui->setupUi(this);

    ui->mainEdit->setReadOnly(true);
    ui->resultEdit->setReadOnly(true);
    ui->capacity->setReadOnly(true);
    ui->size->setReadOnly(true);
    ui->pushBackEdit->setMaxLength(1);
    ui->mainEdit->setText(_mainStr.c_str());
    ui->addEdit->setText(_addStr.c_str());

    connect(ui->pushBackBtn, SIGNAL(clicked(bool)), SLOT(pushBack()));
    connect(ui->popBackBtn, SIGNAL(clicked(bool)), SLOT(popBack()));
    connect(ui->insertBtn, SIGNAL(clicked(bool)), SLOT(insert()));
    connect(ui->eraseBtn, SIGNAL(clicked(bool)), SLOT(erase()));
    connect(ui->findBtn, SIGNAL(clicked(bool)), SLOT(find()));
    connect(ui->rFindBtn, SIGNAL(clicked(bool)), SLOT(rFind()));
    connect(ui->plusBtn, SIGNAL(clicked(bool)), SLOT(plus()));
    connect(ui->clearBtn, SIGNAL(clicked(bool)), SLOT(clear()));
    connect(ui->mainEdit, SIGNAL(textChanged(QString)), SLOT(slotMainChanged(QString)));
    connect(ui->shrinkBtn, SIGNAL(clicked(bool)), SLOT(shrink()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotMainChanged(const QString &arg1)
{
    ui->insertBox->setMaximum(_mainStr.size());
    ui->erasePosBox->setMaximum(_mainStr.size());
    ui->capacity->setText("Capacity: " + QString::number(_mainStr.capacity()));
    ui->size->setText("Size: " + QString::number(_mainStr.size()));
}

void MainWindow::slotAddChanged(const QString &arg1)
{

}

void MainWindow::pushBack()
{
    try {
        if (!ui->pushBackEdit->text().toStdString().empty()) {
            _mainStr.push_back(ui->pushBackEdit->text().toStdString().at(0));
            ui->mainEdit->setText(_mainStr.c_str());
        }
    } catch (...) {
        QMessageBox::warning(this, "Exception", "push_back");
    }
}

void MainWindow::popBack()
{
    try {
        _mainStr.pop_back();
        ui->mainEdit->setText(_mainStr.c_str());
    } catch (...) {
        QMessageBox::warning(this, "Exception", "pop_back");
    }
}

void MainWindow::insert()
{
    try {
        _mainStr.insert(ui->insertBox->value(), _addStr);
        ui->mainEdit->setText(_mainStr.c_str());
    } catch (...) {
        QMessageBox::warning(this, "Exception", "insert");
    }
}

void MainWindow::erase()
{
    try {
        _mainStr.erase(ui->erasePosBox->value(), ui->eraseLengthBox->value());
        ui->mainEdit->setText(_mainStr.c_str());
    } catch (...) {
        QMessageBox::warning(this, "Exception", "erase");
    }
}

void MainWindow::find()
{
    try {
        ui->resultEdit->setText(QString::number(_mainStr.find(_addStr)));
    } catch (...) {
        QMessageBox::warning(this, "Exception", "find");
    }
}

void MainWindow::rFind()
{
    try {
        ui->resultEdit->setText(QString::number(_mainStr.rfind(_addStr)));
    } catch (...) {
        QMessageBox::warning(this, "Exception", "rfind");
    }
}

void MainWindow::plus()
{
    try {
        ui->resultEdit->setText((_mainStr + _addStr).c_str());
    } catch (...) {
        QMessageBox::warning(this, "Exception", "rfind");
    }
}

void MainWindow::clear()
{
    try {
        _mainStr.clear();
        ui->mainEdit->setText(_mainStr.c_str());
    } catch (...) {
        QMessageBox::warning(this, "Exception", "clear");
    }
}

void MainWindow::shrink()
{
    try {
        _mainStr.shrink_to_fit();
        ui->capacity->setText("Capacity: " + QString::number(_mainStr.capacity()));
        ui->size->setText("Size: " + QString::number(_mainStr.size()));
    } catch (...) {
        QMessageBox::warning(this, "Exception", "shrink");
    }
}
