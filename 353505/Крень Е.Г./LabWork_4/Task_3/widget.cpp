#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->spinBox->setRange(1, 80);

    connect(ui->clearPushButton, &QPushButton::clicked, this, [this](){
        numbers.clear();
        ui->vectorLabel->clear();
        ui->mediansLabel->clear();
    });

    connect(ui->addPushButton, &QPushButton::clicked, this, [this](){
        numbers.clear();
        QString text1 = "Массив: ";
        for(int i = 0; i<ui->spinBox->value(); ++i){
            numbers.push_back(QRandomGenerator::global()->bounded(1, 999));
            text1 += QString::number(numbers[i])+ " ";
        }
        ui->vectorLabel->setText(text1);


        QString text2 = "Медианы: ";

        for(int i = 0; i<numbers.size(); i+=3){
            if (i + 1 >= numbers.size()) {
                text2 += QString::number(numbers[i]) + " ";
            }
            else if (i + 2 >= numbers.size()) {
                text2 += QString::number((numbers[i] + numbers[i + 1]) / 2)+ " ";
            }
            else{
                text2 += QString::number(numbers[i] + numbers[i + 1] + numbers[i + 2] - qMax(qMax(numbers[i], numbers[i + 1]), numbers[i + 2]) - qMin(qMin(numbers[i], numbers[i + 1]), numbers[i + 2]))+ " ";
            }
        }

        ui->mediansLabel->setText(text2);
    });
}

Widget::~Widget()
{
    delete ui;
}


