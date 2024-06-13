#include "VisualAVLTree.h"

QStandardItem *createItemForNode(AVLTree<QString>::Node *root, const QString &position = "")
{
    if (root == nullptr) {
        return nullptr;
    }
    QString label = position.isEmpty()
                        ? QString::number(root->height) + ". root: " + QString::number(root->key)
                        : QString::number(root->height) + ". " + position + ": "
                              + QString::number(root->key);
    QStandardItem *item = new QStandardItem(label);
    QStandardItem *leftChild = createItemForNode(root->left, "left");
    QStandardItem *rightChild = createItemForNode(root->right, "right");

    if (leftChild != nullptr) {
        item->appendRow(leftChild);
    }
    if (rightChild != nullptr) {
        item->appendRow(rightChild);
    }
    return item;
}

void directInputVisual(AVLTree<QString>::Node *root, QListWidget &widget)
{
    if (root != nullptr) {
        widget.addItem(root->value);
        directInputVisual(root->left, widget);
        directInputVisual(root->right, widget);
    }
}

void reverseInputVisual(AVLTree<QString>::Node *root, QListWidget &widget)
{
    if (root != nullptr) {
        reverseInputVisual(root->left, widget);
        reverseInputVisual(root->right, widget);
        widget.addItem(root->value);
    }
}

void increaseKeyInputVisual(AVLTree<QString>::Node *root, QListWidget &widget)
{
    if (root != nullptr) {
        increaseKeyInputVisual(root->left, widget);
        widget.addItem(root->value);
        increaseKeyInputVisual(root->right, widget);
    }
}

void findVisual(AVLTree<QString>::Node *root, int64_t key, QListWidget &widget)
{
    if (root != nullptr) {
        if (root->key == key) {
            widget.addItem(root->value);
            return;
        }
        (key < root->key) ? findVisual(root->left, key, widget)
                          : findVisual(root->right, key, widget);
    }
}

void findMinVisual(AVLTree<QString>::Node *root, QListWidget &widget)
{
    if (root != nullptr) {
        if (root->left) {
            findMinVisual(root->left, widget);
        } else {
            widget.addItem(root->value + " - " + QString::number(root->key));
        }
    }
}

void findMaxVisual(AVLTree<QString>::Node *root, QListWidget &widget)
{
    if (root != nullptr) {
        if (root->right) {
            findMaxVisual(root->right, widget);
        } else {
            widget.addItem(root->value + " - " + QString::number(root->key));
        }
    }
}

void findAverageNodeVisual(AVLTree<QString> &tree, QListWidget &widget)
{
    if (tree.getRoot() != nullptr) {
        if (tree.findMin(tree.getRoot()) == nullptr || tree.findMax(tree.getRoot()) == nullptr) {
            return;
        }

        int64_t averageKey = (tree.findMin(tree.getRoot())->key + tree.findMax(tree.getRoot())->key)
                             / 2;

        AVLTree<QString>::Node *averageNode = tree.getRoot();
        int64_t averageDiff = (tree.getRoot()->key > averageKey)
                                  ? (tree.getRoot()->key - averageKey)
                                  : (averageKey - tree.getRoot()->key);

        AVLTree<QString>::Node *stepNode = tree.getRoot();
        while (stepNode != nullptr) {
            int64_t stepDiff = (stepNode->key > averageKey) ? (stepNode->key - averageKey)
                                                            : (averageKey - stepNode->key);
            if (stepDiff < averageDiff) {
                averageNode = stepNode;
                averageDiff = stepDiff;
            }

            stepNode = (averageKey < stepNode->key) ? stepNode->left : stepNode->right;
        }

        widget.addItem(averageNode->value + " - " + QString::number(averageNode->key));
    }
}
