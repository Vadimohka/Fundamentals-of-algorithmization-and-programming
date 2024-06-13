#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QMessageBox>

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

void MainWindow::on_insertArrayButton_clicked()
{
    bool ok;
    int value = ui->arrayInput->text().toInt(&ok);
    if (ok) {
        heapArray.insert(value);
        updateArrayDisplay();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer.");
    }
}

void MainWindow::on_extractArrayButton_clicked()
{
    try {
        int maxValue = heapArray.extractMax();
        QMessageBox::information(this, "Max Value", QString::number(maxValue));
        updateArrayDisplay();
    } catch (std::runtime_error &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::on_insertListButton_clicked()
{
    bool ok;
    int value = ui->listInput->text().toInt(&ok);
    if (ok) {
        heapList.insert(value);
        updateListDisplay();
    } else {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid integer.");
    }
}

void MainWindow::on_extractListButton_clicked()
{
    try {
        int maxValue = heapList.extractMax();
        QMessageBox::information(this, "Max Value", QString::number(maxValue));
        updateListDisplay();
    } catch (std::runtime_error &e) {
        QMessageBox::warning(this, "Error", e.what());
    }
}

void MainWindow::updateArrayDisplay()
{
    QString displayText;
    for (size_t i = 0; i < heapArray.size(); ++i) {
        displayText += QString::number(heapArray.Data()[i]) + " ";
    }
    ui->arrayDisplay->setText(displayText);
}

void MainWindow::updateListDisplay()
{
    QString displayText;
    auto data = heapList.Data();
    for (int value : data) {
        displayText += QString::number(value) + " ";
    }
    ui->listDisplay->setText(displayText);
}
