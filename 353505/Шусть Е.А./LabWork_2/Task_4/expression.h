#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <QString>

class Expression
{
public:
    virtual ~Expression() {}
    virtual QString getType() const = 0;
};

#endif // EXPRESSION_H
