#ifndef VISUALAVLTREE_H
#define VISUALAVLTREE_H

#include <QListWidget>
#include <QStandardItemModel>
#include "AVLTree.h"

QStandardItem *createItemForNode(AVLTree<QString>::Node *root, const QString &position);

void directInputVisual(AVLTree<QString>::Node *root, QListWidget &widget);
void reverseInputVisual(AVLTree<QString>::Node *root, QListWidget &widget);
void increaseKeyInputVisual(AVLTree<QString>::Node *root, QListWidget &widget);

void findVisual(AVLTree<QString>::Node *root, int64_t key, QListWidget &widget);
void findMinVisual(AVLTree<QString>::Node *root, QListWidget &widget);
void findMaxVisual(AVLTree<QString>::Node *root, QListWidget &widget);
void findAverageNodeVisual(AVLTree<QString> &tree, QListWidget &widget);

#endif // VISUALAVLTREE_H
