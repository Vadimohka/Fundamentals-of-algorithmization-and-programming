#ifndef MYVALIDATOR_H
#define MYVALIDATOR_H
#include <QValidator>
class myValidator: public QValidator
{
public:
    myValidator();
    QValidator::State validate(QString &input, int &pos) const override;
};

#endif // MYVALIDATOR_H
