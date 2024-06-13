#ifndef BST_H
#define BST_H
#include <QDebug>
#include <QVector>

template<typename T>
class BST
{
public:
    struct Node
    {
        T value;
        Node* left;
        Node* right;
        int height;

        Node(const T& value): value(value), left(nullptr), right(nullptr), height(0) {}
    };

private:
    Node* root;


    int getHeight(Node* node)
    {
        if (node == nullptr)
        {
            return -1;
        }

        return node->height;
    }


    int getBalance(Node* node)
    {
        return getHeight(node->right) - getHeight(node->left);
    }


    void fixHeight(Node* node)
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        node->height = std::max(leftHeight, rightHeight) + 1;
    }


    Node* leftRotation(Node* node) // возвращаем то, что должно остатьня на месте node
    {
        Node* temp = node->right;
        node->right = temp->left;
        temp->left = node;
        fixHeight(node);
        fixHeight(temp);

        return temp;
    }


    Node* rightRotation(Node* node) // возвращаем то, что должно остатьня на месте node
    {
        Node* temp = node->left;
        node->left = temp->right;
        temp->right = node;
        fixHeight(node);
        fixHeight(temp);

        return temp;
    }


    Node* balance(Node* node) // возвращаем то, что должно остатьня на месте node
    {
        fixHeight(node);

        if (getBalance(node) == 2)
        {

            if (getBalance(node->right) < 0)
            {
                node->right = rightRotation(node->right);
            }

            return leftRotation(node);
        }

        if (getBalance(node) == -2)
        {

            if (getBalance(node->left) > 0)
            {
                node->left = leftRotation(node->left);
            }

            return rightRotation(node);
        }

        return node;
    }


    Node *insert(Node* node, const T& value)
    {
        if (node == nullptr)
        {
            return new Node(value);
        }

        if (value < node->value)
        {
            node->left = insert(node->left, value);
            return balance(node);
        }
        else if (value > node->value)
        {
            qDebug() << "here";
            node->right = insert(node->right, value);
            return balance(node);
        }
        else
        {
            return balance(node);
        }
    }


    Node *del(Node* node, const T& value) // возвращаем мы то, что должно остаться на месте node, который мы и проверяем на предмет удаления
    {
        if (root->value == value && root->left == nullptr && root->right == nullptr)
        {
            root = nullptr;
            return nullptr;
        }

        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->value)
        {
            node->left = del(node->left, value);
            return balance(node);
        }
        else if (value > node->value)
        {
            node->right = del(node->right, value);
            return balance(node);
        }
        else // node - удаляемая вершина
        {
            if (node->left == nullptr || node->right == nullptr) // не больше 1 потомка
            {
                Node* temp = (node->left == nullptr ? node->right : node->left);

                if (temp == nullptr) // нет потомка
                {
                    delete node;
                    return nullptr;
                }
                else // есть потомок
                {
                    delete node;
                    return balance(temp);
                }
            }
            else // ровно 2 потомка
            {
                T minValueInRightSubtree = findMin(node->right)->value;
                node = del(node, minValueInRightSubtree);
                node->value = minValueInRightSubtree;
                return balance(node);
            }
        }
    }


    Node *findMin(Node* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (node->left == nullptr)
        {
            return node;
        }
        else
        {
            return findMin(node->left);
        }
    }


    Node* find(Node* node, const T& value)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        if (value < node->value)
        {
            return find(node->left, value);
        }
        else if (value > node->value)
        {
            return find(node->right, value);
        }
        else
        {
            return node;
        }
    }


    void traverse(Node* node, QVector<Node*>& vec)
    {
        if (node == nullptr)
        {
            return;
        }

        vec.push_back(node);
        traverse(node->left, vec);
        traverse(node->right, vec);
    }


    QVector<Node*> traverse(const T& value)
    {
        Node* node = find(value);
        QVector<Node*> ans;
        traverse(node, ans);
        return ans;
    }


    Node* findTheClosestCommonParent(Node* node, const T& value1, const T& value2)
    {
        if (value1 < node->value && value2 < node->value)
        {
            return findTheClosestCommonParent(node->left, value1, value2);
        }
        else if (value1 > node->value && value2 > node->value)
        {
            return findTheClosestCommonParent(node->right, value1, value2);
        }
        else
        {
            return node;
        }
    }

public:
    BST(): root(nullptr) {}


    Node* getRoot()
    {
        return root;
    }


    void add(const T& value)
    {
        root = insert(root, value);
    }


    void remove(const T& value)
    {
        root = del(root, value);
    }


    Node* find(const T& value)
    {
        return find(root, value);
    }


    QVector<Node*> traverse()
    {
        QVector<Node*> ans;
        traverse(root, ans);
        return ans;
    }


    void insertSubtree(BST<T>* subBST)
    {
        QVector<Node*> vec = subBST->traverse();

        for (int i = 0; i < vec.size(); ++i)
        {
            root = insert(root, vec[i]->value);
        }
    }


    void deleteSubtree(const T& value)
    {
        QVector<Node*> vec = traverse(value);

        for (int i = 0; i < vec.size(); ++i) // сортировка пузырьком
        {
            for (int j = i+1; j < vec.size(); ++j)
            {
                if (vec[j]->value < vec[i]->value)
                {
                    std::swap(vec[i], vec[j]);
                }
            }
        }

        for (int i = 0; i < vec.size(); ++i)
        {
            remove(vec[i]->value);
        }
    }


    Node* findTheClosestCommonParent(const T& value1, const T& value2)
    {
        if (find(value1) == nullptr || find(value2) == nullptr)
        {
            return nullptr;
        }

        return findTheClosestCommonParent(root, value1, value2);
    }

};

#endif // BST_H
