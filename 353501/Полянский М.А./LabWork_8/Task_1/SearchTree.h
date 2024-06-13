#include <climits>
#include <stdexcept>

template <typename T> 
class SearchTree {
public:
  struct TreeNode {
    long key;
    TreeNode *left;
    TreeNode *right;
    T val;

    TreeNode(long key, const T &val) : key(key), val(val), left(nullptr), right(nullptr) {}

    ~TreeNode() {
      if (left != nullptr)
        delete left;
      if (right != nullptr)
        delete right;
    }
  };

protected:
  TreeNode *root;

  void insertFromAnother(const TreeNode *another) {
    insert(another->key, another->val);
    if (another->right)
      insertFromAnother(another->right);
    if (another->left)
      insertFromAnother(another->left);
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

  int walk(TreeNode *cur, bool direct, bool incrementing, T **arr) {
    if (cur == nullptr)
      return 0;

    int movby = 0;
    if (direct || incrementing) {
      *arr = &cur->val;
      movby++;
    }

    movby += walk(cur->left, direct, incrementing, arr + movby);

    if (!incrementing) {
      *arr = &cur->val;
      movby++;
    }

    movby += walk(cur->right, direct, incrementing, arr + movby);

    if (!direct && !incrementing) {
      *arr = &cur->val;
      movby++;
    }

    return movby;
  }

  int maxDepth(const TreeNode *node) {
    if(node == nullptr) return 0;
    int lDepth = maxDepth(node->left);
    int rDepth = maxDepth(node->right);
    return (lDepth > rDepth ? lDepth : rDepth) + 1;
  }

public:
  SearchTree() : root(nullptr) {}

  SearchTree(const SearchTree &another) { fronAnother(another); }

  SearchTree &operator=(const SearchTree &another) {
    delete root;
    this->root = nullptr;

    fronAnother(another);
    return *this;
  }

  SearchTree(SearchTree &&another) : root(another.root) {
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

  void insert(long key, const T &value) {
    TreeNode **target = &this->root;
    while (*target != nullptr) {
      long targkey = (*target)->key;
      if (targkey == key) {
        (*target)->val = value;
        return;
      } else if (key < targkey) {
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

  T &get(long key) {
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
    if(*parBefDel == nullptr) return;

    TreeNode *toDel = *parBefDel;
    if (toDel->key != key)
      return;

    TreeNode *replaceWith;
    if (toDel->left == nullptr) {
      replaceWith = toDel->right;
    } else if (toDel->right == nullptr) {
      replaceWith = toDel->left;
    } else {
      TreeNode **rightmostLeft = &toDel->left;
      while ((*rightmostLeft)->right != nullptr) {
        rightmostLeft = &(*rightmostLeft)->right;
      }

      replaceWith = *rightmostLeft;

      *rightmostLeft = replaceWith->left;

      replaceWith->left = toDel->left;
      replaceWith->right = toDel->right;
    }

    *parBefDel = replaceWith;
    toDel->left = nullptr;
    toDel->right = nullptr;
    delete toDel;
  }

  long size() const { return countNodes(root); }

  void balance() {
    TreeNode *pRoot = new TreeNode(LONG_MIN, T());
    pRoot->right = root;

    long count = intoVine(pRoot);

    long leaves = count + 1 - ((count + 1) & (count + 1));

    compress(pRoot, leaves);
    count -= leaves;
    while (count > 1) {
      count /= 2;
      compress(pRoot, count);
    }

    root = pRoot->right;
  }

  T **walk(bool direct, bool incrementing) {
    T **res = new T *[size()];
    walk(root, direct, incrementing, res);
    return res;
  }

  void AppendTree(const SearchTree &another) {
    if (another.root)
      insertFromAnother(another.root);
  }

  int FindCommonKey(int key_a, int key_b) {
    TreeNode *s = this->root;
    while (s != nullptr) {
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
};
