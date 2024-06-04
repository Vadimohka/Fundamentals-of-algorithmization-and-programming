#ifndef CHORDTRANSPOSER_H
#define CHORDTRANSPOSER_H

#include <QString>
#include <QStringList>
#include <QVector>

class ChordTransposer {

public:
    QStringList sortChords(const QStringList &chords);
    QStringList transposeChords(const QStringList &chords, int transposeInterval);
    bool validateChords(const QStringList &chords);
    bool hasRepeatedSubstring(const QString &input);
    bool binarySearch(const QStringList &sortedChords, const QString &chord);

private:
    void heapSort(QVector<QString> &chords);
    void heapify(QVector<QString> &chords, int n, int i);
    QStringList transposeRepeatedSubstrings(const QStringList &chords, int transposeInterval);
    QString transposeChord(const QString &chord, int interval);
};

#endif // CHORDTRANSPOSER_H


