#include "solution.h"

Solution::Solution() {}

QString Solution::hanoi(int number, QString nameFirstTower,
                        QString nameSecondTower, QString nameThirdTower) {
    if (number == 1) {
    result += "Переместить диск номер " + QString::number(number) + " из  " +
              nameFirstTower + " на " + nameThirdTower + '.' + '\n';
    return result;
  }
  hanoi(number - 1, nameFirstTower, nameThirdTower, nameSecondTower);
  result += "Переместить диск номер " + QString::number(number) + " из  " +
            nameFirstTower + " на " + nameThirdTower + '.' + '\n';
  hanoi(number - 1, nameSecondTower, nameThirdTower, nameFirstTower);
  return result;
}

void Solution::resetLine() {
    result = "Поочередные шаги по перестановке колец:\n";
}
