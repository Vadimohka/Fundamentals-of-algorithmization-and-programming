#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    button->setParent(this);
    button->setText("Рассчитать");
    button->setGeometry(200, 260, 100, 30);

    spinBoxN->setParent(this);
    spinBoxN->setGeometry(15, 30, 300, 30);
    spinBoxN->setRange(0,5);

    spinBoxM->setParent(this);
    spinBoxM->setGeometry(15, 80, 300, 30);
    spinBoxM->setRange(0,20000);

    nLabel->setParent(this);
    nLabel->setGeometry(3, 30,15,30);
    nLabel->setText("n");

    mLabel->setParent(this);
    mLabel->setGeometry(3, 80,15,30);
    mLabel->setText("m");

    ansEdit->setParent(this);
    ansEdit->setGeometry(0, 120, 315, 30);
    ansEdit->setEnabled(false);

    QPushButton::connect(button, SIGNAL(pressed()), this, SLOT(on_button_clicked()));

    connect(timer, &QTimer::timeout, [=](){
        if (spinBoxN->value() == 5) spinBoxM->setRange(0, 0);
        if (spinBoxN->value() == 4) spinBoxM->setRange(0, 1);
        else if (spinBoxN->value() == 3) spinBoxM->setRange(0, 12);
        else if (spinBoxN->value() == 2) spinBoxM->setRange(0, 10000);
        else if (spinBoxN->value() == 1) spinBoxM->setRange(0, 100000);
        else spinBoxM->setRange(0, 2147483647);

    });

    timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int MainWindow::AkkermanFunction(int m, int n)
{
    if (m == 0) return n + 1;
    else if (n == 0) return AkkermanFunction(m - 1, 1);
    else return AkkermanFunction(m - 1, AkkermanFunction(m, n - 1));
}

void MainWindow::on_button_clicked()
{

    ansEdit->setText(QString::number(AkkermanFunction(spinBoxN->value(), spinBoxM->value())));
}
