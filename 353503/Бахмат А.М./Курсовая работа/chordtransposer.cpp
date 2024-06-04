#include "chordtransposer.h""
#include <QRegExp>
#include <QMap>
#include <algorithm>

QStringList ChordTransposer::sortChords(const QStringList &chords) {
    QVector<QString> chordVector = chords.toVector();
    heapSort(chordVector);
    return QStringList::fromVector(chordVector);
}

void ChordTransposer::heapSort(QVector<QString> &chords) {
    int n = chords.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(chords, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        std::swap(chords[0], chords[i]);
        heapify(chords, i, 0);
    }
}

void ChordTransposer::heapify(QVector<QString> &chords, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && chords[left] > chords[largest])
        largest = left;

    if (right < n && chords[right] > chords[largest])
        largest = right;

    if (largest != i) {
        std::swap(chords[i], chords[largest]);
        heapify(chords, n, largest);
    }
}

bool ChordTransposer::validateChords(const QStringList &chords) {
    QRegExp validChordPattern("^[A-G][#b]?(m|maj|min|dim|aug|sus2|sus4|7|9|11|13)?$");
    for (const QString &chord : chords) {
        if (!validChordPattern.exactMatch(chord)) {
            return false;
        }
    }
    return true;
}

bool ChordTransposer::hasRepeatedSubstring(const QString &input) {
    int n = input.length();
    for (int len = 1; len <= n / 2; ++len) {
        QString substring = input.mid(0, len);
        if (input.count(substring) * len == n) return true;
    }
    return false;
}

QStringList ChordTransposer::transposeChords(const QStringList &chords, int transposeInterval) {
    if (hasRepeatedSubstring(chords.join(" "))) {
        return transposeRepeatedSubstrings(chords, transposeInterval);
    } else {
        QStringList transposedChords;
        for (const QString &chord : chords) {
            transposedChords.append(transposeChord(chord, transposeInterval));
        }
        return transposedChords;
    }
}

QStringList ChordTransposer::transposeRepeatedSubstrings(const QStringList &chords, int transposeInterval) {
    QMap<QString, QString> transpositionMap;
    QString concatenatedChords = chords.join(" ");
    int n = concatenatedChords.length();

    for (int len = 1; len <= n / 2; ++len) {
        QString substring = concatenatedChords.mid(0, len);
        if (concatenatedChords.count(substring) * len == n) {
            if (!transpositionMap.contains(substring)) {
                transpositionMap[substring] = transposeChord(substring, transposeInterval);
            }
            concatenatedChords.replace(substring, transpositionMap[substring]);
        }
    }

    return concatenatedChords.split(" ", QString::SkipEmptyParts);
}

QString ChordTransposer::transposeChord(const QString &chord, int interval) {
    QStringList notes = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

    // Extract root note and suffix
    int i = 0;
    while (i < chord.length() && (chord[i] == "A" || chord[i] == "#" || chord[i] == "b" || chord[i] == "B" || chord[i] == "C" || chord[i] == "D" || chord[i] == "F" || chord[i] == "E" || chord[i] == "G")) {
        i++;
    }

    QString rootNote = chord.left(i);
    QString suffix = chord.mid(i);

    int noteIndex = notes.indexOf(rootNote);
    if (noteIndex == -1) return chord;

    int newIndex = (noteIndex + interval + notes.size()) % notes.size();
    QString newChord = notes[newIndex] + suffix;

    return newChord;
}

bool ChordTransposer::binarySearch(const QStringList &sortedChords, const QString &chord) {
    int left = 0;
    int right = sortedChords.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (sortedChords[mid] == chord) {
            return true;
        } else if (sortedChords[mid] < chord) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}



