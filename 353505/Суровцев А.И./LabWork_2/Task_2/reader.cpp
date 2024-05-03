#include "reader.h"

Reader::Reader() {}

QString Reader::getFullName()
{
    return fullName;
}

QString Reader::getAddress()
{
    return address;
}

QString Reader::getPhoneNumber()
{
    return phoneNumber;
}

int Reader::getCode()
{
    return code;
}

void Reader::setCode(int c)
{
    code = c;
}

void Reader::setFullName(QString f)
{
    fullName = f;
}

void Reader::setAddress(QString a)
{
    address = a;
}

void Reader::setPhoneNumber(QString p)
{
    phoneNumber = p;
}

bool Reader::isValidFullName(const QString &fullName)
{
    QRegularExpression russianLetters("[А-ЯЁ][а-яё]*");
    QStringList parts = fullName.split(" ", Qt::SkipEmptyParts);
    if (parts.size() != 3)
        return false;
    foreach (const QString& part, parts) {
        if (!part.isEmpty() && !russianLetters.match(part).hasMatch())
            return false;
        if (!part.isEmpty() && part != part.toUpper().at(0) + part.mid(1))
            return false;
    }
    return true;
}

bool Reader::isValidAddress(const QString &address)
{
    return !address.trimmed().isEmpty();
}
