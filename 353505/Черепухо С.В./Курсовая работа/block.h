#ifndef BLOCK_H
#define BLOCK_H

#include <QString>

class Block
{
public:
    Block();

    QString text;
    int id, tabCount, getType, sendType;

    void doing();
};

#endif // BLOCK_H
