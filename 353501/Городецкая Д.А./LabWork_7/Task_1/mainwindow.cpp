#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->list->setEditTriggers(QAbstractItemView::NoEditTriggers);
    showQueue();
    gen.seed(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showQueue(int index_of_max)
{
    ui->list->clearContents();
    ui->list->setRowCount(std::max(q1.size(), q2.size()));

    auto display_queue = [&index_of_max](std::queue<int>& q, int col) {
        int i = 0;
        while (!q.empty()) {
            QTableWidgetItem *it = new QTableWidgetItem();
            it->setTextAlignment(Qt::AlignCenter);
            it->setText(QString::fromStdString(std::to_string(q.front())));
            if (index_of_max == i) {
                it->setBackground(Qt::red);
            }
            ui->list->setItem(i, col, it);
            q.pop();
            i++;
        }
    };

    display_queue(q1, 0);
    display_queue(q2, 1);

    auto display_queue_info = [](std::queue<int>& q, QLabel* size_label, QLabel* front_label, QLabel* back_label, QLabel* empty_label) {
        size_label->setText(QString::fromStdString(std::to_string(q.size())));
        if (!q.empty()) {
            front_label->setText(QString::fromStdString(std::to_string(q.front())));
            back_label->setText(QString::fromStdString(std::to_string(q.back())));
            empty_label->setText("False");
        } else {
            front_label->clear();
            back_label->clear();
            empty_label->setText("True");
        }
    };

    display_queue_info(q1, ui->Size1, ui->Front1, ui->Back1, ui->Empty1);
    display_queue_info(q2, ui->Size2, ui->Front2, ui->Back2, ui->Empty2);
}

void MainWindow::on_gen1_clicked()
{
    q1 = std::queue<int>();
    q2 = std::queue<int>();

    int size = gen() % 30 + 1;
    for (int i = 0; i < size; i++) {
        int num = gen();
        q1.push(num);
        q2.push(num);
    }
    showQueue();
}

void MainWindow::on_pop_clicked()
{
    int num = ui->spinBox->value();
    if (num == 1 && !q1.empty()) {
        q1.pop();
    } else if (num == 2 && !q2.empty()) {
        q2.pop();
    } else {
        QMessageBox::warning(this, "Error", "Firstly you should add element");
    }
    showQueue();
}

void MainWindow::on_push_clicked()
{
    int num = ui->spinBox->value();
    if (num == 1) {
        q1.push(gen());
    } else {
        q2.push(gen());
    }
    showQueue();
}

void MainWindow::on_clear_clicked()
{
    int num = ui->spinBox->value();
    if (num == 1) {
        q1 = std::queue<int>();
    } else {
        q2 = std::queue<int>();
    }
    showQueue();
}

void MainWindow::on_pushButton_clicked()
{
    if (q1.empty()) {
        QMessageBox::warning(this, "Error", "First queue is empty");
        return;
    }

    int index_of_max = 0, max_value = INT_MIN;
    std::queue<int> temp, temp2;
    int i = 0;

    while (!q1.empty()) {
        temp.push(q1.front());
        if (q1.front() > max_value) {
            index_of_max = i;
            max_value = q1.front();
        }
        q1.pop();
        i++;
    }

    while (i--) {
        q1.push(temp.front());
        temp.pop();
    }

    while (!q2.empty()) {
        temp2.push(q2.front());
        q2.pop();
    }

    while (!temp2.empty()) {
        q2.push(temp2.front());
        q1.push(temp2.front());
        temp2.pop();
    }

    while (!temp.empty()) {
        q1.push(temp.front());
        temp.pop();
    }

    showQueue(index_of_max);
}
