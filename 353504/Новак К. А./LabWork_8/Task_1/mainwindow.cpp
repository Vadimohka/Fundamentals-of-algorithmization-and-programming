#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineKey->setInputMask("00");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Add_clicked()
{
    tree.insert(ui->lineKey->text().toInt(), ui->lineValue->text());

    display();
}

void MainWindow::display()
{
    ui->Root->clear();
    ui->Root_Left->clear();
    ui->Root_Left_Left->clear();
    ui->Root_Left_Right->clear();
    ui->Root_Right->clear();
    ui->Root_Right_Left->clear();
    ui->Root_Right_Right->clear();

    if(tree.getRoot()){
        ui->Root->setText(tree.getRoot()->value);

        if(tree.getRoot()->Left){
            ui->Root_Left->setText(tree.getRoot()->Left->value);

            if(tree.getRoot()->Left->Left){
                ui->Root_Left_Left->setText(tree.getRoot()->Left->Left->value);
            }
            if(tree.getRoot()->Left->Right){
                ui->Root_Left_Right->setText(tree.getRoot()->Left->Right->value);
            }
        }
        if(tree.getRoot()->Right){
            ui->Root_Right->setText(tree.getRoot()->Right->value);

            if(tree.getRoot()->Right->Left){
                ui->Root_Right_Left->setText(tree.getRoot()->Right->Left->value);
            }
            if(tree.getRoot()->Right->Right){
                ui->Root_Right_Right->setText(tree.getRoot()->Right->Right->value);
            }
        }
    }


}

void MainWindow::on_Remove_clicked()
{
    tree.remove(ui->lineKey->text().toInt());

    display();
}


void MainWindow::on_Find_clicked()
{
    if(ui->lineKey->text().isEmpty()){
        return;
    }

    if(tree.find(tree.getRoot(), ui->lineKey->text().toInt()) != nullptr){
        QString value = tree.find(tree.getRoot(), ui->lineKey->text().toInt())->value;

        ui->label_Find->setText(value);
    }
    else{
        ui->label_Find->setText("Unluck");
    }

}

