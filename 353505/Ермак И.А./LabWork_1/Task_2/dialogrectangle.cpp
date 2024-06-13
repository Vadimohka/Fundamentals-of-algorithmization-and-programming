#include "dialogrectangle.h"
#include "ui_dialogrectangle.h"

extern QColor PenColor;
extern QColor BrushColor;
extern bool RECTANGLE_PARAMETRS;

DialogRectangle::DialogRectangle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogRectangle)
{
    ui->setupUi(this);
}

DialogRectangle::~DialogRectangle()
{
    delete ui;
}

void DialogRectangle::on_BrushColor_clicked() {
    BrushColor = QColorDialog::getColor();
    BrushColorChoosed = true;
}

void DialogRectangle::on_PenColor_clicked() {
    PenColor = QColorDialog::getColor();
    PenColorChoosed = true;
}

void DialogRectangle::on_buttonBox_accepted() {
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
    if (string.isEmpty()) {
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
    if (string.isEmpty()) {
        QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
        return;
    }
    string.clear();
    string = ui->lineLength->text();
    size = string.size();
    for (int i = 0; i < size; ++i) {
        if (string.at(i) < '0' || string.at(i) > '9') {
            QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
            return;
        }
    }
    if (string.isEmpty()) {
        QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
        return;
    }
    string.clear();
    string = ui->lineWidth->text();
    size = string.size();
    for (int i = 0; i < size; ++i) {
        if (string.at(i) < '0' || string.at(i) > '9') {
            QMessageBox::warning(this, "ОШИБКА ВВОДА!", "Пожалуйста, введите корректные данные.");
            return;
        }
    }
    if (string.isEmpty()) {
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
    emit sendData(ui->linePositionX->text().toInt(), ui->linePositionY->text().toInt(), ui->lineWidth->text().toInt(),
                   ui->lineLength->text().toInt(), BrushColor, PenColor);
    RECTANGLE_PARAMETRS = true;
}

