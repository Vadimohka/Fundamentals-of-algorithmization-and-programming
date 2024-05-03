#include "Buisenessman.h"
#include <stdexcept>

Buisnessman::Buisnessman() {
  setName("Melon Tusk");
  data.age = 42;
  data.bragsPerDay = 69;
  data.creditRating = 'D';
  data.evil = true;
  data.networth[0] = 226e12;
  data.networth[1] = 244e12;
  data.networth[2] = 218e12;
}

Buisnessman::Buisnessman(QString name, int age, double bragsPerDay,
                         QChar creditRating, bool evil, long long networth_0,
                         long long networth_1, long long networth_2)

{
  setName(name);
  data.age = age;
  data.bragsPerDay = bragsPerDay;
  data.creditRating = creditRating;
  data.evil = evil;
  data.networth[0] = networth_0;
  data.networth[1] = networth_1;
  data.networth[2] = networth_2;
}

Buisnessman::Buisnessman(const QByteArray &binData) {
  if (binData.length() != BINDATA_SIZE)
    throw std::invalid_argument("Invalid bin size");

  memcpy(&data, binData.data(), BINDATA_SIZE);
}

QString Buisnessman::name() { return QString::fromLatin1(data.name); }

void Buisnessman::setName(QString name) {
  QByteArray dat = name.toLatin1();
  int lim = dat.length();
  if (lim > sizeof(data.name) - 1)
    lim = sizeof(data.name) - 1;

  memcpy(data.name, dat.data(), lim);
  data.name[lim] = 0;
}

QString Buisnessman::generateHtmlReport() {
  return QString(R"ff(
    <h1>Buisenessman report</h1>
    <table>
    <tr><td>Name:</td><td>%0</td></tr>
    <tr><td>Age:</td><td>%1</td></tr>
    <tr><td>Brags per day:</td><td>%2</td></tr>
    <tr><td>Credit rating:</td><td>%3</td></tr>
    <tr><td>Is evil:</td><td>%4</td></tr>
    <tr><td>Networth of 3-years (millions):</td><td>%5</td></tr>
    </table>
  )ff")
      .arg(name())
      .arg(age())
      .arg(bragsPerDay())
      .arg(creditRating())
      .arg(evil())
      .arg(QString("%0 %1 %2")
               .arg(networth(0) / 1.0e9)
               .arg(networth(1) / 1.0e9)
               .arg(networth(2) / 1.0e9));
}

QByteArray Buisnessman::toBinData() {
  return QByteArray((const char *)&data, BINDATA_SIZE);
}