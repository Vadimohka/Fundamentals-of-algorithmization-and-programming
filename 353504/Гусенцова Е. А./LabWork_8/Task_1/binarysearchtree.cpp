#include "binarysearchtree.h"
#include <iostream>
#include <ostream>

// Рекурсивное добавление узла с сообщением
Node* BinarySearchTree::add(Node* node, int value, std::string& message) {
    if (node == nullptr) {
        message += "Added " + std::to_string(value);
        return new Node(value);
    }
    if (value < node->value) {
        message += "Left of " + std::to_string(node->value) + " -> ";
        node->left = add(node->left, value, message);
    } else {
        message += "Right of " + std::to_string(node->value) + " -> ";
        node->right = add(node->right, value, message);
    }
    return node;
}

void BinarySearchTree::add(int value) {
    std::string message = "";
    root = add(root, value, message);
    std::cout << message << std::endl;
}

// Рекурсивное удаление узла с сообщением
Node* BinarySearchTree::remove(Node* node, int value, std::string& message) {
    if (node == nullptr) return node;

    if (value < node->value) {
        node->left = remove(node->left, value, message);
    } else if (value > node->value) {
        node->right = remove(node->right, value, message);
    } else {
        message += "Removed " + std::to_string(value)+" ";
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = node->right;
        while (temp && temp->left != nullptr) {
            temp = temp->left;
        }
        node->value = temp->value;
        node->right = remove(node->right, temp->value, message);
    }
    return node;
}

void BinarySearchTree::remove(int value) {
    std::string message = "";
    root = remove(root, value, message);
    std::cout << message << std::endl;
}

// Поиск узла
Node* BinarySearchTree::find(Node* node, int value) {
    if (node == nullptr || node->value == value) {
        return node;
    }
    if (value < node->value) {
        return find(node->left, value);
    }
    return find(node->right, value);
}

Node* BinarySearchTree::find(int value) {
    return find(root, value);
}

// Обход узлов
void BinarySearchTree::traverse(Node* node, std::vector<int>& elements) {
    if (node == nullptr) return;
    traverse(node->left, elements);
    elements.push_back(node->value);
    traverse(node->right, elements);
}

std::vector<int> BinarySearchTree::traverse() {
    std::vector<int> elements;
    traverse(root, elements);
    return elements;
}

// Поиск наименьшего общего предка
Node* BinarySearchTree::findLCA(Node* node, int n1, int n2) {
    if (node == nullptr) return nullptr;
    if (node->value > n1 && node->value > n2)
        return findLCA(node->left, n1, n2);
    if (node->value < n1 && node->value < n2)
        return findLCA(node->right, n1, n2);
    return node;
}

Node* BinarySearchTree::findLCA(int n1, int n2) {
    return findLCA(root, n1, n2);
}

// Вставка поддерева
void BinarySearchTree::insertSubtree(Node* subtree) {
    if (subtree == nullptr) return;
    add(subtree->value);
    if (subtree->left) insertSubtree(subtree->left);
    if (subtree->right) insertSubtree(subtree->right);
}

std::string BinarySearchTree::getMessageForInsertSubtree(Node* subtree) {
    std::string message = "";
    if (subtree != nullptr) {
        root = add(root, subtree->value, message);
        if (subtree->left) insertSubtree(subtree->left);
        if (subtree->right) insertSubtree(subtree->right);
    }
    return message;
}

// Удаление поддерева
void BinarySearchTree::removeSubtree(Node* subtree) {
    if (subtree == nullptr) return;
    remove(subtree->value);
    if (subtree->left) removeSubtree(subtree->left);
    if (subtree->right) removeSubtree(subtree->right);
}

std::string BinarySearchTree::getMessageForRemoveSubtree(Node* subtree) {
    std::string message = "";
    if (subtree != nullptr) {
        root = remove(root, subtree->value, message);
        if (subtree->left) removeSubtree(subtree->left);
        if (subtree->right) removeSubtree(subtree->right);
    }
    return message;
}

// Вставка элемента в определенную позицию
void BinarySearchTree::insertAtPosition(int parentValue, int value, bool asLeftChild) {
    Node* parentNode = find(parentValue);
    if (parentNode != nullptr) {
        if (asLeftChild) {
            if (parentNode->left == nullptr) {
                parentNode->left = new Node(value);
            } else {
                std::cout << "Left child already exists for parent value " << parentValue << std::endl;
            }
        } else {
            if (parentNode->right == nullptr) {
                parentNode->right = new Node(value);
            } else {
                std::cout << "Right child already exists for parent value " << parentValue << std::endl;
            }
        }
    } else {
        std::cout << "Parent value " << parentValue << " not found." << std::endl;
    }
}

// Вставка ветви
void BinarySearchTree::insertBranch(Node* branch, int parentValue, bool asLeftChild) {
    Node* parentNode = find(parentValue);
    if (parentNode != nullptr) {
        if (asLeftChild) {
            if (parentNode->left == nullptr) {
                parentNode->left = branch;
            } else {
                std::cout << "Left child already exists for parent value " << parentValue << std::endl;
            }
        } else {
            if (parentNode->right == nullptr) {
                parentNode->right = branch;
            } else {
                std::cout << "Right child already exists for parent value " << parentValue << std::endl;
            }
        }
    } else {
        std::cout << "Parent value " << parentValue << " not found." << std::endl;
    }
}

// Удаление ветви
void BinarySearchTree::removeBranch(int branchValue) {
    Node* branch = find(branchValue);
    if (branch != nullptr) {
        removeSubtree(branch);
    } else {
        std::cout << "Branch with value " << branchValue << " not found." << std::endl;
    }
}

// Получение сообщения для добавления узла
std::string BinarySearchTree::getMessageForAdd(int value) {
    std::string message = "";
    root = add(root, value, message);
    return message;
}

// Получение сообщения для удаления узла
std::string BinarySearchTree::getMessageForRemove(int value) {
    std::string message = "";
    root = remove(root, value, message);
    return message;
}
