#ifndef TREEEXTENSION_H
#define TREEEXTENSION_H

#include <tree.h>

class TreeExtension : public Tree
{
private:
    Node* findMin(Node* root);
    Node* findMax(Node* root);
public:
    void swapMinMax();
};

#endif // TREEEXTENSION_H
