#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setHeaderLabel("My Tree");
    beginItem = new QTreeWidgetItem(ui->treeWidget);

    ui->comboBox->addItems({"Прямой обход", "Обратный обход", "Симметричный обход (по возрастанию ключей)"});

    updateTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateTree()
{
    ui->treeWidget->clear();

    beginItem = new QTreeWidgetItem(ui->treeWidget);
    beginItem->setText(0, " ");
    tree.fillTreeWidget(beginItem, tree.root);

    ui->treeWidget->expandAll();
}


void MainWindow::on_insertButton_clicked()
{
    tree.insert(ui->keyInsert->value(), ui->valueInsert->text());
    updateTree();

    ui->lineEdit->setText("Элемент с ключом " + QString::number(ui->keyInsert->value()) + " добавлен в дерево с балансировкой.");

    ui->valueInsert->clear();
}


void MainWindow::on_removeButton_clicked()
{
    Node<int, QString>* foundedNode = tree.search(ui->keyInsert->value());
    if(foundedNode == nullptr) ui->lineEdit->setText("Элемента с ключом " + QString::number(ui->keyInsert->value()) + " не найден.");
    else ui->lineEdit->setText("Элемент с ключом " + QString::number(ui->keyInsert->value()) + " удален с балансировкой.");

    tree.root = tree.remove(ui->keyInsert->value());
    updateTree();
}


void MainWindow::on_searchButton_clicked()
{
    Node<int, QString>* foundedNode = tree.search(ui->keyInsert->value());

    if(foundedNode != nullptr) ui->lineEdit->setText("Значение найденного по ключу элемента : '" + foundedNode->value + "'.");
    else ui->lineEdit->setText("Элемента с ключом " + QString::number(ui->keyInsert->value()) + " не найден.");
}


void MainWindow::on_keyInsert_valueChanged(int arg1)
{
    ui->lineEdit->clear();
}


void MainWindow::on_searchButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setText("| ");

    if(ui->comboBox->currentIndex() == 0)
    {
        tree.straightPrint(ui->lineEdit);
    }
    else if(ui->comboBox->currentIndex() == 1)
    {
        tree.reversePrint(ui->lineEdit);
    }
    else
    {
        tree.symmetricalPrint(ui->lineEdit);
    }
}


void MainWindow::on_searchButton_3_clicked()
{
    ui->lineEdit->setText("Кол-во листов дерева = " + QString::number(tree.leavesCount()));
}

