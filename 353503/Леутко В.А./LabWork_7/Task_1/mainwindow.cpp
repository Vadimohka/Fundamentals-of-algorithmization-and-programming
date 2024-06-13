#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bufferLabel->setAlignment(Qt::AlignCenter);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);
    for (int i = 0; i < 10; i++) {
        buffer.pushBack(dis(gen));
    }

    buffer.makeCircular();

    updateView(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// первый элемент буфера перемещается в конец, а сам буфер "сдвигается" влево
void MainWindow::on_leftButton_clicked()
{
    if (!buffer.empty()) {
        buffer.pushBack(buffer.front());
        buffer.popFront();
        updateView(0);
    }
}

// последний элемент буфера перемещается в начало, а сам буфер "сдвигается" вправо
void MainWindow::on_rightButton_clicked()
{
    if (!buffer.empty()) {
        buffer.pushFront(buffer.back());
        buffer.popBack();
        updateView((buffer.size() > 0) ? buffer.size() - 1 : 0);
    }
}

void MainWindow::updateView(int value)
{
    if (buffer.empty()) {
        ui->label->setText("Buffer is empty");
        ui->bufferLabel->setText("");
        return;
    }

    ui->label->setText(QString::number(buffer[0]));


    QString bufferText;
    for (size_t i = 0; i < buffer.size(); ++i) {
        bufferText += QString::number(buffer[i % buffer.size()]);
        if (i < buffer.size() - 1) {
            bufferText += ", ";
        }
    }
    ui->bufferLabel->setText(bufferText);
}
