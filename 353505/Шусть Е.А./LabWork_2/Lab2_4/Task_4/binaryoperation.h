#ifndef BINARYOPERATION_H
#define BINARYOPERATION_H

#include "expression.h"

class BinaryOperation : public Expression
{
public:
    QString getType() const override;
};

#endif // BINARYOPERATION_H
