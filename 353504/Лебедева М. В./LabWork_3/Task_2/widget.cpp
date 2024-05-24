#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setLayout(ui->gridLayout);
    setWindowTitle("Ackerman Fuction");
    ui->ansLabel->setText("A(m,n) = 1");

    connect(ui->spinBox, &QSpinBox::valueChanged, this, &Widget::on_pushButton_clicked);
    connect(ui->spinBox_2, &QSpinBox::valueChanged, this, &Widget::on_pushButton_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    long long m = ui->spinBox->value(), n = ui->spinBox_2->value();
    if (m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)) {
        ui->ansLabel->setText("A(" + ui->spinBox->text() + ", " + ui->spinBox_2->text() +
                              ") is too large!");
        return;
    }
    ui->ansLabel->setText("A(m,n) = " + QString::number(calculator.Calculate(m, n)));
}
