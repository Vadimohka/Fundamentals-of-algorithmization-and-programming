#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qlogging.h>
#include <qpushbutton.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
  
    solver = new Solver();
    treeWidget = ui->treeWidget;
    table = ui->tableWidget;

    treeWidget->expandAll();

    connect(ui->insertBtn, &QPushButton::pressed, this, &MainWindow::add);
    connect(ui->removeBtn, &QPushButton::pressed, this, &MainWindow::remove);
    connect(ui->balanceBtn, &QPushButton::pressed, this, &MainWindow::balance);
    connect(ui->countNumNodesBtn, &QPushButton::pressed, this, &MainWindow::countNumNodesLeftBranch);
    connect(ui->preorderBtn, &QPushButton::pressed, this, &MainWindow::preorder);
    connect(ui->inorderBtn, &QPushButton::pressed, this, &MainWindow::inorder);
    connect(ui->postorderBtn, &QPushButton::pressed, this, &MainWindow::postorder);
    
}

void MainWindow::balance(){
    solver->balance();
    solver->visualize(treeWidget);
}

void MainWindow::add() {
    solver->insert(ui->insertSB->value(), ui->lineEdit->text());
    solver->visualize(treeWidget);
}

void MainWindow::remove() {
    solver->remove(ui->removeSB->value());
    solver->visualize(treeWidget);
}

void MainWindow::countNumNodesLeftBranch() {
    ui->numNodesLE->setText(QString::number(solver->numNodesInLeftmostBranch()));
}

void MainWindow::preorder() {
    auto nodes = solver->getPreorder();
    updateTable(nodes);
}

void MainWindow::inorder() {
    auto nodes = solver->getInorder();
    updateTable(nodes);
}

void MainWindow::postorder() {
    auto nodes = solver->getPostorder();
    updateTable(nodes);
}

void MainWindow::updateTable(QVector<QPair<int, QString>> nodes) {
    ui->tableWidget->clear();

    int rowCount = nodes.size();
    int columnCount = 2;
    ui->tableWidget->setRowCount(rowCount);
    ui->tableWidget->setColumnCount(columnCount);

    QStringList headers;
    headers << "Key" << "Value";
    ui->tableWidget->setHorizontalHeaderLabels(headers);

    for (int row = 0; row < rowCount; ++row) {
        for (int col = 0; col < columnCount; ++col) {
            QTableWidgetItem* item = new QTableWidgetItem();
            if (col == 0) {
                item->setData(Qt::DisplayRole, nodes[row].first);
            } else if (col == 1) {
                item->setData(Qt::DisplayRole, nodes[row].second);
            }
            ui->tableWidget->setItem(row, col, item);
        }
    }


}