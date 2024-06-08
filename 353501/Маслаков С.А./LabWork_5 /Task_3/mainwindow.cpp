#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sizeBox->setMinimum(16);
    ui->sizeBox->setMaximum(64);
    ui->sizeBox->setSingleStep(16);
    ui->setBox->setMinimum(0);
    ui->resetBox->setMinimum(0);
    ui->flipBox->setMinimum(0);
    bitset = new BitSet(16);
    ui->bitsetBrowser->setText(bitset->to_string());
    updateBoxes();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bitset;
}

void MainWindow::updateBoxes()
{
    if (bitset == nullptr || ui->bitsetBrowser->toPlainText().isEmpty()) {
        ui->setBox->setDisabled(true);
        ui->resetBox->setDisabled(true);
        ui->flipBox->setDisabled(true);
    } else {
        ui->setBox->setDisabled(false);
        ui->resetBox->setDisabled(false);
        ui->flipBox->setDisabled(false);
        ui->setBox->setMaximum(bitset->size() - 1);
        ui->resetBox->setMaximum(bitset->size() - 1);
        ui->flipBox->setMaximum(bitset->size() - 1);
    }
}

bool MainWindow::emptyCheck()
{
    return (bitset == nullptr || ui->bitsetBrowser->toPlainText().isEmpty());
}

void MainWindow::on_setBitsetButton_clicked()
{
    int size = ui->sizeBox->text().toInt();
    if (bitset != nullptr) {
        delete bitset;
        bitset = nullptr;
    }
    bitset = new BitSet(size);
    ui->bitsetBrowser->setText(bitset->to_string());
    updateBoxes();
}

void MainWindow::on_allButton_clicked()
{
    if (emptyCheck())
        return;
    if (bitset->all()) {
        msgBox.setText("Все биты установлены");
    } else {
        msgBox.setText("Не все биты установлены");
    }
    msgBox.exec();
}

void MainWindow::on_anyButton_clicked()
{
    if (emptyCheck())
        return;
    if (bitset->any()) {
        msgBox.setText("Хотя бы один бит установлен");
    } else {
        msgBox.setText("Ни одного бита не установлено");
    }
    msgBox.exec();
}

void MainWindow::on_noneButton_clicked()
{
    if (emptyCheck())
        return;
    if (bitset->none()) {
        msgBox.setText("Ни одного бита не установлено");
    } else {
        msgBox.setText("Хотя бы один бит установлен");
    }
    msgBox.exec();
}

void MainWindow::on_countButton_clicked()
{
    if (emptyCheck())
        return;
    msgBox.setText("Количество установленных битов: " + QString::number(bitset->count()));
    msgBox.exec();
}

void MainWindow::on_sizeButton_clicked()
{
    if (emptyCheck())
        return;
    msgBox.setText("Размер битсета: " + QString::number(bitset->size()));
    msgBox.exec();
}

void MainWindow::on_toUllButton_clicked()
{
    if (emptyCheck())
        return;
    msgBox.setText("Битсет в виде unsigned long long: " + QString::number(bitset->to_ullong()));
    msgBox.exec();
}

void MainWindow::on_flipButton_clicked()
{
    if (emptyCheck())
        return;
    bitset->fliper();
    ui->bitsetBrowser->setText(bitset->to_string());
}

void MainWindow::on_resetButton_clicked()
{
    if (emptyCheck())
        return;
    bitset->reset();
    ui->bitsetBrowser->setText(bitset->to_string());
}

void MainWindow::on_setButton_clicked()
{
    if (emptyCheck())
        return;
    bitset->set();
    ui->bitsetBrowser->setText(bitset->to_string());
}

void MainWindow::on_flipIdButton_clicked()
{
    if (emptyCheck())
        return;
    int index = ui->flipBox->text().toInt();
    bitset->flip(index);
    ui->bitsetBrowser->setText(bitset->to_string());
}

void MainWindow::on_resetIdButton_clicked()
{
    if (emptyCheck())
        return;
    int index = ui->resetBox->text().toInt();
    bitset->reset(index);
    ui->bitsetBrowser->setText(bitset->to_string());
}

void MainWindow::on_setIdButton_clicked()
{
    if (emptyCheck())
        return;
    int index = ui->setBox->text().toInt();
    bitset->set(index);
    ui->bitsetBrowser->setText(bitset->to_string());
}
