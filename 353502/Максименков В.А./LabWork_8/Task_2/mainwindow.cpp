#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeView->setModel(model);
    ui->treeView->header()->hide();
    ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::insert);
    connect(ui->removeMaxButton, &QPushButton::clicked, this, &MainWindow::removeMax);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showBHList(QStandardItem *parentItem, BHList<int>::Node *node)
{
    if (bh.size() == 0)
    {
        return;
    }

    if (node == nullptr)
    {
        return;
    }

    QStandardItem* child = new QStandardItem(QString::number(node->value));
    parentItem->appendRow(child);

    showBHList(child, node->left);
    showBHList(child, node->right);
}

void MainWindow::displayBHList()
{
    model->clear();
    showBHList(model->invisibleRootItem(), bhlist.getRoot());
    ui->treeView->expandAll();
}

void MainWindow::displayBH()
{
    QString ans = "";
    QVector<int> vec = bh.getVector();
    std::queue<int> bounds;

    int counter = 1, temp = 0;
    while (temp < vec.size())
    {
        bounds.push(temp);
        ++counter;
        temp = pow(2, counter) - 2;
    }

    for (int i = 0; i < vec.size(); ++i)
    {
        ans += QString::number(vec[i]) + " ";

        if (i == bounds.front())
        {
            ans += "\n";
            bounds.pop();
        }
    }

    ui->demonstratingBrowser->setText(ans);
}

void MainWindow::insert()
{
    int value = ui->spinBox->value();
    bhlist.insert(value);
    bh.insert(value);
    displayBHList();
    displayBH();
}

void MainWindow::removeMax()
{
    int ans;

    try
    {
        ans = bh.removeMax();
        bhlist.removeMax();
        ui->maxElementBrowser->setText("Max element was " + QString::number(ans));
    }
    catch(int)
    {
        ui->maxElementBrowser->setText("Size = 0");
    }

    displayBH();
    displayBHList();
}
