#include <iostream>

// базовый абстрактный класс
class Expression {
public:
    // виртуальный метод для вычисления выражения
    virtual double evaluate() = 0;
};

// класс для представления числа
class Number : public Expression {
private:
    double number;
public:
    // конструктор Number
    explicit Number(double num) {
        this->number = num;
    }

    // реализация виртуального метода evaluate для числа
    double evaluate() override {
        return number;
    }
};

// класс для представления бинарной операции
class BinaryOperation : public Expression {
private:
    Expression *leftOperand;  // левый операнд
    Expression *rightOperand; // правый операнд
    char type;                // тип операции
public:
    // конструктор  BinaryOperation
    BinaryOperation(Expression *left, char type, Expression *right) {
        this->leftOperand = left;
        this->rightOperand = right;
        this->type = type;
    }

    // деструктор
    ~BinaryOperation() {
        delete leftOperand;
        delete rightOperand;
    }

    // реализация виртуального метода evaluate для операции
    double evaluate() override {
        switch (type) {
            case '+':
                return (leftOperand->evaluate() + rightOperand->evaluate());
            case '-':
                return (leftOperand->evaluate() - rightOperand->evaluate());
            case '*':
                return (leftOperand->evaluate() * rightOperand->evaluate());
            case '/':
                if (rightOperand->evaluate() != 0) {
                    return (leftOperand->evaluate() / rightOperand->evaluate());
                } else {
                    std::cout << "Something went wrong\n";
                }
                break;
            default:
                std::cout << "Wrong option\n";
        }
    }
};

int main() {
    // создание выражения (3 - (4.5 * 5))
    Expression *sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression *expr = new BinaryOperation(new Number(3), '-', sube);

    std::cout << expr->evaluate() << "\n";

    delete expr;
}
