#include "Buisenessman.h"

Buisnessman::Buisnessman() {
  data.name = "Melon Tusk";
  data.age = 42;
  data.bragsPerDay = 69;
  data.creditRating = 'D';
  data.evil = true;
  data.networth[0] = 226e12;
  data.networth[1] = 244e12;
  data.networth[2] = 218e12;
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