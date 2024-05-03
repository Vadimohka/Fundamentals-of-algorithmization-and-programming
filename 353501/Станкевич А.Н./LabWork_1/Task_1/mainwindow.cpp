#include "mainwindow.h"
#include "ui_mainwindow.h"

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



void MainWindow::on_pushButton_2_clicked()
{
    static bool isShifted2 = false;
    int shiftAmount2 = isShifted2 ? 40 : -40;
    ui->pushButton_2->move(ui->pushButton_2->x() + shiftAmount2, ui->pushButton_2->y());
    isShifted2 = !isShifted2;
    if (isShifted2) {
        ui->pushButton_2->setText("WindowOpen");
    } else {
        ui->pushButton_2->setText("WindowClosed");
    }
}

void MainWindow::on_pushButton_clicked() {
    static bool isShifted = false; // Флаг для отслеживания состояния сдвига

    // Сдвигаем кнопку на 20 пикселей вправо или влево
    int shiftAmount = isShifted ? -90 : 90;
    ui->pushButton->move(ui->pushButton->x() + shiftAmount, ui->pushButton->y());

    // Инвертируем флаг
    isShifted = !isShifted;
    if (isShifted) {
        ui->pushButton->setText("DoorOpen");
    } else {
        ui->pushButton->setText("DoorClosed");
    }
    }


void MainWindow::on_pushButton_3_clicked()
{
    static bool isShifted3 = false;
    int shiftAmount3 = isShifted3 ? -40 : 40;
    ui->pushButton_3->move(ui->pushButton_3->x() + shiftAmount3, ui->pushButton_3->y());
    isShifted3 = !isShifted3;
    if (isShifted3) {
        ui->pushButton_3->setText("WindowOpen");
    } else {
        ui->pushButton_3->setText("WindowClosed");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    static bool isShifted4 = false;
    int shiftAmount4 = isShifted4 ? 90 : -90;
    ui->pushButton_4->move(ui->pushButton_4->x() + shiftAmount4, ui->pushButton_4->y());
    isShifted4 = !isShifted4;
    if (isShifted4) {
        ui->pushButton_4->setText("DoorOpen");
    } else {
        ui->pushButton_4->setText("DoorClosed");
    }

}

QPoint pt(10,10);
QSize size(20, 10);
QRect r(pt,size);

