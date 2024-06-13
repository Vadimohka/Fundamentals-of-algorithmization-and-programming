#ifndef AVLTREE_H
#define AVLTREE_H

#include <QString>

template<typename T>
class AVLTree
{
    struct node
    {
        T data;
        int key;
        node *left;
        node *right;
        int height;

        node(int64_t key, T data)
            : key(key)
            , data(data)
            , left(nullptr)
            , right(nullptr)
        {}
    };

    node *tree;
    int size;

public:
    AVLTree()
        : size(0)
        , tree(nullptr)
    {}

    ~AVLTree() { clear(tree); }

    node *GetRoot() { return tree; }

    void directOutput(node *Node)
    {
        if (Node != nullptr) {
            qDebug() << Node->data;
            directOutput(Node->left);
            directOutput(Node->right);
        }
    }

    void reverseOutput(node *Node)
    {
        if (Node != nullptr) {
            reverseOutput(Node->left);
            reverseOutput(Node->right);
            qDebug() << Node->data;
        }
    }

    void increaseKeyOutput(node *Node)
    {
        if (Node != nullptr) {
            increaseKeyOutput(Node->left);
            qDebug() << Node->data;
            increaseKeyOutput(Node->right);
        }
    }

    int getheight(node *node)
    {
        if (node) {
            return node->height;
        }
        return 0;
    }

    void fixheight(node *node)
    {
        //qDebug() << 1;
        if (node->left == nullptr && node->right == nullptr) {
            node->height = 1;
            return;
        }
        if (node->left == nullptr || node->right == nullptr) {
            if (node->left == nullptr) {
                node->height = node->right->height + 1;
            } else {
                node->height = node->left->height + 1;
            }
            return;
        }
        //qDebug() << node->left->height << node->right->height;
        node->height = std::max(node->left->height, node->right->height) + 1;
    }

    int heightdif(node *Node)
    {
        //qDebug() << getheight(Node->right) << getheight(Node->left);
        return getheight(Node->right) - getheight(Node->left);
    }

    node *rotateleft(node *Node)
    {
        node *right = Node->right;
        Node->right = right->left;
        right->left = Node;
        fixheight(Node);
        fixheight(right);
        return right;
    }

    node *rotateright(node *Node)
    {
        node *left = Node->left;
        Node->left = left->right;
        left->right = Node;
        fixheight(Node);
        fixheight(left);
        return left;
    }

    node *balance(node *Node)
    {
        //qDebug() << 4;
        fixheight(Node);
        //qDebug() << heightdif(Node);
        if (heightdif(Node) == -2) {
            if (heightdif(Node->left) > 0) {
                Node->left = rotateleft(Node->left);
            }
            return rotateright(Node);
        }
        if (heightdif(Node) == 2) {
            if (heightdif(Node->right) < 0) {
                Node->right = rotateleft(Node->right);
            }
            return rotateleft(Node);
        }
        //qDebug() << 5;
        return Node;
    }

    void add(int key, T value)
    {
        //qDebug() << 1;
        tree = add(tree, key, value);
    }

    node *add(node *Node, int key, T value)
    {
        if (Node == nullptr) {
            size++;
            Node = new node(key, value);
            return Node;
        }
        if (key < Node->key) {
            Node->left = add(Node->left, key, value);
        } else {
            Node->right = add(Node->right, key, value);
        }
        //qDebug() << 2;
        return balance(Node);
        //qDebug() << 3;
    }

    node *find(node *Node, int key)
    {
        if (Node == nullptr) {
            return nullptr;
        }
        if (Node->key == key) {
            return Node;
        }
        if (Node->key > key) {
            find(Node->left, key);
        } else {
            find(Node->right, key);
        }
    }

    void remove(int key) { tree = remove(tree, key); }

    node *findmin(node *Node)
    {
        if (Node->left == nullptr) {
            return Node;
        }
        return findmin(Node->left);
    }

    node *removemin(node *Node)
    {
        if (Node->left == nullptr) {
            return Node->right;
        }
        Node->left = removemin(Node->left);
        balance(Node);
    }

    node *remove(node *Node, int key)
    {
        if (Node == nullptr) {
            return nullptr;
        }
        if (Node->key == key) {
            node *right = Node->right;
            node *left = Node->left;
            delete Node;
            size--;
            if (right == nullptr) {
                return left;
            }
            node *min = findmin(right);
            min->right = removemin(right);
            min->left = left;
            balance(min);
            return min;
        }
        if (Node->key > key) {
            Node->left = remove(Node->left, key);
        } else {
            Node->right = remove(Node->right, key);
        }
        return Node;
    }
};

#endif // AVLTREE_H
