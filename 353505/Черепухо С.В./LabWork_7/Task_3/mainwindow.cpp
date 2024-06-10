#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>

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

void MainWindow::on_insert_btn_clicked()
{
    int key = QInputDialog::getInt(this, "Insert", "Enter a number to insert");
    hashtable.insert(key);
}


void MainWindow::on_remove_btn_clicked()
{
    int key = QInputDialog::getInt(this, "Remove", "Enter a number to remove");
    hashtable.remove(key);
}


void MainWindow::on_search_btn_clicked()
{
    int key = QInputDialog::getInt(this, "Search", "Enter a number to search");
    if (hashtable.search(key))
    {
        ui->textEdit->setText("Found");
    }
    else
    {
        ui->textEdit->setText("Not found");
    }
}


void MainWindow::on_print_btn_clicked()
{
    // show all elements in the hash table
    ui->textEdit->setText(QString::fromStdString(hashtable.toString()));
}


void MainWindow::on_loadFactor_btn_clicked()
{
    // show persentage of load factor in progress bar
    ui->LoadFactor_progBar->setValue(hashtable.getLoadFactor() * 100);
}


void MainWindow::on_execTask_btn_clicked()
{
    HashTable<int> table(20);
    for (int i = 0; i < 20; i++)
    {
        table.insert(QRandomGenerator::global()->bounded(50));
    }

    int min = 100;
    int stack = -1;

    for (size_t i = 0; i < table.getSize(); ++i) {
        Stack<int> temp = table.getTable()[i];
        while (!temp.isEmpty()) {
            int key = temp.pop();
            if (key < min) {
                min = key;
                stack = i;
            }
        }
    }

    ui->textEdit->append(QString::fromStdString(table.toString()));

    if (stack != -1) {
        ui->textEdit->append("Stack number: " + QString::number(stack) + "\nMin value: " + QString::number(min));
    }
    else {
        ui->textEdit->append("No elements in the table");
    }

}


void MainWindow::on_rand_btn_clicked()
{
    // generate random numbers and insert them into the hash table
    for (int i = 0; i < 30; i++)
    {
        hashtable.insert(QRandomGenerator::global()->bounded(50));
    }
    on_print_btn_clicked();
}

