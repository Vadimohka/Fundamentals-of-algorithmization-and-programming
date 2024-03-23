#ifndef EXPRESSION_H
#define EXPRESSION_H

#pragma once

class Expression
{
public:
    virtual ~Expression() {}
    virtual double Evaluate() const = 0;
};

#endif // EXPRESSION_H
