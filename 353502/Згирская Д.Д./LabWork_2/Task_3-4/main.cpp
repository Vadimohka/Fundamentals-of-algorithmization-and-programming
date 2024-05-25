#include <iostream>

class Base {
public:
    virtual void virtualMethod() {
        std::cout << "Вызван виртуальный метод из класса Base" << std::endl;
    }
};

class Derived : public Base {
public:
    void virtualMethod() override {
        std::cout << "Вызван виртуальный метод из класса Derived" << std::endl;
    }
};

class Expression {
public:
    virtual double evaluate() const = 0;
};

class Number: public Expression {
    double _number;
public:
    Number();
    Number(double const Number) {
        this->_number = Number;
    }
    double evaluate() const override {
        return _number;
    }
};

class BinaryOperation: public Expression {
    Expression *_left;
    Expression *_right;
    char _operationType;
public:
    ~BinaryOperation() {
        delete _left;
        delete _right;
    }
    BinaryOperation(Expression *left, char operationType, Expression *right)
            : _left(left), _right(right)
    {
        if (operationType == '+' || operationType == '-' || operationType == '*' || operationType == '/') {
            _operationType = operationType;
            _left = left;
            _right = right;
        }
        else std::cout << "Wrong operation type!";
    }
    double evaluate() const override {
        if (_operationType == '+') {
            return this->_left->evaluate()+ this->_right->evaluate();
        }
        else if (_operationType == '-') {
            return this->_left->evaluate() - this->_right->evaluate();
        }
        else if (_operationType == '*') {
            return this->_left->evaluate()* this->_right->evaluate();
        }
        else if (_operationType == '/') {
            return this->_left->evaluate() / this->_right->evaluate();
        }
    }
};

bool checkEquals(Expression const* left, Expression const* right) {
    return *(unsigned long*)left == *(unsigned long*)right;
}

int main() {
    Expression* num = new Number(6);
    //std::cout << sizeof(*num);
    Expression* sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression* expr = new BinaryOperation(new Number(3), '+', sube);
    //std::cout << sizeof(*expr);
    std::cout << expr->evaluate() << std::endl;
    std::cout << checkEquals(num, expr) <<  '\n';


    Derived derivedObj;

    size_t* vTable = *(size_t**)(&derivedObj);

    typedef void(*FunctionPointer)(Derived*);
    FunctionPointer funcPtr = (FunctionPointer)vTable[0];
    funcPtr(&derivedObj);


    /*Expression* left = new Number(6);
    Expression* right = new BinaryOperation(new Number(4.5), '*', new Number(5));
    std::cout << (unsigned long*)left << ' ' << (unsigned long*)right << '\n';
    std::cout << *(unsigned long*)left << ' ' << *(unsigned long*)right << '\n';
    std::cout << *(unsigned long*)sube << ' ' << *(unsigned long*)right << '\n';*/
    delete expr;
    return 0;
}