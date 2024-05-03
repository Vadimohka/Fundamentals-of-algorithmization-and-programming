#ifndef READER_H
#define READER_H
#include <QString>

class Reader
{
public:

    Reader(int code, const QString& fullName, const QString& address, const QString& phoneNumber);
    ~Reader();

    int getCode() const {
        return m_code;
    }

    QString getFullName() const {
        return m_fullName;
    }

    QString getAddress() const {
        return m_address;
    }

    QString getPhoneNumber() const {
        return m_phoneNumber;
    }

private:
    int m_code;
    QString m_fullName;
    QString m_address;
    QString m_phoneNumber;
};

#endif // READER_H
