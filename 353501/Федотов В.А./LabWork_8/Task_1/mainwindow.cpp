#include "mainwindow.h"
#include "solver.h"
#include "ui_mainwindow.h"
#include <cstdlib>
#include <ctime>
#include <qcontainerfwd.h>
#include <qlogging.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qspinbox.h>
#include <qtreewidget.h>

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);

    srand(time(nullptr));
  
    mainTree = new Solver();
    secondTree = new Solver();

    currentTree = mainTree;


    currentTreeWidget = ui->treeWidget;
    table = ui->tableWidget;

    currentTreeWidget->expandAll();

    generateRandomNode();

    connect(ui->insertBtn, &QPushButton::pressed, this, &MainWindow::add);
    connect(ui->removeBtn, &QPushButton::pressed, this, &MainWindow::remove);
    connect(ui->preorderBtn, &QPushButton::pressed, this, &MainWindow::preorder);
    connect(ui->inorderBtn, &QPushButton::pressed, this, &MainWindow::inorder);
    connect(ui->postorderBtn, &QPushButton::pressed, this, &MainWindow::postorder);
    connect(ui->removeSubtreeBtn, &QPushButton::pressed, this, &MainWindow::removeSubtree);
    connect(ui->insertSecondBtn, &QPushButton::pressed, this, &MainWindow::insertSecond);
    connect(ui->lcaBtn, &QPushButton::pressed, this, &MainWindow::findLowestCommon);

    connect(ui->mainRB, &QRadioButton::pressed, this, &MainWindow::setMain);
    connect(ui->secondRB, &QRadioButton::pressed, this, &MainWindow::setSecond);

    connect(ui->treeWidget, &QTreeWidget::itemClicked, this, &MainWindow::handleTreeClicked);
}

void MainWindow::setMain() { 
    currentTree = mainTree; 
    currentTreeWidget = ui->treeWidget;
}
void MainWindow::setSecond() { 
    currentTree = secondTree; 
    currentTreeWidget = ui->secondTreeWidget;
}

void MainWindow::add() {
    currentTree->insert(ui->insertSB->value(), ui->lineEdit->text());
    currentTree->visualize(currentTreeWidget);
    generateRandomNode();
}

void MainWindow::remove() {
    currentTree->removeByValue(ui->lineEdit->text());
    currentTree->visualize(currentTreeWidget);
}

void MainWindow::removeSubtree() {
    int key = currentTree->findByValue(ui->lineEdit->text());
    if (key == -1)
        return;

    currentTree->clearFrom(key);
    currentTree->visualize(currentTreeWidget);
}

void MainWindow::insertSecond() {
    mainTree->insertSubtree(*secondTree);
    mainTree->visualize(ui->treeWidget);
}

void MainWindow::preorder() {
    auto nodes = currentTree->getPreorder();
    updateTable(nodes);
}

void MainWindow::inorder() {
    auto nodes = currentTree->getInorder();
    updateTable(nodes);
}

void MainWindow::postorder() {
    auto nodes = currentTree->getPostorder();
    updateTable(nodes);
}

void MainWindow::findLowestCommon() {
    int res = currentTree->lowestParentKey(ui->lcaSB1->value(), ui->lcaSB2->value());
    ui->lcaLE->setText(QString::number(res));
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

void MainWindow::handleTreeClicked(QTreeWidgetItem* item, int column) {
    QString itemText = item->text(column);
    QString trimmedText = itemText.section(':', 1).trimmed();
    
    ui->lineEdit->setText(trimmedText);
}

void MainWindow::generateRandomNode() {
    static const QString characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    QString randomString;

    for (int i = 0; i < 6; ++i) {
        int randomIndex = rand() % characters.length();
        QChar randomChar = characters.at(randomIndex);
        randomString.append(randomChar);
    }

    ui->lineEdit->setText(randomString);
    ui->insertSB->setValue(rand() % 99);
}