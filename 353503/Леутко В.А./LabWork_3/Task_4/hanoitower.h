#ifndef HANOITOWER_H
#define HANOITOWER_H

#include <QObject>
#include <QList>

class HanoiTower : public QObject {
    Q_OBJECT

public:
    explicit HanoiTower(QObject *parent = nullptr);

    void solve(int numRings);

signals:
    void movePerformed(int ring, int from, int to);

private:
    void hanoi(int n, int start, int finish, int temp);

    QList<int> tower[3];

};

#endif // HANOITOWER_H
