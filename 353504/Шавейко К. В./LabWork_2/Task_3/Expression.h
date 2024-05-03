#pragma once

class Expression
{
public:
    virtual ~Expression() {}
    virtual double evaluate() const = 0;
};
