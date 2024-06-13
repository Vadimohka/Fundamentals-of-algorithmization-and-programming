//
// Created by acryoz on 14.3.24.
//

#ifndef UNTITLED5_EXPRESSION_H
#define UNTITLED5_EXPRESSION_H
#pragma once


class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() = default;
};


#endif //UNTITLED5_EXPRESSION_H
