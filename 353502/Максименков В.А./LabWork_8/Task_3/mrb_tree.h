#ifndef MRB_TREE_H
#define MRB_TREE_H

#include <memory>
template<class K, class V>
class mrb_tree
{
public:
    struct rb_tree_node
    {
        K key;
        V value;
        rb_tree_node *parent{nullptr};
        rb_tree_node *left{nullptr};
        rb_tree_node *right{nullptr};
        enum color { red, black } color{rb_tree_node::red};

        rb_tree_node(K key, V value, rb_tree_node *parent): key(key), value(value), parent(parent), left(nullptr), right(nullptr), color(rb_tree_node::red) {}
    };

private:
    bool isLeftChild(rb_tree_node *node)
    {
        return node->parent->left == node;
    }

    rb_tree_node *getUncle(rb_tree_node *node)
    {
        return isLeftChild(node->parent) ? getGrandparent(node)->right : getGrandparent(node)->left;
    }

    rb_tree_node *getGrandparent(rb_tree_node *node)
    {
        return node->parent->parent;
    }

    rb_tree_node *getBrother(rb_tree_node *node)
    {
        return isLeftChild(node) ? node->parent->right : node->parent->left;
    }

    bool areChildsBlack(rb_tree_node *node)
    {
        if (!node->left || !node->right)
        {
            return false;
        }

        return node->left->color == rb_tree_node::black && node->right->color == rb_tree_node::black;
    }

protected:
    void insert(K key, V value)
    {
        if (head == nullptr)
        {
            head = new rb_tree_node(key, value, nullptr);
            head->color = rb_tree_node::black;

            return;
        }

        rb_tree_node *curr = head;
        rb_tree_node *prev = nullptr;

        while (curr)
        {
            prev = curr;

            if (curr->key > key)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (prev->key > key)
        {
            prev->left = new rb_tree_node(key, value, prev);
            curr = prev->left;
        }
        else
        {
            prev->right = new rb_tree_node(key, value, prev);
            curr = prev->right;
        }

        fixInsert(curr);
    }

    void remove(K key)
    {
        rb_tree_node *curr = head;

        while (curr->key != key)
        {
            if (curr->key > key)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        if (!curr->left && !curr->right)
        {
            if (curr == head)
            {
                head = nullptr;
            }
            else
            {
                if (isLeftChild(curr))
                {
                    curr->parent->left = nullptr;
                }
                else
                {
                    curr->parent->right = nullptr;
                }
            }

            return;
        }

        rb_tree_node *next = rb_tree_node();

        if (curr->left && !curr->right)
        {
            if (isLeftChild(curr))
            {
                curr->parent->left = curr->left;
            }
            else
            {
                curr->parent->right = curr->left;
            }
        }
        else if (!curr->left && curr->right)
        {
            if (isLeftChild(curr))
            {
                curr->parent->left = curr->right;
            }
            else
            {
                curr->parent->right = curr->right;
            }
        }
        else
        {
            next = curr->right;

            while (next->left)
            {
                next = next->left;
            }

            if (next->right)
            {
                next->right->parent = next->parent;
            }

            if (next == head)
            {
                head = next->right;
            }
            else
            {
                if (isLeftChild(next))
                {
                    next->parent->left = next->right;
                }
                else
                {
                    next->parent->right = next->right;
                }
            }
        }

        if (next != curr)
        {
            curr->color = next->color;
            curr->key = next->key;
        }

        if (next->color == rb_tree_node::black)
        {
            fixRemove(next);
        }
    }

    rb_tree_node *find(K key)
    {
        rb_tree_node *curr = head;

        while (curr && curr->key != key)
        {
            if (curr->key > key)
            {
                curr = curr->left;
            }
            else
            {
                curr = curr->right;
            }
        }

        return curr;
    }

    void leftRotate(rb_tree_node *node)
    {
        auto q = node->right;
        node->right = q->left;
        q->left = node;
        q->parent = node->parent;
        node->parent = q;
        if (node->right)
        {
            node->right->parent = node;
        }

        if (head == node)
        {
            head = q;
        }
    }

    void rightRotate(rb_tree_node *node)
    {
        auto q = node->left;

        node->left = q->right;
        q->right = node;
        q->parent = node->parent;
        node->parent = q;

        if (node->left)
        {
            node->left->parent = node;
        }

        if (head == node)
        {
            head = q;
        }
    }

    void fixInsert(rb_tree_node *node)
    {
        if (node == head)
        {
            node->color = rb_tree_node::black;
            return;
        }

        while (node != head && node->parent->color == rb_tree_node::red)
        {
            if (isLeftChild(node->parent))
            {
                if (getUncle(node) && getUncle(node)->color == rb_tree_node::red)
                {
                    node->parent->color = rb_tree_node::black;
                    getUncle(node)->color = rb_tree_node::black;
                    getGrandparent(node)->color = rb_tree_node::red;
                    node = getGrandparent(node);
                }
                else
                {
                    if (!isLeftChild(node))
                    {
                        node = node->parent;
                        leftRotate(node);
                    }

                    node->parent->color = rb_tree_node::black;
                    getGrandparent(node)->color = rb_tree_node::red;
                    rightRotate(getGrandparent(node));
                }
            }
            else
            {
                if (getUncle(node) && getUncle(node)->color == rb_tree_node::red)
                {
                    node->parent->color = rb_tree_node::black;
                    getUncle(node)->color = rb_tree_node::black;
                    getGrandparent(node)->color = rb_tree_node::red;
                    node = getGrandparent(node);
                }
                else
                {
                    if (isLeftChild(node))
                    {
                        node = node->parent;
                        rightRotate(node);
                    }

                    node->parent->color = rb_tree_node::black;
                    getGrandparent(node)->color = rb_tree_node::red;
                    leftRotate(getGrandparent(node));
                }
            }
        }

        head->color = rb_tree_node::black;
    }

    void fixRemove(rb_tree_node *node)
    {
        while (node->color == rb_tree_node::black && node != head)
        {
            if (isLeftChild(node))
            {
                if (getBrother(node)->color == rb_tree_node::red)
                {
                    getBrother(node)->color = rb_tree_node::black;
                    node->parent->color = rb_tree_node::red;
                    leftRotate(node->parent);
                }

                if (areChildsBlack(getBrother(node)))
                {
                    getBrother(node)->color = rb_tree_node::red;
                }
                else
                {
                    if (!getBrother(node)->right || getBrother(node)->right->color == rb_tree_node::black)
                    {
                        getBrother(node)->left = rb_tree_node::black;
                        getBrother(node)->color = rb_tree_node::red;
                        rightRotate(getBrother(node));
                    }

                    getBrother(node)->color = node->parent->color;
                    node->parent->color = rb_tree_node::black;
                    getBrother(node)->right->color = rb_tree_node::black;
                    leftRotate(node->parent);
                    node = head;
                }
            }
            else
            {
                if (getBrother(node)->color == rb_tree_node::red)
                {
                    getBrother(node)->color = rb_tree_node::black;
                    node->parent->color = rb_tree_node::red;
                    rightRotate(node->parent);
                }

                if (areChildsBlack(getBrother(node)))
                {
                    getBrother(node)->color = rb_tree_node::red;
                }
                else
                {
                    if (!getBrother(node)->left || getBrother(node)->left->color == rb_tree_node::black)
                    {
                        getBrother(node)->right = rb_tree_node::black;
                        getBrother(node)->color = rb_tree_node::red;
                        leftRotate(getBrother(node));
                    }

                    getBrother(node)->color = node->parent->color;
                    node->parent->color = rb_tree_node::black;
                    getBrother(node)->left->color = rb_tree_node::black;
                    rightRotate(node->parent);
                    node = head;
                }
            }
        }

        node->color = rb_tree_node::black;
        head->color = rb_tree_node::black;
    }

public:
    class Iterator
    {
    private:
        rb_tree_node *ptr;

    public:
        friend class mrb_tree<K, V>;
        Iterator(rb_tree_node *node) : ptr(node) {}

        rb_tree_node *operator->()
        {
            return ptr;
        }

        rb_tree_node &operator*()
        {
            return *ptr;
        }

        Iterator &operator++()
        {
            if (!ptr)
            {
                return *this;
            }

            if (ptr->right != nullptr)
            {
                ptr = ptr->right;

                while (ptr->left != nullptr)
                {
                    ptr = ptr->left;
                }
            }
            else
            {
                while (ptr->parent != nullptr && ptr->parent->right == ptr)
                {
                    ptr = ptr->parent;
                }

                ptr = ptr->parent;
            }

            return *this;
        }

        bool operator==(const Iterator &other) { return ptr == other.ptr; }

        bool operator!=(const Iterator &other) { return !(*this == other); }
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

private:
    rb_tree_node *head{nullptr};
};

template<typename K, typename V>
class mmap : public mrb_tree<K, V>
{
public:
    V &operator[](const K &key)
    {
        auto t = mrb_tree<K, V>::find(key);
        if (t != nullptr)
        {
            return t->value;
        }
        mrb_tree<K, V>::insert(key, V());
        return mrb_tree<K, V>::find(key)->value;
    }
};

template<typename V>
class mset : public mrb_tree<V, V>
{
public:
    void insertVal(V value)
    {
        mrb_tree<V, V>::insert(value, value);
    }

    typename mrb_tree<V, V>::Iterator findVal(V value)
    {
        return typename mrb_tree<V, V>::Iterator(mrb_tree<V, V>::find(value));
    }
};

#endif // MRB_TREE_H
