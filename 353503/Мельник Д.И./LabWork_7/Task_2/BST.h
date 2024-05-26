#pragma once

#include <cstddef>
#include <cstdlib>
#include <sys/types.h>
#include <vector>

template <typename T> class BST {
  using key_t = long;

public:
  struct node {
    key_t key;
    T val;
    node *left, *right;
    node *parent;
  };

protected:
  node *root = nullptr;
  size_t sizevar = 0;

  class node_ref {
    node *nd;

  public:
    const T &operator*() const { return nd->val; }
    T &operator*() { return nd->val; }
    bool is_valid() { return nd != nullptr; }

  private:
    node_ref(node *_nd = nullptr) : nd(_nd) {}
    friend class BST<T>;
  };

private:
  node *new_node(key_t key, const T &t, node *parent) {
    node *nd = reinterpret_cast<node *>(new u_int8_t[sizeof(node)]);
    nd->key = key;
    new (&nd->val) T(t);
    nd->left = nullptr;
    nd->right = nullptr;
    nd->parent = parent;
    return nd;
  }

  node *new_node(const node &nd, node *parent) {
    node *new_nd = reinterpret_cast<node *>(new u_int8_t[sizeof(node)]);
    new (&new_nd->val) T(nd.val);
    new_nd->key = nd.key;
    new_nd->parent = parent;
    return new_nd;
  }

  node *build_balanced_from_sorted(const std::vector<node> &sorted, long beg,
                                   long end) {
    if (beg > end) {
      return nullptr;
    }

    auto mid = (beg + end) / 2;

    node *nd = new_node(sorted[mid], nullptr);
    nd->left = build_balanced_from_sorted(sorted, beg, mid - 1);
    nd->right = build_balanced_from_sorted(sorted, mid + 1, end);

    if (nd->left) {
      nd->left->parent = nd;
    }
    if (nd->right) {
      nd->right->parent = nd;
    }

    return nd;
  }

  void _in_order_traverse(node *nd, std::vector<node> &vect) {
    if (nd != nullptr) {
      _in_order_traverse(nd->left, vect);
      vect.push_back(*nd);
      _in_order_traverse(nd->right, vect);
    }
  }

  void _pre_order_traverse(node *nd, std::vector<node> &vect) {
    if (nd != nullptr) {
      vect.push_back(*nd);
      _pre_order_traverse(nd->left, vect);
      _pre_order_traverse(nd->right, vect);
    }
  }

  void _post_order_traverse(node *nd, std::vector<node> &vect) {
    if (nd != nullptr) {
      _post_order_traverse(nd->left, vect);
      _post_order_traverse(nd->right, vect);
      vect.push_back(*nd);
    }
  }

  void release_tree(node *nd) {
    if (!nd) {
      return;
    }
    if (nd->left) {
      release_tree(nd->left);
    }
    if (nd->right) {
      release_tree(nd->right);
    }
    delete nd;
  }

  node *_remove(node *nd, key_t key, bool *removed) {
    if (!nd) {
      *removed = false;
      return nd;
    }

    if (key < nd->key) {
      nd->left = _remove(nd->left, key, removed);
    } else if (key > nd->key) {
      nd->right = _remove(nd->right, key, removed);
    } else {
      *removed = true;
      if (nd->left != nullptr && nd->right != nullptr) {
        // 2. two children
        node *suc = nd->right;
        node *parent = nd;
        while (suc->left != nullptr) {
          parent = suc;
          suc = suc->left;
        }

        nd->key = suc->key;
        nd->val = suc->val;

        if (suc == parent->right)
          parent->right = _remove(suc, suc->key, removed);
        else
          parent->left = _remove(suc, suc->key, removed);

      } else {
        // 1. one or no children at node
        if (nd->left) {
          auto tmp = nd->left;
          tmp->parent = nd->parent;
          delete nd;
          nd = tmp;
        } else if (nd->right) {
          auto tmp = nd->right;
          tmp->parent = nd->parent;
          delete nd;
          nd = tmp;
        } else {
          delete nd;
          return nullptr;
        }
      }
      --sizevar;
    }

    return nd;
  }

public:
  BST() = default;
  ~BST() {
    release_tree(root);
    root = nullptr;
  }

  void insert(key_t key, const T &t) {

    if (!root) {
      root = new_node(key, t, nullptr);
      ++sizevar;
    } else {
      node *cur = root;
      while (true) {
        if (key > cur->key) {
          if (cur->right)
            cur = cur->right;
          else {
            cur->right = new_node(key, t, cur);
            ++sizevar;
            return;
          }
        } else if (key < cur->key) {
          if (cur->left)
            cur = cur->left;
          else {
            cur->left = new_node(key, t, cur);
            ++sizevar;
            return;
          }
        } else {
          cur->val = t;
          return;
        }
      }
    }
  }

  node_ref search(key_t key) {
    if (!root) {
      return node_ref();
    }
    node *cur = root;
    while (cur->left != nullptr || cur->right != nullptr) {
      if (key > cur->key) {
        if (cur->right)
          cur = cur->right;
        else
          return node_ref();
      } else if (key < cur->key) {
        if (cur->left)
          cur = cur->left;
        else
          return node_ref();
      } else {
        return node_ref(cur);
      }
    }

    if (cur->key == key) {
      return node_ref(cur);
    } else {
      return node_ref(nullptr);
    }
  }

  std::vector<node> in_order_traverse() {
    std::vector<node> res;
    _in_order_traverse(root, res);
    return std::move(res);
  }

  std::vector<node> pre_order_traverse() {
    std::vector<node> res;
    _pre_order_traverse(root, res);
    return std::move(res);
  }

  std::vector<node> post_order_traverse() {
    std::vector<node> res;
    _post_order_traverse(root, res);
    return std::move(res);
  }

  void balance() {
    if(!root){
      return;
    }

    std::vector<node> traverse;
    traverse.reserve(sizevar);

    _in_order_traverse(root, traverse);
    release_tree(root);
    root = build_balanced_from_sorted(traverse, 0, traverse.size() - 1);
    root->parent = nullptr;
  }

  bool remove(key_t key) {
    bool was_removed;
    root = _remove(root, key, &was_removed);
    return was_removed;
  }

  size_t size() { return sizevar; }
};
