#include "Cloth.h"

Cloth::Cloth() {
  data.name = "T-short";
  data.count = 42;
  data.price = 69;
  data.size = 'S';
  data.isAvaliable = true;
  data.lenght[0] = 155;
  data.lenght[1] = 165;
  data.lenght[2] = 175;
}


QString Cloth::generateHtmlReport() {
  return QString(R"ff(
    <h1>Cloth report</h1>
    <table>
    <tr><td>Name:</td><td>%0</td></tr>
    <tr><td>Count:</td><td>%1</td></tr>
    <tr><td>Price:</td><td>%2</td></tr>
    <tr><td>size:</td><td>%3</td></tr>
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
