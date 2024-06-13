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

  void insertFromAnother(const TreeNode* source, TreeNode** destination) {
      if (source) {
          insert(source->key, source->value);
          insertFromAnother(source->left, destination);
          insertFromAnother(source->right, destination);
      }
  }

  void fronAnother(const SearchTree& source, SearchTree* destination) {
      destination->root = nullptr;
      if (source.root) {
          insertFromAnother(source.root, &destination->root);
      }
  }

  long countNodes(const TreeNode* node) {
      if (!node) {
          return 0;
      }
      return countNodes(node->left) + countNodes(node->right) + 1;
  }

  long intoVine(TreeNode* tail) {
      long nodeCount = 0;
      TreeNode* currentNode = tail->right;
      while (currentNode) {
          if (!currentNode->left) {
              nodeCount++;
              tail = currentNode;
              currentNode = currentNode->right;
          } else {
              TreeNode* temp = currentNode->left;
              currentNode->left = temp->right;
              temp->right = currentNode;
              currentNode = temp;
              tail->right = temp;
          }
      }
      return nodeCount;
  }

  void compress(TreeNode* root, long nodeCount) {
      for (int i = 0; i < nodeCount; i++) {
          TreeNode* child = root->right;
          root->right = child->right;
          root = root->right;
          child->right = root->left;
          root->left = child;
      }
  }

  int walk(const TreeNode* node, WalkMode walkMode, V** resultArray) {
      if (!node) {
          return 0;
      }

      int nodeCount = 0;

      switch (walkMode) {
      case WalkMode::Direct:
          *resultArray = &node->val;
          nodeCount++;
          break;
      case WalkMode::Incrementing:
          nodeCount += walk(node->left, walkMode, resultArray + nodeCount);
          *resultArray = &node->val;
          nodeCount++;
          break;
      case WalkMode::Reverse:
          nodeCount += walk(node->right, walkMode, resultArray + nodeCount);
          *resultArray = &node->val;
          nodeCount++;
          break;
      }

      nodeCount += walk(node->right, walkMode, resultArray + nodeCount);

      return nodeCount;
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
    delete this->root;
    this->root = nullptr;
  }

  void insert(long key, const V& value) {
      TreeNode** currentNode = &root;
      while (*currentNode) {
          if (key == (*currentNode)->key) {
              (*currentNode)->val = value;
              return;
          } else if (key < (*currentNode)->key) {
              currentNode = &(*currentNode)->left;
          } else {
              currentNode = &(*currentNode)->right;
          }
      }
      *currentNode = new TreeNode(key, value);
  }

  bool contains(long key) const {
      TreeNode* currentNode = root;
      while (currentNode) {
          if (key == currentNode->key) {
              return true;
          } else if (key < currentNode->key) {
              currentNode = currentNode->left;
          } else {
              currentNode = currentNode->right;
          }
      }
      return false;
  }

  V& get(long key) {
      TreeNode* currentNode = root;
      while (currentNode) {
          if (key == currentNode->key) {
              return currentNode->val;
          } else if (key < currentNode->key) {
              currentNode = currentNode->left;
          } else {
              currentNode = currentNode->right;
          }
      }
      throw std::invalid_argument("Key not found");
  }

  void remove(long key) {
      TreeNode** currentNodePtr = &root;
      TreeNode* nodeToRemove = nullptr;

      // Find the node to be removed
      while (*currentNodePtr != nullptr) {
          if (key == (*currentNodePtr)->key) {
              nodeToRemove = *currentNodePtr;
              break;
          } else if (key < (*currentNodePtr)->key) {
              currentNodePtr = &(*currentNodePtr)->left;
          } else {
              currentNodePtr = &(*currentNodePtr)->right;
          }
      }

      if (nodeToRemove == nullptr) {
          return; // Key not found
      }

      TreeNode* replacementNode;
      if (nodeToRemove->left == nullptr) {
          replacementNode = nodeToRemove->right;
      } else if (nodeToRemove->right == nullptr) {
          replacementNode = nodeToRemove->left;
      } else {
          TreeNode** rightmostLeftPtr = &nodeToRemove->left;
          while ((*rightmostLeftPtr)->right != nullptr) {
              rightmostLeftPtr = &(*rightmostLeftPtr)->right;
          }
          replacementNode = *rightmostLeftPtr;
          *rightmostLeftPtr = replacementNode->left;
          replacementNode->left = nodeToRemove->left;
          replacementNode->right = nodeToRemove->right;
      }

      *currentNodePtr = replacementNode;
      nodeToRemove->left = nullptr;
      nodeToRemove->right = nullptr;
      delete nodeToRemove;
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

  V** walk(WalkMode mode) {
    V **res = new V*[size()];
    walk(root, mode, res);
    return res;
  }

protected:
  TreeNode *root;
};
