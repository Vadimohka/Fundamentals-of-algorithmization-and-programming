//
// Created by dmitry on 19.3.24.
//

#ifndef LAB2_2_BOOK_H
#define LAB2_2_BOOK_H

#include "QtCore/qstring.h"

class Book {
 public:
  Book(QString author, QString title, int year, QString Publisher, int pages);

  auto getAuthor() -> QString;

  auto getTitle() -> QString;

  auto getPublisher() -> QString;

  auto getYear() -> int;

  auto getPages() -> int;

  auto toString() -> QString;

 private:
  QString _author;
  QString _title;
  QString _publisher;
  int _year;
  int _pages;
};

#endif  //LAB2_2_BOOK_H
