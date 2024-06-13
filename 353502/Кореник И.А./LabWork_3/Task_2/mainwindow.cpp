#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QPair<int, int>* MainWindow::input()
{
    if (ui->mValue->text().isEmpty() || ui->nValue->text().isEmpty())
        return nullptr;
    bool okM, okN;
    int m = ui->mValue->text().toInt(&okM);
    int n = ui->nValue->text().toInt(&okN);

    if (!(okN && okM))
        return nullptr;

    QPair<int, int>*ans = new QPair<int, int>{m, n};
    return ans;
}

void MainWindow::output(QPair<int, int>* input)
{
    if (input == nullptr) return;
    Mathematics* math = new Mathematics;
    QString answer = QString::number(math->Ackerman(input->first, input->second));

    ui->AckermanValue->setText(answer);
}

void MainWindow::on_countButton_clicked()
{
    output(input());
}

