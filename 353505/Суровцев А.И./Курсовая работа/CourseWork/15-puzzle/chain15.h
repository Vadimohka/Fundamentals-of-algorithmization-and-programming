#ifndef CHAIN15_H
#define CHAIN15_H

#include <QString>
#include <QtMath>
#include <QVector>

class Chain15 {
public:
    Chain15(const QVector<int>& boardState, const QVector<Chain15>& history = {});
    QString toString() const;
    int manhDst() const;
    QString lastNode() const;
    int lastMove() const;
    int h() const;
    int g() const;
    int f() const;
    bool operator<(const Chain15& other) const;
    QVector<Chain15> getNeighbours() const;
    QVector<int> boardState_;
    QVector<Chain15> history_;
    bool operator>(const Chain15& other) const {
        return this->f() > other.f();
    }

private:
    int size_;
    int quadSize_;
    int manhDstMatrix(int a, int b) const;
};

#endif // CHAIN15_H
