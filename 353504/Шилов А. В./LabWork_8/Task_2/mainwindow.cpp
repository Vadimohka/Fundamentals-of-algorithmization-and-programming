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

void MainWindow::display(PriorityQueue<int> &priorityQueue)
{
    ui->label->clear();
    QVector<int> priorityQueueVector = priorityQueue.toVec();
    QString ans = "| ";
    for (int i : priorityQueueVector) {
        ans += QString::number(i) + ' ';
    }
    ans += "|";
    ui->label->setWordWrap(true);
    ui->label->setText(ans);
}


void MainWindow::on_bnt_add_item_clicked()
{
    binHeap.push(ui->spinBox->value());
    display(binHeap);
}


void MainWindow::on_bnt_remove_clicked()
{
    binHeap.pop();
    display(binHeap);
}


void MainWindow::on_bnt_getMax_clicked()
{
    int max = binHeap.getMax();
    QString ans = QString::number(max);
    QMessageBox::information(this, "Максимальный элемент                     ", ans);
}


void MainWindow::on_bnt_getMin_clicked()
{
    int min = binHeap.getMin();
    QString ans = QString::number(min);
    QMessageBox::information(this, "Минимальный элемент                     ", ans);
}

