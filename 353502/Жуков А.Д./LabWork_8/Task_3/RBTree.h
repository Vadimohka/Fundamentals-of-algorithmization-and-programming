#ifndef RBTREE_H
#define RBTREE_H
#include <stdint.h>
#include <memory>
#include <stdexcept>

template <typename K, typename V> class RBTree {


public:
    static const bool RED = 0;
    static const bool BLACK = 1;

    struct Node {
        friend class RBTree;

        K key;
        V value;

    protected:
        Node *left;
        Node *right;
        Node *parent;
        bool color;

        Node(const K &key, const V &val)
            : key(key), value(val), left(nullptr), right(nullptr), parent(nullptr),
            color(RED) {}
    };

protected:

    Node *root;


    void rotateLeft(Node* x)
    {
        Node* y = x->right;
        y->parent = x->parent;
        if (x->parent != nullptr) {
            if (x->parent->left==x)
                x->parent->left = y;
            else
                x->parent->right = y;
        }

        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;

        x->parent = y;
        y->left = x;
    }


    void rotateRight(Node* x)
    {
        Node* y = x->left;

        y->parent = x->parent;
        if (x->parent != nullptr) {
            if (x->parent->left==x)
                x->parent->left = y;
            else
                x->parent->right = y;
        }

        x->left = y->right;
        if (y->right != nullptr)
            y->right->parent = x;

        x->parent = y;
        y->right = x;
    }


    Node* findNode(const K& key) {
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


    Node* getUncle(Node* a){
        if(a->parent == a->parent->parent->left)
            return a->parent->parent->right;
        if(a == a->parent->right)
            return a->parent->parent->left;
    }

    void fixInsertion(Node* t){
        if(t == root){ //case1
            t->color = BLACK;
            return;
        }
        //case2...


        while(t->parent->color == RED){//case3
            if (t->parent == t->parent->parent->left) { //dad is left
                Node* u = getUncle(t); // uncle
                if (u->color == RED) {
                    t->parent->color = BLACK;
                    u->color = BLACK;
                    t->parent->parent->color = RED;
                    t = t->parent->parent;
                }
                else {
                    if (t == t->parent->right) {
                        t = t->parent;
                        rotateLeft(t);
                    }
                    t->parent->color = BLACK;
                    t->parent->parent->color = RED;
                    rotateRight(t->parent->parent);
                }
            }
            else { //dad is right
                Node* u = getUncle(t); // uncle
                if (u->color == RED) {
                    t->parent->color = BLACK;
                    u->color = BLACK;
                    t->parent->parent->color = RED;
                    t = t->parent->parent;
                }
                else {
                    if (t == t->parent->left) {
                        t = t->parent;
                        rotateRight(t);
                    }
                    t->parent->color = BLACK;
                    t->parent->parent->color = RED;
                    rotateLeft(t->parent->parent);
                }
            }
        }
        root->color = BLACK;
    }


    void replaceWith(Node *from, Node *to) {//ставим ребенка на место родителя
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


    int calcSize(Node* n) {
        if (n == nullptr) return 0;
        return 1 + calcSize(n->left) + calcSize(n->right);
    }
public:
    RBTree() : root(nullptr) {}
   // ~RBTree() { clear(); }

//    Node* insert(const K& key, const V& val) {
//        Node* t = new Node(key, val);
//        if (root == nullptr) {
//            root = t;
//        }
//        else{
//            Node* p = root;
//            Node* q = nullptr;

//            while(p != nullptr){
//                q = p;
//                if(p->key < t->key){
//                    p = p->right;
//                }
//                else{
//                    p = p->left;
//                }
//            }

//            t->parent = q;
//            if (q->key < t->key)
//                q->right = t;
//            else
//                q->left = t;
//        }
//        fixInsertion(t);

//    }


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
                parent->value = val;
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

        if (node->left != nullptr && node->right != nullptr) {//min of right
            Node *toRepl = node->right;
            while (toRepl->left != nullptr)
                toRepl = toRepl->left;

            node->key = std::move(toRepl->key);
            node->value = std::move(toRepl->value);

            node = toRepl;
        }

        // One child
        if (node->left == nullptr && node->right != nullptr) {
            node->right->color = RED;
            replaceWith(node, node->right);
            delete node;
            return;
        }

        if (node->right == nullptr && node->left != nullptr) {
            node->left->color = RED;
            replaceWith(node, node->left);
            delete node;
            return;
        }

        // No children there
        if (node == root) {
            delete root;
            root = nullptr;
            return;
        }

        //ALL IS OK WHEN RED
        if (node->color == RED) {
            replaceWith(node, nullptr);
            delete node;
            return;
        }

        Node *nodeToClean = node;

        // At this point we should now have a black node
        // With no children, just to be sure let's check
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

        // Actually remove node from tree
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

    void clear(Node *node) {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    size_t size() {
        return calcSize(root);
    }

    bool contains(const K &key) { return findNode(key) != nullptr; }

    V& get(const K &key) {
        Node *node = findNode(key);
        return node->value;
    }

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
            return cur == other.cur;
        }

        bool operator!=(const Iterator &other) { return !(*this == other); }

    protected:
        Node *cur;
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }

};



template <typename K, typename V> class Map: public RBTree<K, V> {
    using RBTree = RBTree<K, V>;

public:
    V& operator[](const K& key) {
        auto t = RBTree::findNode(key);
        if(t != nullptr) {
            return t->value;
        };
        return RBTree::insert(key, V())->value;
    };
};




template <typename V> class Set: public RBTree<V, char> {
    using RBTree = RBTree<V, char>;
public:
    void insert(V&& val) {
        RBTree::insert(val, 'a');
    }
};
#endif // RBTREE_H
