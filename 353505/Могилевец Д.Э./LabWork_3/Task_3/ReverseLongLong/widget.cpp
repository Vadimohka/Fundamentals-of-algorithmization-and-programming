#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
    connect(ui->spinBox, &QSpinBox::valueChanged, this, &Widget::updateLabel);
    setWindowTitle("Разворот числа");
    updateLabel();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::updateLabel()
{
    ui->label->setText("Развёрнутое число: " + QString::number(rev.Reverse(ui->spinBox->value())));
}
