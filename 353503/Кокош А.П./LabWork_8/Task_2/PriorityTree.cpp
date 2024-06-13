#ifndef BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714
#define BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714

#include <memory>
#include <qtreewidget.h>

template <typename T> class PriorityTree {
protected:
    static const bool left = 0;
    static const bool right = 1;
    struct node
    {
        T value;
        std::weak_ptr<node> parent;
        std::shared_ptr<node> left;
        std::shared_ptr<node> right;
    };
    size_t sizeOfTree;

    std::shared_ptr<node> root;
    std::weak_ptr<node> parentWRL; // Parent With Rightmost Leaf
    bool parentWRL_leaf = 0;       // the rightmost leaf itself

private:
    std::shared_ptr<node> heapify(std::shared_ptr<node> node)
    {
        bool leftMax = false;
        bool rightMax = false;

        if (node->left && node->left->value > node->value) {
            leftMax = true;
        }
        if (node->right && node->right->value > node->value) {
            rightMax = true;
        }
        if (leftMax && rightMax) {
            leftMax = node->left->value > node->right->value;
            rightMax = !leftMax;
        }

        if (leftMax) {
            std::swap(node->value, node->left->value);
            return node->left;
        } else if (rightMax) {
            std::swap(node->value, node->right->value);
            return node->right;
        } else
            return node;
    }

    void incr_parentWRL()
    {
        if (parentWRL_leaf == left) {
            parentWRL_leaf = right;
        } else {
            auto parent = parentWRL.lock()->parent.lock();
            auto child = parentWRL.lock();
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
            parentWRL = child;
            parentWRL_leaf = left;
        }
    }

    void decr_parentWRL()
    {
        if (parentWRL_leaf == right) {
            parentWRL_leaf = left;
        } else {
            auto parent = parentWRL.lock()->parent.lock();
            auto child = parentWRL.lock();
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
            parentWRL = child->parent;
            parentWRL_leaf = right;
        }
    }

    QTreeWidgetItem *getGuiNode(std::shared_ptr<node> node)
    {
        auto item = new QTreeWidgetItem;
        item->setText(0, QString::number(node->value));
        if (node->left) {
            item->addChild(getGuiNode(node->left));
        }
        if (node->right) {
            item->addChild(getGuiNode(node->right));
        }

        return item;
    }

public:
    PriorityTree() { sizeOfTree = 0; }

    ~PriorityTree() { root = nullptr; }

    void push(T value)
    {
        if (!root) {
            root = std::make_shared<node>();
            root->value = value;
            parentWRL = root;
            parentWRL_leaf = left;
            ++sizeOfTree;
            return;
        }

        auto n = parentWRL.lock();
        if (parentWRL_leaf == left) {
            n->left = std::make_shared<node>();
            n->left->parent = n;
            n->left->value = value;
        } else {
            n->right = std::make_shared<node>();
            n->right->parent = n;
            n->right->value = value;
        }

        while (heapify(n) != n && n->parent.lock() != nullptr) {
            n = n->parent.lock();
        }

        incr_parentWRL();
        ++sizeOfTree;
    }

  T pop() {
      const T max = root->value;
      if (sizeOfTree == 1) {
          root = nullptr;
          sizeOfTree = 0;
          return max;
      }

      decr_parentWRL();

      {
          auto lmost_par = parentWRL.lock();
          auto lmost = parentWRL_leaf == left ? lmost_par->left : lmost_par->right;
          root->value = lmost->value;

          if (lmost_par->left == lmost) {
              lmost_par->left = nullptr;
          } else {
              lmost_par->right = nullptr;
          }
    }

    std::shared_ptr<node> largest;
    auto current = root;
    while ((largest = heapify(current)) != current) {
        current = largest;
    }
    --sizeOfTree;
    return max;
  }

  void inspect(QTreeWidget *widget)
  {
    widget->clear();
    if(root){
        widget->insertTopLevelItem(0, getGuiNode(root));
    }
    widget->expandAll();
  }

  size_t size() { return sizeOfTree; }

  T &max() { return root->value; }
};


template class PriorityTree<long>;
template class PriorityTree<int>;
template class PriorityTree<char>;

#endif /* BDF6E45C_ABE6_4678_B2D0_0BA12C9BA714 */
