#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    textEdit(new QTextEdit(this)),
    lineEdit(new QLineEdit(this)),
    enqueueButton(new QPushButton("Enqueue", this)),
    dequeueButton(new QPushButton("Dequeue", this)),
    convertToRingButton(new QPushButton("Convert to Ring", this)) {

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(textEdit);
    layout->addWidget(lineEdit);
    layout->addWidget(enqueueButton);
    layout->addWidget(dequeueButton);
    layout->addWidget(convertToRingButton);

    QWidget* centralWidget = new QWidget(this);
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);

    connect(enqueueButton, &QPushButton::clicked, this, &MainWindow::on_enqueueButton_clicked);
    connect(dequeueButton, &QPushButton::clicked, this, &MainWindow::on_dequeueButton_clicked);
    connect(convertToRingButton, &QPushButton::clicked, this, &MainWindow::on_convertToRingButton_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_enqueueButton_clicked() {
    QString text = lineEdit->text();
    if (!text.isEmpty()) {
        deque.enqueue(text.toStdString());
        deque.displayQueue(textEdit);
        lineEdit->clear();
    }
}

void MainWindow::on_dequeueButton_clicked() {
    try {
        deque.dequeue();
        deque.displayQueue(textEdit);
    } catch (const std::exception& e) {
        textEdit->append("Queue is empty");
    }
}

void MainWindow::on_convertToRingButton_clicked() {
    deque.convertToRing();
    deque.displayQueue(textEdit);
}
