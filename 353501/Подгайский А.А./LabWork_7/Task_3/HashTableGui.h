#ifndef C3504A6D_E441_42A8_B1BC_11659BCFFE56
#define C3504A6D_E441_42A8_B1BC_11659BCFFE56

#include "HashTable.h"
#include <QString>
#include <QTreeWidget>
#include <cstdlib>
#include <limits>
#include <qtreewidget.h>
#include <sys/types.h>

class HashTableGui : public HashTable<QString> {

  static const size_t random_init = 8092;


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
    res.resize(res.size() - 1);
    return std::move(res);
  }

  public:

  void setUpTreeWidget(QTreeWidget *tree) {

    tree->clear();
    for (int i = 0; i < mod; ++i) {

      auto cur = stacks[i];
      if (!cur) {
        continue;
      }

      QTreeWidgetItem *stack_item = new QTreeWidgetItem;
      stack_item->setText(0, QString::number(i));
      while (cur != nullptr) {
        QTreeWidgetItem *element = new QTreeWidgetItem(stack_item);
        element->setText(
            0, QString("%1: %2").arg(QString::number(cur->key)).arg(cur->val));
        cur = cur->prev;
      }
      tree->addTopLevelItem(stack_item);
    }
    tree->expandAll();
  }

  void initRandom(size_t sz) {
    clear();
    while(size_var != sz) {
      insert(std::rand() - RAND_MAX/2, randomString());
    }
  }


  std::pair<long, key_t > findMinKey(){
    key_t min_key = std::numeric_limits<key_t>::max();
    long min_bucket = 0;
    for(int i = 0; i < mod; ++i){
        auto cur = stacks[i];
        while(cur !=  nullptr){
            if(cur->key < min_key){
                min_key = cur->key;
                min_bucket = i;
            }
            cur = cur->prev;
        }
    }
    return {min_bucket, min_key};
  }


};

#endif /* C3504A6D_E441_42A8_B1BC_11659BCFFE56 */
