#include "binary_search_tree.h"

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
    reverseTraverseDelete(root);
    root = nullptr;
}

void BinarySearchTree::add(Node *&node, int key, QString value)
{
    if(node == nullptr)
    {
        node = new Node(key, value);
    }
    else if(key < node->key)
    {
        if(node->left == nullptr) {
            node->left = new Node(key, value);
            node->left->parent = std::move(node);
        } else {
            add(node->left, key, value);
        }
    } else {
        if(node->right == nullptr) {
            node->right = new Node(key, value);
            node->right->parent = std::move(node);
        } else {
            add(node->right, key, value);
        }
    }
}


void BinarySearchTree::add(int key, QString value)
{
    add(root, key, value);
}


void BinarySearchTree::remove(Node *&node, int key)
{
    if(node == nullptr) return;
    else if(key < node->key) remove(node->left, key);
    else if(key > node->key) remove(node->right, key);
    else
    {
        if((node->left == nullptr) || (node->right == nullptr))
        {
            Node* tmp;

            if(node->left == nullptr)
            {
                tmp = std::move(node->right);
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }
            else
            {
                tmp = node->left;
                if(tmp) tmp->parent = node->parent;

                delete node;
                node = std::move(tmp);
            }

            tmp = nullptr;
        }
        else
        {
            Node* maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            remove(node->left, maxInLeft->key);
        }
    }
}


void BinarySearchTree::remove(int key)
{
    return remove(root, key);
}


void BinarySearchTree::remove(Node* &node, int key, QString value)
{
    if (node == nullptr)
        return;
    else if (key < node->key)
        remove(node->left, key, value);
    else if (key > node->key)
        remove(node->right, key, value);
    else if (key == node->key && value != node->value)
        remove(node->right, key, value);
    else
    {
        if((node->left == nullptr) || (node->right == nullptr))
        {
            Node* tmp;

            if(node->left == nullptr)
            {
                tmp = std::move(node->right);
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }
            else
            {
                tmp = node->left;
                if(tmp) tmp->parent = std::move(node->parent);

                delete node;
                node = std::move(tmp);
            }

            tmp = nullptr;
        }
        else
        {
            Node* maxInLeft = getMax(node->left);
            node->key = maxInLeft->key;
            node->value = maxInLeft->value;
            remove(node->left, maxInLeft->key, maxInLeft->value);
        }
    }
}


Node *BinarySearchTree::find(Node *node, int key)
{
    if (node == nullptr || node->key == key)
        return node;
    return (key < node->key) ? find(node->left, key) : find(node->right, key);
}


Node *BinarySearchTree::find(int key)
{
    return find(root, key);
}


void BinarySearchTree::insertSubtree(BinarySearchTree *subTree)
{
    straightTraverseCopy(subTree->root);
}

void BinarySearchTree::removeSubtree(Node*& subtreeRoot)
{
    if (subtreeRoot == nullptr) {
        return;
    }
    reverseTraverse(subtreeRoot);
    subtreeRoot = nullptr;
}

void BinarySearchTree::removeSubtree(BinarySearchTree*& subTree)
{
    if (subTree == nullptr || subTree->root == nullptr) {
        return;
    }

    reverseTraverseDelete(subTree->root);
}

void BinarySearchTree::insertBranch(Node *&node, Node *branchNode, bool isLeftBranch)
{
    if(branchNode == nullptr) return;
    add(node, branchNode->key, branchNode->value);

    if(isLeftBranch) insertBranch(node, branchNode->left, isLeftBranch);
    else insertBranch(node, branchNode->right, isLeftBranch);
}


void BinarySearchTree::insertBranch(Node *branchNode, bool isLeftBranch)
{
    insertBranch(root, branchNode, isLeftBranch);
}

void BinarySearchTree::insertBranch(BinarySearchTree *branch, bool isLeftBranch)
{
    insertBranch(branch->root, isLeftBranch);
}

void BinarySearchTree::removeBranch(Node *&node, Node *branchNode, bool isLeftBranch)
{
    if(branchNode == nullptr) return;

    remove(node, branchNode->key, branchNode->value);

    if(isLeftBranch) removeBranch(node, branchNode->left, isLeftBranch);
    else removeBranch(node, branchNode->right, isLeftBranch);
}

void BinarySearchTree::removeBranch(Node *branchNode, bool isLeftBranch)
{
    removeBranch(root, branchNode, isLeftBranch);
}

void BinarySearchTree::removeBranch(BinarySearchTree *branch, bool isLeftBranch)
{
    removeBranch(branch->root, isLeftBranch);
}

Node *BinarySearchTree::getMax(Node *&node)
{
    if(node == nullptr) return nullptr;
    if(node->right == nullptr) return node;
    else return getMax(node->right);
}

Node *BinarySearchTree::getMin(Node *&node)
{
    if(node == nullptr) return nullptr;
    if(node->left == nullptr) return node;
    else return getMin(node->left);
}

void BinarySearchTree::symmetricalTraverse()
{
    symmetricalTraverse(root);
}

void BinarySearchTree::reverseTraverse()
{
    reverseTraverse(root);
}

void BinarySearchTree::symmetricalTraverse(Node *&node)
{
    if(node == nullptr) return;
    symmetricalTraverse(node->left);
    qDebug() << node->key << " - " << node->value.toStdString() << '\n';
    symmetricalTraverse(node->right);
}

void BinarySearchTree::reverseTraverse(Node*& node)
{
    if (node == nullptr) {
        return;
    }

    reverseTraverse(node->left);
    reverseTraverse(node->right);

    delete node;
    node = nullptr;
}

void BinarySearchTree::straightTraverseCopy(Node* newNode)
{
    if(newNode == nullptr) return;
    add(newNode->key, newNode->value);
    straightTraverseCopy(newNode->left);
    straightTraverseCopy(newNode->right);
}

void BinarySearchTree::reverseTraverseDelete(Node *node)
{
    if(node == nullptr) return;
    reverseTraverseDelete(node->left);
    reverseTraverseDelete(node->right);
    remove(root, node->key, node->value);
}

Node *BinarySearchTree::lowestCommonAncestor(Node *u, Node *v)
{
    Node *a, *b;
    a = u;
    b = v;

    int h1 = depth(a);
    int h2 = depth(b);

    while (h1 != h2) {
        if (h1 > h2) {
            a = std::move(a->parent);
            h1--;
        } else {
            b = std::move(b->parent);
            h2--;
        }
    }

    while (a != b) {
        a = std::move(a->parent);
        b = std::move(b->parent);
    }

    return a;
}

int BinarySearchTree::lowestCommonAncestor(int u, int v)
{
    if (find(u) && find(v))
        return (lowestCommonAncestor(find(u), find(v)))->key;
    else return -1;
}

int BinarySearchTree::depth(Node *&node)
{
    if (node == nullptr)
        return -1;
    return 1 + depth(node->parent);
}

void BinarySearchTree::fillTreeWidget(QTreeWidgetItem *&parent, Node *node)
{
    if (node == nullptr) return;

    QTreeWidgetItem *item = new QTreeWidgetItem(parent);
    item->setText(0, QString::number(node->key) + '(' + node->value + ')');

    fillTreeWidget(item, node->left);
    fillTreeWidget(item, node->right);
}