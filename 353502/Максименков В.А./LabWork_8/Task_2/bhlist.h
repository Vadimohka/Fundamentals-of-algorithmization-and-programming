#ifndef BHLIST_H
#define BHLIST_H
#include <stack>

template<typename T>
class BHList // ВНИМАНИЕ!!! Здесь ключ совпадает со значением
{
public:
    struct Node
    {
        int cnt;
        T value;
        Node* parent;
        Node* left;
        Node* right;

        Node(const T& value): cnt(cnt), value(value), parent(nullptr), left(nullptr), right(nullptr) {}
    };

private:
    Node* root;
    int number;


    void upInsertedElement(Node* node)
    {
        if (node->value == root->value)
        {
            return;
        }

        if (node->value > node->parent->value)
        {
            std::swap(node->value, node->parent->value);
            upInsertedElement(node->parent);
        }
    }


    void insert(Node* parent, const T& value, std::stack<int>& path)
    {
        if (path.size() == 1) // нужно вставлять сейчас
        {
            if (parent->left == nullptr) // мы вставляем в левого ребёнка
            {
                parent->left = new Node(value);
                parent->left->cnt = number;
                parent->left->parent = parent;
                upInsertedElement(parent->left);
            }
            else // мы вставляем в правого ребёнка
            {
                parent->right = new Node(value);
                parent->right->cnt = number;
                parent->right->parent = parent;
                upInsertedElement(parent->right);
            }
            ++number;

            return;
        }

        if (parent->left->cnt == path.top())
        {
            path.pop();
            insert(parent->left, value, path);
        }
        else if (parent->right->cnt == path.top())
        {
            path.pop();
            insert(parent->right, value, path);
        }
    }


    Node* getLastNode(Node* node, std::stack<int>& path)
    {
        if (path.size() == 0) // node - это нужная вершина
        {
            return node;
        }

        if (node->left->cnt == path.top())
        {
            path.pop();
            return getLastNode(node->left, path);
        }
        else if (node->right->cnt == path.top())
        {
            path.pop();
            return getLastNode(node->right, path);
        }
    }


    void heapify(Node* node)
    {
        if (node->left == nullptr) // у вершины нет потомков
        {
            return;
        }
        else if (node->right == nullptr) // у вершины есть только левый потомок
        {
            if (node->left->value > node->value)
            {
                std::swap(node->left->value, node->value);
                heapify(node->left);
            }
        }
        else // у вершины есть два потомка
        {
            T maxChildValue = std::max(node->left->value, node->right->value);
            if (node->left->value == maxChildValue)
            {
                std::swap(node->left->value, node->value);
                heapify(node->left);
            }
            else
            {
                std::swap(node->right->value, node->value);
                heapify(node->right);
            }
        }
    }

public:
    BHList(): root(new Node(0)), number(0)
    {
        root->cnt = 0;
    }

    Node* getRoot() const
    {
        return root;
    }

    int size() const
    {
        return number;
    }

    void insert(const T& value)
    {
        std::stack<int> path;
        int i = number;

        while(i > 0)
        {
            path.push(i);
            i = (i - 1) / 2;
        }

        if (path.size() == 0) // мы вставляем в корень
        {
            root->value = value;
            ++number;
        }
        else
        {
            insert(root, value, path);
        }
    }


    T removeMax()
    {
        if (number == 0)
        {
            throw 1;
        }

        T ans = root->value;
        std::stack<int> path;
        int i = number - 1;

        while (i > 0)
        {
            path.push(i);
            i = (i - 1) / 2;
        }

        if (path.size() == 0) // удаляем корень
        {
            --number;
            return ans;
        }

        Node* last = getLastNode(root, path);
        root->value = last->value;

        last = last->parent;
        if (last->right != nullptr) // удаляем правого ребёнка
        {
            delete last->right;
            last->right = nullptr;
        }
        else // удаляем левого ребёнка
        {
            delete last->left;
            last->left = nullptr;
        }

        --number;
        heapify(root);
        return ans;
    }
};

#endif // BHLIST_H
