#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->insertButton, &QPushButton::clicked, this, &MainWindow::on_insertButton_clicked);
    connect(ui->deleteButton, &QPushButton::clicked, this, &MainWindow::on_deleteButton_clicked);
    ui->treeViewWidget->setTree(&tree);
    connect(ui->findButton, &QPushButton::clicked, this, &MainWindow::on_findButton_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertButton_clicked()
{
    bool ok;
    int value = QInputDialog::getInt(this, tr("Insert Node"), tr("Node Value:"), 0, -2147483647, 2147483647, 1, &ok);
   
        Node* node = tree.find(tree.getRoot(), value);
    if (node != nullptr) {
        return;
    }
     else {
        if (ok) {
        tree.insertValue(value);
        findAndUpdateTreeView(value);
        }
    }
   
   
}

void MainWindow::on_deleteButton_clicked()
{
    bool ok;
    int value = QInputDialog::getInt(this, tr("Delete Node"), tr("Node Value:"), 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
        tree.deleteValue(value);
        findAndUpdateTreeView(value);
    }
}

void MainWindow::updateTreeView()
{
    ui->treeViewWidget->update();
}

void MainWindow::findAndUpdateTreeView(int value)
{
    Node* node = tree.find(tree.getRoot(), value);
    if (node != nullptr) {
        ui->treeViewWidget->update();
    }
}



void MainWindow::on_findButton_clicked()
{
    bool ok;
    int value = QInputDialog::getInt(this, tr("Find Node"), tr("Node Value:"), 0, -2147483647, 2147483647, 1, &ok);
    if (ok) {
       
        Node* node = tree.find(tree.getRoot(), value);
    if (node != nullptr) {
        ui->treeViewWidget->update();
        QMessageBox::information(this, "Результат поиска", "Да");
    } else {
        QMessageBox::information(this, "Результат поиска", "Нет");
    }
    }
}