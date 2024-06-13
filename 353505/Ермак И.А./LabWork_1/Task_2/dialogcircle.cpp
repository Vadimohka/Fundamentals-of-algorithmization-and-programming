#include "dialogcircle.h"
#include "ui_dialogcircle.h"

QColor PenColor;
QColor BrushColor;
extern bool CIRCLE_PARAMETRS;

DialogCircle::DialogCircle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogCircle) {
    ui->setupUi(this);
}

DialogCircle::~DialogCircle() {
    delete ui;
}

void DialogCircle::on_BrushColor_clicked() {
    BrushColor = QColorDialog::getColor();
    BrushColorChoosed = true;
}

void  DialogCircle::on_PenColor_clicked() {
    PenColor = QColorDialog::getColor();
    PenColorChoosed = true;
}

void DialogCircle::on_buttonBox_accepted()
{
    QString string = ui->linePositionX->text();
    int size = string.size();
    for (int i = 0; i < size; ++i) {
        if (string.at(i) == '-' && i == 0 && size > 1) {
            continue;
        }
        if (string.at(i) < '0' || string.at(i) > '9') {
            QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
            return;
        }
    }
    if(string.isEmpty()) {
        QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
        return;
    }
    string.clear();
    string = ui->linePositionY->text();
    size = string.size();
    for (int i = 0; i < size; ++i) {
        if (string.at(i) == '-' && i == 0 && size > 1) {
            continue;
        }
        if (string.at(i) < '0' || string.at(i) > '9') {
            QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
            return;
        }
    }
    if(string.isEmpty()) {
        QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
        return;
    }
    string.clear();
    string = ui->lineRadius->text();
    size = string.size();
    for (int i = 0; i < size; ++i) {
        if (string.at(i) < '0' || string.at(i) > '9') {
            QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
            return;
        }
    }
    if(string.isEmpty()) {
        QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
        return;
    }
    if (!BrushColorChoosed) {
        QMessageBox::warning(this,"Ошибка!","Выбирите цвет заливки фигуры");
        return;
    }
    if (!PenColorChoosed) {
        QMessageBox::warning(this,"Ошибка!","Выбирите цвет контура фигуры");
        return;
    }
    emit sendData(ui->linePositionX->text().toInt(), ui->linePositionY->text().toInt(), ui->lineRadius->text().toInt(), BrushColor, PenColor);
    CIRCLE_PARAMETRS = true;
}
