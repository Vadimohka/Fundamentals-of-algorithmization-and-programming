#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new QTreeWidget(ui->treeView);

    tree->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tree->resize(500, 500);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    int data = 0;
    bool ok;
    int id = QInputDialog::getInt(nullptr, "Input", "Enter the Id value: ", 1, -100, 100, 1, &ok);
    if (ok)
    {
        data = id;
    }
    heap.addNodeToTree(data, tree);
}

void MainWindow::on_insert_btn_clicked()
{
    tree->clear();
    addNode();
}


void MainWindow::on_remove_btn_clicked()
{
    int val = QInputDialog::getInt(nullptr, "Input", "Enter the value to remove: ", 1, -100, 100, 1);
    heap.remove(val);
    heap.update(tree);
}


void MainWindow::on_print_btn_clicked()
{
    QString res = heap.inOrder();
    ui->lineEdit->setText(res);
}


void MainWindow::on_getMax_btn_clicked()
{
    int res = heap.getMax();
    QMessageBox::information(nullptr, "Get Max", "Max value: " + QString::number(res));
}


void MainWindow::on_extrMax_btn_clicked()
{
    int res = heap.extractMax();
    QMessageBox::information(nullptr, "Extract Max", "Extracted Max value: " + QString::number(res));
    heap.update(tree);
}

