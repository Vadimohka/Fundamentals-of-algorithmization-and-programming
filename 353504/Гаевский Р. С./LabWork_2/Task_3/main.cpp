#include <iostream>
class Expression{
public:
    virtual double evaluate(){
        return  0;
    };
};
class Number : public Expression{
public:
    double number;
    Number(double n){
        this->number = n;
    }
    double evaluate() override{
        return number;
    }
};
class Binary_Operation : public Expression{
public:
    Expression* right;
    Expression* left;
    char operation;
    ~Binary_Operation(){
        delete left;
        delete right;
    }
    Binary_Operation(Expression* le,char op,Expression* ri) {
        this->right = ri;
        this->left = le;
        this->operation = op;
    }
    double evaluate() override{
        switch (operation) {
            case('+'):
                return left->evaluate() + right->evaluate();
            case('-'):
                return left->evaluate() - right->evaluate();
            case('*'):
                return left->evaluate() * right->evaluate();
            case('/'):
                if(right->evaluate() == 0){
                    std::cout<<"U can't divide by zero";
                    break;
                }
                else{
                    return left->evaluate() / right->evaluate();
                }
            default:
                std::cout<<"Wrong input";
        }
    }
};
bool check_equals(Expression const* left, Expression const* right) {
    return  *(void **)left == *(void **)right;
}
int main() {
    Number* n1 = new Number(1);
    Number* n2 = new Number(3);
    Binary_Operation* a = new Binary_Operation(n1, '-', n2);
    std::cout<<a->evaluate()<<"\n";
    std::cout << (check_equals(n1, n2) ? "Yes\n" : "No\n");
    std::cout << (check_equals(n1, a) ? "Yes\n" : "No\n");
    return 0;
}
