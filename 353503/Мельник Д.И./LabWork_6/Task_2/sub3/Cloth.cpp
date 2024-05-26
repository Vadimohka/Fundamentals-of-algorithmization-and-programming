#include "Cloth.h"
#include <stdexcept>

Cloth::Cloth() {
  setName("T-short");
  data.count = 42;
  data.price = 69;
  data.size = 'S';
  data.isAvaliable = true;
  data.lenght[0] = 155;
  data.lenght[1] = 165;
  data.lenght[2] = 175;
}

Cloth::Cloth(QString name, int count, double price,
                         QChar size, bool avaliable, long long lav_0,
                         long long val_1, long long val_2)

{
  setName(name);
  data.count = count;
  data.price = price;
  data.size = size;
  data.isAvaliable = avaliable;
  data.lenght[0] = lav_0;
  data.lenght[1] = val_1;
  data.lenght[2] = val_2;
}

Cloth::Cloth(const QByteArray &binData) {
  if (binData.length() != BINDATA_SIZE)
    throw std::invalid_argument("Invalid bin lenght");

  memcpy(&data, binData.data(), BINDATA_SIZE);
}

QString Cloth::name() { return QString::fromLatin1(data.name); }

void Cloth::setName(QString name) {
  QByteArray dat = name.toLatin1();
  int lim = dat.length();
  if (lim > sizeof(data.name) - 1)
    lim = sizeof(data.name) - 1;

  memcpy(data.name, dat.data(), lim);
  data.name[lim] = 0;
}

QString Cloth::generateHtmlReport() {
  return QString(R"ff(
    <h1>Cloth report</h1>
    <table>
    <tr><td>Name:</td><td>%0</td></tr>
    <tr><td>Count:</td><td>%1</td></tr>
    <tr><td>Price:</td><td>%2</td></tr>
    <tr><td>Size:</td><td>%3</td></tr>
    <tr><td>Is avaliable:</td><td>%4</td></tr>
    <tr><td>Lenght:</td><td>%5</td></tr>
    </table>
  )ff")
      .arg(name())
      .arg(count())
      .arg(price())
      .arg(size())
      .arg(isAvaliable())
      .arg(QString("%0 %1 %2")
               .arg(lenght(0) / 1.0e9)
               .arg(lenght(1) / 1.0e9)
               .arg(lenght(2) / 1.0e9));
}

QByteArray Cloth::toBinData() {
  return QByteArray((const char *)&data, BINDATA_SIZE);
}