#ifndef READER_H
#define READER_H
#include <QString>
#include <QRegularExpression>
class Reader
{
public:
    Reader();
    QString getFullName();
    QString getAddress();
    QString getPhoneNumber();
    int getCode();
    void setCode(int c);
    void setFullName(QString f);
    void setAddress(QString a);
    void setPhoneNumber(QString p);
    static bool isValidFullName(const QString& fullName);
    static bool isValidAddress(const QString& address);
private:
    int code;
    QString fullName;
    QString address;
    QString phoneNumber;
};

#endif // READER_H
