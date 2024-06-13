#pragma once

#include <QVector>
class Stack {
private:
    static const int MAX = 1000;
    QPair<int, int> a[MAX];
    int top;

public:
    Stack() { top = -1; }
    bool isEmpty();
    bool isFull();
    void push(QPair<int, int>);
    void clearStack();
    QPair<int, int> pop();
    QVector<QPair<int, int>> toQVector();
    QPair<int, int> peek();
};
