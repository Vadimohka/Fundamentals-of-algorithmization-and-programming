#ifndef CUSTOMVALIDATOR_H
#define CUSTOMVALIDATOR_H

#include <QValidator>

class CustomValidator : public QValidator {
public:
    CustomValidator(QObject *parent = nullptr);
    State validate(QString &input, int &pos) const override;
};

#endif // CUSTOMVALIDATOR_H
