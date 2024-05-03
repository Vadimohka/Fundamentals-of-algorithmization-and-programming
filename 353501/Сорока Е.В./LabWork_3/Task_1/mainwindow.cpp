
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <bitset>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->answer, &QPushButton::pressed, this, &MainWindow::getBinary );

}

MainWindow::~MainWindow()
{
    delete ui;
}

void getBinary(double num, int& offset, std::bitset<64>& bits) {
    if(offset == 64) return;

    uint64_t* ptr = reinterpret_cast<uint64_t*>(&num);

    bool bit = (*ptr << (63 - offset)) & (1ull << 63);
    bits[offset] = bit;

    getBinary(num, ++offset, bits);
}


QString binaryRepresentation(double num) {
    std::bitset<64> bits;
    int offset = 0;
    getBinary(num, offset, bits);
    return QString::fromStdString(bits.to_string());
}


void MainWindow::getBinary()
{
    bool ok;
    double value = ui->edit->text().toDouble(&ok);
    if (!ok)
    {
        QMessageBox::warning(this, "Error", "Введите вещественное число");
        return;
    }

    ui->out->setText(binaryRepresentation(value));
}
