#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QFont font = ui->vectorBrowser->font();
    font.setPointSize(12);
    ui->vectorBrowser->setFont(font);

    updateVector();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateVector()
{
    QString vectorString = "";
    for (auto i : v) {
        vectorString += QString::number(i) + " ";
    }
    ui->vectorBrowser->setText(vectorString);
}

void MainWindow::on_at_clicked()
{
    bool ok;
    int index = ui->inputEdit->text().toInt(&ok);
    if (ok) {
        try {
            int val = v.at(index);
            QMessageBox::information(this,
                                     tr("At"),
                                     tr("Value at index %1 is %2").arg(index).arg(val));
        } catch (std::out_of_range &e) {
            QMessageBox::warning(this, tr("Error"), tr("Index is out of range"));
        }
    }
}

void MainWindow::on_pop_back_clicked()
{
    try {
        v.pop_back();
        updateVector();
    } catch (std::out_of_range) {
        QMessageBox::warning(this, tr("Error"), tr("Vector is empty"));
    }
}

void MainWindow::on_push_back_clicked()
{
    bool ok;
    int val = ui->inputEdit->text().toInt(&ok);
    if (ok) {
        v.push_back(val);
        updateVector();
    } else {
        QMessageBox::information(this, "Push back", "Incorrect input");
    }
}

void MainWindow::on_resize_clicked()
{
    bool ok;
    unsigned long long i = ui->inputEdit->text().toInt(&ok);
    if (ok && i < 1e6) {
        if (i >= 0) {
            v.resize(i);
            QMessageBox::information(this, "Resize", "Success");
            updateVector();
        }
    } else {
        QMessageBox::warning(this, "Error", "Incorrect input, enter less than 10^6 and more than 0");
    }
}

void MainWindow::on_maxsize_clicked()
{
    QMessageBox::information(this, "Max size", "Max size: " + QString::number(v.max_size()));
}

void MainWindow::on_clear_clicked()
{
    v.clear();
    QMessageBox::information(this, "Clear", "Vector is cleared");
    updateVector();
}

void MainWindow::on_capacity_clicked()
{
    QMessageBox::information(this, "Capacity", "Result " + QString::number(v.getCapacity()));
}

void MainWindow::on_erase_clicked()
{
    bool ok;
    size_t i = ui->inputEdit->text().toInt(&ok);
    if (ok && i >= 0 && i < v.Size()) {
        v.erase(v.begin() + i);
        updateVector();
    } else {
        QMessageBox::warning(this, "Error", "Incorrect input");
    }
}

void MainWindow::on_empty_clicked()
{
    QMessageBox::information(this, "Empty Check", v.empty() ? "Result: Empty" : "Result: Not Empty");
}

void MainWindow::on_reserve_clicked()
{
    bool ok;
    unsigned long long i = ui->inputEdit->text().toInt(&ok);
    if (ok) {
        if (i >= 0) {
            v.reserve(i);
            QMessageBox::information(this, "Reserve", "Success");
            updateVector();
        }
    } else {
        QMessageBox::warning(this, "Error", "Incorrect input");
    }
}

void MainWindow::on_data_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(v.Data()),
                                         QT_POINTER_SIZE * 2,
                                         16,
                                         QChar('0'));
    QMessageBox::information(this, "Data", "Result: " + ptrStr);
}

void MainWindow::on_size_clicked()
{
    QMessageBox::information(this, "Size", QString::number(v.Size()));
}
