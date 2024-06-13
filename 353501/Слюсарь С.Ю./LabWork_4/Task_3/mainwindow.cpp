#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    for (int i = 0; i < 9; ++i)
    {
        nums.push_back(rand() % 10);
    }
    Splitting(nums);
    ui->tableWidget->setRowCount(nums.size());
    for (int i = 0; i < 9; ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(nums[i])));
    }
    for (int i = 0; i < 3; ++i)
    {
        ui->tableWidget->setItem(i * 3 + 1, 1, new QTableWidgetItem(QString::number(meds[i])));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Splitting(QVector<int> nums)
{
    meds.clear();
    int l = nums.length();
    if (l % 3 == 0)
    {
        for (int i = 0; i < l - 1; i += 3)
        {
            meds.push_back(median(nums[i], nums[i + 1], nums[i + 2]));
        }
    }
    if (l % 3 == 1)
    {
        for (int i = 0; i < l - 2; i += 3)
        {
            meds.push_back(median(nums[i], nums[i + 1], nums[i + 2]));
        }
        meds.push_back(nums[l - 1]);
    }
    if (l % 3 == 2)
    {
        for (int i = 0; i < l - 3; i += 3)
        {
            meds.push_back(median(nums[i], nums[i + 1], nums[i + 2]));
        }
        meds.push_back(((nums[l - 1]) + nums[l - 2]) / 2.0);
    }
}

int MainWindow::median(int a, int b, int c)
{
    int arr[] = {a, b, c};
    std::sort(arr, arr + 3);
    return arr[1];
}

void MainWindow::on_add_clicked()
{
    if (ui->input->text().isEmpty())
    {
        ui->label->setText("Неверный ввод");
    }
    else
    {
        nums.push_back(ui->input->text().toInt());
        if (ui->tableWidget->rowCount() < nums.length())
        {
            ui->tableWidget->setRowCount(nums.size() + 2);
        }
        ui->tableWidget->setItem(nums.length() - 1, 0, new QTableWidgetItem(QString::number(nums[nums.length() - 1])));
        Splitting(nums);
        for (int i = 0; i < meds.length(); ++i)
        {
            ui->tableWidget->setItem(i * 3 + 1, 1, new QTableWidgetItem(QString::number(meds[i])));
        }
    }
}
