#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::UpdateDeque()
{
    ui->listWidget->clear();

    if(!deque.empty()){
        auto it = deque.begin();
        do {
            ui->listWidget->addItem((*it));
            ++it;
        } while (it != deque.end());
    }
    int size = deque.size();
    ui->lcdNumber->display(size);
}

void MainWindow::on_pushButton_pushBack_clicked()
{
    deque.push_back(QInputDialog::getText(nullptr, tr("User Input"), "Enter value:"));
    UpdateDeque();
}


void MainWindow::on_pushButton_pushFront_clicked()
{
    deque.push_front(QInputDialog::getText(nullptr, tr("User Input"), "Enter value:"));
    UpdateDeque();
}


void MainWindow::on_pushButton_popBack_clicked()
{
    if (deque.empty())
    {
        QMessageBox::information(nullptr, tr("Pop Back"), "Deque is empty", QMessageBox::Ok | QMessageBox::NoButton);
        return;
    }
    deque.pop_back();
    UpdateDeque();
}


void MainWindow::on_pushButton_popFront_clicked()
{
    if (deque.empty())
    {
        QMessageBox::information(nullptr, tr("Pop Front"), "Deque is empty");
        return;
    }
    deque.pop_front();
    UpdateDeque();
}


void MainWindow::on_pushButton_clear_clicked()
{
    if (deque.empty())
    {
        QMessageBox::information(nullptr, tr("Clear"), "Deque is empty");
        return;
    }
    deque.clear();
    UpdateDeque();
}

