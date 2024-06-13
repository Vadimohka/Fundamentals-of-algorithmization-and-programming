#ifndef NUMBER_H
#define NUMBER_H

#include "expression.h"

class Number : public Expression
{
public:
    QString getType() const override;
};

#endif // NUMBER_H
