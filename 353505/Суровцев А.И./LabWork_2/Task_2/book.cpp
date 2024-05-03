#include "book.h"

Book::Book() {}

QString Book::getTitle()
{
    return title;
}

QString Book::getAuthor()
{
    return author;
}

int Book::getCode()
{
    return code;
}

int Book::getYear()
{
    return year;
}

QString Book::getLanguage()
{
    return language;
}

void Book::setCode(int c)
{
    code = c;
}

void Book::setAuthor(QString a)
{
    author = a;
}

void Book::setTitle(QString t)
{
    title = t;
}

void Book::setYear(int y)
{
    year = y;
}

void Book::setLanguage(QString l)
{
    language = l;
}
