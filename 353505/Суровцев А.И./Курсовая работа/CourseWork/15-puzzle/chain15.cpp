#include "chain15.h"

Chain15::Chain15(const QVector<int> &boardState, const QVector<Chain15> &history) {
    boardState_ = boardState;
    size_ = qSqrt(boardState.size());
    history_ = history;
    quadSize_ = size_ * size_;
}

QString Chain15::toString() const {
    QString str;
    for (int i = 0; i < quadSize_; ++i) {
        str += QString::number(boardState_[i]) + " ";
        if (i % size_ == size_ - 1)
            str += "\n";
    }
    return str;
}

int Chain15::manhDst() const {
    int dst = 0;
    for (int i = 0; i < quadSize_; ++i) {
        dst += manhDstMatrix((boardState_[i] - 1) % quadSize_, i);
    }
    return dst;
}

QString Chain15::lastNode() const {
    QString node;
    for (int num : boardState_) {
        node += QString::number(num);
    }
    return node;
}

int Chain15::lastMove() const {
    if (boardState_.back() == quadSize_ - 1 || boardState_.back() == quadSize_ - size_)
        return 0;
    return 2;
}

int Chain15::h() const {
    return manhDst() + lastMove();
}

int Chain15::g() const {
    return history_.size();
}

int Chain15::f() const {
    return h() + g();
}

bool Chain15::operator<(const Chain15 &other) const {
    return f() < other.f();
}

QVector<Chain15> Chain15::getNeighbours() const {
    QVector<Chain15> neighs;
    int zeroCoord = boardState_.indexOf(0);

    if (zeroCoord + 1 < quadSize_ && manhDstMatrix(zeroCoord, zeroCoord + 1) == 1) {
        QVector<int> newState = boardState_;
        std::swap(newState[zeroCoord], newState[zeroCoord + 1]);
        neighs.push_back(Chain15(newState, history_ + QVector<Chain15>({*this})));
    }

    if (zeroCoord - 1 >= 0 && manhDstMatrix(zeroCoord, zeroCoord - 1) == 1) {
        QVector<int> newState = boardState_;
        std::swap(newState[zeroCoord], newState[zeroCoord - 1]);
        neighs.push_back(Chain15(newState, history_ + QVector<Chain15>({*this})));
    }

    if (zeroCoord + size_ < quadSize_ && manhDstMatrix(zeroCoord, zeroCoord + size_) == 1) {
        QVector<int> newState = boardState_;
        std::swap(newState[zeroCoord], newState[zeroCoord + size_]);
        neighs.push_back(Chain15(newState, history_ + QVector<Chain15>({*this})));
    }

    if (zeroCoord - size_ >= 0 && manhDstMatrix(zeroCoord, zeroCoord - size_) == 1) {
        QVector<int> newState = boardState_;
        std::swap(newState[zeroCoord], newState[zeroCoord - size_]);
        neighs.push_back(Chain15(newState, history_ + QVector<Chain15>({*this})));
    }

    return neighs;
}

int Chain15::manhDstMatrix(int a, int b) const {
    return qAbs(a % size_ - b % size_) + qAbs(a / size_ - b / size_);
}
