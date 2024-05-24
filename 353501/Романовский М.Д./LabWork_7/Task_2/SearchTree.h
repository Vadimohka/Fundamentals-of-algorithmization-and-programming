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

  void insertFromAnother(const TreeNode *another) {
    insert(another->key, another->val);
    if (another->left)
      insertFromAnother(another->left);
    if (another->right)
      insertFromAnother(another->right);
  }

  void fronAnother(const SearchTree &another) {
    this->root = nullptr;
    if (another.root)
      insertFromAnother(another.root);
  }

  long countNodes(const TreeNode *root) const {
    if (root == nullptr)
      return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
  }

  long intoVine(TreeNode *tail) {
    long count = 0;
    TreeNode *curNode = tail->right;
    while (curNode != nullptr) {
      if (curNode->left == nullptr) {
        count++;
        tail = curNode;
        curNode = curNode->right;
      } else {
        // Rotate to make left node higher
        TreeNode *temp = curNode->left;
        curNode->left = temp->right;
        temp->right = curNode;
        curNode = temp;
        tail->right = temp;
      }
    }

    return count;
  }

  void compress(TreeNode *root, long count) {

    for (int i = 0; i < count; i++) {
      TreeNode *child = root->right;
      root->right = child->right;
      root = root->right;
      child->right = root->left;
      root->left = child;
    }
  }

  int walk(TreeNode *cur, WalkMode walkMode, V **arr) {
    if (cur == nullptr)
      return 0;

    int movby = 0;
    if (walkMode == WalkMode::Direct) {
      *arr = &cur->val;
      movby++;
    }

    movby += walk(cur->left, walkMode, arr + movby);

    if (walkMode == WalkMode::Incrementing) {
      *arr = &cur->val;
      movby++;
    }

    movby += walk(cur->right, walkMode, arr + movby);

    if (walkMode == WalkMode::Reverse) {
      *arr = &cur->val;
      movby++;
    }

    return movby;
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

  void insert(long key, const V &value) {
    TreeNode **target = &this->root;
    while (*target != nullptr) {
      long targkey = (*target)->key;
      if (targkey == key) {
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

  bool contains(long key) {
    TreeNode *s = this->root;
    while (s != nullptr) {
      if (s->key == key)
        return true;

      if (key < s->key) {
        s = s->left;
      } else {
        s = s->right;
      }
    }

    return false;
  }

  V &get(long key) {
    TreeNode *s = this->root;
    while (s != nullptr) {
      if (s->key == key)
        return s->val;

      if (key < s->key) {
        s = s->left;
      } else {
        s = s->right;
      }
    }

    throw new std::invalid_argument("Key not found");
  }

  void remove(long key) {
    // Address of pointer to node to be deleted
    TreeNode **parBefDel = &this->root;

    while (*parBefDel != nullptr) {
      if ((*parBefDel)->key == key)
        break;

      if (key < (*parBefDel)->key) {
        parBefDel = &(*parBefDel)->left;
      } else {
        parBefDel = &(*parBefDel)->right;
      }
    }

    // Node that will be deleted
    TreeNode *toDel = *parBefDel;
    if (toDel->key != key)
      return;

    // Node that will replace deleted node
    TreeNode *replaceWith;
    if (toDel->left == nullptr) {
      replaceWith = toDel->right;
    } else if (toDel->right == nullptr) {
      replaceWith = toDel->left;
    } else {
      // Address of pointer to node with
      // biggest key in left subtree
      TreeNode **rightmostLeft = &toDel->left;
      while ((*rightmostLeft)->right != nullptr) {
        rightmostLeft = &(*rightmostLeft)->right;
      }

      replaceWith = *rightmostLeft;

      // Detach this node from subtree it has only
      // one child (left), so replace with it
      *rightmostLeft = replaceWith->left;

      // Replace node to be deleted with
      // biggest node in left subtree
      replaceWith->left = toDel->left;
      replaceWith->right = toDel->right;
    }

    *parBefDel = replaceWith;
    toDel->left = nullptr;
    toDel->right = nullptr;
    delete toDel;

    return;
  }

  long size() const { return countNodes(root); }

  // Balance tree using Day–Stout–Warren algo
  void balance() {
    TreeNode *pRoot = new TreeNode(LONG_MIN, V());
    pRoot->right = root;

    // Creates sorted single-linked list
    long count = intoVine(pRoot);

    long leaves = count + 1 - lowered_power(count + 1);

    // Transform sorted link-list into tree
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
