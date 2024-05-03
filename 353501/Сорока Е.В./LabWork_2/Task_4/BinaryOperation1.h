class BinaryOperation : public Expression {
public:
    BinaryOperation(Expression * left, char op, Expression * right) 
        : left(left), op(op), right(right) {}
    double evaluate() const {
        switch(op) {
            case '+': return left->evaluate() + right->evaluate();
            case '-': return left->evaluate() - right->evaluate();
            case '*': return left->evaluate() * right->evaluate();
            case '/': return left->evaluate() / right->evaluate();
        }
        return 0.0;
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }
    int getID() const { return 2; } // Реализуем метод в этом классе
    private:
    Expression * left;
    char op;
    Expression * right;
};

bool check_equals(Expression const* left, Expression const* right) {
    return left->getID() == right->getID(); // Сравниваем идентификаторы
}
