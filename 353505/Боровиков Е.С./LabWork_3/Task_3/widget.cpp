#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    QIntValidator *validator = new QIntValidator;
    validator->setBottom(0); // Минимальное значение
    validator->setTop(99999);

    ui->setupUi(this);
    close = new QPushButton("Закрыть",this);
    close->setGeometry(500,500,300,200);
    close->setStyleSheet("font-size: 55px;");
    connect(close,SIGNAL(clicked(bool)),SLOT(close()));

    Otvet = new QPushButton("Получить результат",this);
    Otvet->setGeometry(500,300,300,195);
    connect(Otvet,SIGNAL(clicked(bool)),SLOT(fun_rez()));

    line1 = new QLineEdit(this);
    line1->setStyleSheet("font-size: 35px;");
    line1->setGeometry(500,200,300,95);
    line1->setValidator(validator);


    // line2 = new QLineEdit(this);
    // line2->setStyleSheet("font-size: 35px;");
    // line2->setGeometry(500,100,300,95);
    // line2->setValidator(validator);

    rez = new QLabel(this);
    rez->setStyleSheet("font-size: 35px;");
    rez->setGeometry(1200,300,300,195);
}

int Widget::reverseNumber(int n, int reversed) {
    if (n == 0)
        return reversed;
    reversed = reversed * 10 + n % 10;
    return reverseNumber(n / 10, reversed);
}

void Widget::fun_rez(){
    int rezalt;
    QString LINE1 = line1->text();

    int m_1 = LINE1.toInt();
    rezalt = reverseNumber(m_1,0);
    QString rezalt_str = QString::number(rezalt);
    rez->setText(rezalt_str);
}

Widget::~Widget()
{
    delete ui;
}
