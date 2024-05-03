#include <iostream>
#include <cstdint>

class A {
public:
    virtual void virtualMethod() {
        std::cout << "ejj";
    }
};

class B : public A {
public:
    void virtualMethod() override {
        std::cout << "ecub";
    }
};

class Expression {
public:
    Expression() = default;

    virtual ~Expression() = default;

    virtual void foo() {};

    virtual double evaluate() = 0;
};

class Number : public Expression {
    double _number;
public:
    Number(double number) : Expression() {
        _number = number;
    }

    double evaluate()override {
        return _number;
    }
};

class BinaryOperation : public Expression {
    Expression *l_value;
    Expression *r_value;
    char operation;
public:
    BinaryOperation(Expression *l_value, char operation, Expression *r_value) : l_value(l_value), r_value(r_value) {
        this->operation = operation;
    }

    ~BinaryOperation() {
        delete l_value;
        delete r_value;
    }
void foo() override {
        std::cout << "sfa";
    }


    double evaluate()override {
        std::cout << "rer";
        switch (operation) {
            case '+':
                return l_value->evaluate() + r_value->evaluate();
            case '*':
                return l_value->evaluate() + r_value->evaluate();
            case '-':
                return l_value->evaluate() + r_value->evaluate();
            case '/':
                return l_value->evaluate() + r_value->evaluate();
            default:
                return 0;
        }
    }
};

bool checkEquals(Expression const* left, Expression const* right)
{
    return *(size_t*)left == *(size_t*)right;
}

/*int main() {
    Expression *sube = new BinaryOperation(new Number(3), '+', new Number(5.7));
    Expression *expr = new BinaryOperation(new Number(4), '*', sube);
    //std::cout << expr->evaluate() << "\n";
    Expression *number = new BinaryOperation(new Number(3), '+', new Number(5.7));

    BinaryOperation derivedObj(new Number(3),'+',new Number(5.7));
    size_t* vTable = *(size_t**)(&derivedObj);

    delete number;
    delete expr;
    return 0;
}*/

int main() {
    B x;

    uintptr_t* vir = *(uintptr_t**)(&x);
    typedef void(*ptr)(A*);
    ptr funcPtr = (ptr)vir[0];

    funcPtr(&x);

    return 0;
}

