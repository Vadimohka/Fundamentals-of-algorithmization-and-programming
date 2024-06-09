#include "Kidtoy.h"

KidToy::KidToy(){
    toy.Name = "LEGO SET";
    toy.AgeCategory = 8;
    toy.Price = 123.50;
    toy.Material = 'P';
    toy.Safety = true;
    toy.Comments[0] = 122000;
    toy.Comments[1] = 3000;
}

QString KidToy::generateReport(){
    return QString(R"ff(
    <h1>Kid Toy Report</h1>
    <table>
    <tr><td>Name:</td><td>%0</td></tr>
    <tr><td>Age Category:</td><td>%1</td></tr>
    <tr><td>Price:</td><td>%2</td></tr>
    <tr><td>Material:</td><td>%3</td></tr>
    <tr><td>Safety:</td><td>%4</td></tr>
    <tr><td>Positive Comment:</td><td>%5</td></tr>
    <tr><td>Negative Comment:</td><td>%6</td></tr>
    </table>
  )ff")
      .arg(toy.Name)
      .arg(toy.AgeCategory)
      .arg(toy.Price)
      .arg(toy.Material)
      .arg(toy.Safety ? "Yes" : "No")
      .arg(GetComment(0))
      .arg(GetComment(1));
}
