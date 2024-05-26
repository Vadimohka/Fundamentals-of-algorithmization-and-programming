#pragma once

#include <QString>
#include <cstddef>
#include <qtmetamacros.h>

class Cloth {
public:
  Cloth();
  Cloth(QString name, int count, double price, QChar size,
              bool avaliable, long long lav_0, long long val_1,
              long long val_2);
  Cloth(const QByteArray &binData);

  QString name();
  void setName(QString newName);

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
  void setAvaliable(bool avaliable) { data.isAvaliable = avaliable; }

  long long lenght(long long val = 2) { return data.lenght[val]; }
  void setLenght(long long newVal, long long val = 2) {
    data.lenght[val] = newVal;
  }

  QString generateHtmlReport();
  QByteArray toBinData();

private:
  struct DATA {
    char name[256];
    int count;
    double price;
    QChar size;
    bool isAvaliable;
    long long lenght[3];
  };
  DATA data;

public:
  static const size_t BINDATA_SIZE = sizeof(DATA);
};