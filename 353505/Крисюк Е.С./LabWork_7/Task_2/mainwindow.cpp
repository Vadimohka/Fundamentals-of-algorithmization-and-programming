#include "mainwindow.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    tree = new BinaryTree();

    standart_model = new QStandardItemModel(this);

    BinaryTree tree;

    for(int i = 1; i < 8;++i){
        tree.Add_element("123", i);
    }

    tree.Debug_tree();

    tree.Balance_tree();

    qDebug() << "=============================";

    tree.Debug_tree();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Add_button_clicked()
{
    add_new_element_window = new Add_new_element_window();
    connect(add_new_element_window, &Add_new_element_window::OpenMainWindow, this, &MainWindow::Add_element_to_window);

    add_new_element_window -> exec();
}

void MainWindow::Add_element_to_window(QString & value , int & key){

    tree -> Add_element(value, key);

    Update_treeview();

}


void MainWindow::on_Balance_button_clicked()
{
    tree -> Balance_tree();
    Update_treeview();
}


void MainWindow::on_Delete_button_clicked()
{
    delete_element_window = new Delete_element_window();

    connect(delete_element_window, &Delete_element_window::OpenMainWindow, this, &MainWindow::Delete_element_from_window);

    delete_element_window -> exec();

}

void MainWindow::Delete_element_from_window(int key){

    tree -> Delete_information_from_key(key);
    Update_treeview();

}

void MainWindow::Update_treeview(){
    ui -> treeView -> setModel(new QStandardItemModel(this));

    node_list.clear();

    tree -> Get_all_nodes(tree -> root, node_list);

    QStandardItem* item = new QStandardItem("Tree");

    Update(item, tree -> root, "Root");

    standart_model -> setItem(0,0, item);
    ui -> treeView -> setModel(standart_model);


    ui->treeView->expandAll();

}


void MainWindow::Update(QStandardItem* parent, Node* node, QString status){

    if (!node) {
        return;
    }

    QString key = "(key:" + QString::number(node->key) + ")";

    QString node_str = status + " " + node -> value + key;

    QStandardItem* child = new QStandardItem(node_str);

    parent->appendRow(child);


    Update(child, node -> left, "Left ");
    Update(child, node -> right, "Right ");

}


void MainWindow::on_Get_right_nodes_cout_clicked()
{
    int count = tree -> Get_right_node_nodes_count();

    ui -> lineEdit -> setText(QString::number(count));
}

