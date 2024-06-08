#ifndef NODE_H
#define NODE_H

#include <QGraphicsItem>

class Node : public QGraphicsItem
{
public:
    Node(int key, QString value)
        : key(key)
        , value(value)
        , left(nullptr)
        , right(nullptr)
        , height(1)
    {}

    Node *getLeft() const { return left; }
    Node *getRight() const { return right; }
    void setLeft(Node *node) { left = node; }
    void setRight(Node *node) { right = node; }
    int getKey() const { return key; }
    QString getValue() const { return value; }

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override
    {
        // Реализация метода paint
    }
    QRectF boundingRect() const override
    {
        // Реализация метода boundingRect
    }

private:
    int key;
    QString value;
    Node *left;
    Node *right;
    int height; // Высота узла для AVL-дерева
};

#endif // NODE_H
