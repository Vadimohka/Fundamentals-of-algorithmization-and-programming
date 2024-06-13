#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->element->setMinimum(1);
    ui->element->setMaximum(1000);
    ui->numberOfElements->setMinimum(1);
    ui->numberOfElements->setMaximum(100000);
    ui->modul->setMinimum(1);
    ui->modul->setMaximum(1000000000);
    ui->element->setEnabled(false);
    ui->modul->setEnabled(false);
    ui->powerButton->setEnabled(false);

    connect(ui->sortButton, &QPushButton::clicked, this, &MainWindow::sortArray);
    connect(ui->powerButton, &QPushButton::clicked, this, &MainWindow::binPow);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::sortArray()
{
    int sz = ui->numberOfElements->value();

    if (sz > 15)
    {
        QMessageBox::information(this, "INFORMATION", "Can not visualize sorting with number of elements more than 15.");
    }

    v.resize(sz);

    for (int i = 0; i < sz; ++i)
    {
        v[i] = 1 + (rand() % 1000);
    }

    timer.start();

    if (sz <= 15)
    {
        steps = QVector<QVector<int>>();
        Sort::SortAnimation(v, steps);
        ui->timeBrowser->setText("Time: " + QString::number(timer.elapsed()) + " ms");

        QString answer = "";

        for (int i = 0; i < steps.size(); ++i)
        {
            for (int j = 0; j < steps[i].size(); ++j)
            {
                answer += QString::number(steps[i][j]) + " ";
            }

            answer += '\n';
            answer += '\n';
        }

        ui->answerBrowser->setText(answer);
    }
    else
    {
        Sort::Sorty(v);
        ui->timeBrowser->setText("Time: " + QString::number(timer.elapsed()) + " ms");
    }

    ui->element->setEnabled(true);
    ui->modul->setEnabled(true);
    ui->powerButton->setEnabled(true);
}


void MainWindow::binPow()
{
    int number = ui->element->value();
    int index = Binsearch::BinSearch(v, number);
    int modul = ui->modul->value();
    int sz = v.size();
    QString answer = "";

    answer += "index = " + QString::number(index) + '\n';
    answer += "size = " + QString::number(v.size()) + '\n';
    answer += "modul = " + QString::number(modul) + '\n';
    answer += '\n';

    int ans = 0;
    ans = Binpow::BinPow(index, sz, modul);
    answer += "ans = " + QString::number(ans);

    ui->binpowBrowser->setText(answer);
}
