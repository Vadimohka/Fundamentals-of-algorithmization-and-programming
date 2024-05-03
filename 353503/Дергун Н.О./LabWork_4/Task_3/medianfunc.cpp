#include "medianfunc.h"


QVector<float> getMedianVector(const QVector<float> &origVector) {
    QVector<float> inVector = origVector;
    QVector<float> outVector;
    int rem = inVector.size() % 3;

    for (int i = 1; i < inVector.size() - rem; i += 3) {
        std::sort(inVector.begin() + i - 1, inVector.begin() + i + 2);
        outVector.push_back(inVector.at(i));
    }

    if (rem == 1) {
        outVector.push_back(inVector.back());
    } else if (rem == 2) {
        outVector.push_back((inVector.back() +
                             inVector.at(inVector.size() - 2)) / 2);
    }

    return outVector;
}
