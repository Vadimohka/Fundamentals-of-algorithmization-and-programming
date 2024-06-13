#include "Heap.h"
#include <memory>

class TreeHeap : public Heap
{
private:
    struct TreeNode
    {
        int val;
        std::weak_ptr<TreeNode> parent;
        std::shared_ptr<TreeNode> left;
        std::shared_ptr<TreeNode> right;
    };

    void heapifyUp(std::shared_ptr<TreeNode> node)
    {
        if (node->parent.lock() == nullptr)
            return;

        if (node->val > node->parent.lock()->val) {
            std::swap(node->val, node->parent.lock()->val);
            heapifyUp(node->parent.lock());
        }
    }

    void heapifyDown(std::shared_ptr<TreeNode> cur)
    {
        std::shared_ptr<TreeNode> nextNode = cur;
        long best = cur->val;
        if (cur->left) {
            if (cur->left->val > best) {
                nextNode = cur->left;
                best = cur->left->val;
            }
        }

        if (cur->right) {
            if (cur->right->val > best) {
                nextNode = cur->right;
                best = cur->right->val;
            }
        }

        if (nextNode == cur)
            return;

        std::swap(nextNode->val, cur->val);
        heapifyDown(nextNode);
    }

    void inspect(HeapInspector *root, std::shared_ptr<TreeNode> cur)
    {
        if (cur == nullptr)
            return;
        root->setVal(cur->val);
        if (cur->left != nullptr) {
            inspect(root->createChild(), cur->left);
        }
        if (cur->right != nullptr) {
            inspect(root->createChild(), cur->right);
        }
    }

public:
    TreeHeap()
    {
        root = nullptr;
        level = 0;
        level_i = 0;
    }

    virtual ~TreeHeap() {}

    virtual void push(long x)
    {
        if (level == 0) {
            root = std::make_shared<TreeNode>();
            root->val = x;
            root->parent.reset();
            root->left = nullptr;
            root->right = nullptr;

            level++;
            level_i = 0;
            return;
        }

        std::shared_ptr<TreeNode> cur = root;
        for (int i = level - 1; i >= 0; i--) {
            bool should_right = (level_i & (1 << i)) != 0;
            if (should_right) {
                if (cur->right == nullptr) {
                    cur->right = std::make_shared<TreeNode>();
                    cur->right->parent = cur;
                }
                cur = cur->right;
            } else {
                if (cur->left == nullptr) {
                    cur->left = std::make_shared<TreeNode>();
                    cur->left->parent = cur;
                }
                cur = cur->left;
            }
        }

        cur->val = x;
        level_i++;

        if (level_i == (1 << level)) {
            level++;
            level_i = 0;
        }

        heapifyUp(cur);
    };

    virtual long pop()
    {
        long res = root->val;

        level_i--;
        if (level_i < 0) {
            level--;
            level_i = (1 << level) - 1;
        }

        if (level == 0) {
            root.reset();
            return res;
        }

        std::shared_ptr<TreeNode> cur = root;
        for (int i = level - 1; i >= 0; i--) {
            bool should_right = (level_i & (1 << i)) != 0;
            if (should_right) {
                cur = cur->right;
            } else {
                cur = cur->left;
            }
        }

        std::swap(cur->val, root->val);
        std::shared_ptr<TreeNode> par = cur->parent.lock();
        if (par->left == cur) {
            par->left.reset();
        }
        if (par->right == cur) {
            par->right.reset();
        }
        heapifyDown(root);

        return res;
    };

    virtual bool empty() { return root == nullptr; }

    void clear() { root = 0; }

    void inspect(HeapInspector *ins) { inspect(ins, root); }
    std::unique_ptr<Heap> createTreeHeap() { return std::make_unique<TreeHeap>(); }

private:
    std::shared_ptr<TreeNode> root;
    int level;
    int level_i;
};
