#include "SearchTree.h"
#include <QString>
#include <qcontainerfwd.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

class Solver: public SearchTree<QString> {
private:
  QTreeWidgetItem *generateForNode(TreeNode *node);
  long lenForNode(TreeNode *node);

public:
  Solver();
  ~Solver();

  void randomize();
  
  void fillEnties(QTreeWidget *entries);

  void countStartingWithRecursive(TreeNode* node, QString letter, int& count);

  int countStartingWithLetter(QString letter);

  int countStartingWith(QString letter);
};
