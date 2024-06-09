#include "SearchTree.h"
#include <QString>
#include <qcontainerfwd.h>
#include <qtablewidget.h>
#include <qtreewidget.h>

class VisualBST: public SearchTree<QString> {
private:
  QTreeWidgetItem *generateForNode(TreeNode *node);
  long lenForNode(TreeNode *node);

public:
  VisualBST();
  ~VisualBST();

  void randomize();
  
  void fillEnties(QTreeWidget *entries);
};