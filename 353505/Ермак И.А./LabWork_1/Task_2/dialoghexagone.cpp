#include "dialoghexagone.h"
#include "ui_dialoghexagone.h"

extern QColor BrushColor;
extern QColor PenColor;
extern bool HEXAGONE_PARAMETRS;

DialogHexagone::DialogHexagone(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogHexagone)
{
    ui->setupUi(this);
}

DialogHexagone::~DialogHexagone()
{
    delete ui;
}

void DialogHexagone::on_BrushColor_clicked() {
    BrushColor = QColorDialog::getColor();
    BrushColorChoosed = true;
}

void DialogHexagone::on_PenColor_clicked() {
    PenColor = QColorDialog::getColor();
    PenColorChoosed = true;
}

void DialogHexagone::on_buttonBox_accepted() {
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
    if (!BrushColorChoosed) {
        QMessageBox::warning(this,"Ошибка!","Выбирите цвет заливки фигуры");
        return;
    }
    if (!PenColorChoosed) {
        QMessageBox::warning(this,"Ошибка!","Выбирите цвет контура фигуры");
        return;
    }
    emit sendData(ui->linePositionX->text().toInt(), ui->linePositionY->text().toInt(), ui->lineLength->text().toInt(), BrushColor, PenColor);
    HEXAGONE_PARAMETRS = true;
}
