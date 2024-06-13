#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->sizeSpinBox->setMinimum(1);
    ui->sizeSpinBox->setMaximum(30);
    connect(ui->createButton, &QPushButton::clicked, this, &MainWindow::createVectorWithMedians);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::createVectorWithMedians()
{
    QVector<int> v;
    int sz = ui->sizeSpinBox->value();
    int temp = 0;

    srand(time(nullptr));
    for (int i = 0; i < sz; ++i)
    {
        temp = 1 + rand() % 100;
        v.push_back(temp);
    }

    QString ans = "vector = ";
    for (int i = 0; i < sz; ++i)
    {
        ans += QString::number(v[i]) + " ";
        if (i % 3 == 2) ans += "   ";
    }
    ans.push_back('\n');
    ans += "medians = ";

    MediansSearcher* median = new MediansSearcher(v);
    QVector<double> vectorWithMedians;
    vectorWithMedians = median->crateMedians();

    for (int i = 0; i < vectorWithMedians.size(); ++i)
    {
        ans += QString::number(vectorWithMedians[i]) + " ";
    }

    ui->answerBrowser->setText(ans);
}












