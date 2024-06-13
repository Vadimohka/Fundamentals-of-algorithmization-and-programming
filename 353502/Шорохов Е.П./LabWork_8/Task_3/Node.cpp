//
// Created by shosh on 5/27/24.
//

#include "Node.h"

//int Node::getHeight(Node *node) {
//    return node ? node->height : 0;
//}


//void Node::fixHeight(Node *node) {
//    int left_height = getHeight(node->left);
//    int right_height = getHeight(node->right);
//    node->height = ((left_height > right_height ? left_height : right_height) + 1);
//}

Node *Node::rotateLeft(Node *node) {
    Node *new_root = node->right;
    Node *temp_parent = node->parent;
    node->parent = new_root;
    node->right = new_root->left;
    node->right->parent = node;
    new_root->parent = temp_parent;
    new_root->left = node;
    return new_root;
}

Node *Node::rotateRight(Node *node) {
    Node *new_root = node->left;
    node->left = new_root->right;
    new_root->right = node;
    node->parent = new_root;
    return new_root;
}

Node *Node::bigRotateLeft(Node *node) {
    rotateRight(node->right);
    rotateLeft(node);
    return nullptr;
}

Node *Node::bigRotateRight(Node *node) {
    rotateLeft(node->left);
    rotateRight(node);
    return node->right->left;
}

Node *Node::search(Node* root, int k) {
    if (root == nullptr || k == root->key) {
        return root;
    }
    if (k < root->key) {
        return search(root->left, k);
    } else {
        return search(root->right, k);
    }
}

Node* Node::insert(Node *root, int k) {
    Node *inserted = new Node(k, RED);
    if (root == nullptr) {
        root = inserted;
        inserted->parent = nullptr;
        return root;
    } else {
        Node *start_of_search = root;
        Node *searched = nullptr;
        while (start_of_search != nullptr) {
            searched = start_of_search;
            if (start_of_search->key < inserted->key) {
                start_of_search = start_of_search->right;
            } else if (start_of_search->key > inserted->key) {
                start_of_search = start_of_search->left;
            } else {
                return root;
            }
            inserted->parent = searched;
        }
        if (searched != nullptr) {
            if (searched->key < inserted->key) {
                searched->right = inserted;
            } else {
                searched->left = inserted;
            }
        }
       return fixInsertion(inserted);
    }
}

Node* Node::fixInsertion(Node *node) {

    Node *root = nullptr;
    Node* grandFather = nullptr;

    if (node->parent == nullptr) {
        node->color = BLACK;
        return node;
    }

    while (node->parent != nullptr && node->parent->color == RED) {
        grandFather = node->parent->parent;
        if (grandFather == nullptr) {
            return node;
        }
        if (grandFather->left == node->parent) {
            Node *uncle = grandFather->right;
            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandFather->color = RED;
                node = grandFather;
            } else {
                if (node->parent->right == node) {
                    node = node->parent;
                    node = rotateLeft(node);
                }
                node->parent->color = BLACK;
                grandFather->color = RED;
                node = rotateRight(grandFather);
            }
        } else {
            Node *uncle = grandFather->left;
            if (uncle != nullptr && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                grandFather->color = RED;
                node = grandFather;
            } else {
                if (node->parent->left == node) {
                    node = node->parent;
                    rotateRight(node);
                }
                node->parent->color = BLACK;
                grandFather->color = RED;
                rotateLeft(grandFather);
            }
        }
        Node *root_searcher = node;
        while (root_searcher->parent != nullptr) {
            root_searcher = root_searcher->parent;
        }
        root = root_searcher;
        root->color = BLACK;
    }
        Node *root_searcher = node;
        while (root_searcher->parent != nullptr) {
            root_searcher = root_searcher->parent;
        }
        root = root_searcher;
        root->color = BLACK;
    return root;
}


Node *Node::findMinimum(Node *root) {
    return root->left ? findMinimum(root->left) : root;
}

Node *Node::findMaximum(Node *root) {
    return root->right ? findMaximum(root->right) : root;
}

void Node::inorderTraverse(Node *root) {
    if (root != nullptr) {
        inorderTraverse(root->left);
        qDebug() << root->key;
        inorderTraverse(root->right);
    }
}

void Node::preorderTraverse(Node *root) {
    if (root != nullptr) {
        qDebug() << root->key;
        if (root->left != nullptr) {
            preorderTraverse(root->left);
        }
        if (root->right != nullptr) {
            preorderTraverse(root->right);
        }
    }
}

void Node::postorderTraverse(Node *root) {
    if (root != nullptr) {
        if (root->left != nullptr) {
            preorderTraverse(root->left);
        }
        if (root->right != nullptr) {
            preorderTraverse(root->right);
        }
        qDebug() << root->key;
    }
}

Node *Node::pop(Node *root, int k) {

    Node *deleted_node = root;
    if (root == nullptr) {
        return root;
    }

    while (deleted_node->key != k) {
        if (deleted_node->key < k) {
            deleted_node = deleted_node->right;
        } else if (deleted_node->key > k ){
            deleted_node = deleted_node->left;
        }
    }
    Node *next_value_node = nullptr;
    if (deleted_node->left == nullptr && deleted_node->right == nullptr) {
        if (deleted_node->parent == nullptr) {
            root = nullptr;
        } else {
            (deleted_node->parent->left == deleted_node ? deleted_node->parent->left : deleted_node->parent->right) = nullptr;
            Node* root_searcher = deleted_node;
            while (root_searcher->parent != nullptr) {
                root_searcher = root_searcher->parent;
            }
            root = root_searcher;
            return root;
        }
        return root;
    } else if ((deleted_node->left != nullptr || deleted_node->left != nullptr) &&
    (deleted_node->left == nullptr || deleted_node->right == nullptr)) {
        if (deleted_node->parent != nullptr) {
            if (deleted_node->left != nullptr) {
                deleted_node->parent = deleted_node->left;
            }
            if (deleted_node->right != nullptr) {
                deleted_node->parent = deleted_node->right;
            }
        }
    } else if (root->left != nullptr && root->right != nullptr) {
        next_value_node = findMinimum(root->right);
        if (next_value_node->right != nullptr) {
            next_value_node->right->parent = next_value_node->parent;
        }
        if (next_value_node != deleted_node) {
            deleted_node->color = next_value_node->color;
            deleted_node->key = next_value_node->key;
        }
        if (next_value_node->color == BLACK) {
            return fixDeleting(root->left);
        }
        Node* root_searcher = deleted_node;
        while (root_searcher->parent != nullptr) {
            root_searcher = root_searcher->parent;
        }
        root = root_searcher;
        return root;
    }
    return root;
}

Node *Node::fixDeleting(Node *node) {
    while (node->parent != nullptr && node->color != BLACK) {
        if (node->parent->left == node) {
            Node *brother = node->parent->right;
            if (brother != nullptr) {
                if (brother->color == RED) {
                    brother->color = BLACK;
                    brother->parent->color = RED;
                    rotateLeft(brother->parent);
                }
                if (brother->left != nullptr && brother->left->color == BLACK &&
                brother->right != nullptr && brother->right->color == BLACK) {
                  brother->color = RED;
                } else if (brother->right != nullptr && brother->right->color == BLACK) {
                    if (brother->left != nullptr) {
                        brother->left->color = BLACK;
                    }
                    brother->color = RED;
                    rotateRight(brother);
                    brother->color = brother->parent->color;
                } else if (brother->right != nullptr && brother->right->color == RED) {
                    brother->color = brother->parent->color;
                    brother->parent->color = BLACK;
                    brother->right->color = BLACK;
                    rotateLeft(brother->parent);
                    break;
                }
            }
        }
        if (node->parent->right == node) {
            Node *brother = node->parent->right;
            if (brother != nullptr) {
                if (brother->color == RED) {
                    brother->color = BLACK;
                    brother->parent->color = RED;
                    rotateRight(brother->parent);
                }
                if (brother->left != nullptr && brother->left->color == BLACK &&
                    brother->right != nullptr && brother->right->color == BLACK) {
                    brother->color = RED;
                } else if (brother->left != nullptr && brother->left->color == BLACK) {
                    if (brother->right != nullptr) {
                        brother->right->color = BLACK;
                    }
                    brother->color = RED;
                    rotateLeft(brother);
                    brother->color = brother->parent->color;
                } else if (brother->left != nullptr && brother->left->color == RED) {
                    brother->color = brother->parent->color;
                    brother->parent->color = BLACK;
                    brother->left->color = BLACK;
                    rotateRight(brother->parent);
                    break;
                }
            }
        }
    }
    node->color = BLACK;
    Node* root_searcher = node;
    while (root_searcher->parent != nullptr) {
        root_searcher = root_searcher->parent;
    }
    Node* root = root_searcher;
    root->color = BLACK;
    return root;
}


