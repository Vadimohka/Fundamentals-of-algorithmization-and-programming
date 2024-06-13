#include "BST.h"

template <typename T>
class myBST : public BinarySearchTree<T>{
    public:
        int countRightBranch(BinarySearchTree<T>::Node* node) {
            if (node == nullptr) {
                return 0;
            }

            if (node->right == nullptr) {
                return 0;
            }

            return 1 + countRightBranch(node->right);
        }

};
