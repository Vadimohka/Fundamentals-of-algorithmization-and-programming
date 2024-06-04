#include "binarysearch.h"

BinarySearch::BinarySearch(QVector<int> vector, int element) {
    this->vector = vector;
    this->element = element;
}

int BinarySearch::binarySearch(int left, int right)
{
    int mid = (left + right) / 2;
    if (qAbs(left - right) <= 1) {
        if (vector[left] == element) {
            vector.append(left);
            return left;
        }
        if (vector[right] == element) {
            return right;
        }
        return -1;
    }
    if (vector[mid] > element) {
        return binarySearch(left, mid);
    }
    else {
        return binarySearch(mid, right);
    }

}
