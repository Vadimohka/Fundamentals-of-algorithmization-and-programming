#include "puzzlesolver.h"

PuzzleSolver::PuzzleSolver(QObject *parent)
    : QObject{parent}
{}

Chain15 PuzzleSolver::a_star(const Chain15 &startChain, const QString &goalNode)
{
    QHash<QString, int> nodeHash;
    std::priority_queue<Chain15, std::vector<Chain15>, std::greater<Chain15>> chainsQueue;
    chainsQueue.push(startChain);

    while (!chainsQueue.empty()) {
        Chain15 curChain = chainsQueue.top();
        chainsQueue.pop();

        QString curNode = curChain.lastNode();
        if (curNode == goalNode) {
            return curChain;
        }

        nodeHash[curNode] = curChain.g();

        QVector<Chain15> neighbours = curChain.getNeighbours();
        for (const Chain15 &chain : neighbours) {
            QString chainNode = chain.lastNode();
            if (nodeHash.contains(chainNode)) {
                if (chain.g() >= nodeHash[chainNode]) {
                    continue;
                }
                nodeHash[chainNode] = chain.g();
            }

            chainsQueue.push(chain);
        }
    }

    throw std::runtime_error("No solution found");
}

int PuzzleSolver::get_empty_move(const QVector<int> &prev_state, const QVector<int> &curr_state)
{
    int prev_empty_index = prev_state.indexOf(0);
    int curr_empty_index = curr_state.indexOf(0);
    int size = static_cast<int>(qSqrt(prev_state.size()));

    if (curr_empty_index == prev_empty_index + 1) {
        return 3;  // Сдвиг вправо
    } else if (curr_empty_index == prev_empty_index - 1) {
        return 2;  // Сдвиг влево
    } else if (curr_empty_index == prev_empty_index + size) {
        return 1;  // Сдвиг вниз
    } else if (curr_empty_index == prev_empty_index - size) {
        return 0;  // Сдвиг вверх
    } else {
        throw std::invalid_argument("Invalid move between states");
    }
}

void PuzzleSolver::solvePuzzle(const Chain15 &start, const QString &goalNode)
{
    Chain15 result = a_star(start, goalNode);
    emit solutionFound(result);
}
