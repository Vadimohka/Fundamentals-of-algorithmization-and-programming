//
// Created by dmitry on 19.3.24.
//

#ifndef TABLE_H
#define TABLE_H

#include <QtCore/qfile.h>
#include <QTableWidget>
#include "book.h"

class Table {
 public:
  explicit Table(QTableWidget* table);

  auto setTableInfo(const QVector<Book*>& books) -> void;

  auto setRow(Book* book, int row) -> void;

  auto addRow(QFile* file, Book* book) -> void;

  auto sortByYear() -> void;

  auto sortByPublisher() -> void;

  auto showNecessary(const QString& name) -> void;

  auto deleteRow(QFile* file, int row) -> void;

 private:
  QTableWidget* _table;
  QVector<Book*> _library;

  auto setItem(int row, int column, const QString& text) -> void;

  auto updateRowSize() -> void;

  auto updateInfo() -> void;
};

#endif  //TABLE_H
