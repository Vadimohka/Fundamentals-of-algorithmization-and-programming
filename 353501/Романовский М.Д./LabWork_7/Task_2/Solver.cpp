#include "Solver.h"
#include <qframe.h>
#include <qnamespace.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

const QString alpha =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

QString randString() {
  QString str;
  int lim = rand() % 10 + 2;
  for (int i = 0; i < lim; i++) {
    if (i % 4 == 3)
      str += '_';
    else
      str += alpha[rand() % alpha.size()];
  }
  return str;
}

QTreeWidgetItem *Solver::generateForNode(TreeNode *node) {

  QTreeWidgetItem *item = new QTreeWidgetItem();
  item->setText(0, "node");
  item->setText(1, QString::number(node->key));
  item->setText(2, node->val);

  if (node->left != nullptr) {
    item->addChild(generateForNode(node->left));
  } else {
    QTreeWidgetItem *lack = new QTreeWidgetItem();
    lack->setText(0, "no L");
    item->addChild(lack);
  }
  if (node->right != nullptr) {
    item->addChild(generateForNode(node->right));
  } else {
    QTreeWidgetItem *lack = new QTreeWidgetItem();
    lack->setText(0, "no R");
    item->addChild(lack);
  }
  // item->setExpanded(true);
  return item;
}

long Solver::lenForNode(TreeNode *node) {
  if (node == nullptr)
    return 0;
  return node->val.length() + lenForNode(node->left) + lenForNode(node->right);
}

Solver::Solver() : SearchTree<QString>() { randomize(); }

void Solver::randomize() {
  delete this->root;
  this->root = nullptr;

  for (int i = 0; i < 64; i++) {
    insert(rand(), randString());
  }
}

Solver::~Solver() {}

void Solver::fillEnties(QTreeWidget *tree) {
  tree->setColumnWidth(0, 400);
  tree->clear();
  if (this->root != nullptr) {
    tree->insertTopLevelItem(0, generateForNode(this->root));
    tree->expandAll();
  }
}

long Solver::findTotalLen() { return lenForNode(this->root); }