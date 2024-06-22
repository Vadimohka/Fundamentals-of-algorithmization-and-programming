#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QLabel *mLabel = new QLabel("m: ", this);
    QLabel *nLabel = new QLabel("n: ", this);
    res = new QLabel(this);
    mEdit = new QLineEdit(this);
    nEdit = new QLineEdit(this);
    QPushButton *push = new QPushButton("calculate A(m,n)", this);

    ui->gridLayout->addWidget(mLabel, 0, 0);
    ui->gridLayout->addWidget(mEdit, 0, 1);
    ui->gridLayout->addWidget(nLabel, 1, 0);
    ui->gridLayout->addWidget(nEdit, 1, 1);
    ui->gridLayout->addWidget(push, 2, 0);
    ui->gridLayout->addWidget(res, 2, 2);

    connect(push, SIGNAL(clicked()), this, SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::calc(int m, int n)
{
    int result = 0;
    if (m == 0) {
        result = n + 1;
    } else if (m > 0 && n == 0) {
        result = calc(m - 1, 1);
    } else if (m > 0 && n > 0) {
        result = calc(m - 1, calc(m, n - 1));
    }
    return result;
}

void MainWindow::click()
{
    int m = mEdit->text().toInt();
    int n = nEdit->text().toInt();

    int result = calc(m, n);
    res->setText(QString::number(result));
}

