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
        return 0.0; // Должно быть недостижимо
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }
private:
    Expression * left;
    char op;
    Expression * right;
};
