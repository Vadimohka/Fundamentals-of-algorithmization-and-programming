class Number : public Expression {
public:
    Number(double value) : value(value) {}
    double evaluate() const { return value; } // Реализация метода evaluate
private:
    double value;
};
