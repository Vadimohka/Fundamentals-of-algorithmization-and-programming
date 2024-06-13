#ifndef EXPRESSION_H
#define EXPRESSION_H

//I am booored
class Expression
{
public:
    Expression();
    virtual ~Expression() = default;
    virtual const void* my_type_id() const;
};

#endif // EXPRESSION_H
