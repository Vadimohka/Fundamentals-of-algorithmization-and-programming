#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>

// Базовый класс Expression
class Expression {
public:
    virtual ~Expression() {} // Виртуальный деструктор

    virtual double evaluate() const = 0; // Виртуальная функция для вычисления значения выражения
};

// Класс Number для представления чисел
class Number : public Expression {
private:
    double value; // Значение числа
public:
    Number(double val) : value(val) {} // Конструктор

    double evaluate() const override { return value; } // Реализация метода evaluate
};

// Класс BinaryOperation для представления бинарной операции
class BinaryOperation : public Expression {
private:
    Expression* leftOperand; // Левый операнд
    Expression* rightOperand; // Правый операнд
    char operation; // Операция

public:
    BinaryOperation(Expression* left, char op, Expression* right) : leftOperand(left), operation(op), rightOperand(right) {} // Конструктор

    ~BinaryOperation() override { // Деструктор
        delete leftOperand;
        delete rightOperand;
    }

    double evaluate() const override { // Реализация метода evaluate
        double leftValue = leftOperand->evaluate();
        double rightValue = rightOperand->evaluate();

        switch (operation) {
            case '+':
                return leftValue + rightValue;
            case '-':
                return leftValue - rightValue;
            case '*':
                return leftValue * rightValue;
            case '/':
                if (rightValue != 0)
                    return leftValue / rightValue;
                else {
                    std::cerr << "Error: Division by zero" << std::endl;
                    return 0;
                }
            default:
                std::cerr << "Invalid operation" << std::endl;
                return 0;
        }
    }
};

// Функция для проверки является ли символ оператором
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Функция для разбора арифметического выражения и создания объектов классов Number и BinaryOperation
Expression* parseExpression(const std::string& expr) {
    std::stack<Expression*> numbers;
    std::stack<char> ops;

    std::istringstream iss(expr);
    char c;
    while (iss >> c) {
        if (std::isdigit(c) || c == '.') { // Если символ - число или десятичная точка
            iss.putback(c);
            double value;
            iss >> value;
            numbers.push(new Number(value));
        } else if (isOperator(c)) { // Если символ - оператор
            while (!ops.empty() && (ops.top() != '(') && ((c != '*' && c != '/') || (ops.top() != '+' && ops.top() != '-'))) {
                char op = ops.top();
                ops.pop();
                Expression* right = numbers.top();
                numbers.pop();
                Expression* left = numbers.top();
                numbers.pop();
                numbers.push(new BinaryOperation(left, op, right));
            }
            ops.push(c);
        } else if (c == '(') { // Если символ - открывающая скобка
            ops.push(c);
        } else if (c == ')') { // Если символ - закрывающая скобка
            while (ops.top() != '(') {
                char op = ops.top();
                ops.pop();
                Expression* right = numbers.top();
                numbers.pop();
                Expression* left = numbers.top();
                numbers.pop();
                numbers.push(new BinaryOperation(left, op, right));
            }
            ops.pop();
        }
    }

    while (!ops.empty()) {
        char op = ops.top();
        ops.pop();
        Expression* right = numbers.top();
        numbers.pop();
        Expression* left = numbers.top();
        numbers.pop();
        numbers.push(new BinaryOperation(left, op, right));
    }

    return numbers.top();
}

int main() {
    std::string input;
    std::cout << "Enter an arithmetic expression: ";
    std::getline(std::cin, input);

    Expression* expr = parseExpression(input);
    if (expr) {
        std::cout << "Result: " << expr->evaluate() << std::endl;
        delete expr;
    } else {
        std::cerr << "Error: Invalid expression" << std::endl;
    }

    return 0;
}
