#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{

    QIntValidator *validator = new QIntValidator;
    validator->setBottom(0); // Минимальное значение
    validator->setTop(12);

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


    line2 = new QLineEdit(this);
    line2->setStyleSheet("font-size: 35px;");
    line2->setGeometry(500,100,300,95);
    line2->setValidator(validator);

    rez = new QLabel(this);
    rez->setStyleSheet("font-size: 35px;");
    rez->setGeometry(1200,300,300,195);



}

void Widget::fun_rez(){
    int rezalt;
    QString LINE1 = line1->text();
    QString LINE2 = line2->text();

    int m_1 = LINE1.toInt();
    int n_1 = LINE2.toInt();
    if((m_1==5 && n_1>0)||(n_1==5 && m_1>0)){
        QMessageBox::warning(this, "Ошибка", "Некоректное значение");
        return;
    } else if((m_1==4 && n_1>1)||(n_1==4 && m_1>1)){
        QMessageBox::warning(this, "Ошибка", "Некоректное значение");
        return;
    }else if((m_1==3 && n_1>10)||(n_1==3 && m_1>10)){
        QMessageBox::warning(this, "Ошибка", "Некоректное значение");
        return;
    }else if((m_1>5 && n_1>5)||(n_1>5 && m_1>5)){
        QMessageBox::warning(this, "Ошибка", "Некоректное значение");
        return;
    }
    rezalt = ackermann(m_1,n_1);
    QString rezalt_str = QString::number(rezalt);
    rez->setText(rezalt_str);
}


    int Widget :: ackermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (m > 0 && n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

Widget::~Widget()
{
    delete ui;
}
