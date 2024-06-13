#include "VisualBST.h"
#include <qframe.h>
#include <qnamespace.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

const QString letters =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

QString randString() {
  QString str;
  int lim = rand() % 10 + 2;
  for (int i = 0; i < lim; i++) {
    str += letters[rand() % letters.size()];
  }
  return str;
}

QTreeWidgetItem *VisualBST::generateForNode(TreeNode *node) {

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
 
  return item;
}

long VisualBST::lenForNode(TreeNode *node) {
  if (node == nullptr)
    return 0;
  return node->val.length() + lenForNode(node->left) + lenForNode(node->right);
}

VisualBST::VisualBST() : SearchTree<QString>() { randomize(); }

void VisualBST::randomize() {
  delete this->root;
  this->root = nullptr;

  for (int i = 0; i < 64; i++) {
    insert(rand()%10000, randString());
  }
}

VisualBST::~VisualBST() {}

void VisualBST::fillEnties(QTreeWidget *tree) {
  tree->setColumnWidth(0, 400);
  tree->clear();
  if (this->root != nullptr) {
    tree->insertTopLevelItem(0, generateForNode(this->root));
    tree->expandAll();
  }
}