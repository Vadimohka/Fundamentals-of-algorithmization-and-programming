#ifndef BOOK_H
#define BOOK_H

#include "QtCore/qstring.h"

class Book
{
public:
    Book(QString author,QString title,int year,QString Publisher,int pages);
    QString getAuthor() const;
    QString getTitle() const;
    QString getPublisher() const;
    int getYear() const;
    int getPages() const;
    QString toString() const;

private:
    QString _author;
    QString _title;
    QString _publisher;
    int _year;
    int _pages;
};

#endif // BOOK_H
