#include "widget.h"
#include "./ui_widget.h"
#include <QRandomGenerator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    refreshMatrix();
    refreshTable();

    connect(ui->pushButton, &QPushButton::clicked, this, [this](){
        refreshMatrix();
        refreshTable();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::refreshTable()
{
    int rowCount = data[0].first.size();
    int colCount1 = data[0].first.size();
    int colCount2 = data[0].second.size();
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(colCount1 + colCount2);
    QStringList headers;
    for (int i = 0; i < colCount1; ++i) {
        headers << QString("Matrix 1, Col %1").arg(i + 1);
    }
    for (int i = 0; i < colCount2; ++i) {
        headers << QString("Matrix 2, Col %1").arg(i + 1);
    }
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int i = 0; i < rowCount; ++i) {
        for (int j = 0; j < colCount1; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[0].first[j]));
            ui->tableWidget->setItem(i, j, item);
        }
        for (int j = 0; j < colCount2; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(data[0].second[j].first) + ", " +
                                                          QString::number(data[0].second[j].second));
            ui->tableWidget->setItem(i, colCount1 + j, item);
        }
    }
}


void Widget::refreshMatrix()
{

    data.clear();

    Vector<int> tempInt;

    for(int i = 0; i<27; ++i)
    {
        tempInt.push_back(QRandomGenerator::global()->bounded(1, 100));
    }

    Vector<int> vecInt1 = {tempInt[1], tempInt[2], tempInt[3]};
    Vector<int> vecInt2 = {tempInt[4], tempInt[5], tempInt[6]};
    Vector<int> vecInt3 = {tempInt[7], tempInt[8], tempInt[9]};
    Vector<pair<int, double>> vecPair1 = {{tempInt[10], static_cast<double>(tempInt[18])/10}, {tempInt[11], static_cast<double>(tempInt[19])/10}, {tempInt[12], static_cast<double>(tempInt[20])/10}};
    Vector<pair<int, double>> vecPair2 = {{tempInt[13], static_cast<double>(tempInt[21])/10}, {tempInt[22], static_cast<double>(tempInt[23])/10}, {tempInt[15], static_cast<double>(tempInt[24])/10}};
    Vector<pair<int, double>> vecPair3 = {{tempInt[16], static_cast<double>(tempInt[25])/10}, {tempInt[17], static_cast<double>(tempInt[26])/10}, {tempInt[0], static_cast<double>(tempInt[22])/10}};
    data.push_back({vecInt1, vecPair1});
    data.push_back({vecInt2, vecPair2});
    data.push_back({vecInt3, vecPair3});
}
