#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{
public:
    Book(int code, const QString& author, const QString& title, int year, const QString& language);
    ~Book();

    // Геттеры и сеттеры для свойств
    int getCode() const { return m_code; }
    QString getAuthor() const { return m_author; }
    QString getTitle() const { return m_title; }
    int getYear() const { return m_year; }
    QString getLanguage() const { return m_language; }


private:
    int m_code;
    QString m_author;
    QString m_title;
    int m_year;
    QString m_language;
};

#endif // BOOK_H
