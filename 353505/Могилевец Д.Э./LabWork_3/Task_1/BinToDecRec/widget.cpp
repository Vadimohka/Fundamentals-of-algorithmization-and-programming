#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->doubleSpinBox, &QDoubleSpinBox::valueChanged, this, &Widget::updateValue);
    this->setLayout(ui->gridLayout);
    ui->ansLabel->setText("Двоичное число (IEEE754): 0"
                          "\nДвоичное число: 0");
    this->setWindowTitle("Перевод в двоичную систему счисления");

    ui->doubleSpinBox->setMinimum(-1e308);
    ui->doubleSpinBox->setMaximum(1e308);

    ui->doubleSpinBox->setValue(-1e300);
    updateValue();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateValue()
{
    ui->ansLabel->setText("Двоичное число (IEEE754): " + translator.TranslateToIEEE754(ui->doubleSpinBox->value()) +
                          "\nДвоичное число: " + translator.TranslateToDotBin(ui->doubleSpinBox->value()));
}
