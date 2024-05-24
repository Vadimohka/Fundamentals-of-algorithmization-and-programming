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
    ui->InputArr->setValidator(&validator);
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

void MainWindow::on_InputArr_returnPressed()
{
    if (!isSorting) {
        isSorted = false;
        if (!ui->InputArr->text().isEmpty()) {
            if (isRandomPressed) {
                inputArr.clear();
                ui->textBrowser->setText("Numbers:");
                isRandomPressed = false;
            }
            inputArr.push_back(ui->InputArr->text().toInt());
            ui->textBrowser->append(ui->InputArr->text());
            sorter->setArr(inputArr);
        }
        ui->InputArr->clear();
    }
}

void MainWindow::on_pushButtonRand_clicked()
{
    if (!isSorting) {
        isSorted = false;
        isRandomPressed = true;
        inputArr.clear();
        ui->textBrowser->setText("Numbers:");
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
        ui->textBrowser->setText("Numbers:");
        sorter->setArr(inputArr);
    }
}

void MainWindow::on_SortButton_clicked()
{
    if (!isSorting) {
        isSorting = true;
        countSortings++;
        QString time;
        QString type = ui->comboBox->currentText();
        int cnt = inputArr.size();
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
        ui->tableWidget->setItem(countSortings - 1, 1, new QTableWidgetItem(QString::number(cnt)));
        ui->tableWidget->setItem(countSortings - 1, 2, new QTableWidgetItem(time));
        ui->textBrowser->setText("Numbers:");
        for (int i : inputArr) {
            ui->textBrowser->append(QString::number(i));
        }
        isSorting = false;
        isSorted = true;
    }
}

void MainWindow::on_InputNum_returnPressed()
{
    if (isSorted) {
        int digit = sorter->binSearch(ui->InputNum->text().toInt());
        int power = inputArr.size();
        int mod = ui->spinBox_mod->value();
        if (digit == -1) {
            ui->label_binPow->setText("-1");
        } else {
            ui->label_binPow->setText(QString::number(sorter->binPow(digit, power, mod)));
        }
    }
}
