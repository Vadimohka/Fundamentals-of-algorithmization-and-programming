#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabWidget->setTabText(0, "Демонстрация методов");
    ui->tabWidget->setTabText(1, "Решение задачи");
    ui->insertButton->setDisabled(true);
    ui->popButton->setDisabled(true);
    ui->insertButton->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->popButton->setDisabled(false);
    queue.push(ui->insertedElComboBox->value());
    showQueue(ui->demoMethodsList, queue);
}


void MainWindow::on_popButton_clicked()
{
    queue.pop();
    if (queue.size() == 0) ui->popButton->setDisabled(true);
    showQueue(ui->demoMethodsList, queue);
}

void MainWindow::on_fillButton_clicked()
{
    ui->insertButton->setDisabled(false);
    queue1.clear();
    queue2.clear();

    for (int i = 0; i < 20; ++i) {
        queue1.push(QRandomGenerator64::global()->bounded(100));
    }
    for (int i = 0; i < 20; ++i) {
        queue2.push(QRandomGenerator64::global()->bounded(100));
    }

    showQueue(ui->queue1Widget, queue1);
    showQueue(ui->queue2Widget, queue2);
}


void MainWindow::on_insertButton_clicked()
{
    QVector<int> a = queue1.toVector(), b = queue2.toVector();
    int maxind = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[maxind] < a[i]) maxind = i;
    }

    for (int i = 0; i < b.size(); ++i) {
        a.insert(maxind + i + 1, b[i]);
    }

    queue1.clear();

    for (int i = 0; i < a.size(); ++i) {
        queue1.push(a[i]);
    }

    showQueue(ui->queue1Widget, queue1);
    showQueue(ui->queue2Widget, queue2);

    ui->insertButton->setDisabled(true);
}

void MainWindow::showQueue(QListWidget* showingWidget, Queue<int>& showedQueue)
{
    showingWidget->clear();
    for (auto el : showedQueue.toVector())
        showingWidget->addItem(QString::number(el));
}

