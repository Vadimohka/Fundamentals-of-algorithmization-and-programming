#ifndef BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714
#define BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714

#include <memory>
#include <qtreewidget.h>

template <typename T> class PriorityTree {

protected:
  static const bool l = 0;
  static const bool r = 1;
  struct node {
    T val;
    std::weak_ptr<node> parent;
    std::shared_ptr<node> left;
    std::shared_ptr<node> right;
  };
  size_t sizevar;

  std::shared_ptr<node> root;
  std::weak_ptr<node> pwrl; // Parent With Rightmost Leaf
  bool pwrl_leaf = 0;       // the rightmost leaf itself

private:
  std::shared_ptr<node> heapify(std::shared_ptr<node> nd) {
    bool lmax = false;
    bool rmax = false;

    if (nd->left && nd->left->val > nd->val) {
      lmax = true;
    }
    if (nd->right && nd->right->val > nd->val) {
      rmax = true;
    }
    if (lmax && rmax) {
      lmax = nd->left->val > nd->right->val;
      rmax = !lmax;
    }

    if (lmax) {
      std::swap(nd->val, nd->left->val);
      return nd->left;
    } else if (rmax) {
      std::swap(nd->val, nd->right->val);
      return nd->right;
    } else
      return nd;
  }

  void incr_pwrl() {
    if (pwrl_leaf == l) {
      pwrl_leaf = r;
    } else {
      auto parent = pwrl.lock()->parent.lock();
      auto child = pwrl.lock();
      while (parent != nullptr && child == parent->right) {
        child = parent;
        parent = parent->parent.lock();
      }

      if (parent != nullptr) {
        child = parent->right;
      }

      while (child->left) {
        child = child->left;
      }
      pwrl = child;
      pwrl_leaf = l;
    }
  }

  void decr_pwrl() {
    if (pwrl_leaf == r) {
      pwrl_leaf = l;
    } else {
      auto parent = pwrl.lock()->parent.lock();
      auto child = pwrl.lock();
      while (parent != nullptr && child == parent->left) {
        child = parent;
        parent = parent->parent.lock();
      }

      if (parent != nullptr) {
        child = parent->left;
      }

      while (child->right) {
        child = child->right;
      }
      pwrl = child->parent;
      pwrl_leaf = r;
    }
  }

  QTreeWidgetItem* getGuiNode(std::shared_ptr<node> nd){
    auto item = new QTreeWidgetItem;
    item->setText(0, QString::number(nd->val));
    if(nd->left){
        item->addChild(getGuiNode(nd->left));
    }
    if(nd->right){
        item->addChild(getGuiNode(nd->right));
    }

    return item;
  }

public:

  PriorityTree() { sizevar = 0; }

  ~PriorityTree() { root = nullptr; }

  void push(T val) {
    if (!root) {
      root = std::make_shared<node>();
      root->val = val;
      pwrl = root;
      pwrl_leaf = l;
      ++sizevar;
      return;
    }

    auto n = pwrl.lock();
    if (pwrl_leaf == l) {
      n->left = std::make_shared<node>();
      n->left->parent = n;
      n->left->val = val;
    } else {
      n->right = std::make_shared<node>();
      n->right->parent = n;
      n->right->val = val;
    }

    while (heapify(n) != n && n->parent.lock() != nullptr) {
      n = n->parent.lock();
    }

    incr_pwrl();
    ++sizevar;
  }

  T pop() {
    const T max = root->val;
    if (sizevar == 1) {
      root = nullptr;
      sizevar = 0;
      return max;
    }

    decr_pwrl();

    {
      auto lmost_par = pwrl.lock();
      auto lmost = pwrl_leaf == l ? lmost_par->left : lmost_par->right;
      root->val = lmost->val;

      if (lmost_par->left == lmost) {
        lmost_par->left = nullptr;
      } else {
        lmost_par->right = nullptr;
      }
    }

    std::shared_ptr<node> largest;
    auto cur = root;
    while ((largest = heapify(cur)) != cur) {
      cur = largest;
    }
    --sizevar;
    return max;
  }


  void inspect(QTreeWidget* w){
    w->clear();
    if(root){
        w->insertTopLevelItem(0, getGuiNode(root));
    }
    w->expandAll();
  }

  size_t size() { return sizevar; }

  T &max() { return root->val; }
};


template class PriorityTree<long>;
template class PriorityTree<int>;
template class PriorityTree<char>;

#endif /* BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714 */
