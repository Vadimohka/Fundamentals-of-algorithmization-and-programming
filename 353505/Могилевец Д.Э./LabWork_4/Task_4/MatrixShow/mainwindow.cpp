#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    fillData();
    setupUi();
    displayMatrices();
    this->setMinimumSize(800, 300);
    setWindowTitle("Показ матриц");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupUi()
{
    tableWidget = new QTableWidget(this);
    setCentralWidget(tableWidget);
    setWindowTitle("Matrix Viewer");
}

void MainWindow::displayMatrices()
{
    if (data.empty()) {
        QMessageBox::warning(this, "Empty Data", "No data to display.");
        return;
    }

    int rowCount = data[0].first.size();
    int colCount1 = data[0].first.size();
    int colCount2 = data[0].second.size();
    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(colCount1 + colCount2);
    QStringList headers;
    for (int i = 0; i < colCount1; ++i) {
        headers << QString("Matrix 1, Col %1").arg(i + 1);
    }
    for (int i = 0; i < colCount2; ++i) {
        headers << QString("Matrix 2, Col %1").arg(i + 1);
    }
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount1; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[0].first[j]));
            tableWidget->setItem(i, j, item);
        }
        for (int j = 0; j < colCount2; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[0].second[j].first) + ", " +
                                                          QString::number(data[0].second[j].second));
            tableWidget->setItem(i, colCount1 + j, item);
        }
    }
}


void MainWindow::fillData()
{
    Vector<int> vecInt1 = {1, 2, 3};
    Vector<int> vecInt2 = {4, 5, 6};
    Vector<int> vecInt3 = {7, 8, 9};
    Vector<pair<int, double>> vecPair1 = {{1, 1.1}, {2, 2.2}, {3, 3.3}};
    Vector<pair<int, double>> vecPair2 = {{4, 4.4}, {5, 5.5}, {6, 6.6}};
    Vector<pair<int, double>> vecPair3 = {{7, 7.7}, {8, 8.8}, {9, 9.9}};
    data.push_back({vecInt1, vecPair1});
    data.push_back({vecInt2, vecPair2});
    data.push_back({vecInt3, vecPair3});
}
