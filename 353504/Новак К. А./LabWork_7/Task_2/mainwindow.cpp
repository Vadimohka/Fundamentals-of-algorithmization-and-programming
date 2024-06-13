#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    key = ui->Edit_Key->text().toInt();
    value = ui->Edit_Value->text();

    AVLTree<QString> tre = AVLTree<QString>(key, value);

    tree = tre;

    ui->Root->setText(tree.getRoot()->value);
}


void MainWindow::on_pushButton_2_clicked()
{
    int k = ui->Edit_AddKey->text().toInt();
    QString v = ui->Edit_AddValue->text();


    tree.insert(k,v);

   // tree.directInput(tree.getRoot());
    display();
}

void MainWindow::display()
{
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

void MainWindow::DOTask()
{
    if(tree.getRoot()->Left){
        // qDebug() << tree.findMax(tree.getRoot()->Left)->key;

        qDebug() << tree.getRoot()->Left->Right->value;

        tree.remove(tree.findMax(tree.getRoot()->Left)->key);

        display();
    }
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->Root_Left_Right->clear();

    DOTask();
}

