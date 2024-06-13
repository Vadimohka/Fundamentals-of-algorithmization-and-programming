#ifndef GRAPHICS_TREE_H
#define GRAPHICS_TREE_H

#include <QtWidgets>
#include <thread>
#include <QCoreApplication>
struct TreeNode
{
public:
    TreeNode(){}
    TreeNode(int _data, TreeNode* _left, TreeNode* _right, bool _color){
        data = _data;
        left = _left;
        right = _right;
        color = _color;
    }
    int data;
    TreeNode *left;
    TreeNode *right;
    bool color;
};
class GraphicsTree : public QWidget
{
public:

    GraphicsTree(QWidget *parent = nullptr);

    void setTree(TreeNode* root);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    void drawTree(QPainter *painter, TreeNode *node, int x, int y, int dx, int dy, int h = 0);

    int r = 30;

    TreeNode *tree;

    bool find = false;

    int findValue;

    const double kriv = 2;
    //const double kriv2 =
};



#endif // GRAPHICS_TREE_H
