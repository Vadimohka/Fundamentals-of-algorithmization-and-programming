#include "hanoiselver.h"

QVector<QPair<int, int>> HanoiSelver::Execute(int rings, int from, int to)
{
    QVector<QPair<int, int>> list;
    if (rings == 1)
    {
        list.push_back({from, to});
    }
    else
    {
        int temp = 6 - from - to;
        list.append(Execute(rings - 1, from, temp));
        list.push_back({from, to});
        list.append(Execute(rings - 1, temp, to));
    }

    return list;
}
