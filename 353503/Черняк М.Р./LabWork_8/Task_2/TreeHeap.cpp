#include "Heap.h"
#include <memory>

class TreeHeap : public Heap {
private:
  struct TreeNode {
    int val;
    std::weak_ptr<TreeNode> parent;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
  };

  void heapifyUp(std::shared_ptr<TreeNode> node) {
    if (node->parent.lock() == nullptr)
      return;

    if (node->val > node->parent.lock()->val) {
      std::swap(node->val, node->parent.lock()->val);
      heapifyUp(node->parent.lock());
    }
  }

  void heapifyDown(std::shared_ptr<TreeNode> node) {
      std::shared_ptr<TreeNode> largestChild = node;
      long largestValue = node->val;

      if (node->left) {
          if (node->left->val > largestValue) {
              largestChild = node->left;
              largestValue = node->left->val;
          }
      }
      if (node->right) {
          if (node->right->val > largestValue) {
              largestChild = node->right;
              largestValue = node->right->val;
          }
      }

      if (largestChild != node) {
          std::swap(node->val, largestChild->val);
          heapifyDown(largestChild);
      }
  }

  void inspect(HeapInspector* root, std::shared_ptr<TreeNode> node) {
      if (!node) {
          return;
      }

      root->setVal(node->val);

      if (node->left) {
          auto leftChild = root->createChild();
          inspect(leftChild, node->left);
      }

      if (node->right) {
          auto rightChild = root->createChild();
          inspect(rightChild, node->right);
      }
  }

public:
  TreeHeap() {
    root = nullptr;
    level = 0;
    level_i = 0;
  }


  virtual ~TreeHeap() {}

  void push(long x) {
      if (!root) {
          root = std::make_shared<TreeNode>();
          root->val = x;
          root->parent.reset();
          root->left = nullptr;
          root->right = nullptr;
          level = 1;
          level_i = 0;
          return;
      }

      std::shared_ptr<TreeNode> currentNode = root;
      for (int i = level - 1; i >= 0; i--) {
          bool shouldGoRight = (level_i & (1 << i)) != 0;
          if (shouldGoRight) {
              if (!currentNode->right) {
                  currentNode->right = std::make_shared<TreeNode>();
                  currentNode->right->parent = currentNode;
              }
              currentNode = currentNode->right;
          } else {
              if (!currentNode->left) {
                  currentNode->left = std::make_shared<TreeNode>();
                  currentNode->left->parent = currentNode;
              }
              currentNode = currentNode->left;
          }
      }

      currentNode->val = x;
      level_i++;
      if (level_i == (1 << level)) {
          level++;
          level_i = 0;
      }

      heapifyUp(currentNode);
  }

  long pop() {
      // If the tree is empty, return 0
      if (!root) {
          return 0;
      }

      // Save the root value
      long result = root->val;

      // Update the level and level_i
      level_i--;
      if (level_i < 0) {
          level--;
          level_i = (1 << level) - 1;
      }

      // If the tree is now empty, reset the root
      if (level == 0) {
          root.reset();
          return result;
      }

      // Find the last node in the tree
      std::shared_ptr<TreeNode> lastNode = root;
      for (int i = level - 1; i >= 0; i--) {
          bool shouldGoRight = (level_i & (1 << i)) != 0;
          if (shouldGoRight) {
              lastNode = lastNode->right;
          } else {
              lastNode = lastNode->left;
          }
      }

      // Swap the root and last node values, and remove the last node
      std::swap(root->val, lastNode->val);
      std::shared_ptr<TreeNode> parent = lastNode->parent.lock();
      if (parent->left == lastNode) {
          parent->left.reset();
      } else {
          parent->right.reset();
      }

      // Heapify down the tree
      heapifyDown(root);

      return result;
  }

  virtual bool empty() { return root == nullptr; }

  void clear() { root = 0; }

  void inspect(HeapInspector *ins) {
    inspect(ins, root);
  }

private:
  std::shared_ptr<TreeNode> root;
  int level;
  int level_i;
};

extern "C" {
std::unique_ptr<Heap> createTreeHeap() { return std::make_unique<TreeHeap>(); };
}
