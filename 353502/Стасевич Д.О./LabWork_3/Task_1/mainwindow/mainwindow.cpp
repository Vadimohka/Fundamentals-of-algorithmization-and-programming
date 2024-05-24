#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>

#include <QDebug>

mainwindow::mainwindow(): ui(new Ui::mainwindow) {

    ui->setupUi(this);

    ui->resultTextEdit->hide();
    ui->resultlabel->hide();
    ui->Mlabel->hide();
    ui->MspinBox->hide();
    ui->Nlabel->hide();
    ui->NspinBox->hide();
    ui->doubleTask1SpinBox->hide();
    ui->valuespinBox->hide();
    ui->doubleTask1SpinBox->setMaximum(1.7e+308);
    ui->doubleTask1SpinBox->setMinimum(-1.7e+308);

    connect(ui->comboBox, SIGNAL(activated(int)), this, SLOT(task_choose_clicked(int)));
    connect(ui->doubleTask1SpinBox, SIGNAL(valueChanged(double)), this, SLOT(execute_task1()));
    connect(ui->NspinBox, SIGNAL(valueChanged(int)), this, SLOT(execute_task2()));
    connect(ui->MspinBox, SIGNAL(valueChanged(int)), this, SLOT(execute_task2()));
    connect(ui->valuespinBox, SIGNAL(valueChanged(int)), this, SLOT(execute_task3()));

}

void mainwindow::task_choose_clicked(int type) {
    switch (type) {
        case 0:
        {
            ui->resultTextEdit->hide();
            ui->resultlabel->hide();
            ui->Mlabel->hide();
            ui->MspinBox->hide();
            ui->Nlabel->show();
            ui->NspinBox->hide();
            ui->doubleTask1SpinBox->clear();
            ui->doubleTask1SpinBox->show();
            ui->valuespinBox->hide();
            break;
        }
        case 1:
        {
            qDebug() << "1";
            ui->resultTextEdit->hide();
            ui->resultlabel->hide();
            ui->Mlabel->show();
            ui->MspinBox->clear();
            ui->MspinBox->show();
            ui->Nlabel->show();
            ui->NspinBox->clear();
            ui->NspinBox->show();
            ui->doubleTask1SpinBox->hide();
            ui->valuespinBox->hide();
            break;
        }
        default:
        {
            ui->resultTextEdit->hide();
            ui->resultlabel->hide();
            ui->Mlabel->hide();
            ui->MspinBox->hide();
            ui->Nlabel->show();
            ui->NspinBox->hide();
            ui->doubleTask1SpinBox->hide();
            ui->valuespinBox->show();
        }
    }
}

void mainwindow::execute_task1() {
    double value = ui->doubleTask1SpinBox->value();
    ui->resultlabel->show();
    QString main_answer;
    if(value < 0)
        main_answer += '1', value = -value;
    else
        main_answer += '0';
    long double max_st = Calculate::CalculateMaxSt(value, 1);
    QString full_answer = Calculate::DecimaltoBinary(value, max_st, 0);
    qDebug() << full_answer;
    QString answer;
    bool point = false;
    for(int i = 0; i < full_answer.size(); i ++)
    {
        if(full_answer[i] == '.')
        {
            point = true;
            break;
        }
    }
    if(!point)
        full_answer += '.';
    while(full_answer[0] == '0')
    {
        full_answer.remove(0, 1);
    }
    while(full_answer.back() == '0')
    {
        full_answer.remove(full_answer.size() - 1, 1);
    }
    if(full_answer[0] == '.')
        full_answer = '0' + full_answer;
    qDebug() << full_answer << '\n';

    /*if(full_answer.back() == '.')
        full_answer.remove(full_answer.size() - 1, 1);
    if(main_answer == '1')
        full_answer = '-' + full_answer;
    ui->resultTextEdit->setText(full_answer);
    ui->resultTextEdit->show();
    ui->resultlabel->show();
    */

    int p;
    int left_one_pos = -1;
    for(int i = 0; i < full_answer.size(); i ++) {
        if (full_answer[i] == '.')
        {
            p = i;
            break;
        }
    }
    for(int i = 0; i < full_answer.size(); i ++) {
        if (full_answer[i] == '.')
        {
            break;
        }
        if(full_answer[i] == '1')
        {
            left_one_pos = i;
            break;
        }
    }
    int right_one_pos = -1;
    for(int i = full_answer.size() - 1; i >= 0; i --)
    {
        if(full_answer[i] == '.')
            break;
        if(full_answer[i] == '1')
        {
            right_one_pos = i;
            break;
        }
    }
    int move = 0;
  //  qDebug() << move << " " << p << " " << left_one_pos << " " << right_one_pos;
    if(left_one_pos != -1)
    {
        while(p != left_one_pos + 1)
        {
  //          qDebug() << "p " << p << " p-1 " << p-1 << " " << left_one_pos;
            full_answer[p] = full_answer[p - 1];
   //         qDebug() << "k";
            full_answer[p - 1] = '.';
   //         qDebug() << "k";
            p --;
   //         qDebug() << "k";
            move ++;
        }
        right_one_pos = -1;
    }
   // qDebug() << move << " " << left_one_pos << " " << right_one_pos;

    if(right_one_pos != -1)
    {
        while(p != right_one_pos)
        {
            full_answer[p] = full_answer[p + 1];
            full_answer[p + 1] = '.';
            p ++;
            move --;
        }
    }
   // qDebug() << move << " " << left_one_pos << " " << right_one_pos << " " << Calculate::DecimaltoBinary(move, 2048) ;

//    qDebug() << full_answer;
    main_answer = main_answer + "|" + Calculate::DecimaltoBinary(move + 2047, 2048) + "|";
    for(int i = p + 1; i < std::min(full_answer.size(), p + 53); i ++)
        main_answer += full_answer[i];
    while(main_answer.size() < 64)
        main_answer += "0";



    ui->resultTextEdit->setText(main_answer);
    ui->resultTextEdit->show();
    ui->resultlabel->show();
}

void mainwindow::execute_task2() {
    int m, n;
    try {
        m = ui->MspinBox->value();
    }
    catch(...){
        return;
    }
    try{
        n = ui->NspinBox->value();
    }
    catch (...){
        return;
    }
    m = std::min(m, 3);
    n = std::min(n, 12);
    ui->MspinBox->setValue(m);
    ui->NspinBox->setValue(n);
    ui->resultTextEdit->setText(QString::number(Calculate::Akkerman(m, n)));
    ui->resultTextEdit->show();
    ui->resultlabel->show();
}

void mainwindow::execute_task3() {
    int n = ui->valuespinBox->value();
    int sz = std::max((int) 1, Calculate::FindSize(n));
    int num = Calculate::swap(n, 0, sz - 1);
    ui->resultTextEdit->setText(QString::number(num));
    ui->resultTextEdit->show();
    ui->resultlabel->show();
}
