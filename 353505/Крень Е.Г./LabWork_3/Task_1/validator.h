#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <QValidator>

class Validator: public QValidator
{
public:
    Validator();
    QValidator::State validate(QString inputData);
};

#endif // VALIDATOR_H
