#include "bst.h"
#include <iostream>

Node::Node(int nKey, const std::string &nValue)
    : key(nKey), value(nValue), left(nullptr), right(nullptr) {}

std::shared_ptr<Node> Node::newNode(int nKey, const std::string &nValue)
{
    return std::make_shared<Node>(nKey, nValue);
}

BST::BST() {}

BST::~BST() {}

// O(logn)
std::shared_ptr<Node> BST::insert(std::shared_ptr<Node> node, int key, const std::string& value)
{
    if (!node) {
        return node->newNode(key, value);
    }

    if (key < node->key) {
        node->left = insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = insert(node->right, key, value);
    } else {
        // Ключи должны быть уникальными, поэтому возвращаем существующий узел
        return node;
    }

    return node;
}

std::shared_ptr<Node> BST::insertAtPosition(std::shared_ptr<Node> root, int key, const std::string &value, int position)
{
    if (!root) {
        return std::make_shared<Node>(key, value);
    }

    if (position == 0) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(key, value);
        newNode->left = root;
        return newNode;
    }

    if (position == 1) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>(key, value);
        newNode->right = root;
        return newNode;
    }

    if (key < root->key) {
        root->left = insertAtPosition(root->left, key, value, position - 1);
    } else {
        root->right = insertAtPosition(root->right, key, value, position - 1);
    }

    return root;
}

std::shared_ptr<Node> BST::remove(std::shared_ptr<Node> node, int key)
{
    if (!node) // удаляемый элемент является листом -> заменяем на null
        return nullptr;
    else if (key < node->key)
        node->left = remove(node->left, key);
    else if (key > node->key)
        node->right = remove(node->right, key);
    else {
        if (!node->left || !node->right) // если один ребенок -> заменяем на ребенка
            node = (node->left==nullptr) ? node->left : node->right;
        else { // два ребенка (узел должен быть больше чем вся левая подветка и больше чем вся правая отн. удаляемого)
            std::shared_ptr<Node> maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            node->right = remove(node->right, maxInLeft->key);
            /*std::shared_ptr<Node> minInRight = getMin(node->right);
            node->key = minInRight->key;
            node->value = minInRight->value;
            node->right = remove(node->right, minInRight->key);*/
        }
    }
    return node;
}

// O(logn)
std::shared_ptr<Node> BST::find(std::shared_ptr<Node> node, int key)
{
    if (!node || node->key == key)
        return node;

    return (key < node->key) ? find(node->left, key) : find(node->right, key);
}

std::shared_ptr<Node> BST::getMin(std::shared_ptr<Node> node)
{
    if (!node || !node->left) {
        return node;
    }
    return getMin(node->left);
}

/*                                  7
                                  /   \
                                 5     8 <- самый максимальный элемент
                               /   \
 самый минимальный элемент -> 4     6
*/
std::shared_ptr<Node> BST::getMax(std::shared_ptr<Node> node)
{
    if (!node || !node->right) {
        return node;
    }
    return getMax(node->right);
}

void BST::inorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    inorderTraversal(node->left);
    std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
    inorderTraversal(node->right);
}

void BST::preorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}

void BST::postorderTraversal(std::shared_ptr<Node> node)
{
    if (!node) {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
}

std::shared_ptr<Node> BST::insertSubtree(std::shared_ptr<Node> root, std::shared_ptr<Node> subtree, int position)
{
    if (position == 0) {
        return subtree;
    }

    if (position == 1) {
        std::shared_ptr<Node> newRoot = std::make_shared<Node>(subtree->key, subtree->value);
        newRoot->right = root;
        newRoot->left = subtree->left;
        return newRoot;
    }

    if (position == 2) {
        std::shared_ptr<Node> newRoot = std::make_shared<Node>(subtree->key, subtree->value);
        newRoot->left = root;
        newRoot->right = subtree->right;
        return newRoot;
    }

    if (subtree->key < root->key) {
        root->left = insertSubtree(root->left, subtree, position - 1);
    } else {
        root->right = insertSubtree(root->right, subtree, position - 1);
    }

    return root;
}

std::shared_ptr<Node> BST::insertBranch(std::shared_ptr<Node> root, std::shared_ptr<Node> branch, int position)
{
    if (position == 0) {
        return branch;
    }

    if (position == 1) {
        std::shared_ptr<Node> newRoot = std::make_shared<Node>(branch->key, branch->value);
        newRoot->right = root;
        return newRoot;
    }

    if (position == 2) {
        std::shared_ptr<Node> newRoot = std::make_shared<Node>(branch->key, branch->value);
        newRoot->left = root;
        return newRoot;
    }

    if (branch->key < root->key) {
        root->left = insertBranch(root->left, branch, position - 1);
    } else {
        root->right = insertBranch(root->right, branch, position - 1);
    }

    return root;
}

std::shared_ptr<Node> BST::removeSubtree(std::shared_ptr<Node> root, int position)
{
    if (position == 0) {
        return nullptr;
    }

    if (position == 1) {
        return root->right;
    }

    if (position == 2) {
        return root->left;
    }

    if (position > 2) {
        if (root->key < root->left->key) {
            root->left = removeSubtree(root->left, position - 1);
        } else {
            root->right = removeSubtree(root->right, position - 1);
        }
    }

    return root;
}

std::shared_ptr<Node> BST::removeBranch(std::shared_ptr<Node> root, int position)
{
    if (position == 0) {
        return nullptr;
    }

    if (position == 1) {
        return root->right;
    }

    if (position == 2) {
        return root->left;
    }

    if (position > 2) {
        if (root->key < root->left->key) {
            root->left = removeBranch(root->left, position - 1);
        } else {
            root->right = removeBranch(root->right, position - 1);
        }
    }

    return root;
}

// наименьшего общего предка (Least Common Ancestor, LCA)
// std::shared_ptr<Node> BST::lca(std::shared_ptr<Node> root, int n1, int n2)
// {
//     if (root == nullptr) {
//         return nullptr;
//     }
//     // Если оба n1 и n2 меньше, чем корень, то LCA находится в левом поддереве
//     if (root->key > min(n1, n2)) {
//         return lca(root->left, n1, n2);
//     }
//     // Если оба n1 и n2 больше, чем корень, то LCA находится в правом поддереве
//     if (root->key < min(n1, n2)) {
//         return lca(root->right, n1, n2);
//     }
//     // Если значения n1 и n2 находятся по разные стороны от корня, то корень является LCA
//     return root;
// }


