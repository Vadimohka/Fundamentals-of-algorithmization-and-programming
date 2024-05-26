#pragma once

#include "BSTWithDepth.h"
#include <QString>
#include <QTableWidget>
#include <cstdlib>
#include <qlist.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

class BSTGui : public BSTWithDepth<QString> {

public:
  static const size_t init_max_size = 256;

  QTreeWidgetItem *nodeToTreeWidgetItem(BSTWithDepth<QString>::node *nd) {
    auto item = new QTreeWidgetItem;
    item->setText(0, QString("%1: %2").arg(nd->key).arg(nd->val));

    if (nd->left) {
      item->addChild(nodeToTreeWidgetItem(nd->left));
    }
    if (nd->right) {
      item->addChild(nodeToTreeWidgetItem(nd->right));
    }

    return item;
  }

  void setUpTreeWidget(QTreeWidget *tree) {
    tree->clear();
    if (root) {
      tree->insertTopLevelItem(0, nodeToTreeWidgetItem(root));
    }
    tree->expandAll();
  }

  QString randomString() {
    static QString alph = "qwertyuiopasdfghjklzxcvbnm1234567890";
    static const auto alph_sz = alph.size();

    QString res;
    res.reserve(20);
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        res += alph[std::rand() % alph_sz];
      }
      res += '-';
    }
    res.resize(res.size()-1);
    return std::move(res);
  }

  void initRandomly() {
    BSTWithDepth<QString>::~BSTWithDepth();
    for (int i = 0; i < init_max_size; ++i) {
      insert(std::rand() % 2048 - 1024, randomString());
    }
  }
};

