#ifndef FOLDERNAMEVALIDATOR_H
#define FOLDERNAMEVALIDATOR_H

#include <QValidator>


class FolderNameValidator: public QValidator
{
public:
    FolderNameValidator();
    QValidator::State validate(QString &input, int &pos) const override;

};

#endif // FOLDERNAMEVALIDATOR_H
