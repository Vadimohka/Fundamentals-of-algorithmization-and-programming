#include <iostream>

// базовый абстрактный класс для выражений
class Expression {
public:
    // виртуальный метод для вычисления выражения
    virtual double evaluate() = 0;

    virtual ~Expression() = default;
};

// класс для представления числа
class Number : public Expression {
private:
    double num;
public:
    // конструктор Number
    explicit Number(double number) {
        this->num = number;
    }

    // реализация виртуального метода evaluate для числа
    double evaluate() override {
        return num;
    }
};

// класс для представления бинарной операции
class BinaryOperation : public Expression {
private:
    Expression *left;   // левый операнд
    Expression *right;  // правый операнд
    char type;          // тип операции
public:
    // конструктор BinaryOperation
    BinaryOperation(Expression *left, char type, Expression *right) {
        this->left = left;
        this->right = right;
        this->type = type;
    }

    // деструктор для освобождения памяти
    ~BinaryOperation() {
        delete left;
        delete right;
    }

    // реализация виртуального метода evaluate для бинарной операции
    double evaluate() override {
        switch (type) {
            case '+':
                return (left->evaluate() + right->evaluate());
            case '-':
                return (left->evaluate() - right->evaluate());
            case '*':
                return (left->evaluate() * right->evaluate());
            case '/':
                if (right->evaluate() != 0) {
                    return (left->evaluate() / right->evaluate());
                } else {
                    std::cout << "Error\n";
                }
                break;
            default:
                std::cout << "Wrong option\n";
        }
    }
};

// функция для проверки равенства двух выражений
bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}

int main() {
    // создание объектов выражений и чисел
    auto *n1 = new Number(1);
    auto *n2 = new Number(2);
    auto *a = new BinaryOperation(n1, '-', n2);
    auto *b = new BinaryOperation(n1, '/', n2);

    // вывод адресов объектов
    std::cout << *(double **)n1 << "\t- n1" << "\n" << *(double **)n2 << "\t- n2" << "\n" << *(double **)a << "\t- a"
    << "\n" << *(double **)b << "\t- b" << "\n\n";

    // проверка равенства объектов
    std::cout << (check_equals(a, b) ? "Yes\n" : "No\n");
    std::cout << (check_equals(n1, b) ? "Yes\n" : "No\n");

    delete n1;
    delete n2;
    delete a;
    delete b;
}
