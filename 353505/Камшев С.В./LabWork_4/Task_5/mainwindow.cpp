#include "mainwindow.h"
#include "ui_mainwindow.h"

std::random_device MainWindow::rd;
std::mt19937 MainWindow::gen(rd());

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSize currentSize = size();
    setFixedSize(currentSize);
    ui->left_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->right_tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    modelL = new QStandardItemModel(0, 2, this);
    modelR = new QStandardItemModel(0, 3, this);
    ui->left_tableView->setModel(modelL);
    ui->right_tableView->setModel(modelR);
    modelL->setHeaderData(0, Qt::Horizontal, "INT1");
    modelL->setHeaderData(1, Qt::Horizontal, "Ссылка");

    modelR->setHeaderData(0, Qt::Horizontal, "INT");
    modelR->setHeaderData(1, Qt::Horizontal, "DOUBLE");
    modelR->setHeaderData(2, Qt::Horizontal, "Ссылка");

    Vector<pair<Vector<int>, Vector<pair<int, double>>>> vec;
    vec.resize(1);
    for (int i = 0; i < 30; i++) {
        vec[0].first.push_back(getRandomNumber(0, 100));
        vec[0].second.push_back(
            {
                getRandomNumber(0, 100),
                static_cast<double>(getRandomNumber(0, 100)) / 5
            }
            );
    }
    for (int i = 0; i < 30; ++i) {
        modelL->insertRow(i);
        QModelIndex index = modelL->index(i, 0);
        modelL->setData(index, vec[0].first[i]);
        index = modelL->index(i, 1);
        modelL->setData(index, vec[0].first[i]);

        modelR->insertRow(i);
        index = modelR->index(i, 0);
        modelR->setData(index, vec[0].second[i].first);
        index = modelR->index(i, 1);
        modelR->setData(index, vec[0].second[i].second);
        index = modelR->index(i, 2);
        modelR->setData(index, vec[0].second[i].first);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::getRandomNumber(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}
