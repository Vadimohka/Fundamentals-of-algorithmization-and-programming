#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->positionComboBox->addItem("Left");
    ui->positionComboBox->addItem("Right");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addButton_clicked()
{
    int value = ui->inputLineEdit->text().toInt();
    std::string message = bst.getMessageForAdd(value);
    ui->outputTextEdit->append(QString::fromStdString(message));
}

void MainWindow::on_removeButton_clicked()
{
    int value = ui->inputLineEdit->text().toInt();
    std::string message = bst.getMessageForRemove(value);
    ui->outputTextEdit->append(QString::fromStdString(message));
}

void MainWindow::on_findButton_clicked()
{
    int value = ui->inputLineEdit->text().toInt();
    Node* result = bst.find(value);
    if (result) {
        ui->outputTextEdit->append("Found value: " + QString::number(value));
    } else {
        ui->outputTextEdit->append("Value not found: " + QString::number(value));
    }
}

void MainWindow::on_traverseButton_clicked()
{
    std::vector<int> elements = bst.traverse();
    QString result = "Traversal: ";
    for (int value : elements) {
        result += QString::number(value) + " ";
    }
    ui->outputTextEdit->append(result);
}

void MainWindow::on_InsertSubtreeButton_clicked()
{
    // Пример создания поддерева
    Node* subtree = new Node(20);
    subtree->left = new Node(15);
    subtree->right = new Node(25);

    std::string message = bst.getMessageForInsertSubtree(subtree);
    ui->outputTextEdit->append(QString::fromStdString(message));
}

void MainWindow::on_RemoveSubtreeButton_clicked()
{
    int value = ui->inputLineEdit->text().toInt();
    Node* subtree = bst.find(value);
    if (subtree) {
        std::string message = bst.getMessageForRemoveSubtree(subtree);
        ui->outputTextEdit->append(QString::fromStdString(message));
    } else {
        ui->outputTextEdit->append("Subtree root not found: " + QString::number(value));
    }
}

void MainWindow::on_InsertAtPositionButton_clicked()
{
    int parentValue = ui->parentLineEdit->text().toInt();
    int value = ui->inputLineEdit->text().toInt();
    bool asLeftChild = ui->positionComboBox->currentText() == "Left";
    bst.insertAtPosition(parentValue, value, asLeftChild);
    ui->outputTextEdit->append("Inserted " + QString::number(value) +
                               " at " + (asLeftChild ? "left" : "right") +
                               " of " + QString::number(parentValue));
}

void MainWindow::on_InsertBranchButton_clicked()
{
    Node* branch = new Node(30);
    branch->left = new Node(25);
    branch->right = new Node(35);

    int parentValue = ui->parentLineEdit->text().toInt();
    bool asLeftChild = ui->positionComboBox->currentText() == "Left";
    bst.insertBranch(branch, parentValue, asLeftChild);

    ui->outputTextEdit->append("Inserted branch rooted at " + QString::number(branch->value) +
                               " at " + (asLeftChild ? "left" : "right") +
                               " of " + QString::number(parentValue));
}

void MainWindow::on_RemoveBranchButton_clicked()
{
    int value = ui->inputLineEdit->text().toInt();
    bst.removeBranch(value);
    ui->outputTextEdit->append("Removed branch rooted at " + QString::number(value));
}

void MainWindow::on_FindLCAButton_clicked()
{
    int value1 = ui->value1LineEdit->text().toInt();
    int value2 = ui->value2LineEdit->text().toInt();
    Node* lca = bst.findLCA(value1, value2);
    if (lca) {
        ui->outputTextEdit->append("LCA of " + QString::number(value1) +
                                   " and " + QString::number(value2) +
                                   " is " + QString::number(lca->value));
    } else {
        ui->outputTextEdit->append("LCA not found for " +
                                   QString::number(value1) + " and " +
                                   QString::number(value2));
    }
}
