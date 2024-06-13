#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    updateUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_randomButton1_clicked()
{
    fillRandom(deque1, ui->listWidget1);
    updateUI();
}

void MainWindow::on_buttonTask_clicked()
{
    deque1.remove_between_max_min();
    updateUI();
}

void MainWindow::updateUI()
{
    displayDeque(deque1, ui->listWidget1);

    ui->label11->setText(deque1.is_empty() ? "Да" : "Нет");
    ui->label12->setText(QString::number(deque1.get_size()));
    ui->label13->setText(deque1.is_empty() ? "-" : QString::number(deque1.front()));
    ui->label14->setText(deque1.is_empty() ? "-" : QString::number(deque1.back()));
}

void MainWindow::fillRandom(Deque<int> &deque, QListWidget *listWidget)
{
    while (!deque.is_empty()) {
        deque.pop_back();
    }

    for (int i = 0; i < 10; ++i) {
        int randomValue = QRandomGenerator::global()->bounded(1, 100);
        deque.push_back(randomValue);
    }

    updateUI();
}

void MainWindow::displayDeque(const Deque<int> &deque, QListWidget *listWidget)
{
    listWidget->clear();
    Node<int>* current = deque.get_head();
    while (current) {
        listWidget->addItem(QString::number(current->data));
        current = current->next;
    }
}


void MainWindow::on_pushBackButton_clicked()
{
    deque1.push_back(ui->spinBoxQ1->value());
    updateUI();
}


void MainWindow::on_pushFrontButton_clicked()
{
    deque1.push_front(ui->spinBoxQ1->value());
    updateUI();
}


void MainWindow::on_popFrontButton_clicked()
{
    try {
        int deleted_element = deque1.pop_front();
        ui->labelDeletedItem->setText(QString::number(deleted_element));
    } catch (const std::exception &e) {

    }
    updateUI();
}


void MainWindow::on_popBackButton_clicked()
{
    try {
        int deleted_element = deque1.pop_back();
        ui->labelDeletedItem->setText(QString::number(deleted_element));
    } catch (const std::exception &e) {

    }
    updateUI();
}
