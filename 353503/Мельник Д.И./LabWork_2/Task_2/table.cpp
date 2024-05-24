//
// Created by dmitry on 19.3.24.
//

#include "table.h"
#include "QtWidgets/qheaderview.h"

static bool compareByYear(Book* a, Book* b) {
  return (a->getYear() < b->getYear());
}

static bool compareByPublisher(Book* a, Book* b) {
  return (a->getPublisher() < b->getPublisher());
}

Table::Table(QTableWidget* table) {
  this->_table = table;
}

auto Table::setTableInfo(QVector<Book*> const& b) -> void {
  _library = b;
  _table->setColumnCount(5);
  QStringList headers;
  headers << "АВТОР"
          << "НАЗВАНИЕ"
          << "ИЗДАТЕЛЬ"
          << "ГОД"
          << "СТРАНИЦЫ";
  _table->setHorizontalHeaderLabels(headers);

  _table->setStyleSheet("QTableView { gridline-color: #FFFFFF; }");

  _table->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

  _table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  _table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  _table->resizeColumnsToContents();
  _table->resizeRowsToContents();

  _table->horizontalHeader()->setStretchLastSection(true);
  _table->resizeColumnsToContents();
  _table->setAlternatingRowColors(true);
  for (int i = 0; i < b.count(); ++i) {
    this->setRow(b.at(i), i);
  }

  this->updateRowSize();
  _table->setColumnWidth(0, 100);
  _table->setColumnWidth(1, 150);
  _table->setColumnWidth(2, 150);
  _table->setColumnWidth(3, 50);
}

auto Table::setRow(Book* book, int n) -> void {
  if (_table->rowCount() - 1 < n) {
    _table->insertRow(n);
  }

  setItem(n, 0, book->getAuthor());
  setItem(n, 1, book->getTitle());
  setItem(n, 2, book->getPublisher());
  setItem(n, 3, QString::number(book->getYear()));
  setItem(n, 4, QString::number(book->getPages()));
}

auto Table::setItem(int row, int column, const QString& text) -> void {
  QTableWidgetItem* newItem = new QTableWidgetItem(text);
  _table->setItem(row, column, newItem);
  Qt::ItemFlags flags = newItem->flags();
  flags = flags & ~Qt::ItemIsEditable;
  newItem->setFlags(flags);
}

auto Table::updateRowSize() -> void {
  int tableHeight = 0;
  for (int i = 0; i < int(_table->rowCount()); ++i) {
    tableHeight += int(_table->rowHeight(i));
  }
  _table->setFixedHeight(tableHeight + 25);
}

auto Table::sortByYear() -> void {
  std::sort(_library.begin(), _library.end(), compareByYear);
  updateInfo();
}

auto Table::sortByPublisher() -> void {
  std::sort(_library.begin(), _library.end(), compareByPublisher);
  updateInfo();
}

auto Table::addRow(QFile* file, Book* book) -> void {
  _library.push_back(book);
  this->setRow(book, _table->rowCount());
  if (_library.size() < 14) {
    this->updateRowSize();
  }

  file->open(QIODevice::ReadWrite);
  QString str;
  QTextStream fileStream(file);
  fileStream.seek((_table->rowCount()) *
                  (3 * sizeof(QString) + 2 * sizeof(int) + 5 * sizeof(char)));
  fileStream << book->toString();
  file->close();
}

auto Table::updateInfo() -> void {
  for (int i = 0; i < _library.count(); ++i) {
    setRow(_library.at(i), i);
  }
}

auto Table::showNecessary(QString const& name) -> void {
  _table->clear();
  for (int i = 0; i < _library.count(); ++i) {
    if (_library.at(i)->getTitle().contains(name))
      setRow(_library.at(i), i);
  }
}

auto Table::deleteRow(QFile* file, int n) -> void {
  _table->removeRow(n - 1);
  _library.removeAt(n - 1);
  this->updateRowSize();
  file->open(QIODevice::WriteOnly);
  QTextStream fileStream(file);
  for (int i = 0; i < _library.size(); ++i) {
    if (i != n - 1) {
      fileStream << _library.at(i)->toString();
    }
  }
  file->close();
}
