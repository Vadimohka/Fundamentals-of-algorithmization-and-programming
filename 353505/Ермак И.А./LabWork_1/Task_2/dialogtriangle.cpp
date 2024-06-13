#include "dialogtriangle.h"
#include "ui_dialogtriangle.h"

extern QColor BrushColor;
extern QColor PenColor;
extern bool TRIANGLE_PARAMETRS;

DialogTriangle::DialogTriangle(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogTriangle)
{
    ui->setupUi(this);
}

DialogTriangle::~DialogTriangle()
{
    delete ui;
}

void DialogTriangle::on_BrushColor_clicked() {
    BrushColor = QColorDialog::getColor();
    BrushColorChoosed = true;
}

void DialogTriangle::on_PenColor_clicked() {
    PenColor = QColorDialog::getColor();
    PenColorChoosed = true;
}

void DialogTriangle::on_buttonBox_accepted() {
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
    string = ui->BaseLine->text();
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
    string = ui->SideLine->text();
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
    emit sendData(ui->linePositionX->text().toInt(), ui->linePositionY->text().toInt(), ui->BaseLine->text().toInt(),
                   ui->SideLine->text().toInt(), BrushColor, PenColor);
    TRIANGLE_PARAMETRS = true;
}
