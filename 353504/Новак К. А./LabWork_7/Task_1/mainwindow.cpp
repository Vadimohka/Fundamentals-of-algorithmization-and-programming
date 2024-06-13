#include "mainwindow.h"
#include "./ui_mainwindow.h"

const int ELEMENT_LIMIT = 100;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Size_Edit_editingFinished()
{
    if(ui->Size_Edit->text().toInt() > 10){
        return;
    }

    int size = ui->Size_Edit->text().toInt();

    MyDeque<int> t = MyDeque<int>();

    while(size--){
        t.push_back(rand() % ELEMENT_LIMIT);
    }

    dq = t;

    display = "";

    int c = 0;
    DequeIterator<int> iterator = dq.begin();
    for(; iterator != dq.end(); ++iterator){
        if(iterator == dq.begin()){
            c++;
            if(c == 2){
                break;
            }
        }
        display += QString().setNum(*iterator) + " ";
        qDebug() << *iterator;
    }

    ui->label_2->setText(display);
}


void MainWindow::on_pushButton_clicked()
{
    MyDeque<int> t = MyDeque<int>();

    for(int i = 0; i < dq.size(); ++i){
        if(dq.at(i) > 0){
            t.push_back(t.at(i));
        }
    }

    QString answer = "";

    int c = 0;
    DequeIterator<int> iterator = t.begin();
    for(; iterator != t.end(); ++iterator){
        if(iterator == t.begin()){
            c++;
            if(c == 2){
                break;
            }
        }
        answer += QString().setNum(*iterator) + " ";
        qDebug() << *iterator;
    }

    ui->label_4->setText(answer);
}

