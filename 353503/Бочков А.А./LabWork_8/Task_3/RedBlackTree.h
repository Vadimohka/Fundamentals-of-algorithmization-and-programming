#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include <stdexcept>
#include <utility>
template<typename KeyT, typename ValT>
class RedBlackTree
{
protected:
    enum node_colors { RED, BLACK };

    struct node
    {
        node *parent, *left, *right;
        enum node_colors color;
        KeyT key;
        ValT val;
        node(node *p, node *l, node *r, enum node_colors c, KeyT k, ValT v)
            : parent(p)
            , left(l)
            , right(r)
            , color(c)
            , key(std::move(k))
            , val(std::move(v))
        {}
    };

    node *findNode(const KeyT &key)
    {
        node *cur = root;
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

    node *grandparent(struct node *n)
    {
        if ((n != nullptr) && (n->parent != nullptr))
            return n->parent->parent;
        else
            return nullptr;
    }

    node *uncle(struct node *n)
    {
        struct node *g = grandparent(n);
        if (g == nullptr)
            return nullptr;
        if (n->parent == g->left)
            return g->right;
        else
            return g->left;
    }

    void rotateLeft(struct node *n)
    {
        struct node *pivot = n->right;

        pivot->parent = n->parent;
        if (n->parent != nullptr) {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }

        n->right = pivot->left;
        if (pivot->left != nullptr)
            pivot->left->parent = n;

        n->parent = pivot;
        pivot->left = n;

        if (n == root) {
            root = pivot;
        }
    }

    void rotateRight(struct node *n)
    {
        struct node *pivot = n->left;

        pivot->parent = n->parent;
        if (n->parent != nullptr) {
            if (n->parent->left == n)
                n->parent->left = pivot;
            else
                n->parent->right = pivot;
        }

        n->left = pivot->right;
        if (pivot->right != nullptr)
            pivot->right->parent = n;

        n->parent = pivot;
        pivot->right = n;

        if (n == root) {
            root = pivot;
        }
    }

    void insert_case1(struct node *n)
    {
        if (n->parent == nullptr)
            n->color = BLACK;
        else
            insert_case2(n);
    }

    void insert_case2(struct node *n)
    {
        if (n->parent->color == BLACK)
            return;
        else
            insert_case3(n);
    }

    void insert_case3(struct node *n)
    {
        struct node *u = uncle(n), *g;

        if ((u != nullptr) && (u->color == RED)) {
            n->parent->color = BLACK;
            u->color = BLACK;
            g = grandparent(n);
            g->color = RED;
            insert_case1(g);
        } else {
            insert_case4(n);
        }
    }

    void insert_case4(struct node *n)
    {
        struct node *g = grandparent(n);

        if ((n == n->parent->right) && (n->parent == g->left)) {
            rotateLeft(n->parent);
            n = n->left;
        } else if ((n == n->parent->left) && (n->parent == g->right)) {
            rotateRight(n->parent);
            n = n->right;
        }
        insert_case5(n);
    }

    void insert_case5(struct node *n)
    {
        struct node *g = grandparent(n);

        n->parent->color = BLACK;
        g->color = RED;
        if ((n == n->parent->left) && (n->parent == g->left)) {
            rotateRight(g);
        } else {
            rotateLeft(g);
        }
    }

    struct node *sibling(struct node *n)
    {
        if (n == n->parent->left)
            return n->parent->right;
        else
            return n->parent->left;
    }

    void replaceWith(node *from, node *to)
    {
        node *parent = from->parent;

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

    void clear(node *node)
    {
        if (node == nullptr)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }

    int calcSize(node *n)
    {
        if (n == nullptr)
            return 0;
        return 1 + calcSize(n->left) + calcSize(n->right);
    }

public:
    RedBlackTree()
        : root(nullptr){};

    node *insert(KeyT key, ValT val)
    {
        if (root == nullptr) {
            root = new node(nullptr, nullptr, nullptr, BLACK, key, val);
            return root;
        }
        return insert(key, val, root);
    }

    node *insert(KeyT key, ValT val, node *n)
    {
        if (key == n->key) {
            //n->val = val;
            return n;
        }

        if (key > n->key) {
            if (n->right)
                return insert(key, val, n->right);
            else {
                n->right = new node(n, nullptr, nullptr, RED, key, val);
                insert_case1(n->right);
                return n->right;
            }
        } else {
            if (n->left)
                return insert(key, val, n->left);
            else {
                n->left = new node(n, nullptr, nullptr, RED, key, val);
                insert_case1(n->left);
                return n->left;
            }
        }
    }

    bool contains(KeyT &key) { return findNode(key) != nullptr; }

    void erase(const KeyT &key)
    {
        node *n = findNode(key);
        if (n == nullptr)
            return;

        if (n->left != nullptr && n->right != nullptr) {
            node *toRepl = n->right;
            while (toRepl->left != nullptr)
                toRepl = toRepl->left;

            n->key = std::move(toRepl->key);
            n->val = std::move(toRepl->val);

            n = toRepl;
        }

        if (n->left == nullptr && n->right != nullptr) {
            n->right->color = RED;
            replaceWith(n, n->right);
            delete n;
            return;
        }

        if (n->right == nullptr && n->left != nullptr) {
            n->left->color = RED;
            replaceWith(n, n->left);
            delete n;
            return;
        }

        if (n == root) {
            delete root;
            root = nullptr;
            return;
        }

        if (n->color == BLACK) {
            replaceWith(n, nullptr);
            delete n;
            return;
        }

        node *nodeToClean = n;

        if (n->left != nullptr || n->right != nullptr) {
            throw new std::logic_error("Invalid attempt to remove");
        }

        while (n->parent != nullptr) {
            {
                node *parent = n->parent;
                bool atLeft = parent->left == n;
                node *sibling = atLeft ? parent->right : parent->left;
                if (sibling->color == BLACK) {
                    parent->color = BLACK;
                    sibling->color = RED;

                    if (atLeft)
                        rotateLeft(parent);
                    else
                        rotateRight(parent);
                }
            }

            {
                node *parent = n->parent;
                bool atLeft = parent->left == n;
                node *sibling = atLeft ? parent->right : parent->left;

                bool blackSiblings = (sibling->color == RED)
                                     && (sibling->left == nullptr || sibling->left->color == RED)
                                     && (sibling->right == nullptr || sibling->right->color == RED);

                if ((parent->color == RED) && blackSiblings) {
                    sibling->color = BLACK;
                    n = n->parent;
                    continue;
                }

                if ((parent->color == BLACK) && blackSiblings) {
                    sibling->color = BLACK;
                    parent->color = RED;
                    break;
                }
            }

            {
                node *parent = n->parent;
                bool atLeft = parent->left == n;
                node *sibling = atLeft ? parent->right : parent->left;

                if (sibling->color == RED) {
                    if (atLeft && (sibling->right == nullptr || sibling->right->color == RED)
                        && (sibling->left && sibling->left->color == BLACK)) {
                        sibling->color = BLACK;
                        sibling->left->color = RED;
                        rotateRight(sibling);
                    } else if (!atLeft && (sibling->left == nullptr || sibling->left->color == RED)
                               && (sibling->right && sibling->right->color == BLACK)) {
                        sibling->color = BLACK;
                        sibling->right->color = RED;
                        rotateLeft(sibling);
                    }
                }
            }

            {
                node *parent = n->parent;
                bool atLeft = parent->left == n;
                node *sibling = atLeft ? parent->right : parent->left;

                parent = n->parent;
                atLeft = parent->left == n;
                sibling = atLeft ? parent->right : parent->left;
                sibling->color = parent->color;
                parent->color = RED;

                if (atLeft) {
                    if (sibling->right)
                        sibling->right->color = RED;
                    rotateLeft(parent);
                } else {
                    if (sibling->left)
                        sibling->left->color = RED;
                    rotateRight(parent);
                }
            }

            break;
        }

        {
            node *parent = nodeToClean->parent;
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

    void clear()
    {
        clear(root);
        root = nullptr;
    }

    node *root;

    size_t size() { return calcSize(root); }

public:
    class Iterator
    {
    protected:
        friend class RedBlackTree<KeyT, ValT>;
        Iterator(node *root)
            : cur(root)
        {
            if (!cur)
                return;
            while (cur->left != nullptr)
                cur = cur->left;
        }

    public:
        node *operator->() { return cur; }

        node &operator*() { return *cur; }

        Iterator &operator++()
        {
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

        bool operator==(const Iterator &other) { return cur == other.cur; }

        bool operator!=(const Iterator &other) { return !(*this == other); }

    protected:
        node *cur;
    };

    Iterator begin() { return Iterator(root); }
    Iterator end() { return Iterator(nullptr); }
};

template<typename KeyT, typename ValT>
class Map : public RedBlackTree<KeyT, ValT>
{
    using RedBlackTree = RedBlackTree<KeyT, ValT>;

public:
    ValT &operator[](const KeyT &key)
    {
        auto t = RedBlackTree::findNode(key);
        if (t != nullptr) {
            return t->val;
        };
        return RedBlackTree::insert(key, ValT())->val;
    };

    const ValT operator[](const KeyT &key) const { return *this[key]; }
};

template<typename ValT>
class Set : public RedBlackTree<ValT, char>
{
    using RedBlackTree = RedBlackTree<ValT, char>;

public:
    void insert(ValT &val) { RedBlackTree::insert(val, 'a'); }
};

#endif // REDBLACKTREE_H
