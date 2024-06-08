#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t.fill({{1,"A"},{2,"B"},{3,"C"},{4,"D"},{5,"E"}});
    showTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updWidget(QTreeWidgetItem *anc, node *v)
{
    if(v==nullptr)return;

    anc->setText(0,QString::fromStdString("{"+std::to_string(v->key))+" "+v->str+"}");

    if(v->left!=nullptr)
    {
        QTreeWidgetItem *item=new QTreeWidgetItem(anc);
        updWidget(item,v->left);
    }
    if(v->right!=nullptr)
    {
        QTreeWidgetItem *item=new QTreeWidgetItem(anc);
        updWidget(item,v->right);
    }
}

void MainWindow::showTree()
{
    ui->treeWidget->clear();
    if (t.getRoot() == nullptr)
        return;
    qDebug()<<"Exist";
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    updWidget(rootItem, t.getRoot());
    ui->treeWidget->addTopLevelItem(rootItem);
}

bool MainWindow::check_key()
{
    std::string s=ui->key->toPlainText().toStdString();
    for(auto& i:s)
    {
        if(!(i>='0'&&i<='9'))
            return false;
    }

    try
    {
        key=stoi(s);
    }
    catch(...)
    {
        return false;
    }
    return true;
}

bool MainWindow::check_str()
{
    str=ui->value->toPlainText();
    if(str=="")
        return false;
    return true;
}

void MainWindow::on_pushButton_clicked()
{
    if(check_key()&&check_str())
    {
        t.insert(key,str);
    }
    else
    {
        QMessageBox::warning(this,"Error","Key should be int, Value should be non void");
    }
    showTree();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(check_key())
    {
        if(t.find(key)!="")
            t.remove(key);
        else
            QMessageBox::warning(this,"Error","Key doesn`t added into tree");
    }
    else
    {
        QMessageBox::warning(this,"Error","Key should be int");
    }
    showTree();
}


void MainWindow::on_pushButton_3_clicked()
{

    if(check_key())
    {
        ui->fval->setText(t.find(key));
        if(ui->fval->toPlainText()=="")
            ui->fval->setText("Not found");
    }
    else
    {
        QMessageBox::warning(this,"Error","Key should be int");
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->leaves->setText(QString::number(t.leaves()));
}


void MainWindow::on_pushButton_5_clicked()
{
    if(t.getRoot()==nullptr)
    {
        QMessageBox::warning(this,"Error","Firstly make tree");
        return;
    }
    t.balance();
    showTree();
}


void MainWindow::on_pushButton_6_clicked()
{
    if(t.getRoot()==nullptr)
    {
        QMessageBox::warning(this,"Error","Firstly make tree");
        return;
    }
    QString ord;
    t.postfOrder(ord);
    ui->postf->setText(ord);
    ord="";
    t.infOrder(ord);
    ui->inf->setText(ord);
    ord="";
    t.prefOrder(ord);
    ui->pref->setText(ord);
}
