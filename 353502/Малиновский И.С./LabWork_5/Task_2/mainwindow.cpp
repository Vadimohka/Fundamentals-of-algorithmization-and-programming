#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    srcTextEdit(new QTextEdit(this)),
    destTextEdit(new QTextEdit(this)),
    str1TextEdit(new QTextEdit(this)),
    str2TextEdit(new QTextEdit(this)),
    cmpTextEdit1(new QTextEdit(this)),
    cmpTextEdit2(new QTextEdit(this)),
    cmpResultLabel(new QLabel(this))
{
    QWidget *centralWidget = new QWidget(this);

    QPushButton *copyButton = new QPushButton("Copy", this);
    QPushButton *concatButton = new QPushButton("Concat", this);
    QPushButton *compareButton = new QPushButton("Compare", this);

    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(srcTextEdit);
    layout->addWidget(destTextEdit);
    layout->addWidget(copyButton);
    layout->addWidget(str1TextEdit);
    layout->addWidget(str2TextEdit);
    layout->addWidget(concatButton);
    layout->addWidget(cmpTextEdit1);
    layout->addWidget(cmpTextEdit2);
    layout->addWidget(compareButton);
    layout->addWidget(cmpResultLabel);

    setCentralWidget(centralWidget);

    connect(copyButton, &QPushButton::clicked, this, &MainWindow::on_copyButton_clicked);
    connect(concatButton, &QPushButton::clicked, this, &MainWindow::on_concatButton_clicked);
    connect(compareButton, &QPushButton::clicked, this, &MainWindow::on_compareButton_clicked);
}

MainWindow::~MainWindow() {}

void MainWindow::on_copyButton_clicked()
{
    String src(srcTextEdit->toPlainText().toStdString().c_str());
    String dest;
    dest.strcpy(dest.c_str(), src.c_str());
    destTextEdit->setPlainText(dest.c_str());
}

void MainWindow::on_concatButton_clicked()
{
    String str1(str1TextEdit->toPlainText().toStdString().c_str());
    String str2(str2TextEdit->toPlainText().toStdString().c_str());
    str1.strcat(str1.c_str(), str2.c_str());
    str1TextEdit->setPlainText(str1.c_str());
}

void MainWindow::on_compareButton_clicked()
{
    String str1(cmpTextEdit1->toPlainText().toStdString().c_str());
    String str2(cmpTextEdit2->toPlainText().toStdString().c_str());
    int result = str1.strcmp(str1.c_str(), str2.c_str());
    cmpResultLabel->setText(QString::number(result));
}
