#ifndef NAME_H
#define NAME_H

#include <QString>

class Name
{
public:
    Name();
    Name(QString name, QString surname, QString patronymic);

    QString getName() const;
    QString getSurname() const;
    QString getPatronymic() const;

    void setName(QString name);
    void setSurname(QString surname);
    void setPatronymic(QString patronymic);

private:
    QString name, surname, patronymic;
};

#endif // NAME_H
