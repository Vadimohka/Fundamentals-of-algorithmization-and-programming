#include "VisualBST.h"
#include <cstdlib> // for rand()
#include <QTreeWidgetItem>

const QString alphabet =
    "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

QString randString() {
  QString str;
  int lim = rand() % 10 + 2;
  for (int i = 0; i < lim; i++) {
    str += alphabet[rand() % alphabet.size()];
  }
  return str;
}

QTreeWidgetItem *VisualBST::generateForNode(SearchTree<QString>::TreeNode *node) {

  QTreeWidgetItem *item = new QTreeWidgetItem();
  item->setText(0, "node");
  item->setText(1, QString::number(node->key));
  item->setText(2, node->data);

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

long VisualBST::lenForNode(TreeNode *node) {
  if (node == nullptr)
    return 0;
  return node->data.length() + lenForNode(node->left) + lenForNode(node->right);
}

VisualBST::VisualBST() : SearchTree<QString>() { randomize(); }

void VisualBST::randomize() {
    clear();

    for (int i = 0; i < 64; i++) {
        long key = rand(); 
        QString value = randString(); 
        insert(key, value); 
    }
}

VisualBST::~VisualBST() {}

void VisualBST::fillEntries(QTreeWidget *tree) {
  tree->setColumnWidth(0, 400);
  tree->clear();
  if (root != nullptr) {
    tree->insertTopLevelItem(0, generateForNode(root));
    tree->expandAll();
  }
}

long VisualBST::findTotalLen() { return lenForNode(root); }