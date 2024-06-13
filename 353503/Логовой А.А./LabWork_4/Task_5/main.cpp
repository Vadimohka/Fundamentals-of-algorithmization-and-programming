#include<Vector.h>
#include<QDebug>
#include<Pair.h>

int main()
{

    Pair< Vector<int>,Vector<Pair<int,double>> > a;

    a.first.assign(20, 20);
    a.second.assign(20, Pair<int, double>(20, 90.90));

    for (auto i: a.first) {
        qDebug() << i;
    }

    for (auto i: a.second) {
        qDebug() << i.first << i.second;
    }

    return 0;
}
