#ifndef RBT_H
#define RBT_H
#include "node.h"
#include <memory>
template<class T, class T1>
class RBT {

protected:
    std::shared_ptr<Node<T, T1>> root;

public:
    RBT() : root(nullptr) {}
    ~RBT() {
        clear();
    }
    void add(T key, T1 value) {
        std::shared_ptr<Node<T, T1>> tmp = root, p = std::shared_ptr<Node<T, T1>>();

        while (tmp) {
            p = tmp;

            if (tmp->key() > key) {
                tmp = tmp->left;
            } else if (tmp->key() < key) {
                tmp = tmp->right;
            } else {
                return;
            }
        }

        tmp = std::make_shared<Node<T, T1>>(key, value);
        tmp->parent = p;

        if (p) {
            if (tmp->key() > p->key()) {
                p->right = tmp;
            } else {
                p->left = tmp;
            }
        } else {
            root = tmp;
        }

        if (p) {
            if (tmp->key() > p->key()) {
                tmp->next = p->next;
                if (p->next) {
                    p->next->prev = tmp;
                }
                p->next = tmp;
                tmp->prev = p;
            } else {
                tmp->prev = p->prev;
                if (p->prev) {
                    p->prev->next = tmp;
                }
                p->prev = tmp;
                tmp->next = p;
            }
        } else {
            tmp->next = nullptr;
            tmp->prev = nullptr;
        }

        if (!tmp->prev) {
            root = tmp;
        }

        InsCase1(tmp);
        return;
    }
    void remove(T key) {
        std::shared_ptr<Node<T, T1>> tmp = root ? find(root, key) : std::shared_ptr<Node<T, T1>>();

        if (!tmp) {
            return;
        }

        // Update the doubly linked list pointers
        if (tmp->prev) {
            tmp->prev->next = tmp->next;
        }
        if (tmp->next) {
            tmp->next->prev = tmp->prev;
        }

        if (tmp->parent.expired() && !tmp->left && !tmp->right) {
            root = std::shared_ptr<Node<T, T1>>();
            return;
        }

        if (tmp->left && tmp->right) {
            std::shared_ptr<Node<T, T1>> removed = tmp->left;
            while (removed->right) {
                removed = removed->right;
            }
            // Create a new Node with updated key and value
            auto newNode = std::make_shared<Node<T, T1>>(removed->key(), removed->value()); // Use removed->key() instead of tmp->key()

            // Update pointers to the new node
            if (tmp->parent.expired()) {
                root = newNode;
            } else {
                auto parent = tmp->parent.lock();
                if (parent->left == tmp) {
                    parent->left = newNode;
                } else {
                    parent->right = newNode;
                }
            }

            // Update the current node to point to the new node
            tmp = newNode;
        }

        std::shared_ptr<Node<T, T1>> child = tmp->left ? tmp->left : tmp->right;

        if (!child) {
            if (tmp->color) {
                DelCase1(tmp);
            }
            std::shared_ptr<Node<T, T1>> p = tmp->parent.lock();
            if (p->left == tmp) {
                p->left = child;
            } else {
                p->right = child;
            }
        } else {
            child->parent = tmp->parent;
            std::shared_ptr<Node<T, T1>> p = tmp->parent.lock();
            if (tmp->parent.lock()) {
                if (tmp == p->left) {
                    p->left = child;
                } else {
                    p->right = child;
                }
            } else {
                root = child;
                if (tmp->color) {
                    if (!child->color) {
                        child->color = 1;
                    } else {
                        DelCase1(child);
                    }
                }
            }
        }
    }
    T1 findValueWithKey(T key){
        auto node = find(root, key);
        if (!node) {
            throw "Key not found";
        }
        return node->data;
    }
    bool contains(T key){
        return find(root, key) != nullptr;
    }
    T1& operator[](T key){
        auto node = find(root, key);
        if (node) {
            return node->value();
        } else {
            add(key, T1());
            node = find(root, key);
            return node->value();
        }
    }
    void clear() {
        clear(root);
        root = nullptr;
    }

protected:
    void clear(std::shared_ptr<Node<T, T1>> node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            node.reset();
        }
    }

    std::shared_ptr<Node<T, T1>> grandparent(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        if (p && !p->parent.expired()) {
            return p->parent.lock();
        } else {
            return std::shared_ptr<Node<T, T1>>();
        }
    }

    std::shared_ptr<Node<T, T1>> uncle(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> tmp = grandparent(node);

        if (tmp) {
            if (tmp->left == node->parent.lock()) {
                return tmp->right;
            } else {
                return tmp->left;
            }
        }

        return std::shared_ptr<Node<T, T1>>();
    }
    std::shared_ptr<Node<T, T1>> sibling(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.expired()) {
            return std::shared_ptr<Node<T, T1>>();
        }

        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        if (node == p->left) {
            return p->right;
        } else {
            return p->left;
        }
    }

    void RotateLeft(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> right = node->right;

        right->parent = node->parent;
        if (!node->parent.expired()) {
            std::shared_ptr<Node<T, T1>> p = node->parent.lock();

            if (p->left == node) {
                p->left = right;
            } else {
                p->right = right;
            }
        } else {
            root = right;
        }

        node->right = right->left;
        if (right->left) {
            right->left->parent = node;
        }

        node->parent = right;
        right->left = node;
    }
    void RotateRight(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> left = node->left;

        left->parent = node->parent;
        if (!node->parent.expired()) {
            std::shared_ptr<Node<T, T1>> p = node->parent.lock();

            if (p->left == node) {
                p->left = left;
            } else {
                p->right = left;
            }
        } else {
            root = left;
        }

        node->left = left->right;
        if (left->right) {
            left->right->parent = node;
        }

        node->parent = left;
        left->right = node;
    }

    void InsCase1(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.expired()) {
            node->color = 1;
        }
        else {
            InsCase2(node);
        }
    }
    void InsCase2(std::shared_ptr<Node<T, T1>> node){
        if (node->parent.lock()->color) {
            return;
        } else {
            InsCase3(node);
        }
    }
    void InsCase3(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> u = uncle(node);

        if (u && !u->color) {
            node->parent.lock()->color = 1;
            u->color = 1;
            std::shared_ptr<Node<T, T1>> g = grandparent(node);
            g->color = 0;
            InsCase1(g);
        } else {
            InsCase4(node);
        }
    }
    void InsCase4(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> g = grandparent(node), tmp = node;
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        if (node == p->right && p == g->left) {
            RotateLeft(p);
            tmp = node->left;
        } else if (node == p->left && p == g->right) {
            RotateRight(p);
            tmp = node->right;
        }

        InsCase5(tmp);
    }
    void InsCase5(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> g = grandparent(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        p->color = 1;
        g->color = 0;

        if (node == p->left) {
            RotateRight(g);
        } else {
            RotateLeft(g);
        }
    }

    void DelCase1(std::shared_ptr<Node<T, T1>> node){
        if (!node->parent.expired()) {
            DelCase2(node);
        }
    }
    void DelCase2(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        bool scol = s ? s->color : 1;

        if (!scol) {
            p->color = 0;
            s->color = 1;

            if (node == p->left) {
                RotateLeft(p);
            } else {
                RotateRight(p);
            }
        }

        DelCase3(node);
    }
    void DelCase3(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool scol = s ? s->color : 1;
        bool lcol = s && s->left ? s->left->color : 1;
        bool rcol = s && s->right ? s->right->color : 1;

        if (p->color && scol && lcol && rcol) {
            if (s) {
                s->color = 0;
            }
            DelCase1(p);
        } else {
            DelCase4(node);
        }
    }
    void DelCase4(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool scol = s ? s->color : 1;
        bool lcol = s && s->left ? s->left->color : 1;
        bool rcol = s && s->right ? s->right->color : 1;

        if (!p->color && scol && lcol && rcol) {
            if (s) {
                s->color = 0;
            }
            p->color = 1;
        } else {
            DelCase5(node);
        }
    }
    void DelCase5(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();

        bool lcol = s->left ? s->left->color : 1;
        bool rcol = s->right ? s->right->color : 1;

        if (s->color) {
            if (node == p->left && rcol && !lcol) {
                s->color = 0;
                s->left->color = 1;
                RotateRight(s);
            } else if (node == p->right && lcol && !rcol) {
                s->color = 0;
                s->right->color = 1;
                RotateLeft(s);
            }
        }

        DelCase6(node);
    }
    void DelCase6(std::shared_ptr<Node<T, T1>> node){
        std::shared_ptr<Node<T, T1>> s = sibling(node);
        std::shared_ptr<Node<T, T1>> p = node->parent.lock();
        s->color = p->color;
        p->color = 1;

        if (node == p->left) {
            if (s->right) {
                s->right->color = 1;
            }
            RotateLeft(p);
        } else {
            if (s->left) {
                s->left->color = 1;
            }
            RotateRight(p);
        }
    }

    std::shared_ptr<Node<T, T1>> find(std::shared_ptr<Node<T, T1>> node, T key){
        while (node) {
            if (node->key() > key) {
                node = node->left;
            } else if (node->key() < key) {
                node = node->right;
            } else {
                return node;
            }
        }
        return nullptr;
    }

    std::shared_ptr<Node<T, T1>> min(std::shared_ptr<Node<T, T1>> node){
        if (!node) {
            return nullptr;
        }
        while (node->left) {
            node = node->left;
        }
        return node;
    }
    std::shared_ptr<Node<T, T1>> max(std::shared_ptr<Node<T, T1>> node){
        if (!node) {
            return nullptr;
        }
        while (node->right) {
            node = node->right;
        }
        return node;
    }

public:
    class TreeIterator {
    public:
        TreeIterator(std::shared_ptr<Node<T, T1>> root) {
            current = min(root);
        }

        std::shared_ptr<Node<T, T1>> Next() {
            if (!current) return nullptr;

            std::shared_ptr<Node<T, T1>> nextNode = nullptr;

            if (current->right) {
                nextNode = min(current->right);
            } else {
                std::shared_ptr<Node<T, T1>> parent;
                while ((parent = current->parent.lock()) && current == parent->right) {
                    current = parent;
                }
                nextNode = parent;
            }

            current = nextNode;
            return current;
        }

        T Key() const {
            return current ? current->key() : T();
        }

        std::shared_ptr<Node<T, T1>> current;

    private:

        std::shared_ptr<Node<T, T1>> min(std::shared_ptr<Node<T, T1>> node) {
            if (!node) {
                return nullptr;
            }
            while (node->left) {
                node = node->left;
            }
            return node;
        }
    };
    TreeIterator GetIterator() {
        return TreeIterator(root);
    }
public:
    class ListIterator {
    public:
        ListIterator(std::shared_ptr<Node<T, T1>> start) : current(start) {}

        bool Next() {
            if (current) {
                current = current->next;
                return current != nullptr;
            }
            return false;
        }

        T Key() const {
            return current ? current->key() : T();
        }

        T1 Value() const {
            return current ? current->value() : T1();
        }
        std::shared_ptr<Node<T, T1>> current;
    };

    ListIterator GetListIterator() {
        return ListIterator(min(root));
    }
};
#endif // RBT_H
