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
  Node* findNode(const K& key) {
      Node* current = root;
      while (current != nullptr) {
          if (key == current->key) {
              return current;
          } else if (key < current->key) {
              current = current->left;
          } else {
              current = current->right;
          }
      }
      return nullptr;
  }

  void replaceWith(Node* from, Node* to) {
      if (from->parent == nullptr) {
          // 'from' is the root
          root = to;
      } else if (from->parent->left == from) {
          // 'from' is the left child
          from->parent->left = to;
      } else {
          // 'from' is the right child
          from->parent->right = to;
      }

      if (to != nullptr) {
          to->parent = from->parent;
      }
  }

  void rotateLeft(Node* x) {
      // Get the right child of x
      Node* y = x->right;

      // Rearrange the pointers
      x->right = y->left;
      if (y->left != nullptr) {
          y->left->parent = x;
      }
      y->parent = x->parent;

      // Replace x with y in the tree
      if (x->parent == nullptr) {
          // x was the root
          root = y;
      } else if (x == x->parent->left) {
          x->parent->left = y;
      } else {
          x->parent->right = y;
      }

      // Set x as the left child of y
      y->left = x;
      x->parent = y;
  }

  void rotateRight(Node* x) {
      // Get the left child of x
      Node* y = x->left;

      // Rearrange the pointers
      x->left = y->right;
      if (y->right != nullptr) {
          y->right->parent = x;
      }
      y->parent = x->parent;

      // Replace x with y in the tree
      if (x->parent == nullptr) {
          // x was the root
          root = y;
      } else if (x == x->parent->right) {
          x->parent->right = y;
      } else {
          x->parent->left = y;
      }

      // Set x as the right child of y
      y->right = x;
      x->parent = y;
  }

  long maxDepth(Node* node) {
      if (node == nullptr) {
          return 0;
      }
      return 1 + std::max(maxDepth(node->left), maxDepth(node->right));
  }

  int validateTree(Node* node) {
      if (node == nullptr) {
          return 0;
      }

      int leftBlackCount = validateTree(node->left);
      int rightBlackCount = validateTree(node->right);

      // Check if the number of black nodes on the left and right subtrees are equal
      if (leftBlackCount != rightBlackCount) {
          throw std::logic_error("Invalid tree black length");
      }

      // Check the color constraints
      if (node->color == 1) { // Red node
          if (node->left && node->left->color == 1) {
              throw std::logic_error("Invalid tree left color");
          }
          if (node->right && node->right->color == 1) {
              throw std::logic_error("Invalid tree right color");
          }
      }
      if ((node->left == nullptr && node->right != nullptr && node->right->color != 1) ||
          (node->right == nullptr && node->left != nullptr && node->left->color != 1)) {
          throw std::logic_error("Invalid tree single child color");
      }

      return leftBlackCount + (node->color == 0 ? 1 : 0);
  }

  void clear(Node* node) {
      if (node == nullptr) {
          return;
      }

      // Recursively clear the left and right subtrees
      clear(node->left);
      clear(node->right);

      // Delete the current node
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

  Node* insert(const K& key, const V& val) {
      if (root == nullptr) {
          root = new Node(key, val);
          root->color = false; // Black
          return root;
      }

      Node* node = insertInBST(root, key, val);
      node->color = true; // Red
      rebalanceAfterInsertion(node);
      return node;
  }

  Node* insertInBST(Node* parent, const K& key, const V& val) {
      if (key == parent->key) {
          parent->val = val;
          return parent;
      }

      Node* node = nullptr;
      if (key < parent->key) {
          if (parent->left == nullptr) {
              node = new Node(key, val);
              parent->left = node;
          } else {
              return insertInBST(parent->left, key, val);
          }
      } else {
          if (parent->right == nullptr) {
              node = new Node(key, val);
              parent->right = node;
          } else {
              return insertInBST(parent->right, key, val);
          }
      }

      node->parent = parent;
      return node;
  }

  void rebalanceAfterInsertion(Node* node) {
      while (node->parent != nullptr && node->parent->color) {
          Node* parent = node->parent;
          Node* grandparent = parent->parent;

          if (grandparent->left == parent) {
              Node* uncle = grandparent->right;
              if (uncle != nullptr && uncle->color) {
                  parent->color = false;
                  uncle->color = false;
                  grandparent->color = true;
                  node = grandparent;
              } else {
                  if (parent->right == node) {
                      rotateLeft(parent);
                      std::swap(node, parent);
                  }
                  rotateRight(grandparent);
                  parent->color = false;
                  grandparent->color = true;
              }
          } else {
              Node* uncle = grandparent->left;
              if (uncle != nullptr && uncle->color) {
                  parent->color = false;
                  uncle->color = false;
                  grandparent->color = true;
                  node = grandparent;
              } else {
                  if (parent->left == node) {
                      rotateRight(parent);
                      std::swap(node, parent);
                  }
                  rotateLeft(grandparent);
                  parent->color = false;
                  grandparent->color = true;
              }
          }
      }

      root->color = false; // Black
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

    // One child
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
      // Case 2:
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

      // Case 3 and 4:
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

      // Case 5:
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

      // Case 6:
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

  void validateTree() { validateTree(root); }

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
      } else {
        while (cur->parent != nullptr && cur->parent->right == cur) {
          cur = cur->parent;
        }
        cur = cur->parent;
      }


      return *this;
    }

    bool operator==(const Iterator &other) {
      // if (cur == nullptr && other.cur == nullptr)
      //   return true;
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
};


template <typename K, typename V> class Map: public RBTree<K, V> {
  using RBTree = RBTree<K, V>;
  
public:
  V& operator[](const K& key) {
    auto t = RBTree::findNode(key);
    if(t != nullptr) {
      return t->val;
    };
    return RBTree::insert(key, V())->val;
  };
};
