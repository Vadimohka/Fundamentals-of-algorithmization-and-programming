#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::appendToTextEdit(const QString &text)
{
    ui->textEdit->append(text);
}

void MainWindow::on_insertArrayButton_clicked()
{
    bool ok;
    int value = ui->insertArrayLineEdit->text().toInt(&ok);
    if (ok) {
        heapArray.insert(value);
        appendToTextEdit("Value added into HeapArray.");
    } else {
        appendToTextEdit("Invalid input.");
    }
}

void MainWindow::on_extractMaxArrayButton_clicked()
{
    try {
        int maxValue = heapArray.extractMax();
        appendToTextEdit(QString("Max value deleted from HeapArray: %1").arg(maxValue));
    } catch (const std::runtime_error &error) {
        appendToTextEdit(error.what());
    }
}

void MainWindow::on_getMaxArrayButton_clicked()
{
    try {
        int maxValue = heapArray.getMax();
        appendToTextEdit(QString("Max value in HeapArray: %1").arg(maxValue));
    } catch (const std::runtime_error &error) {
        appendToTextEdit(error.what());
    }
}

void MainWindow::on_insertListButton_clicked()
{
    bool ok;
    // Получаем введенное значение из текстового поля
    int value = ui->insertListLineEdit->text().toInt(&ok);
    if (ok) {
        // Вставляем значение в HeapList
        heapList.insert(value);
        appendToTextEdit("Value added into HeapList.");
    } else {
        appendToTextEdit("Invalid input.");
    }
}

void MainWindow::on_extractMaxListButton_clicked()
{
    try {
        // Извлекаем максимальное значение из HeapList
        int maxValue = heapList.extractMax();
        appendToTextEdit(QString("Max value deleted from HeapList: %1").arg(maxValue));
    } catch (const std::runtime_error &error) {
        appendToTextEdit(error.what());
    }
}

void MainWindow::on_getMaxListButton_clicked()
{
    try {
        // Получаем максимальное значение из HeapList
        int maxValue = heapList.getMax();
        appendToTextEdit(QString("Max value in HeapList: %1").arg(maxValue));
    } catch (const std::runtime_error &error) {
        appendToTextEdit(error.what());
    }
}
