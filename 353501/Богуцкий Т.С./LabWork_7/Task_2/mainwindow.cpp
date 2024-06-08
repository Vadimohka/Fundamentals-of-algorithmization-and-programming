#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QIntValidator>
#include <QItemDelegate>
class NumberDelegate : public QItemDelegate {
public:
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        Q_UNUSED(option)
        Q_UNUSED(index)

        QSpinBox *editor = new QSpinBox(parent);
        editor->setFrame(false);
        editor->setMinimum(std::numeric_limits<int>::min());
        editor->setMaximum(std::numeric_limits<int>::max());
        return editor;
    }

    void setEditorData(QWidget *editor, const QModelIndex &index) const override {
        int value = index.model()->data(index, Qt::EditRole).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override {
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value, Qt::EditRole);
    }

    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override {
        editor->setGeometry(option.rect);
    }
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QVector<QPair<int, QString>> a(20);
    for (int i = 0; i < 20; ++i) {
        a[i].first = QRandomGenerator::global()->bounded(26);
        a[i].second = QChar(i + 'A');
    }

    tree = BinaryTree(a);

    displayTree();

    ui->tableWidget->setRowCount(20);
    ui->tableWidget->setColumnCount(2);
    for (int row = 0; row < 20; ++row) {
        QTableWidgetItem *item0 = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 0, item0);

        QTableWidgetItem *item1 = new QTableWidgetItem();
        ui->tableWidget->setItem(row, 1, item1);
    }

    for (int i = 0; i < 20; ++i) {
        ui->tableWidget->item(i, 0)->setText(QString::number(a[i].first));
        ui->tableWidget->item(i, 1)->setText(a[i].second);
    }

    ui->resLAbel->setReadOnly(true);

    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    setWindowTitle("Дерево поиска");

    ui->tableWidget->setItemDelegateForColumn(0, new NumberDelegate());

    tree.balanceTree();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::fillTreeWidgetFromBST(QTreeWidgetItem *item, BinaryTree::Data *node)
{
    if (node == nullptr)
        return;

    item->setText(0, QString::number(node->key) + " " + node->info);

    if (node->LeftChild != nullptr) {
        QTreeWidgetItem* leftSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(leftSon, node->LeftChild);
    }

    if (node->RightChild != nullptr) {
        QTreeWidgetItem* rightSon = new QTreeWidgetItem(item);
        fillTreeWidgetFromBST(rightSon, node->RightChild);
    }
}

void MainWindow::displayTree()
{
    ui->treeWidget->clear();

    if (tree.root == nullptr)
        return;

    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);

    fillTreeWidgetFromBST(rootItem, tree.root);

    ui->treeWidget->addTopLevelItem(rootItem);
}

void MainWindow::on_insertButton_clicked()
{
    tree.insert(ui->keySpinBox->value(), ui->infoLineEdit->text());
    displayTree();
}

void MainWindow::on_findButton_clicked()
{
    QString res = tree.find(ui->keySpinBox->value());
    ui->resLAbel->setPlainText(res == "" ? "Нет такого ключа!" : res);
}

void MainWindow::on_balanceButton_clicked()
{
    tree.balanceTree();
    displayTree();
}

void MainWindow::on_removeButton_clicked()
{
    tree.remove(ui->keySpinBox->value());
    displayTree();
}

void MainWindow::on_preorderButton_clicked()
{
    auto res = tree.preOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_inorderButton_clicked()
{
    auto res = tree.inOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_postorderButton_clicked()
{
    auto res = tree.postOrderTraversal();
    QString text = "";
    for (auto el : res) {
        text += el + "\n";
    }
    ui->resLAbel->setPlainText(text);
}

void MainWindow::on_addStringButton_clicked()
{
    ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
}

void MainWindow::on_removeStringButton_clicked()
{
    ui->tableWidget->setRowCount(std::max(ui->tableWidget->rowCount() - 1, 0));
}

void MainWindow::on_inputButton_clicked()
{
    QVector<QPair<int, QString>> a(ui->tableWidget->rowCount());

    for (int i = 0; i < a.size(); ++i) {
        a[i].first = ui->tableWidget->item(i, 0)->text().toInt();
        a[i].second = ui->tableWidget->item(i, 1)->text();
    }

    tree = BinaryTree(a);

    displayTree();
}

void MainWindow::on_leavesButton_clicked()
{
    ui->resLAbel->setPlainText(QString::number(tree.calcLeaves()));
}
