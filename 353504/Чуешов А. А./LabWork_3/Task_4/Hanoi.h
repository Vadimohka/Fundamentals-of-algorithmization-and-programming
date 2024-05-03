#include <QList>
#include <QString>

class Hanoi {
public:
    static QList<QPair<int, int>> Solve(long long x, int from = 0, int aux = 1,
                                        int to = 2);
};
