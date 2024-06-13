#include <stdexcept>
#include <utility>



template <typename K, typename V> class RBTree {
public:
  struct Node {
    friend class RBTree;

    K key;
    V val;

  protected:
    Node *left;
    Node *right;
    Node *parent;
    bool color;

    Node(const K &key, const V &val)
        : key(key), val(val), left(nullptr), right(nullptr), parent(nullptr),
          color(0) {}
  };

protected:
  Node *findNode(const K &key) {
    Node *cur = root;
    while (cur != nullptr) {
      if (key == cur->key)
        return cur;

      if (key < cur->key)
        cur = cur->left;
      else
        cur = cur->right;
    }

    return nullptr;
  }

  void replaceWith(Node *from, Node *to) {
    Node *parent = from->parent;

    if (to) {
      to->parent = parent;
    }

    if (parent == nullptr) {
      root = to;
    } else {
      if (parent->left == from) {
        parent->left = to;
      } else {
        parent->right = to;
      }
    }
  }

  void rotateLeft(Node *x) {
    Node *y = x->right;

    Node *b = y->left;
    x->right = b;
    if (b != nullptr)
      b->parent = x;

    replaceWith(x, y);

    y->left = x;
    x->parent = y;
  }

  void rotateRight(Node *x) {

    Node *y = x->left;

    Node *b = y->right;
    x->left = b;
    if (b != nullptr)
      b->parent = x;

    replaceWith(x, y);

    y->right = x;
    x->parent = y;
  }

  long maxDepth(Node *node) {
    if (node == nullptr)
      return 0;
    int lnodes = maxDepth(node->left);
    int rnodes = maxDepth(node->right);
    return lnodes > rnodes ? lnodes + 1 : rnodes + 1;
  }

  void clear(Node *node) {
    if (node == nullptr)
      return;

    clear(node->left);
    clear(node->right);
    delete node;
  }

public:
  RBTree() : root(nullptr) {}
  ~RBTree() { clear(); }

  void clear() {
    clear(root);
    root = nullptr;
  }

  bool contains(const K &key) { return findNode(key) != nullptr; }

  V &get(const K &key) {
    Node *node = findNode(key);
    return node->val;
  }

  Node *insert(const K &key, const V &val) {
    if (root == nullptr) {
      root = new Node(key, val);
      root->color = 0;
      return root;
    }

    Node *parent = root;
    Node *node = nullptr;
    while (true) {
      if (key == parent->key) {
        parent->val = val;
        return parent;
      }

      if (key < parent->key) {
        if (parent->left == nullptr) {
          node = new Node(key, val);
          parent->left = node;
          break;
        } else {
          parent = parent->left;
        }
      } else {
        if (parent->right == nullptr) {
          node = new Node(key, val);
          parent->right = node;
          break;
        } else {
          parent = parent->right;
        }
      }
    }
    Node *res = node;

    node->color = true;
    node->parent = parent;

    while (node->parent != nullptr) {
      parent = node->parent;

      if (parent->color == 0)
        return res;

      Node *grand = parent->parent;
      if (grand == nullptr) {
        parent->color = 0;
        return res;
      }

      Node *uncle = grand->left == parent ? grand->right : grand->left;
      if (uncle == nullptr || uncle->color == 0) {
        if (grand->left == parent && parent->right == node) {
          rotateLeft(parent);
          std::swap(node, parent);
        }

        if (grand->right == parent && parent->left == node) {
          rotateRight(parent);
          std::swap(node, parent);
        }

        if (grand->left == parent) {
          rotateRight(grand);
        } else {
          rotateLeft(grand);
        }

        parent->color = 0; 
        grand->color = 1; 
        return res;
      }


      parent->color = 0;
      uncle->color = 0;
      grand->color = 1;

      node = grand;
    }

    return res;
  }

  void erase(const K &key) {
    Node *node = findNode(key);
    if (node == nullptr)
      return;

    if (node->left != nullptr && node->right != nullptr) {
      Node *toRepl = node->right;
      while (toRepl->left != nullptr)
        toRepl = toRepl->left;

      node->key = std::move(toRepl->key);
      node->val = std::move(toRepl->val);

      node = toRepl;
    }

    if (node->left == nullptr && node->right != nullptr) {
      node->right->color = 0;
      replaceWith(node, node->right);
      delete node;
      return;
    }

    if (node->right == nullptr && node->left != nullptr) {
      node->left->color = 0;
      replaceWith(node, node->left);
      delete node;
      return;
    }

    if (node == root) {
      delete root;
      root = nullptr;
      return;
    }

    if (node->color == 1) {
      replaceWith(node, nullptr);
      delete node;
      return;
    }

    Node *nodeToClean = node;

    if (node->left != nullptr || node->right != nullptr) {
      throw new std::logic_error("Invalid attempt to remove");
    }

      while (node->parent != nullptr) {
    
      {
        Node *parent = node->parent;
        bool atLeft = parent->left == node;
        Node *sibling = atLeft ? parent->right : parent->left;
        if (sibling->color == 1) {
          parent->color = 1;
          sibling->color = 0;

          if (atLeft)
            rotateLeft(parent);
          else
            rotateRight(parent);
        }
      }

    
      {
        Node *parent = node->parent;
        bool atLeft = parent->left == node;
        Node *sibling = atLeft ? parent->right : parent->left;

        bool blackSiblings =
            (sibling->color == 0) &&
            (sibling->left == nullptr || sibling->left->color == 0) &&
            (sibling->right == nullptr || sibling->right->color == 0);

        if ((parent->color == 0) && blackSiblings) {
          sibling->color = 1;
          node = node->parent;
          continue;
        }

        if ((parent->color == 1) && blackSiblings) {
          sibling->color = 1;
          parent->color = 0;
          break;
        }
      }

      {
        Node *parent = node->parent;
        bool atLeft = parent->left == node;
        Node *sibling = atLeft ? parent->right : parent->left;

        if (sibling->color == 0) {
          if (atLeft &&
              (sibling->right == nullptr || sibling->right->color == 0) &&
              (sibling->left && sibling->left->color == 1)) {
            sibling->color = 1;
            sibling->left->color = 0;
            rotateRight(sibling);
          } else if (!atLeft &&
                     (sibling->left == nullptr || sibling->left->color == 0) &&
                     (sibling->right && sibling->right->color == 1)) {
            sibling->color = 1;
            sibling->right->color = 0;
            rotateLeft(sibling);
          }
        }
      }

      {
        Node *parent = node->parent;
        bool atLeft = parent->left == node;
        Node *sibling = atLeft ? parent->right : parent->left;

        parent = node->parent;
        atLeft = parent->left == node;
        sibling = atLeft ? parent->right : parent->left;
        sibling->color = parent->color;
        parent->color = 0;

        if (atLeft) {
          if (sibling->right)
            sibling->right->color = 0;
          rotateLeft(parent);
        } else {
          if (sibling->left)
            sibling->left->color = 0;
          rotateRight(parent);
        }
      }

      break;
    }
    {
      Node *parent = nodeToClean->parent;
      if (parent) {
        if (parent->left == nodeToClean) {
          parent->left = nullptr;
        } else {
          parent->right = nullptr;
        }
      }
    }
    delete nodeToClean;
  }

  long maxDepth() { return maxDepth(root); }

public:
  class Iterator {
  protected:
    friend class RBTree<K, V>;
    Iterator(Node *root) : cur(root) {
      if(!cur) return;
      while (cur->left != nullptr)
        cur = cur->left;
    }

  public:
    Node *operator->() { return cur; }

    Node &operator*() { return *cur; }

    Iterator &operator++() {
    if (!cur)
        return *this;

    if (cur->right != nullptr) {
        cur = cur->right;
        while (cur->left != nullptr)
            cur = cur->left;
    } 
    else {
        while (cur->parent != nullptr && cur->parent->right == cur) {
            cur = cur->parent;
        }
        cur = cur->parent;
    }


      return *this;
    }

    bool operator==(const Iterator &other) {
      return cur == other.cur;
    }

    bool operator!=(const Iterator &other) { return !(*this == other); }

  protected:
    Node *cur;
  };

  Iterator begin() { return Iterator(root); }
  Iterator end() { return Iterator(nullptr); }

protected:
  Node *root;

public:
  class Inspector {
  public:
    virtual ~Inspector() {}
    virtual void setVal(const V& val) = 0;
    virtual void setKey(const K& key) = 0;
    virtual void setMode(int mode) = 0;
    virtual Inspector * createChild() = 0;
  };

protected:

  void inspect(Inspector *ins, Node *node) {
    if (node == nullptr) {
      ins->setMode(-1);
    } else {
      ins->setMode(node->color);
      ins->setKey(node->key);
      ins->setVal(node->val);
      inspect(ins->createChild(), node->left);
      inspect(ins->createChild(), node->right);
    }
  }

public:
  void inspect(Inspector *ins) {
    inspect(ins, root);
  }

  int calcSize(Node* n) {
    if (n == nullptr) return 0;
    return 1 + calcSize(n->left) + calcSize(n->right);
  }

  int size() {
    return calcSize(root);
  }
};


template <typename K, typename V> class Map: public RBTree<K, V> {
public:

  V& operator[](const K& key) {
    auto t = RBTree<K, V>::findNode(key);
    if(t != nullptr) {
      return t->val;
    };
    return RBTree<K, V>::insert(key, V())->val;
  };
};

template <typename K> class Set: public RBTree<K, char> {
public:
    void insert(const K& val) {
        RBTree<K, char>::insert(val, 'a');
    }
};  