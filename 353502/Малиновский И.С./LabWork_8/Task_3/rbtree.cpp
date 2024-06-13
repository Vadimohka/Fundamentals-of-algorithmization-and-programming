#include "rbtree.h"

Node::Node(int key, int val) : key(key), val(val), color(1), left(nullptr), right(nullptr), parent(nullptr) {};

RBTree::RBTree() : root(nullptr) {};

int RBTree::getColor(Node *&node) {
    if (!node) return 0;
    return node->color;
}

void RBTree::setColor(Node *&node, int color) {
    if (!node) return;
    node->color = color;
}

Node* RBTree::insertBST(Node *&root, Node *&ptr) {
    if (root == nullptr)
        return ptr;

    if (ptr->key < root->key) {
        root->left = insertBST(root->left, ptr);
        root->left->parent = root;
    } else if (ptr->key > root->key) {
        root->right = insertBST(root->right, ptr);
        root->right->parent = root;
    }

    return root;
}

void RBTree::insertValue(const int &key, const int &value) {
    Node *node = new Node(key, value);
    root = insertBST(root, node);
    fixInsertRBTree(node);
}

void RBTree::rotateLeft(Node *&ptr) {
    Node *right_child = ptr->right;
    ptr->right = right_child->left;

    if (ptr->right != nullptr)
        ptr->right->parent = ptr;

    right_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = right_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = right_child;
    else
        ptr->parent->right = right_child;

    right_child->left = ptr;
    ptr->parent = right_child;
}

void RBTree::rotateRight(Node *&ptr) {
    Node *left_child = ptr->left;
    ptr->left = left_child->right;

    if (ptr->left != nullptr)
        ptr->left->parent = ptr;

    left_child->parent = ptr->parent;

    if (ptr->parent == nullptr)
        root = left_child;
    else if (ptr == ptr->parent->left)
        ptr->parent->left = left_child;
    else
        ptr->parent->right = left_child;

    left_child->right = ptr;
    ptr->parent = left_child;
}

void RBTree::fixInsertRBTree(Node *&ptr) {
    Node *parent = nullptr;
    Node *grandparent = nullptr;
    while (ptr != root && getColor(ptr) && getColor(ptr->parent)) {
        parent = ptr->parent;
        grandparent = parent->parent;
        if (parent == grandparent->left) {
            Node *uncle = grandparent->right;
            if (getColor(uncle)) {
                setColor(uncle, 0);
                setColor(parent, 0);
                setColor(grandparent, 1);
                ptr = grandparent;
            } else {
                if (ptr == parent->right) {
                    rotateLeft(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateRight(grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        } else {
            Node *uncle = grandparent->left;
            if (getColor(uncle)) {
                setColor(uncle, 0);
                setColor(parent, 0);
                setColor(grandparent, 1);
                ptr = grandparent;
            } else {
                if (ptr == parent->left) {
                    rotateRight(parent);
                    ptr = parent;
                    parent = ptr->parent;
                }
                rotateLeft(grandparent);
                std::swap(parent->color, grandparent->color);
                ptr = parent;
            }
        }
    }
    setColor(root, 0);
}

void RBTree::fixDeleteRBTree(Node *&node) {
    if (node == nullptr)
        return;

    if (node == root) {
        root = nullptr;
        return;
    }

    if (getColor(node) || getColor(node->left) || getColor(node->right)) {
        Node *child = node->left != nullptr ? node->left : node->right;

        if (node == node->parent->left) {
            node->parent->left = child;
            if (child != nullptr) child->parent = node->parent;
            setColor(child, 0);
            delete (node);
        } else {
            node->parent->right = child;
            if (child != nullptr) child->parent = node->parent;
            setColor(child, 0);
            delete (node);
        }
    } else {
        Node *sibling = nullptr;
        Node *parent = nullptr;
        Node *ptr = node;
        setColor(ptr, 2);
        while (ptr != root && getColor(ptr) == 2) {
            parent = ptr->parent;
            if (ptr == parent->left) {
                sibling = parent->right;
                if (getColor(sibling) == 1) {
                    setColor(sibling, 0);
                    setColor(parent, 1);
                    rotateLeft(parent);
                } else {
                    if (getColor(sibling->left) == 0 && getColor(sibling->right) == 1) {
                        setColor(sibling, 1);
                        if(getColor(parent) == 1)
                            setColor(parent, 0);
                        else
                            setColor(parent, 2);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->right) == 0) {
                            setColor(sibling->left, 0);
                            setColor(sibling, 1);
                            rotateRight(sibling);
                            sibling = parent->right;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, 0);
                        setColor(sibling->right, 0);
                        rotateLeft(parent);
                        break;
                    }
                }
            } else {
                sibling = parent->left;
                if (getColor(sibling) == 1) {
                    setColor(sibling, 0);
                    setColor(parent, 1);
                    rotateRight(parent);
                } else {
                    if (getColor(sibling->left) == 0 && getColor(sibling->right) == 0) {
                        setColor(sibling, 1);
                        if (getColor(parent) == 1)
                            setColor(parent, 0);
                        else
                            setColor(parent, 2);
                        ptr = parent;
                    } else {
                        if (getColor(sibling->left) == 0) {
                            setColor(sibling->right, 0);
                            setColor(sibling, 1);
                            rotateLeft(sibling);
                            sibling = parent->left;
                        }
                        setColor(sibling, parent->color);
                        setColor(parent, 0);
                        setColor(sibling->left, 0);
                        rotateRight(parent);
                        break;
                    }
                }
            }
        }
        if (node == node->parent->left)
            node->parent->left = nullptr;
        else
            node->parent->right = nullptr;
        delete(node);
        setColor(root, 0);
    }
}

Node* RBTree::eraseBST(Node *&root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        return eraseBST(root->left, key);

    if (key > root->key)
        return eraseBST(root->right, key);

    if (root->left == nullptr || root->right == nullptr)
        return root;

    Node *temp = minValueNode(root->right);
    root->key = temp->key;
    return eraseBST(root->right, temp->key);
}

void RBTree::eraseValue(const int &key) {
    Node *node = eraseBST(root, key);
    fixDeleteRBTree(node);
}

Node *RBTree::minValueNode(Node *&node) {

    Node *ptr = node;

    while (ptr->left != nullptr)
        ptr = ptr->left;

    return ptr;
}

Node* RBTree::maxValueNode(Node *&node) {
    Node *ptr = node;

    while (ptr->right != nullptr)
        ptr = ptr->right;

    return ptr;
}

int RBTree::getBlackHeight(Node *node) {
    int blackheight = 0;
    while (node != nullptr) {
        if (getColor(node) == 0)
            blackheight++;
        node = node->left;
    }
    return blackheight;
}

void RBTree::printTree(QTreeWidget *treeWidget, QTreeWidgetItem *parent, Node *root) {
    if (!root) return;
    QTreeWidgetItem* item = new QTreeWidgetItem(parent ? parent : treeWidget->invisibleRootItem());
    item->setText(0, "(" + QString::number(root->key) + "; " + QString::number(root->val) + ") - " + (getColor(root) == 1 ? "RED" : "BLACK"));
    printTree(treeWidget, item, root->left);
    printTree(treeWidget, item, root->right);
}

void RBTree::print(QTreeWidget *treeWidget, QTreeWidgetItem *parent) {
    printTree(treeWidget, parent, root);
}
