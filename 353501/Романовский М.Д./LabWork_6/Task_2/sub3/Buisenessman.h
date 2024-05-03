#pragma once

#include <QString>
#include <cstddef>
#include <qtmetamacros.h>

class Buisnessman {
public:
  Buisnessman();
  Buisnessman(QString name, int age, double bragsPerDay, QChar creditRating,
              bool evil, long long networth_0, long long networth_1,
              long long networth_2);
  Buisnessman(const QByteArray &binData);

  QString name();
  void setName(QString newName);

  int age() { return data.age; }
  void setAge(int newAge) { data.age = newAge; }

  double bragsPerDay() { return data.bragsPerDay; }
  void setBragsPerDay(double newBragsPerDay) {
    data.bragsPerDay = newBragsPerDay;
  }

  QChar creditRating() { return data.creditRating; }
  void setCreditRating(QChar newCreditRating) {
    data.creditRating = newCreditRating;
  }

  bool evil() { return data.evil; }
  void setEvil(bool newEvil) { data.evil = newEvil; }

  long long networth(long long year = 2) { return data.networth[year]; }
  void setNetworth(long long newVal, long long year = 2) {
    data.networth[year] = newVal;
  }

  QString generateHtmlReport();
  QByteArray toBinData();

private:
  struct DATA {
    char name[256];
    int age;
    double bragsPerDay;
    QChar creditRating;
    bool evil;
    long long networth[3];
  };
  DATA data;

public:
  static const size_t BINDATA_SIZE = sizeof(DATA);
};