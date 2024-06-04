#ifndef PUZZLESOLVER_H
#define PUZZLESOLVER_H

#include <QObject>
#include <QHash>
#include <QVector>
#include <queue>
#include "chain15.h"

class PuzzleSolver : public QObject
{
    Q_OBJECT
public:
    explicit PuzzleSolver(QObject *parent = nullptr);
    int get_empty_move(const QVector<int> &prev_state, const QVector<int> &curr_state);
signals:
    void solutionFound(const Chain15 &result);
public slots:
    void solvePuzzle(const Chain15 &start, const QString &goalNode);
private:
    Chain15 a_star(const Chain15 &startChain, const QString &goalNode);
};

#endif // PUZZLESOLVER_H
