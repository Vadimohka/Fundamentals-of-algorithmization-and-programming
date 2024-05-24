#include "BST.h"

template <typename T> class BSTWithDepth : public BST<T> {

private:
  long _depth(BST<T>::node * nd) {
    if (!nd) {
      return 0;
    }
    return std::max(1 + _depth(nd->left), 1 + _depth(nd->right));
  }

public:
  long depth() { return _depth(BST<T>::root); }
};