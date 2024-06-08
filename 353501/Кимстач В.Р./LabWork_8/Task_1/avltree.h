

#ifndef TASK2_TREE_H
#define TASK2_TREE_H


#include <string>
#include <vector>
#include <iostream>
#include <climits>

class Tree {

    std::vector<std::pair<int, int> > tree;
    std::vector<std::pair<int, int> > path;
    std::vector<int> keys;

    int size = 0;

    struct Node
    {
        int data;
        int key;
        Node* left = nullptr;
        Node* right = nullptr;
        Node(int key, int data){
            this->key = key;
            this->data = data;
        }
    };

    Node* root = nullptr;

    int GetHeight(Node* node)
    {
        if(node == nullptr)
            return 0;
        return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
    }

    int GetBalance(Node* node)
    {

        if(node == nullptr)
            return  0;
        int h1 = GetHeight(node->left);
        int h2 = GetHeight(node->right);
        return h1 - h2;
    }

    Node* LeftRotate(Node* node)
    {
        if(node == nullptr)
            return node;

        auto b = node->right;
        auto c = b->left;

        b->left = node;
        node->right = c;

        return b;
    }

    Node* RightRotate(Node* node)
    {
        if(node == nullptr)
            return node;

        auto b = node->left;
        auto c = b->right;

        b->right = node;
        node->left = c;

        return b;
    }

    Node* DoBalance(Node* p)
    {
        //int height = GetHeight(p);
        int balance = GetBalance(p);
        if(balance == 2)
        {
            // right turn
            if(GetBalance(p->left) >= 0)
            {
                p = RightRotate(p);
                return p;
            }
            else
            {
                p->left = LeftRotate(p->left);
                p = RightRotate(p);
                return p;
            }
        }
        else if (balance == -2)
        {
            // left turn
            if(GetBalance(p->right) <= 0)
            {
                // small left turn
                p = LeftRotate(p);
                return p;
            }
            else
            {
                p->right = RightRotate(p->right);
                p = LeftRotate(p);
                return p;
            }
        }
        return p;
    }

    Node* FindMin(Node* node)
    {
        if(node->left == nullptr)
        {
            return node;
        }
        return FindMin(node->left);
    }

    Node* remove_min(Node* node)
    {
        if(node->left == nullptr)
            return node->right;
        node->left = remove_min(node->left);
        return DoBalance(node);
    }

    Node* Delete(Node* p, int k)
    {
        if(p == nullptr)
            return p;
        if(p->key < k)
        {
            p->right = Delete(p->right, k);
        }
        else if(p->key > k)
        {
            p->left = Delete(p->left, k);
        }
        else
        {
            size --;
            // p->key == k
            Node* q = p->left;
            Node* r = p->right;
            bool f = 0;
            if(p == root)
                f = 1;
            delete p;
            if(r == nullptr)
            {
                p = q;
                if(f)
                    root = p;
                return p;
            }
            Node* f_min = FindMin(r);
            f_min->right = remove_min(r);
            f_min->left = q;
            p = DoBalance(f_min);
            if(f)
                root = p;
            return p;
        }
        bool f = 0;
        if(p == root)
            f = 1;
        p = DoBalance(p);
        if(f)
            root = p;
        std::cout << "root " << root << " " << root->data << std::endl;
        return p;
    }

    Node* Insert(Node* p, int k, const int& s)
    {
        std::cout << "start p " << p << '\n';
        Node* add = new Node(k, s);
        if(p == nullptr)
        {
            return add;
        }

        if(k < p->key)
        {
            // add to left
            p->left = Insert(p->left, k, s);
        }
        else if(k > p->key)
        {
            // add to right
            p->right = Insert(p->right, k, s);
        }
        else
        {
            // k == p
            size --;
            return p;
        }
        p = DoBalance(p);
        return p;
    }

    Node* Find(Node* node, int k)
    {
        if(node == nullptr)
            return node;
        if(node->key == k)
        {
            return node;
        }
        if(node->key < k)
        {
            return Find(node->right, k);
        }
        else
        {
            return Find(node->left, k);
        }
    }

    void getTree(Node* node)
    {
        if(node == nullptr)
            return;
        if(node->left != nullptr)
        {
            tree.push_back({node->key, node->left->key});
            getTree(node->left);
        }
        if(node->right != nullptr)
        {
            tree.push_back({node->key, node->right->key});
            getTree(node->right);
        }
    }

    void Prime(Node* node)
    {
        if(node == nullptr)
            return;
        path.push_back({node->key, node->data});
        Prime(node->left);
        Prime(node->right);
    }

    void Reverse(Node* node)
    {
        if(node == nullptr)
            return;
        Reverse(node->left);
        Reverse(node->right);
        path.push_back({node->key, node->data});
    }

    void IncreasePath(Node* node)
    {
        if(node == nullptr)
            return;
        IncreasePath(node->left);
        path.push_back({node->key, node->data});
        IncreasePath(node->right);
    }

    void DoDeleting(Node* node)
    {
        if(node == nullptr)
            return;
        keys.push_back(node->key);
        DoDeleting(node->left);
        DoDeleting(node->right);
    }

public:

    Tree() {};

    void Insert(int k, const int & s)
    {
        size ++;
        root = Insert(root, k, s);
    }

    int Find(int k)
    {
        auto t = Find(root, k);
        if(t == nullptr)
            return INT_MIN;
        else
            return t->data;
    }

    Node* GetNode(int k)
    {
        Node* ret = Find(root, k);
        return ret;
    }

    void Delete(int k)
    {
        Delete(root, k);
        if(size == 0)
            root = nullptr;
    }

    int GetValue(Node* node)
    {
        return node->data;
    }

    std::vector<std::pair<int, int> > getTree()
    {
        tree.clear();
        if(root == nullptr)
            return tree;
        tree.push_back({-1, root->key});

        getTree(root);
        return tree;
    }

    std::vector<std::pair<int, int> > GetInfo(int type)
    {
        path.clear();
        switch (type) {
        case 1:
        {
            Prime(root);
            break;
        }
        case 2:
        {
            Reverse(root);
            break;
        }
        default:
        {
            IncreasePath(root);
        }
        }
        return path;
    }

    void DeleteSubtree(int value)
    {
        std::cout << "delete start node " << root << " " << root->key << '\n';
        Node* node = Find(root, value);
        keys.clear();
        DoDeleting(node);
        for(auto x : keys)
            Delete(x);
        //      std::cout << "delete end root " << root << " " << root->key << '\n';
    }

    void DeleteLeftSon(int value)
    {
        Node* node = Find(root, value);
        if(node == nullptr)
            return;
        DeleteSubtree(node->left->data);
    }

    void DeleteRightSon(int value)
    {
        Node* node = Find(root, value);
        if(node == nullptr)
            return;
        DeleteSubtree(node->right->data);
    }

    void AddSubtree(Node* node)
    {
        keys.clear();
        DoDeleting(node);
        for(auto x : keys) {
            Insert(x, x);
        }
    }

    void AddLeftSon(Node* node)
    {
        if(node == nullptr)
            return;
        node = node->left;
        AddSubtree(node);
    }

    void AddRightSon(Node* node)
    {
        if(node == nullptr)
            return;
        node = node->right;
        AddSubtree(node);
    }

    int DoLCA(Node* node, int x, int y)
    {
        int value = node->key;
        if(value == x || value == y)
            return value;
        if(x < value && y < value)
        {
            return DoLCA(node->left, x, y);
        }
        if(x > value && y > value)
        {
            return DoLCA(node->right, x, y);
        }
        return node->key;
    }

    int lca(int x, int y)
    {
        if(Find(root, x) == nullptr || Find(root, y) == nullptr)
        {
            return -1;
        }
        return DoLCA(root, x, y);
    }
};


#endif //TASK2_TREE_H
