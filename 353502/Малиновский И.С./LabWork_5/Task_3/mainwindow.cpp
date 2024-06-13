#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), bitset(16)
{
    QWidget *centralWidget = new QWidget(this);

    posTextEdit = new QTextEdit(this);
    posTextEdit->setPlaceholderText("Position");

    QPushButton *flipButton = new QPushButton("Flip", this);
    QPushButton *setButton = new QPushButton("Set", this);
    QPushButton *resetButton = new QPushButton("Reset", this);
    QPushButton *testButton = new QPushButton("Test", this);

    bitsetLabel = new QLabel(this);
    bitsetLabel->setText(QString::fromStdString(bitset.to_string()));

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(posTextEdit);
    layout->addWidget(flipButton);
    layout->addWidget(setButton);
    layout->addWidget(resetButton);
    layout->addWidget(testButton);
    layout->addWidget(bitsetLabel);

    setCentralWidget(centralWidget);

    connect(flipButton, &QPushButton::clicked, this, &MainWindow::on_flipButton_clicked);
    connect(setButton, &QPushButton::clicked, this, &MainWindow::on_setButton_clicked);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::on_resetButton_clicked);
    connect(testButton, &QPushButton::clicked, this, &MainWindow::on_testButton_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_flipButton_clicked()
{
    int pos = posTextEdit->toPlainText().toInt();
    bitset.flip(pos);
    bitsetLabel->setText(QString::fromStdString(bitset.to_string()));
}

void MainWindow::on_setButton_clicked()
{
    int pos = posTextEdit->toPlainText().toInt();
    bitset.set(pos);
    bitsetLabel->setText(QString::fromStdString(bitset.to_string()));
}

void MainWindow::on_resetButton_clicked()
{
    int pos = posTextEdit->toPlainText().toInt();
    bitset.reset(pos);
    bitsetLabel->setText(QString::fromStdString(bitset.to_string()));
}

void MainWindow::on_testButton_clicked()
{
    int pos = posTextEdit->toPlainText().toInt();
    bool bit = bitset.test(pos);
    bitsetLabel->setText(bit ? "1" : "0");
}
