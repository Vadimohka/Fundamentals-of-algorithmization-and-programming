#include "dialogellipse.h"
#include "ui_dialogellipse.h"

extern QColor PenColor;
extern QColor BrushColor;
extern bool ELLIPSE_PARAMETRS;

DialogEllipse::DialogEllipse(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogEllipse)
{
    ui->setupUi(this);
}

DialogEllipse::~DialogEllipse()
{
    delete ui;
}

void DialogEllipse::on_BrushColor_clicked() {
    BrushColor = QColorDialog::getColor();
    BrushColorChoosed = true;
}

void DialogEllipse::on_PenColor_clicked() {
    PenColor = QColorDialog::getColor();
    PenColorChoosed = true;
}

void DialogEllipse::on_buttonBox_accepted() {
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
    string = ui->lineRadiusH->text();
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
    string = ui->lineRadiusV->text();
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
    emit sendData(ui->linePositionX->text().toInt(), ui->linePositionY->text().toInt(), ui->lineRadiusH->text().toInt(),
                   ui->lineRadiusV->text().toInt(), BrushColor, PenColor);
    ELLIPSE_PARAMETRS = true;
}


