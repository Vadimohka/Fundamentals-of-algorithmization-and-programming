#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->treeWidget->setColumnCount(2);
  ui->treeWidget->setHeaderLabels(QStringList() << "Key" << "String");
  connect(ui->addButton, SIGNAL(clicked()), this, SLOT(addNode()));
  connect(ui->searchButton, SIGNAL(clicked()), this, SLOT(searchNode()));
  connect(ui->removeButton, SIGNAL(clicked()), this, SLOT(removeNode()));
  connect(ui->preorderButton, SIGNAL(clicked()), this, SLOT(printPreorder1()));
  connect(ui->inorderButton, SIGNAL(clicked()), this, SLOT(printInorder1()));
  connect(ui->postorderButton, SIGNAL(clicked()), this, SLOT(printPostorder1()));
  connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearTree()));
  connect(ui->balanceButton, SIGNAL(clicked()), this, SLOT(balanceTree()));
  connect(ui->taskButton, SIGNAL(clicked()), this, SLOT(task()));
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::addNode() {
  int key = ui->keyLineEdit->text().toInt();
  QString string = ui->stringLineEdit->text();
  Data data;
  data.key = key;
  data.string = string;
  m_root = m_bst.add(m_root, data);
  updateTreeWidget();
  ui->keyLineEdit->clear();
  ui->stringLineEdit->clear();
}

void MainWindow::searchNode() {
  int key = ui->keyLineEdit1->text().toInt();
  Node* found = m_bst.search(m_root, key);
  if (found) {
    ui->resultTextEdit->setText(QString("Ключ = %1, Строка = %2")
                                    .arg(found->data.key)
                                    .arg(found->data.string));
  } else {
    ui->resultTextEdit->setText("Ключ не найден");
  }
}

void MainWindow::removeNode() {
  int key = ui->keyLineEdit1->text().toInt();
  m_root = m_bst.remove(m_root, key);
  updateTreeWidget();
}

void MainWindow::printPreorder1() {
  ui->resultTextEdit->clear();
  m_bst.printPreorder(m_root, *ui->resultTextEdit);
}

void MainWindow::printInorder1() {
  ui->resultTextEdit->clear();
  m_bst.printInorder(m_root, *ui->resultTextEdit);
}

void MainWindow::printPostorder1() {
  ui->resultTextEdit->clear();
  m_bst.printPostorder(m_root, *ui->resultTextEdit);
}

void MainWindow::updateTreeWidget() {
  ui->treeWidget->clear();
  updateTreeWidgetRecursive(m_root);
}

void MainWindow::updateTreeWidgetRecursive(Node* node,
                                           QTreeWidgetItem* parentItem) {
  if (node == nullptr) {
    return;
  }

  QTreeWidgetItem* item = new QTreeWidgetItem();
  item->setText(0, QString::number(node->data.key));
  item->setText(1, node->data.string);

  if (parentItem == nullptr) {
    ui->treeWidget->addTopLevelItem(item);
  } else {
    parentItem->addChild(item);
  }

  updateTreeWidgetRecursive(node->left, item);
  updateTreeWidgetRecursive(node->right, item);
}

void MainWindow::clearTree() {
  m_bst.clear(m_root);
  ui->treeWidget->clear();
  m_root = nullptr;
}

void MainWindow::balanceTree() {
  m_root = m_bst.balance(m_root);
  updateTreeWidget();
}

void MainWindow::task() {

  int key = ui->keyLineEdit2->text().toInt();
  m_root = task_bst.remove(m_root, key);
  updateTreeWidget();
}
