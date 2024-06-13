#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , sorter(new Sort)
    , validator(LEFT_BORDER, RIGHT_BORDER, this)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(sorter);

    ui->InputNum->setValidator(&validator);

    random = QRandomGenerator::global();
    countSortings = 0;
    isSorting = false;
    isSorted = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonRand_clicked()
{
    if (!isSorting) {
        isSorted = false;
        isRandomPressed = true;
        inputArr.clear();
        int border = ui->spinBoxCount->value();
        int num = 0;
        for (int i = 0; i < border; i++) {
            num = random->bounded(LEFT_BORDER, RIGHT_BORDER);
            inputArr.push_back(num);
            ui->textBrowser->append(QString::number(num));
        }
        sorter->setArr(inputArr);
    }
}

void MainWindow::on_ClearButton_clicked()
{
    if (!isSorting) {
        inputArr.clear();
        sorter->setArr(inputArr);
        ui->textBrowser->clear();
    }
}

void MainWindow::on_SortButton_clicked()
{
    if (!isSorting) {
        isSorting = true;
        countSortings++;
        QString time;
        QString type = ui->comboBox->currentText();
        if (!inputArr.empty()) {
            if (type == "Heap") {
                time = sorter->heapSort();
            } else if (type == "Quick") {
                time = sorter->quickSort();
            } else if (type == "Merge") {
                time = sorter->mergeSort();
            } else if (type == "Interpolation") {
                time = sorter->interpolationSort();
            }
            inputArr = sorter->getArr();
        }
        ui->tableWidget->setRowCount(countSortings);
        ui->tableWidget->setItem(countSortings - 1, 0, new QTableWidgetItem(type));
        ui->tableWidget->setItem(countSortings - 1, 1, new QTableWidgetItem(time));
        isSorting = false;
        isSorted = true;
    }
}


void MainWindow::on_binsearch_clicked()
{
    if (isSorted) {
        int digit = sorter->binSearch(ui->InputNum->text().toInt());
        ui->label->setText(QString::number(digit));
    }
}

void MainWindow::on_binpow_clicked()
{
    if (isSorted && !ui->mod->text().isEmpty()) {
        int digit = sorter->binSearch(ui->InputNum->text().toInt());
        int power = inputArr.size();
        int mod = ui->mod->text().toInt();
        if (digit == -1) {
            ui->label_binPow->setText("-1");
        } else {
            ui->label_binPow->setText(QString::number(sorter->binPow(digit, power, mod)));
        }
    }
}
