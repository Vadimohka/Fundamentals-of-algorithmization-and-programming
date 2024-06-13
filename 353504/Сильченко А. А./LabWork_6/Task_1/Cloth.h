#pragma once

#include <QString>
#include <qtmetamacros.h>

class Cloth {
public:
  Cloth();

  QString name() { return data.name; }
  void setName(QString newName) { data.name = newName; }

  int count() { return data.count; }
  void setCount(int newCount) { data.count = newCount; }

  double price() { return data.price; }
  void setPrice(double newPrice) {
    data.price = newPrice;
  }

  QChar size() { return data.size; }
  void setSize(QChar newSize) {
    data.size = newSize;
  }

  bool isAvaliable() { return data.isAvaliable; }
  void setAvaliable(bool newAvaliable) { data.isAvaliable = newAvaliable; }

  long long lenght(long long lav = 2) { return data.lenght[lav]; }
  void setLenght(long long newVal, long long val = 2) {
    data.lenght[val] = newVal;
  }

  QString generateHtmlReport();

private:
  struct DATA {
    QString name;
    int count;
    double price;
    QChar size;
    bool isAvaliable;
    long long lenght[3];
  };
  DATA data;
};