#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadButton_clicked()
{
    // Пример массива данных
    QVector<QPair<int, QString>> data = {
        {101, "David"},
        {123, "Alice"},
        {456, "Bob"},
        {789, "Charlie"},
        
        {112, "Eve"}
    };

    for (const auto &entry : data) {
        bst.insert(entry.first, entry.second);
    }

    updateTreeView();
}

void MainWindow::on_balanceButton_clicked()
{
    bst.balance();
    updateTreeView();
}

void MainWindow::on_addButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this, tr("Add Entry"),
                                   tr("Key:"), 0, 0, 2147483647, 1, &ok);
    if (ok) {
        QString value = QInputDialog::getText(this, tr("Add Entry"),
                                              tr("Value:"), QLineEdit::Normal, "", &ok);
        if (ok && !value.isEmpty()) {
            bst.insert(key, value);
            updateTreeView();
        }
    }
}

void MainWindow::on_findButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this, tr("Find Entry"),
                                   tr("Key:"), 0, 0, 2147483647, 1, &ok);
    if (ok) {
        QString result = bst.find(key);
        if (!result.isEmpty()) {
            QMessageBox::information(this, tr("Find Entry"), tr("Found: %1").arg(result));
        } else {
            QMessageBox::warning(this, tr("Find Entry"), tr("Key not found"));
        }
    }
}

void MainWindow::on_deleteButton_clicked()
{
    bool ok;
    int key = QInputDialog::getInt(this, tr("Delete Entry"),
                                   tr("Key:"), 0, 0, 2147483647, 1, &ok);
    if (ok) {
        bst.remove(key);
        updateTreeView();
    }
}

void MainWindow::on_printButton_clicked()
{
    QString order = QInputDialog::getItem(this, tr("Print Tree"),
                                          tr("Order:"), {"In-Order", "Pre-Order", "Post-Order"}, 0, false);
    if (!order.isEmpty()) {
        QStringList result;
        if (order == "In-Order") {
            result = bst.inOrder();
        } else if (order == "Pre-Order") {
            result = bst.preOrder();
        } else if (order == "Post-Order") {
            result = bst.postOrder();
        }
        ui->textEdit->clear();
        ui->textEdit->append(result.join("\n"));
    }
}

void MainWindow::on_countButton_clicked()
{
    QChar letter = QInputDialog::getText(this, tr("Count Entries"),
                                         tr("Starting letter:"), QLineEdit::Normal, "").at(0);
    int count = bst.countStartingWith(letter);
    QMessageBox::information(this, tr("Count Entries"), tr("Count: %1").arg(count));
}

void MainWindow::updateTreeView()
{
    ui->treeWidget->clear();

    std::function<void(QTreeWidgetItem*, Node*)> addItem = [&](QTreeWidgetItem* parent, Node* node) {
        if (!node) return;
        QTreeWidgetItem* item = new QTreeWidgetItem(parent);
        item->setText(0, QString::number(node->key));
        item->setText(1, node->value);
        if (!parent) {
            ui->treeWidget->addTopLevelItem(item);
        } else {
            parent->addChild(item);
        }
        addItem(item, node->left);
        addItem(item, node->right);
    };

    addItem(nullptr, bst.root());
}
