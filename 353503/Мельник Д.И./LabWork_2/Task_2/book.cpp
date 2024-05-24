//
// Created by dmitry on 19.3.24.
//

#include "book.h"

Book::Book(QString author, QString title, int year, QString publisher,
           int pages)
    : _author(author),
      _title(title),
      _publisher(publisher),
      _year(year),
      _pages(pages) {}

auto Book::getAuthor() -> QString {
  return this->_author;
}

auto Book::getTitle() -> QString {
  return this->_title;
}

auto Book::getPublisher() -> QString {
  return this->_publisher;
}

auto Book::getYear() -> int {
  return this->_year;
}

auto Book::getPages() -> int {
  return this->_pages;
}

auto Book::toString() -> QString {
  QString str = this->getAuthor() + " " + this->getTitle() + " " +
                this->getPublisher() + " " + QString::number(this->getYear()) +
                " " + QString::number(this->getPages()) + "\n";
  return str;
}
