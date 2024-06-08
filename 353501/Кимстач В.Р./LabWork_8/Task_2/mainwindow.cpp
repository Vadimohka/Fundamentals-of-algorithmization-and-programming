#include "mainwindow.h"
#include "ui_mainwindow.h"


mainwindow::mainwindow(QWidget *parent) :
    QWidget(parent), ui(new Ui::mainwindow) {
    ui->setupUi(this);

    connect(ui->checkBox, SIGNAL(stateChanged(int)), this, SLOT(do_init(int)));
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(add_item()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(get_max()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(extract_max()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(increase_position()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(decrease_position()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(increase_value()));
    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(decrease_value()));

}

mainwindow::~mainwindow() {
    delete ui;
}

void mainwindow::do_init(int t) {
    type = t;
    if(type)
    {
        // list
        heapList.clear();
        Display();
    }
    else
    {
        heapArray.clear();
        Display();
    }
}

void mainwindow::Display() {
    std::vector<int> v;
    if(type)
    {
        v = heapList.GetHeap();

    }
    else
    {
        v = heapArray.GetHeap();
    }
    ui->plainTextEdit->clear();
    QString s;
    for(int i = 0; i < v.size(); i ++)
    {
        s = s + QString::number(v[i]) + " ";
    }
    ui->plainTextEdit->setPlainText(s);
}

void mainwindow::add_item() {
    int t = ui->plainTextEdit_2->toPlainText().toInt();
    if(type)
    {
        heapList.add(t);
        ui->plainTextEdit_2->clear();
        Display();
    }
    else
    {
        heapArray.add(t);
        ui->plainTextEdit_2->clear();
        Display();
    }
}

void mainwindow::get_max() {
    if(type)
    {
        ui->plainTextEdit_2->setPlainText(QString::number(heapList.getMax()));
    }
    else
    {
        ui->plainTextEdit_2->setPlainText(QString::number(heapArray.getMax()));
    }
}

void mainwindow::extract_max() {
    if(type)
    {
        heapList.ExtractMax();
        Display();
    }
    else
    {
        heapArray.ExtractMax();
        Display();
    }
}

void mainwindow::increase_position() {
    int i = ui->plainTextEdit_3->toPlainText().toInt();
    int value = ui->plainTextEdit_4->toPlainText().toInt();
    if(type)
    {

    }
    else
    {
        heapArray.increaseElement(i, value);
        Display();
    }
}

void mainwindow::decrease_position() {
    int i = ui->plainTextEdit_3->toPlainText().toInt();
    int value = ui->plainTextEdit_4->toPlainText().toInt();
    if(type)
    {

    }
    else
    {
        heapArray.decreaseElement(i, value);
        Display();
    }
}

void mainwindow::increase_value() {
    int i = ui->plainTextEdit_5->toPlainText().toInt();
    int value = ui->plainTextEdit_6->toPlainText().toInt();
    if(type)
    {
        heapList.increaseValue(i, value);
        Display();
    }
    else
    {
        heapArray.increaseValue(i, value);
        Display();
    }
}

void mainwindow::decrease_value() {
    int i = ui->plainTextEdit_5->toPlainText().toInt();
    int value = ui->plainTextEdit_6->toPlainText().toInt();
    if(type)
    {
        heapList.decreaseValue(i, value);
        Display();
    }
    else
    {
        heapArray.decreaseValue(i, value);
        Display();
    }
}
