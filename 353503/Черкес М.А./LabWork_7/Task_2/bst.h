#ifndef BST_H
#define BST_H

#include <QString>
#include <QTextEdit>
#include <algorithm>
#include <iostream>
#include <vector>

struct Data {
  QString string;
  int key;
};

struct Node {
  Data data;
  Node* left;
  Node* right;
  int height;
};

class BST {
 public:
  Node* root = nullptr;
  Node* add(Node* root, Data x);
  virtual Node* remove(Node* root, int key);
  Node* findLeft(Node* node);
  Node* search(Node* root, int key);
  void printInorder(Node* root, QTextEdit& textEdit);
  void printPreorder(Node* root, QTextEdit& textEdit);
  void printPostorder(Node* root, QTextEdit& textEdit);
  void clear(Node* root);

  Node* balance(Node* node);

  int getBalance(Node* node);

  int getHeight(Node* node);

  Node* rotateLeft(Node* node);

  Node* rotateRight(Node* node);
};
#endif  // BST_H
