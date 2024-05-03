class Expression {
public:
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
    virtual int getID() const = 0; // Добавляем этот метод
};
