#include "SVector.h"
#include <QTime>
#include <QApplication>


void SVector::sigSet(size_t i, long val){
    QVector<long>::operator[](i) = val;

    auto endTime = QTime::currentTime().addMSecs(1);
    while(QTime::currentTime() < endTime){
        QApplication::processEvents(QEventLoop::AllEvents);
    }

     emit elementChanged(i);
}

long SVector::operator[](size_t i) const {
    return QVector<long>::operator[](i);   
}

void SVector::sigSwap(size_t i, size_t j) {
    long tmp = QVector<long>::operator[](i);
    sigSet(i, QVector<long>::operator[](j));
    sigSet(j, tmp);
}

long& SVector::operator[](size_t i) {
    return QVector<long>::operator[](i);
}

SVector::SVector(const SVector& vect) : QVector<long>(vect) {}

SVector::SVector(const SVector& vect, size_t beg, size_t end) : QVector<long>(end - beg) {
    for(size_t i = beg, j = 0; i < end; ++i, ++j){
        QVector<long>::operator[](j) = vect[i];
    }

}