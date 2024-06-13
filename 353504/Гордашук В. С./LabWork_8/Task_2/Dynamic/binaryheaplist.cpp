#include "binaryheaplist.h"

BinaryHeapList::BinaryHeapList() {}

void BinaryHeapList::insert(int value) {
    auto newNode = std::make_shared<Node>(value);
    if (!root)
    {
        root = newNode;
    }
    else
    {
        std::queue<std::shared_ptr<Node>> q;
        q.push(root);

        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (!node->left)
            {
                node->left = newNode;
                newNode->parent = node;
                break;
            }
            else if (!node->right)
            {
                node->right = newNode;
                newNode->parent = node;
                break;
            }
            q.push(node->left);
            q.push(node->right);
        }
        siftUp(newNode);
    }
}

void BinaryHeapList::remove() {
    if (!root) throw QException();
    int rootValue = root->value;
    std::queue<std::shared_ptr<Node>> q;
    q.push(root);
    std::shared_ptr<Node> lastNode;
    while (!q.empty())
    {
        lastNode = q.front();
        q.pop();
        if (lastNode->left)
        {
            q.push(lastNode->left);
        }
        if (lastNode->right)
        {
            q.push(lastNode->right);
        }
    }
    if (lastNode == root)
    {
        root.reset();
    }
    else
    {
        root->value = lastNode->value;
        if (lastNode == lastNode->parent.lock()->left)
        {
            lastNode->parent.lock()->left.reset();
        }
        else
        {
            lastNode->parent.lock()->right.reset();
        }

        siftDown(root);
    }
}

void BinaryHeapList::siftUp(std::shared_ptr<Node> node)
{
    while (node->parent.lock() && node->parent.lock()->value < node->value)
    {
        std::swap(node->value, node->parent.lock()->value);
        node = node->parent.lock();
    }
}

void BinaryHeapList::siftDown(std::shared_ptr<Node> node)
{
    while (node->left || node->right)
    {
        std::shared_ptr<Node> largerChild;
        if (node->left && node->right)
        {
            largerChild = (node->left->value > node->right->value) ? node->left : node->right;
        }
        else if (node->left)
        {
            largerChild = node->left;
        }
        else
        {
            largerChild = node->right;
        }

        if (node->value < largerChild->value)
        {
            std::swap(node->value, largerChild->value);
            node = largerChild;
        }
        else
        {
            break;
        }
    }
}

QString BinaryHeapList::printHeap()
{
    QString s;
    if (!root) throw QException();

    std::queue<std::shared_ptr<Node>> q;
    q.push(root);

    while (!q.empty())
    {
        auto node = q.front();
        q.pop();

        s += QString::number(node->value);
        s += ' ';
        if (node->left)
        {
            q.push(node->left);
        }
        if (node->right)
        {
            q.push(node->right);
        }
    }
    return s;
}

int BinaryHeapList::front()
{
    if (!root) throw QException();
    return root->value;
}

void BinaryHeapList::printHeapToTreeWidget(QTreeWidget* treeWidget)
{
    if (!root) throw QException();

    treeWidget->clear();
    std::queue<QTreeWidgetItem*> items;
    std::queue<std::shared_ptr<Node>> nodes;
    nodes.push(root);
    auto item = new QTreeWidgetItem(treeWidget);
    item->setText(0, QString::number(root->value));
    items.push(item);

    while (!nodes.empty())
    {
        auto node = nodes.front();
        nodes.pop();
        auto parentItem = items.front();
        items.pop();

        if (node->left)
        {
            nodes.push(node->left);
            auto leftItem = new QTreeWidgetItem();
            leftItem->setText(0, QString::number(node->left->value));
            parentItem->addChild(leftItem);
            items.push(leftItem);
        }
        if (node->right)
        {
            nodes.push(node->right);
            auto rightItem = new QTreeWidgetItem();
            rightItem->setText(0, QString::number(node->right->value));
            parentItem->addChild(rightItem);
            items.push(rightItem);
        }
    }
    treeWidget->expandAll();
}
