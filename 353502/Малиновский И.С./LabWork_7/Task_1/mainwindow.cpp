#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    inputLineEdit = new QLineEdit(this);
    inputLineEdit->setPlaceholderText("Enter an integer");

    QPushButton *enqueueButton = new QPushButton("Enqueue", this);
    QPushButton *dequeueButton = new QPushButton("Dequeue", this);
    QPushButton *sortButton = new QPushButton("Sort", this);

    listWidget = new QListWidget(this);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(enqueueButton);
    buttonLayout->addWidget(dequeueButton);
    buttonLayout->addWidget(sortButton);

    mainLayout->addWidget(inputLineEdit);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(listWidget);

    setCentralWidget(centralWidget);

    connect(enqueueButton, &QPushButton::clicked, this, &MainWindow::on_enqueueButton_clicked);
    connect(dequeueButton, &QPushButton::clicked, this, &MainWindow::on_dequeueButton_clicked);
    connect(sortButton, &QPushButton::clicked, this, &MainWindow::on_sortButton_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_enqueueButton_clicked()
{
    bool ok;
    int value = inputLineEdit->text().toInt(&ok);
    if (ok) {
        queue.enqueue(value);
        updateListWidget();
    }
}

void MainWindow::on_dequeueButton_clicked()
{
    if (!queue.isEmpty()) {
        queue.dequeue();
        updateListWidget();
    }
}

void MainWindow::on_sortButton_clicked()
{
    queue.bubbleSort();
    updateListWidget();
}

void MainWindow::updateListWidget()
{
    listWidget->clear();
    Node* current = queue.getHead(); // Используем новый метод
    while (current != nullptr) {
        listWidget->addItem(QString::number(current->data));
        current = current->next;
    }
}
