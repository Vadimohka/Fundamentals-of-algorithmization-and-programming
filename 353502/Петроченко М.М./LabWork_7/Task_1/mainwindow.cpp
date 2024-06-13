//
// Created by acryoz on 22.05.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QWidget(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->list_widget1 = new QListWidget;
    this->list_widget1->setMinimumSize(LIST_MIN_SIZE);
    this->list_widget2 = new QListWidget;
    this->list_widget2->setMinimumSize(LIST_MIN_SIZE);
    this->list_widget3 = new QListWidget;
    this->list_widget3->setMinimumSize(LIST_MIN_SIZE);
    this->task_button = new QPushButton("Do task");
    this->task_button->setMinimumSize(BUTTON_MIN_SIZE);
    QObject::connect(this->task_button, SIGNAL(clicked()), this,
                     SLOT(doTask()));

    this->upper_hbox = new QHBoxLayout;
    this->upper_hbox->addWidget(this->list_widget1);
    this->upper_hbox->addWidget(this->task_button);

    this->lower_hbox = new QHBoxLayout;
    this->lower_hbox->addWidget(this->list_widget2);
    this->lower_hbox->addWidget(this->list_widget3);

    this->vbox = new QVBoxLayout;
    this->vbox->addLayout(this->upper_hbox);
    this->vbox->addLayout(this->lower_hbox);

    this->setLayout(this->vbox);
}

void MainWindow::doTask() {
    this->list_widget1->clear();
    this->list_widget2->clear();
    this->list_widget3->clear();
    QRandomGenerator gen(
        std::chrono::system_clock::now().time_since_epoch().count());
    for (size_t i = 0; i < QUEUE_LEN; ++i) {
        this->queue1.push(gen.bounded(0, 100));
    }
    uint32_t greatest_index = 0;
    uint32_t smallest_index = 0;
    uint32_t greatest = 0;
    uint32_t smallest = UINT32_MAX;
    uint32_t val;
    for (int i = 0; i < queue1.size(); ++i) {
        val = queue1.front();
        if (val > greatest) {
            greatest = queue1.front();
            greatest_index = i;
        }
        if (queue1.front() < smallest) {
            smallest = queue1.front();
            smallest_index = i;
        }
        queue1.cycle_pop();
    }
    auto vec = this->qtovec(this->queue1);
    std::sort(vec.begin(), vec.end());
    qDebug() << vec.front() << vec.back();
    uint32_t start = greatest_index;
    uint32_t end = smallest_index;
    uint32_t q1_len = queue1.size();
    if (greatest_index > smallest_index) {
        std::swap(start, end);
    }
    for (int i = 0; i <= start; ++i) {
        queue3.push(queue1.front());
        queue1.cycle_pop();
    }
    for (int i = start + 1; i < end; ++i) {
        queue2.push(queue1.front());
        queue1.cycle_pop();
    }
    for (int i = end; i < q1_len; ++i) {
        queue3.push(queue1.front());
        queue1.cycle_pop();
    }
    buildLists();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::buildLists() {
    QStringList list1;
    QStringList list2;
    QStringList list3;
    uint32_t size1 = queue1.size();
    uint32_t size2 = queue2.size();
    uint32_t size3 = queue3.size();
    for (int i = 0; i < size1; ++i) {
        list1.push_back(QString::number(this->queue1.front()));
        this->queue1.pop();
    }
    for (int i = 0; i < size2; ++i) {
        list2.push_back(QString::number(this->queue2.front()));
        this->queue2.pop();
    }
    for (int i = 0; i < size3; ++i) {
        list3.push_back(QString::number(this->queue3.front()));
        this->queue3.pop();
    }
    this->list_widget1->addItems(list1);
    this->list_widget2->addItems(list2);
    this->list_widget3->addItems(list3);
}

QVector<uint32_t> MainWindow::qtovec(Queue<uint32_t>& queue) {
    QVector<uint32_t> res;
    for (int i = 0; i < queue.size(); ++i) {
        res.push_back(queue.front());
        queue.cycle_pop();
    }
    return res;
}
