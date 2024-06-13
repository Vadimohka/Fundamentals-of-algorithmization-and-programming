#include "redblacktree.h"
using namespace std;

RedBlackTree::RedBlackTree() { root = nullptr; }

bool RedBlackTree::isLeafNode(Node* node) {
    return (node->left == nullptr && node->right == nullptr);
}

void RedBlackTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;
    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

void RedBlackTree::rotateRight(Node *&root, Node *&pt) {
    Node *pt_left = pt->left;
    pt->left = pt_left->right;

    if (pt->left != nullptr)
        pt->left->parent = pt;

    pt_left->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_left;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;

    else
        pt->parent->right = pt_left;

    pt_left->right = pt;
    pt->parent = pt_left;
}

void RedBlackTree::fixInsertRBTree(Node *&root, Node *&pt) {
    Node *parent_pt = nullptr;
    Node *grand_parent_pt = nullptr;

    while ((pt != root) && (pt->color != BLACK) && (pt->parent->color == RED)) {
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;

        if (parent_pt == grand_parent_pt->left) {
            Node *uncle_pt = grand_parent_pt->right;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->right) {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        } else {
            Node *uncle_pt = grand_parent_pt->left;

            if (uncle_pt != nullptr && uncle_pt->color == RED) {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            } else {
                if (pt == parent_pt->left) {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }

                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }

    root->color = BLACK;
}

void RedBlackTree::fixDeleteRBTree(Node *&root, Node *&node) {
    Node *sibling;

    while (node != root && node->color == BLACK) {
        if (node == node->parent->left) {
            sibling = node->parent->right;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateLeft(root, node->parent);
                sibling = node->parent->right;
            }

            if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (sibling->right->color == BLACK) {
                    sibling->left->color = BLACK;
                    sibling->color = RED;
                    rotateRight(root, sibling);
                    sibling = node->parent->right;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->right->color = BLACK;
                rotateLeft(root, node->parent);
                node = root;
            }
        } else {
            sibling = node->parent->left;

            if (sibling->color == RED) {
                sibling->color = BLACK;
                node->parent->color = RED;
                rotateRight(root, node->parent);
                sibling = node->parent->left;
            }

            if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
                sibling->color = RED;
                node = node->parent;
            } else {
                if (sibling->left->color == BLACK) {
                    sibling->right->color = BLACK;
                    sibling->color = RED;
                    rotateLeft(root, sibling);
                    sibling = node->parent->left;
                }

                sibling->color = node->parent->color;
                node->parent->color = BLACK;
                sibling->left->color = BLACK;
                rotateRight(root, node->parent);
                node = root;
            }
        }
    }

    node->color = BLACK;
}

Node* RedBlackTree::BSTInsert(Node* root, Node *pt) {
    if (root == nullptr)
        return pt;

    if (pt->data < root->data) {
        root->left = BSTInsert(root->left, pt);
        root->left->parent = root;
    } else if (pt->data > root->data) {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }

    return root;
}

void RedBlackTree::insertValue(int data) {
    Node *pt = new Node(data);
    root = BSTInsert(root, pt);
    fixInsertRBTree(root, pt);
}

void RedBlackTree::deleteNodeHelper(Node *node, int key) {
    Node *z = nullptr;
    Node *x, *y;

    while (node != nullptr) {
        if (node->data == key) {
            z = node;
        }

        if (node->data <= key) {
            node = node->right;
        } else {
            node = node->left;
        }
    }

    if (z == nullptr) {
        cout << "Couldn't find key in the tree" << endl;
        return;
    }

    y = z;
    Color y_original_color = y->color;
    if (z->left == nullptr) {
        x = z->right;
        if (x != nullptr) {
            x->parent = z->parent;
        }
        if (z->parent == nullptr) {
            root = x;
        } else if (z == z->parent->left) {
            z->parent->left = x;
        } else {
            z->parent->right = x;
        }
        if (z->parent != nullptr) {
            fixDeleteRBTree(root, x);
        }
    } else if (z->right == nullptr) {
        x = z->left;
        if (x != nullptr) {
            x->parent = z->parent;
        }
        if (z->parent == nullptr) {
            root = x;
        } else if (z == z->parent->left) {
            z->parent->left = x;
        } else {
            z->parent->right = x;
        }
        if (z->parent != nullptr) {
            fixDeleteRBTree(root, x);
        }
    } else {
        y = z->right;
        while (y->left != nullptr) {
            y = y->left;
        }
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z) {
            if (x != nullptr) {
                x->parent = y;
            }
        } else {
            if (x != nullptr) {
                x->parent = y->parent;
            }
            y->parent->left = x;
            y->right = z->right;
            z->right->parent = y;
        }

        if (z->parent == nullptr) {
            root = y;
        } else if (z == z->parent->left) {
            z->parent->left = y;
        } else {
            z->parent->right = y;
        }
        y->parent = z->parent;
        y->color = z->color;
        y->left = z->left;
        z->left->parent = y;

        if (y_original_color == BLACK) {
            fixDeleteRBTree(root, x);
        }
    }
    delete z;
}

void RedBlackTree::deleteValue(int data) {
    deleteNodeHelper(root, data);
}

void RedBlackTree::inorderHelper(Node *node) {
    if (node == nullptr)
        return;

    inorderHelper(node->left);
    cout << node->data << " ";
    inorderHelper(node->right);
}

void RedBlackTree::inorder() {
    inorderHelper(root);
}

Node* RedBlackTree::getRoot() {
    return root;
}

Node* RedBlackTree::find(Node* root, int key) {
    Node* current = root;
    while (current != nullptr) {
        if (key == current->data) {
            return current;
        } else if (key < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return nullptr;
}
