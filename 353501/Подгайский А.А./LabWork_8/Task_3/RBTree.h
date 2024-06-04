#ifndef CC4E0E29_2C74_45C9_8C94_F19AC36959E7
#define CC4E0E29_2C74_45C9_8C94_F19AC36959E7
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <valarray>

template <typename K, typename V> class RBTree {

protected:
  static const unsigned char RED = 0;
  static const unsigned char BLACK = 1;

  static const int l = 0;
  static const int r = 1;

  using kv_pair = std::pair<K, V>;

  struct node {
    kv_pair kv; // key-value pair
    node *children[2];
    node *parent;
    unsigned char color;
  };

  // a fictional leaf node for convinience:
  // REASON: we want to assure that 'null' children are BLACK
  node *leaf_node;

  node *root;
  size_t sizevar = 0;

private:
  node *new_node(K key, const V &val, node *parent) {
    node *nd = reinterpret_cast<node *>(new uint8_t[sizeof(node)]);
    new (&nd->kv.first) K(key);
    new (&nd->kv.second) V(val);
    nd->children[l] = leaf_node;
    nd->children[r] = leaf_node;
    nd->color = RED;
    nd->parent = parent;
    return nd;
  }

  node *_small_left_rotate(node *X) {
    //              X
    //          /       \
    //        A         B
    //               /    \
    //               E    R

    //             X(B)
    //          /       \
    //        A(X)     B(R)
    //     /     \    
    //    Q(A) W(E)

    auto old_X = X;
    auto old_E = X->children[r]->children[l];

    // = B
    _reset_node(X, X->children[r]);
    X->parent = old_X->parent;

    X->children[l] = old_X;
    old_X->parent = X;

    old_X->children[r] = old_E;
    if (old_E && old_E != leaf_node)
      old_E->parent = old_X;
    return X;
  }

  node *_small_right_rotate(node *X) {
    //             X
    //          /    \
    //        A         B
    //       /  \      
    //      Q    W

    //             X(A)
    //          /       \
    //        A(Q)     B(X)
    //                /  \
    //              E(W)    R(B)

    auto old_X = X;
    auto old_W = X->children[l]->children[r];

    _reset_node(X, X->children[l]);
    X->parent = old_X->parent;

    X->children[r] = old_X;
    old_X->parent = X;

    old_X->children[l] = old_W;
    if (old_W && old_W != leaf_node)
      old_W->parent = old_X;
    return X;
  }

  void _reset_node(node *&nd, node *new_nd) {
    auto parent = nd->parent;
    if (nd == leaf_node) {
      return;
    }
    if (!parent) {
      root = new_nd;
    } else {
      if (parent->children[l] == nd) {
        parent->children[l] = new_nd;
      } else if (parent->children[r] == nd) {
        parent->children[r] = new_nd;
      }
      if (new_nd != leaf_node)
        new_nd->parent = parent;
    }

    nd = new_nd;
  }

  int _validateTree(node *node) {
    if (node == nullptr)
      return 0;

    if ((node->children[r] && node->children[r] != leaf_node &&
         node->children[r]->parent != node) ||
        (node->children[l] && node->children[l] != leaf_node &&
         node->children[l]->parent != node)) {
      throw std::logic_error("Node with invalid parent met");
    }

    if (node->color == RED) {
      if (node->children[l] && node->children[l]->color == RED) {
        throw std::logic_error("Invalid tree left color");
      }

      if (node->children[r] && node->children[r]->color == RED) {
        throw std::logic_error("Invalid tree right color");
      }
    }

    if (node->children[l] == leaf_node && node->children[r] != leaf_node) {
      if (node->children[r]->color != RED) {
        throw std::logic_error("Invalid tree single left color");
      }
    }

    if (node->children[r] == leaf_node && node->children[l] != leaf_node) {
      if (node->children[l]->color != RED) {
        throw std::logic_error("Invalid tree single right color");
      }
    }

    int blackLenLeft = _validateTree(node->children[l]);
    int blackLenRight = _validateTree(node->children[r]);

    if (blackLenLeft != blackLenRight) {
      throw std::logic_error("Invalid tree black length");
    }

    return blackLenLeft + (node->color == BLACK ? 1 : 0);
  }

  node *_sibling(node *nd) {
    auto par = nd->parent;
    if (!par) {
      return nullptr;
    }
    if (par->children[0] == nd) {
      return par->children[1];
    } else if (par->children[1] == nd) {
      return par->children[0];
    } else {
      std::cerr << "node with invalid [parent met\n";
      return nullptr;
    }
  }

  // assuming that nd is recently inserted RED node
  void _post_insert(node *nd) {

    // case 0: added node is root - recolor it to black and leave
    if (nd == root) {
      nd->color = BLACK;
      return;
    }
    // case 1: no rb tree rules violation: children is red, parent is black
    if (nd->parent->color == BLACK) {
      return;
    } else {
      // case 2: several actions are requered to fix rb tree
      // structure if parent is red
      auto N = nd;     // current node
      node *P, *G, *U; // parent, grandparent, uncle
      while (N != root && N->parent->color == RED) {
        P = N->parent;
        G = P->parent;
        U = _sibling(P);

        if (U->color == RED) {
          // case 2.1: uncle is RED. then the following recoloring does not
          // violate rb tree
          G->color = RED;
          P->color = BLACK;
          U->color = BLACK;
          N = G; // continue to the grandparent
        } else {
          // case 2.2: uncle is BLACK. perform several rotations, depending on
          // the position of current node and parent, and recolor them
          // parent is left child of grandparent
          if (G->children[l] == P) {
            if (P->children[r] == N) {
              //       G              G
              //     /  \            / \
              //    P    U    =>    N  U
              //     \             /
              //      N           P
              P = _small_left_rotate(P);
            }
            std::swap(G->color, P->color);
            _small_right_rotate(G);

            // std::cout << (int)G->parent->color << "  " << (int)G->color << "
            // " << (int)sibling(G)->color << "  \n";
            break;

          } else {
            if (P->children[l] == N) {
              //      G              G
              //     /  \            / \
              //    U    P    =>    U  N
              //        /               \
              //       N                 P
              P = _small_right_rotate(P);
            }
            std::swap(P->color, G->color);
            _small_left_rotate(G);

            // std::cout << (int)G->parent->color << "  " << (int)G->color << "
            // "  << (int)sibling(G)->color << "  \n";
            break;
          }
        }
      }
      root->color = BLACK;
    }
  }

  void _release_tree(node *nd) {
    if (!nd) {
      return;
    }
    if (nd->children[0] != leaf_node) {
      _release_tree(nd->children[0]);
    }
    if (nd->children[1] != leaf_node) {
      _release_tree(nd->children[1]);
    }
    delete nd;
  }

  // reference: https://www.cs.purdue.edu/homes/ayg/CS251/slides/chap13c.pdf
  //            https://www.geeksforgeeks.org/deletion-in-red-black-tree/
  void _post_remove(node *nd, node *nd_par, bool removed_color) {
    // case 0 : either removed red node, or replaced a red node
    if (removed_color == RED || nd->color == RED) {
      nd->color = BLACK;
      //  neither red-red case was introduced, nor black depth was violated
      return;
    } else {
      // cases 1, 2: we removed black node and hence violated the black depth

      // mark the new node DOUBLE BLACK, as if it would be 2 nodes in black
      // depth
      node *bb = nd;
      // unpleasant workaraund of obtaining the sibling
      node *S =
          nd_par->children[0] == nd ? nd_par->children[1] : nd_par->children[0];
      node *P = nd_par;

      // in this cycle double BLACK node is somehow compensated to become singly
      // BLACK node
      while (bb != root) {

        // case 1 : sibling is leaf or black
        if (S == leaf_node) {
          bb = P;
        } else if (S->color == BLACK) {
          // case 1.1 black sibling with all black children
          if (S->children[l]->color == BLACK &&
              S->children[r]->color == BLACK) {
            // recoloring
            //  if parent is RED, recolor to BLACK, and 2x BLACK -> 1x BLACK.
            //  end. otherwise recolor parent to 2x BLACK and continue
            S->color = RED;
            if (P->color == BLACK) {
              bb = P;
            } else {
              P->color = BLACK;
              return;
            }
          } // case 1.2 : black sibling with at least one red child
          else {
            // perform 1 or 2 rotations of the tree
            if (S == P->children[r]) { // RIGHT RIGHT

              if (S->children[r]->color == RED) {
                S->children[r]->color = BLACK;
                S->color = P->color;
                _small_left_rotate(P);
              } else { // RIGHT LEFT
                S->children[l]->color = P->color;
                _small_right_rotate(S);
                _small_left_rotate(P);
              }

            } else if (S == P->children[l]) {
              // std::cout << "ll\n";
              if (S->children[l]->color == RED) { // LEFT LEFT
                S->children[l]->color = BLACK;
                S->color = P->color;
                _small_right_rotate(P);

              } else { // LEFT RIGHT
                S->children[r]->color = P->color;
                _small_left_rotate(S);
                _small_right_rotate(P);
              }
            }
            P->color = BLACK; // in all cases the parent is colored BLACK
            return;
          }

        } else if (S->color == RED) {
          // case 2 : red sibling

          // recolor and perform rotation, so that sibling becomes black.
          P->color = RED;
          S->color = BLACK;
          if (S == P->children[r]) {
            _small_left_rotate(P);
            S = P->children[r]; // don't forget to update the sibling
          } else {
            _small_right_rotate(P);
            S = P->children[l];
          }
          continue;
        }

        S = _sibling(bb);
        P = bb->parent;
      }
    }
    // just to be sure
    root->color = BLACK;
  }

  node *_find_node(const K &key) {
    auto cur = root;
    while (cur != leaf_node) {
      if (key > cur->kv.first) {
        cur = cur->children[r];
      } else if (key < cur->kv.first) {
        cur = cur->children[l];
      } else {
        return cur;
      }
    }
    return nullptr;
  }

  void _replace_with_child(node *&nd, int i) {
    auto tmp = nd;
    _reset_node(nd, nd->children[i]);
    if (nd != leaf_node) {
      nd->parent = tmp->parent;
    }
    delete tmp;
  }

public:
  RBTree() {
    leaf_node = reinterpret_cast<node *>(new uint8_t[sizeof(node)]);
    leaf_node->children[0] = leaf_node->children[1] = nullptr;
    leaf_node->color = BLACK;

    root = nullptr;
  }

  ~RBTree() {
    _release_tree(root);
    delete leaf_node;
  }

  void clear() {
    _release_tree(root);
    root = nullptr;
  }

  void insert(const K &key, const V &val) {

    if (!root) {
      root = new_node(key, val, nullptr);
      _post_insert(root);
      ++sizevar;
    } else {
      node *cur = root;
      while (true) {
        if (key > cur->kv.first) {
          if (cur->children[r] != leaf_node)
            cur = cur->children[r];
          else {
            cur->children[r] = new_node(key, val, cur);
            _post_insert(cur->children[r]);
            ++sizevar;
            return;
          }
        } else if (key < cur->kv.first) {
          if (cur->children[l] != leaf_node)
            cur = cur->children[l];
          else {
            cur->children[l] = new_node(key, val, cur);
            _post_insert(cur->children[l]);
            ++sizevar;
            return;
          }
        } else {
          cur->kv.second = val;
          return;
        }
      }
    }
  }

  bool remove(K key) {

    node *to_remove = _find_node(key);

    if (to_remove == leaf_node || to_remove == nullptr) {
      return false;
    }

    if (to_remove->children[r] != leaf_node &&
        to_remove->children[l] != leaf_node) {
      // both children exist

      node *suc = to_remove->children[r];
      node *parent = to_remove;
      while (suc->children[l] != leaf_node) {
        parent = suc;
        suc = suc->children[l];
      }

      // copy keyval from leftmost successor to to_removed
      to_remove->kv = suc->kv;

      // gonna remove suc, so update the color and save its parent
      auto suc_parent = suc->parent;
      unsigned char color_being_removed = suc->color;
      node *replaced_with = suc->children[r];

      // suc has no left child, so replace with right child
      _replace_with_child(suc, r);
      _post_remove(replaced_with, suc_parent, color_being_removed);
    } else {

      // here we indeed remove 'to_remove'
      unsigned char color_being_removed = to_remove->color;
      node *parent = to_remove->parent;
      node *replaced_with;
      if (to_remove->children[l] != leaf_node) {
        replaced_with = to_remove->children[l];
        _replace_with_child(to_remove, l);
      } else if (to_remove->children[r] != leaf_node) {
        replaced_with = to_remove->children[r];
        _replace_with_child(to_remove, r);
      } else {
        replaced_with = leaf_node;
        _replace_with_child(to_remove, 0);
      }

      _post_remove(replaced_with, parent, color_being_removed);
    }

    --sizevar;
    return true;
  }

  void validate_tree() { _validateTree(root); }

  V &get(K key) { return _find_node(key)->kv.second; }

  bool contains(K key) { return _find_node(key) != nullptr; }

  size_t size() { return sizevar; }

  class iterator {
    friend class RBTree;
    node *cur;
    node *leaf_node;

    iterator(node *target, node *leaf) : cur(target), leaf_node(leaf) {}

  public:
    iterator &operator++() {
      if (cur->children[r] != leaf_node) {
        cur = cur->children[r];
        while (cur->children[l] != leaf_node) {
          cur = cur->children[l];
        }
      } else {
        while (cur->parent != nullptr && cur == cur->parent->children[r]) {
          cur = cur->parent;
        }
        cur = cur->parent;
      }
      return *this;
    }

    std::pair<K,V> operator*() { return cur->kv; }
    std::pair<K,V> *operator->() { return &cur->kv; }
    bool operator==(const iterator &other) { return cur == other.cur; }
    bool operator!=(const iterator &other) { return cur != other.cur; }
  };

  iterator begin() {
    node *lmost = root;
    while (lmost->children[l] != leaf_node) {
      lmost = lmost->children[l];
    }
    return iterator(lmost, leaf_node);
  }

  iterator end() { return iterator(nullptr, leaf_node); }
};

#endif /* CC4E0E29_2C74_45C9_8C94_F19AC36959E7 */
