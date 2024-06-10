#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QRandomGenerator>
#include <QMessageBox>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new QTreeWidget(ui->treeView);

    tree->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    tree->resize(500, 500);


    // tree->header()->setStretchLastSection(true);
    // tree->header()->setMinimumSectionSize(300);
    // tree->header()->resizeSection(0, 300);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addNode()
{
    int key = 0;
    QString data;
    bool ok = false;
    QString name = QInputDialog::getText(nullptr, "Enter Name", "Enter the name: ", QLineEdit::Normal, "", &ok);
    if (ok)
    {
        data = name;
    }
    int id = QInputDialog::getInt(nullptr, "Input", "Enter the Id value: ", 1, -100, 100, 1, &ok);
    if (ok)
    {
        key = id;
    }
    ui->key_spinBox->setValue(id);
    bst.addNodeToTree(key, data, tree);
}

void MainWindow::on_insert_btn_clicked()
{
    tree->clear();
    addNode();
}


void MainWindow::on_find_btn_clicked()
{
    int key = QInputDialog::getInt(nullptr, "Input", "Enter the key value: ", 1, -100, 100, 1);
    QString result = bst.search(key);
    if (result.isEmpty()) {
        ui->data_lineedit->setText("Not found");
    } else {
        ui->data_lineedit->setText(result);
    }
}


void MainWindow::on_preOrder_clicked()
{
    ui->print_lineEdit->setText(bst.preOrder(bst.getRoot()));
}


void MainWindow::on_inOrder_btn_clicked()
{
    ui->print_lineEdit->setText(bst.inOrder(bst.getRoot()));
}


void MainWindow::on_postOrder_btn_clicked()
{
    ui->print_lineEdit->setText(bst.postOrder(bst.getRoot()));
}


void MainWindow::on_clear_btn_clicked()
{
    tree->clear();
    bst.clear();
}


void MainWindow::on_execTask_btn_clicked()
{
    QVector<QPair<int, QString>> vec(15);

    for (int i = 0; i < vec.size(); ++i) {
        vec[i].first = QRandomGenerator::global()->bounded(50);
        vec[i].second = QString("Data %1").arg(vec[i].first);
    }

    bst = BST<QString>(vec);

    tree->clear();

    auto* item = new QTreeWidgetItem(tree);
    bst.addNodeToTree(bst.getRoot(), item, "");
}


void MainWindow::on_balance_btn_clicked()
{
    // bst.balance();
    bst.update(tree);
}

void MainWindow::on_getInfo_btn_clicked()
{
    QMessageBox::information(this, "Info", bst.countLeavesPerLevel(bst.getRoot()));
}
