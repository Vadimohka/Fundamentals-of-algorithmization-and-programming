class Number : public Expression {
public:
    Number(double value) : value(value) {}
    double evaluate() const { return value; }
    int getID() const { return 1; } // Реализуем метод в этом классе
private:
    double value;
};
