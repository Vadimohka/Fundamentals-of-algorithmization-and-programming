#ifndef C1055AA3_293C_4655_8880_F3BF24ABB235
#define C1055AA3_293C_4655_8880_F3BF24ABB235
#include "RBTree.h"
#include <optional>
#include <qicon.h>
#include <qnamespace.h>
#include <qpixmap.h>

#ifndef E8D26EAF_A465_484C_9B3C_D9EF31B4FBD3
#define E8D26EAF_A465_484C_9B3C_D9EF31B4FBD3

#include "RBTree.h"
#include <QString>
#include <QTableWidget>
#include <cstdlib>
#include <qlist.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

class MapInspector : public RBTree<long, QString> {


    QIcon *redIcon, *blackIcon;

public:
    MapInspector(){

        QPixmap red(16,16);
        red.fill(Qt::red);
        redIcon = new QIcon(red);

        QPixmap black(16,16);
        black.fill(Qt::black);
        blackIcon = new QIcon(black);

    }

    ~MapInspector(){
        delete redIcon;
        delete blackIcon;
    }

public:
  static const size_t init_max_size = 256;

  QTreeWidgetItem *nodeToTreeWidgetItem(node *nd) {
    auto item = new QTreeWidgetItem;
    item->setText(1, QString("%1: %2").arg(nd->kv.first).arg(nd->kv.second));
    item->setIcon(0, nd->color == RED ? *redIcon : *blackIcon);

    if (nd->children[l] != leaf_node) {
      item->addChild(nodeToTreeWidgetItem(nd->children[l]));
    }
    if (nd->children[r] != leaf_node) {
      item->addChild(nodeToTreeWidgetItem(nd->children[r]));
    }

    return item;
  }

  void setUpTreeWidget(QTreeWidget *tree) {
    tree->clear();
    tree->setColumnCount(2);
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
    clear();
    for (int i = 0; i < init_max_size; ++i) {
      insert(std::rand() % 2048 - 1024, randomString());
    }
  }
};

#endif /* E8D26EAF_A465_484C_9B3C_D9EF31B4FBD3 */

#endif /* C1055AA3_293C_4655_8880_F3BF24ABB235 */
