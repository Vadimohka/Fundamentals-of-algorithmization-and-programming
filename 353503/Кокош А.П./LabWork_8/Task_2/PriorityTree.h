#ifndef CC7A4E3D_51EC_4B76_90A7_E9CB9BD4AB52
#define CC7A4E3D_51EC_4B76_90A7_E9CB9BD4AB52
#include <cstddef>
#include <QTreeWidget>

template<typename T>
class PriorityTree
{
public:
  PriorityTree();
  void push(T);
  T pop();
  size_t size();
  T &max();
  void inspect(QTreeWidget*);
};

#endif /* CC7A4E3D_51EC_4B76_90A7_E9CB9BD4AB52 */
