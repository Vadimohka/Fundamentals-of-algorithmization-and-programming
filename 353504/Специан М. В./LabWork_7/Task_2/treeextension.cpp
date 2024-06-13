#include "treeextension.h"

Node* TreeExtension::findMin(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    while (root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node* TreeExtension::findMax(Node* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

void TreeExtension::swapMinMax()
{
    if (root == nullptr)
        return;

    Node* minNode = findMin(root);
    Node* maxNode = findMax(root);

    if (minNode == nullptr || maxNode == nullptr)
    {
        return;
    }

    QString temp = minNode->value;
    minNode->value = maxNode->value;
    maxNode->value = temp;
}
