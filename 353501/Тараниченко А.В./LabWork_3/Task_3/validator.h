#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <QValidator>

class My_validator : public QValidator
{
public:
    My_validator(QObject *parent = nullptr)
        : QValidator(parent){};

    QValidator::State validate(QString &input, int &pos) const override;
};

#endif // VALIDATOR_H
