#pragma once

#include <QString>
#include <qtmetamacros.h>

class Buisnessman {
public:
  Buisnessman();

  QString name() { return data.name; }
  void setName(QString newName) { data.name = newName; }

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

private:
  struct DATA {
    QString name;
    int age;
    double bragsPerDay;
    QChar creditRating;
    bool evil;
    long long networth[3];
  };
  DATA data;
};