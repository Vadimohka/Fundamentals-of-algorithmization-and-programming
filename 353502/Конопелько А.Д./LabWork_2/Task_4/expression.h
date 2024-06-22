#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expression
{
public:
    Expression();
    virtual ~Expression() = default;
    virtual const void* typeClass() const;
};

#endif // EXPRESSION_H
