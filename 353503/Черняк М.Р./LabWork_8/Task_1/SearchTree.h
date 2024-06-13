#include <climits>
#include <stdexcept>

enum WalkMode { Direct, Reverse, Incrementing };

template <typename V> class SearchTree {
private:
  long lowered_power(long x) {
    long s = x >> 1;
    while (s != 0) {
      x &= ~s;
      s >>= 1;
    }
    return x;
  }

protected:
  const long UNIHASH_P = 65519;

  struct TreeNode {
    long key;
    TreeNode *left;
    TreeNode *right;
    V val;

    TreeNode(long key, const V &val) : key(key), val(val) {
      left = nullptr;
      right = nullptr;
    }

    ~TreeNode() {
      if (left != nullptr)
        delete left;
      if (right != nullptr)
        delete right;
    }
  };

  void insertFromAnother(const TreeNode* node) {
      if (!node) {
          return;
      }
      insert(node->key, node->val);
      insertFromAnother(node->left);
      insertFromAnother(node->right);
  }

  void fromAnother(const SearchTree& another) {
      clear();
      if (another.root) {
          insertFromAnother(another.root);
      }
  }

  long countNodes(const TreeNode* root) const {
      if (!root) {
          return 0;
      }
      return 1 + countNodes(root->left) + countNodes(root->right);
  }

  long intoVine(TreeNode* tail) {
      long count = 0;
      TreeNode* current = tail->right;
      while (current != nullptr) {
          if (current->left == nullptr) {
              count++;
              tail = current;
              current = current->right;
          } else {
              TreeNode* temp = current->left;
              current->left = temp->right;
              temp->right = current;
              tail->right = temp;
              current = temp;
          }
      }
      return count;
  }

  void compress(TreeNode* root, long count) {
      for (long i = 0; i < count; i++) {
          TreeNode* child = root->right;
          root->right = child->right;
          root = root->right;
          child->right = root->left;
          root->left = child;
      }
  }

  int walk(TreeNode* current, WalkMode walkMode, V** arr) {
      if (current == nullptr) {
          return 0;
      }

      int moveBy = 0;
      if (walkMode == WalkMode::Direct) {
          *arr = &current->val;
          moveBy++;
      }

      moveBy += walk(current->left, walkMode, arr + moveBy);

      if (walkMode == WalkMode::Incrementing) {
          *arr = &current->val;
          moveBy++;
      }

      moveBy += walk(current->right, walkMode, arr + moveBy);

      if (walkMode == WalkMode::Reverse) {
          *arr = &current->val;
          moveBy++;
      }

      return moveBy;
  }

  int maxDepth(const TreeNode* node) {
      if (node == nullptr) {
          return 0;
      }
      return 1 + std::max(maxDepth(node->left), maxDepth(node->right));
  }

public:
  SearchTree() { this->root = nullptr; }

  SearchTree(const SearchTree &another) { fronAnother(another); }

  SearchTree &operator=(const SearchTree &another) {
    delete root;
    this->root = nullptr;

    fronAnother(another);
    return *this;
  }

  SearchTree(SearchTree &&another) {
    this->root = another.root;
    another.root = nullptr;
  }

  ~SearchTree() {
    if (this->root)
      delete this->root;
  }

  void clear() {
      delete root;
      root = nullptr;
  }

  void insert(long key, const V& value) {
      TreeNode** target = &root;
      while (*target != nullptr) {
          if ((*target)->key == key) {
              (*target)->val = value;
              return;
          } else if (key < (*target)->key) {
              target = &(*target)->left;
          } else {
              target = &(*target)->right;
          }
      }

      *target = new TreeNode(key, value);
  }

  bool contains(long key) const {
      TreeNode* current = root;
      while (current != nullptr) {
          if (current->key == key) {
              return true;
          } else if (key < current->key) {
              current = current->left;
          } else {
              current = current->right;
          }
      }
      return false;
  }

  V& get(long key) {
      TreeNode* current = root;
      while (current != nullptr) {
          if (current->key == key) {
              return current->val;
          } else if (key < current->key) {
              current = current->left;
          } else {
              current = current->right;
          }
      }
      throw std::invalid_argument("Key not found");
  }

  void remove(long key) {
      TreeNode** parentOfDeleteNode = &root;
      while (*parentOfDeleteNode != nullptr) {
          if ((*parentOfDeleteNode)->key == key) {
              break;
          } else if (key < (*parentOfDeleteNode)->key) {
              parentOfDeleteNode = &(*parentOfDeleteNode)->left;
          } else {
              parentOfDeleteNode = &(*parentOfDeleteNode)->right;
          }
      }
      if (*parentOfDeleteNode == nullptr) {
          return;
      }

      TreeNode* nodeToDelete = *parentOfDeleteNode;
      if (nodeToDelete->key != key) {
          return;
      }

      TreeNode* replacementNode;
      if (nodeToDelete->left == nullptr) {
          replacementNode = nodeToDelete->right;
      } else if (nodeToDelete->right == nullptr) {
          replacementNode = nodeToDelete->left;
      } else {
          TreeNode** rightmostInLeft = &nodeToDelete->left;
          while ((*rightmostInLeft)->right != nullptr) {
              rightmostInLeft = &(*rightmostInLeft)->right;
          }
          replacementNode = *rightmostInLeft;
          *rightmostInLeft = replacementNode->left;
          replacementNode->left = nodeToDelete->left;
          replacementNode->right = nodeToDelete->right;
      }

      *parentOfDeleteNode = replacementNode;
      nodeToDelete->left = nullptr;
      nodeToDelete->right = nullptr;
      delete nodeToDelete;
  }

  long size() const { return countNodes(root); }

  void balance() {
    TreeNode *pRoot = new TreeNode(LONG_MIN, V());
    pRoot->right = root;

    long count = intoVine(pRoot);

    long leaves = count + 1 - lowered_power(count + 1);

    compress(pRoot, leaves);
    count -= leaves;
    while (count > 1) {
      count /= 2;
      compress(pRoot, count);
    }

    root = pRoot->right;
  }

  V **walk(WalkMode mode) {
    V **res = new V *[size()];
    walk(root, mode, res);
    return res;
  }

  void appendTree(const SearchTree &another) {
    if (another.root)
      insertFromAnother(another.root);
  }

  int findLCA(int key_a, int key_b) {
    TreeNode *s = this->root;
    while (s != nullptr) {
      // One is a parent of another
      if (s->key == key_a)
        return s->key;
      if (s->key == key_b)
        return s->key;

      if(key_a < s->key && key_b < s->key) {
        s = s->left;
      } else if(key_a > s->key && key_b > s->key) {
        s = s->right;
      } else {
        return s->key;
      }
    }
    return 0;
  }

  int maxDepth() {
    return maxDepth(root);
  }

protected:
  TreeNode *root;
};
