#include "book.h"

Book::Book(QString author, QString title, int year, QString publisher, int pages) : _author(author),_title(title),_publisher(publisher),_year(year), _pages(pages)
{}

QString Book::getAuthor() const
{
    return this->_author;
}

QString Book::getTitle() const
{
    return this->_title;
}

QString Book::getPublisher() const
{
    return this->_publisher;
}

int Book::getYear() const
{
    return this->_year;
}

int Book::getPages() const
{
    return this->_pages;
}

QString Book::toString() const
{
    QString str = this->getAuthor() +" "+ this->getTitle() +" "+ this->getPublisher() + " " + QString::number(this->getYear()) +" "+ QString::number(this->getPages()) + "\n";
    return str;
}
