#ifndef SOLUTION_H
#define SOLUTION_H
#include <QString>
#include <QDebug>

class Solution
{
public:
    Solution();
    QString hanoi(int n, QString firstTower = "первая башня", QString secondTower =  "вторая башня", QString thirdTower = "третья башня");
    void resetLine();
private:
    QString result = "Поочередные шаги по перестановке колец:\n";
};

#endif // SOLUTION_H
