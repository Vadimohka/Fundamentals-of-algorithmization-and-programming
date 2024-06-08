#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <random>
#include <QMessageBox>
MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    for(int i = 0;i < 10;++i){
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> num(1, 10);
        queue.pushFront(num(generator));
    }
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    ui->listWidget->addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
    connect(ui->pushBackBut,&QPushButton::clicked,this,&MainWindow::pushBackSlot);
    connect(ui->pushFrontBut,&QPushButton::clicked,this,&MainWindow::pushFrontSlot);
    connect(ui->popBackBut,&QPushButton::clicked,this,&MainWindow::popBackSlot);
    connect(ui->popFrontBut,&QPushButton::clicked,this,&MainWindow::popFrontSlot);
    connect(ui->clearBut,&QPushButton::clicked,this,&MainWindow::clearSlot);
    connect(ui->swapMinAndMax,&QPushButton::clicked,this,&MainWindow::swapMinAndMax);
}
void MainWindow::pushBackSlot() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> num(1, 10);
    int el = num(generator);
    queue.pushBack(el);
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
}
void MainWindow::pushFrontSlot() {
    std::random_device rd;
    std::mt19937 generator(rd());
    std::uniform_int_distribution<int> num(1, 10);
    int el = num(generator);
    queue.pushFront(el);
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
}
void MainWindow::popBackSlot() {
    if(queue.isEmpty()){
        QMessageBox::warning(this, "Warning", "Queue is empty");
        return;
    }
    queue.popBack();
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    if(queue.isEmpty()){
        output += "empty";
    }
    addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
}
void MainWindow::popFrontSlot() {
    if(queue.isEmpty()){
        QMessageBox::warning(this, "Warning", "Queue is empty");
        return;
    }
    queue.popFront();
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    if(queue.isEmpty()){
        output += "empty";
    }
    addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
}
void MainWindow::clearSlot() {
    if(queue.isEmpty()){
        QMessageBox::warning(this, "Warning", "Queue is empty");
        return;
    }
    queue.clear();
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    output += "empty";
    addItem(output);
    //ui->listWidget->addItem(output);
    ui->sizeLabel->setText(QString::number(queue.size()));
}
void MainWindow::swapMinAndMax() {
    if(queue.isEmpty()){
        QMessageBox::warning(this, "Warning", "Queue is empty");
        return;
    }
    queue.swapMaxMin();
    output.clear();
    for (Node<int> *curr = queue.front; curr != nullptr; curr = curr->next) {
        output += QString::number(curr->data) + " ";
    }
    addItem(output);
}
void MainWindow::addItem(QString output){
    ui->listWidget->addItem(output);
    ui->listWidget->scrollToBottom();
}