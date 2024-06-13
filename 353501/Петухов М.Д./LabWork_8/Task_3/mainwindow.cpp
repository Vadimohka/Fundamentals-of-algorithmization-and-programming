#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i = 0; i < 10; ++i) {
        setTree.addNode(QRandomGenerator::global()->bounded(100));
        mapTree.addNode(QRandomGenerator::global()->bounded(100), QRandomGenerator::global()->bounded(100));
    }

    ui->mapTableWidget->horizontalHeader()->setStretchLastSection(true);

    updateMapDisplay();
    updateSetDisplay();

    setFixedSize(size());
    setWindowTitle("Map and Set Example");

    // Connecting signals to slots
    connect(ui->mapInsertButton, &QPushButton::clicked, this, &MainWindow::handleMapInsert);
    connect(ui->mapRemoveButton, &QPushButton::clicked, this, &MainWindow::handleMapRemove);
    connect(ui->mapContainsButton, &QPushButton::clicked, this, &MainWindow::handleMapContains);
    connect(ui->mapClearButton, &QPushButton::clicked, this, &MainWindow::handleMapClear);
    connect(ui->setInsertButton, &QPushButton::clicked, this, &MainWindow::handleSetInsert);
    connect(ui->setRemoveButton, &QPushButton::clicked, this, &MainWindow::handleSetRemove);
    connect(ui->setContainsButton, &QPushButton::clicked, this, &MainWindow::handleSetContains);
    connect(ui->setClearButton, &QPushButton::clicked, this, &MainWindow::handleSetClear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleMapInsert()
{
    mapTree.addNode(ui->keySpinBox->value(), ui->valueSpinBox->value());
    updateMapDisplay();
}

void MainWindow::handleMapRemove()
{
    mapTree.removeNode(ui->keySpinBox->value());
    updateMapDisplay();
}

void MainWindow::handleMapContains()
{
    ui->mapResultLabel->setText(mapTree.containsKey(ui->keySpinBox->value()) ? "YES" : "NO");
}

void MainWindow::handleMapClear()
{
    mapTree.clearTree();
    updateMapDisplay();
}

void MainWindow::handleSetInsert()
{
    setTree.addNode(ui->setElementSpinBox->value());
    updateSetDisplay();
}

void MainWindow::handleSetRemove()
{
    setTree.removeNode(ui->setElementSpinBox->value());
    updateSetDisplay();
}

void MainWindow::handleSetContains()
{
    ui->setResultLabel->setText(setTree.containsKey(ui->setElementSpinBox->value()) ? "YES" : "NO");
}

void MainWindow::handleSetClear()
{
    setTree.clearTree();
    updateSetDisplay();
}

void MainWindow::updateMapDisplay()
{
    ui->mapTableWidget->clear();
    ui->mapTableWidget->setRowCount(mapTree.calculateSize());
    int row = 0;
    for (const auto& entry : mapTree) {
        ui->mapTableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(entry.key)));
        ui->mapTableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(entry.value)));
        ++row;
    }
}

void MainWindow::updateSetDisplay()
{
    QString setElements;
    for (const auto& entry : setTree) {
        setElements += QString::number(entry.key) + " ";
    }
    ui->setElementsLabel->setText(setElements);
}
