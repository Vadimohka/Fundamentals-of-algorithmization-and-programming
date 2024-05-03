#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setLayout(ui->gridLayout);
    amountOfElementsInArray = 1;
    on_reloadVectorButton_clicked();
    ui->label->setWordWrap(true);
    setFixedSize(size());
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_reloadVectorButton_clicked()
{
    vect.clear();
    int addedElement = 0;
    for (int i = 0; i < amountOfElementsInArray; ++i) {
        addedElement = QRandomGenerator::global()->bounded(1, 100);
        vect.append(addedElement);
    }
    printVector();
    printMedians();
}


void Widget::on_amountOfElementsSpinBox_valueChanged(int)
{
    amountOfElementsInArray = ui->amountOfElementsSpinBox->value();
}

void Widget::printVector()
{
    QString text = "Вектор: ";
    for (auto el : vect) {
        text += ' ' + QString::number(el);
    }
    ui->label->setText(text);
}

void Widget::printMedians()
{
    QString text =  ui->label->text() + "\nМеданы: ";
    for (int i = 0; i < amountOfElementsInArray; i += 3) {
        text += ' ' + QString::number(findMedian(i));
    }
    ui->label->setText(text);
}

double Widget::findMedian(int index)
{
    if (index + 1 >= amountOfElementsInArray) {
        return vect[index];
    }
    if (index + 2 >= amountOfElementsInArray) {
        return 1.0 * (vect[index] + vect[index + 1]) / 2;
    }
    return vect[index] + vect[index + 1] + vect[index + 2] -
           qMax(qMax(vect[index], vect[index + 1]), vect[index + 2]) -
           qMin(qMin(vect[index], vect[index + 1]), vect[index + 2]);
}

