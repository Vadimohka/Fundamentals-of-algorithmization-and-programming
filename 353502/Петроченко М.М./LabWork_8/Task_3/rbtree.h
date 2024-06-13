#include <algorithm>
#include <cstdint>

enum color_t : uint8_t {
    RED = 0,
    BLACK = 1,
};

enum directions : uint8_t {
    LEFT = 0,
    RIGHT = 1,
};

template <typename K, typename V>
class RedBlackTree {

    friend class TreeNode;
    friend class TreeGraph;

   public:
    void del(K key) { this->internal_delete(this->root_, key); }

    void insert(K key, const V& value) {
        this->internal_insert(this->root_, key, value);
    }

    void insert(std::pair<K, V>& kval) {
        this->internal_insert(this->root_, kval.first, kval.second);
    }


   private:
    struct Node {
        std::pair<K, V> kv;
        Node* children[2] = { nullptr, nullptr };
        Node* parent = nullptr;
        color_t color = BLACK;

        Node(K key, V value, Node* parent = nullptr) : parent(parent) {
            this->color = RED;
            this->kv.first = key;
            this->kv.second = value;
        }

        ~Node() = default;
    };

   public:
    Node* find(K key) { return this->inner_find(this->root_, key); }

   private:
    Node* findGrandparent(Node* node) {
        if (node != nullptr && node->parent != nullptr) {
            return node->parent->parent;
        }
        return nullptr;
    }

    Node* inner_find(Node* root, K key) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->kv.first == key) {
            return root;
        }
        if (root->kv.first > key) {
            if (root->children[LEFT] == nullptr) {
                return nullptr;
            }
            return inner_find(root->children[LEFT], key);
        } else {
            if (root->children[RIGHT] == nullptr) {
                return nullptr;
            }
            return inner_find(root->children[RIGHT], key);
        }
    }

    Node* findUncle(Node* node) {
        Node* gp = this->findGrandparent(node);
        if (gp == nullptr) {
            return nullptr;
        } else if (node->parent == gp->children[RIGHT]) {
            return gp->children[LEFT];
        }
        return gp->children[RIGHT];
    }

    void internal_insert(Node*& root, K key, const V& value) {
        Node* to_insert = new Node(key, value, nullptr);
        if (root == nullptr) {
            root = to_insert;
            to_insert->color = BLACK;
            return;
        }
        Node* cur_node = root;
        Node* parent_node = nullptr;
        Node* grandparent_node = nullptr;
        directions insert_dir;
        bool case4 = false;
        bool case56 = false;
        bool case3 = true;
        while (cur_node != nullptr) {
            parent_node = cur_node;
            if (key < cur_node->kv.first) {
                cur_node = cur_node->children[LEFT];
            } else {
                cur_node = cur_node->children[RIGHT];
            }
        }
        to_insert->parent = parent_node;
        if (key < parent_node->kv.first) {
            parent_node->children[LEFT] = to_insert;
            insert_dir = LEFT;
        } else {
            parent_node->children[RIGHT] = to_insert;
            insert_dir = RIGHT;
        }
        do {
            if (parent_node->color == BLACK) {
                return;
            }
            if ((grandparent_node = parent_node->parent) == nullptr) {
                case4 = true;
                case3 = false;
                break;
            }
            directions dir =
                (parent_node == parent_node->parent->children[LEFT] ? LEFT
                                                                    : RIGHT);
            Node* uncle_node = parent_node->parent->children[1 - dir];
            if (uncle_node == nullptr || uncle_node->color == BLACK) {
                case56 = true;
                case3 = false;
                insert_dir = dir;
                break;
            }
            //INSERT_CASE2
            parent_node->color = BLACK;
            uncle_node->color = BLACK;
            grandparent_node->color = RED;
            to_insert = grandparent_node;
        } while ((parent_node = to_insert->parent) != nullptr);
        //INSERT_CASE3
        if (case3) {
            return;
        }
        //INSERT_CASE4
        if (case4) {
            parent_node->color = BLACK;
            return;
        }
        //INSERT_CASES 5 & 6
        if (case56) {
            if (to_insert == parent_node->children[1 - insert_dir]) {
                this->rotateDir(parent_node, insert_dir);
                to_insert = parent_node;
                parent_node = grandparent_node->children[insert_dir];
            }
            //INSERT_CASE6
            rotateDir(grandparent_node, 1 - insert_dir);
            parent_node->color = BLACK;
            grandparent_node->color = RED;
            return;
        }
    }

    void swap(Node* n1, Node* n2) {
        if (n1 == nullptr || n2 == nullptr) {
            return;
        }
        K n1_key = n1->kv.first;
        n1->kv.first = n2->kv.first;
        n2->kv.first = n1_key;
        V n1_val = n1->kv.second;
        n1->kv.second = n2->kv.second;
        n2->kv.second = n1_val;
    }

    Node* rotRootDir(Node*& root, Node* node, uint8_t dir) {
        Node* parent_node = node->parent;
        Node* subtree = node->children[1 - dir];
        Node* child = nullptr;
        if (subtree == nullptr) {
            return nullptr;
        }
        child = subtree->children[dir];
        node->children[1 - dir] = child;
        if (child != nullptr) {
            child->parent = node;
        }
        subtree->children[dir] = node;
        node->parent = subtree;
        subtree->parent = parent_node;
        if (parent_node != nullptr) {
            uint8_t direction =
                (node == parent_node->children[RIGHT]) ? RIGHT : LEFT;
            parent_node->children[direction] = subtree;
        } else {
            root = subtree;
        }
        return subtree;
    }

    Node* rotateLeft(Node* node) {
        return this->rotRootDir(this->root_, node, LEFT);
    }

    Node* rotateRight(Node* node) {
        return this->rotRootDir(this->root_, node, RIGHT);
    }

    Node* rotateDir(Node* node, uint8_t dir) {
        return this->rotRootDir(this->root_, node, dir);
    }

    Node* findMin(Node* node) {
        if (node->children[LEFT] == nullptr) {
            return node;
        }
        return findMin(node->children[LEFT]);
    }

    void internal_delete(Node*& root, K key) {
        Node* p = root;
        while (p->kv.first != key) {
            if (key < p->kv.first) {
                p = p->children[LEFT];
            } else {
                p = p->children[RIGHT];
            }
        }
        if (p == nullptr) {
            return;
        }
        if (p->children[RIGHT] == nullptr && p->children[LEFT] == nullptr) {
            if (p == root) {
                delete root;
                root = nullptr;
                return;
            }
            if (p->color == RED) {
                if (p->parent->children[LEFT] == p) {
                    delete p->parent->children[LEFT];
                    p->parent->children[LEFT] = nullptr;
                } else {
                    delete p->parent->children[RIGHT];
                    p->parent->children[RIGHT] = nullptr;
                }
            } else {
                this->rebalanceDel(root, p);
            }
            return;
        }
        if (p->children[RIGHT] != nullptr || p->children[LEFT] != nullptr) {
            if (p->children[RIGHT] != nullptr && p->children[LEFT] == nullptr) {
                p->children[RIGHT]->color = BLACK;
                if (p->parent->children[LEFT] == p) {
                    p->parent->children[LEFT] = p->children[RIGHT];
                } else {
                    p->parent->children[RIGHT] = p->children[RIGHT];
                }
                return;
            }
            if (p->children[RIGHT] == nullptr && p->children[LEFT] != nullptr) {
                p->children[LEFT]->color = BLACK;
                if (p->parent->children[LEFT] == p) {
                    p->parent->children[LEFT] = p->children[LEFT];
                } else {
                    p->parent->children[RIGHT] = p->children[LEFT];
                }
                return;
            }
        }
        Node* replace = this->findMin(p->children[RIGHT]);
        p->kv = replace->kv;
        if (replace->children[RIGHT] != nullptr) {
            if (replace->color == BLACK) {
                this->rebalanceDel(root, replace);
            } else {
                replace->children[RIGHT]->parent = replace->parent;
                replace->parent->children[LEFT] = replace->children[RIGHT];
                delete replace;
                return;
            }
        } else {
            replace->parent->children[LEFT] = nullptr;
        }
    }

    bool isBlack(Node* node) { return node == nullptr || node->color == BLACK; }

    void rebalanceDel(Node*& root, Node* deleted) {
        uint8_t dir =
            (deleted->parent->children[LEFT] == deleted) ? LEFT : RIGHT;
        Node* sibling = nullptr;
        Node* close_nephew = nullptr;
        Node* distant_nephew = nullptr;
        Node* parent_node = deleted->parent;
        bool start = true;
        bool case3 = false;
        bool case4 = false;
        bool case5 = false;
        bool case6 = false;
        parent_node->children[dir] = nullptr;
        do {
            if (start) {
                start = false;
            } else {
                dir =
                    (deleted->parent->children[LEFT] == deleted) ? LEFT : RIGHT;
            }
            sibling = parent_node->children[1 - dir];
            distant_nephew = sibling->children[1 - dir];
            close_nephew = sibling->children[dir];
            if (sibling->color == RED) {
                case3 = true;
                break;
            }
            if (distant_nephew != nullptr && distant_nephew->color == RED) {
                case6 = true;
                break;
            }
            if (close_nephew != nullptr && close_nephew->color == RED) {
                case5 = true;
                break;
            }
            if (parent_node->color == RED) {
                case4 = true;
                break;
            }
            if (parent_node == nullptr) {
                return;
            }
            sibling->color = RED;
            deleted = parent_node;
        } while ((parent_node = deleted->parent) != nullptr);
        if (!(case3 || case4 || case5 || case6)) {
            return;
        }
        //DEL_CASE3
        if (case3) {
            this->rotRootDir(root, parent_node, dir);
            parent_node->color = RED;
            sibling->color = BLACK;
            sibling = close_nephew;
            distant_nephew = sibling->children[1 - dir];
            if (distant_nephew != nullptr && distant_nephew->color == RED) {
                case6 = true;
            }
            if (!case6) {
                close_nephew = sibling->children[dir];
                if (close_nephew != nullptr && close_nephew->color == RED) {
                    case5 = true;
                }
            }
        }
        if (case4) {
            sibling->color = RED;
            parent_node->color = BLACK;
            return;
        }
        if (case5) {
            this->rotateDir(sibling, 1 - dir);
            sibling->color = RED;
            close_nephew->color = BLACK;
            distant_nephew = sibling;
            sibling = close_nephew;
            return;
        }
        if (case6) {
            this->rotRootDir(root, parent_node, dir);
            sibling->color = parent_node->color;
            parent_node->color = BLACK;
            distant_nephew->color = BLACK;
        }
    }

    Node* root_;
};
