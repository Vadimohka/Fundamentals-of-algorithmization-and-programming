#ifndef BOOK_H
#define BOOK_H
#include <QString>
class Book
{
public:
    Book();
    QString getTitle();
    QString getAuthor();
    int getCode();
    int getYear();
    QString getLanguage();
    void setCode(int c);
    void setAuthor(QString a);
    void setTitle(QString t);
    void setYear(int y);
    void setLanguage(QString l);
private:
    int code;
    QString author;
    QString title;
    int year;
    QString language;
};

#endif // BOOK_H
