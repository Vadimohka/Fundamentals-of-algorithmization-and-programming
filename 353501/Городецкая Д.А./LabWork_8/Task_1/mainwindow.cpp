#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    t.fill({{1, "A"}, {2, "B"}, {3, "C"}, {4, "D"}, {5, "E"}});
    showTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updWidget(QTreeWidgetItem *anc, node *v)
{
    if (v == nullptr) return;

    anc->setText(0, QString::fromStdString("{" + std::to_string(v->key)) + " " + v->str + "}");

    if (v->left != nullptr)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(anc);
        updWidget(item, v->left);
    }
    if (v->right != nullptr)
    {
        QTreeWidgetItem *item = new QTreeWidgetItem(anc);
        updWidget(item, v->right);
    }
}

void MainWindow::showTree()
{
    ui->treeWidget->clear();
    if (t.getRoot() == nullptr)
        return;
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    updWidget(rootItem, t.getRoot());
    ui->treeWidget->addTopLevelItem(rootItem);

    ui->k1->clear();
    ui->k2->clear();
    QStringList vars;
    t.getVerts(t.getRoot(), vars);
    ui->k1->addItems(vars);
    ui->k2->addItems(vars);
}

bool MainWindow::check_key()
{
    std::string s = ui->key->text().toStdString();
    for (auto& i : s)
    {
        if (!(i >= '0' && i <= '9'))
            return false;
    }

    try
    {
        key = std::stoi(s);
    }
    catch (...)
    {
        return false;
    }
    return true;
}

bool MainWindow::check_str()
{
    str = ui->value->toPlainText();
    if (str == "")
        return false;
    return true;
}

void MainWindow::on_addButton_clicked()
{
    if (check_key() && check_str())
    {
        t.insert(key, str);
    }
    else
    {
        QMessageBox::warning(this, "Error", "Key should be int, Value should be non void");
    }
    showTree();
}

void MainWindow::on_removeButton_clicked()
{
    if (check_key())
    {
        if (t.find(key).second == true)
            t.remove(key);
        else
            QMessageBox::warning(this, "Error", "Key doesn't exist in the tree");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Key should be int");
    }
    showTree();
}

void MainWindow::on_findButton_clicked()
{
    if (check_key())
    {
        ui->fval->setText(t.find(key).first);
        if (ui->fval->toPlainText() == "")
            ui->fval->setText("Not found");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Key should be int");
    }
}

void MainWindow::on_traverseButton_clicked()
{
    if (t.getRoot() == nullptr)
    {
        QMessageBox::warning(this, "Error", "Firstly make tree");
        return;
    }
    QString ord;
    ord = t.traverse(1);
    ui->postf->setText(ord);
    ord = "";
    ord = t.traverse(0);
    ui->inf->setText(ord);
    ord = t.traverse(-1);
    ui->pref->setText(ord);
}

void MainWindow::on_balanceButton_clicked()
{
    if (t.getRoot() == nullptr)
    {
        QMessageBox::warning(this, "Error", "Firstly make tree");
        return;
    }
    t.balance();
    showTree();
}

void MainWindow::on_removeSubtreeButton_clicked()
{
    if (check_key())
    {
        if (t.find(key).second == true)
            t.removeSubtree(key);
        else
            QMessageBox::warning(this, "Error", "Key doesn't exist in the tree");
    }
    else
    {
        QMessageBox::warning(this, "Error", "Key should be int");
    }
    showTree();
}

void MainWindow::on_lcaButton_clicked()
{
    node *v = t.LCA(ui->k1->currentText().toInt(), ui->k2->currentText().toInt());
    ui->LCA->setText("{" + QString::number(v->key) + " ; " + v->str + "}");
}
