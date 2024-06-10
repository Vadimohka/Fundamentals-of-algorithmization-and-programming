#ifndef FILENAMEVALIDAROR_H
#define FILENAMEVALIDAROR_H

#include <QValidator>

class FileNameValidaror: public QValidator
{
public:
    FileNameValidaror();
    QValidator::State validate(QString &input, int &pos) const override;

};

#endif // FILENAMEVALIDAROR_H
