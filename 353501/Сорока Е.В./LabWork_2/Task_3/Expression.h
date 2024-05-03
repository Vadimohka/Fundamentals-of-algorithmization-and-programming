class Expression {
public:
    virtual double evaluate() const = 0; // Чистая виртуальная функция
    virtual ~Expression() {} // Виртуальный деструктор
};
