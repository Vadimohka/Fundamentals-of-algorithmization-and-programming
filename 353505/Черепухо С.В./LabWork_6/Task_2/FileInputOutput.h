#ifndef FILEINPUTOUTPUT_H
#define FILEINPUTOUTPUT_H

#include <QString>
#include <QVector>
#include <Plant.h>
#include <notebook.h>

static const QString pathToSimpleParagraph
    = "/home/hines/Рабочий стол/Labs/LabWork_6/Task_2/files/ЧерепухоЛаб20.txt";
static const QString pathToArray
    = "/home/hines/Рабочий стол/Labs/LabWork_6/Task_2/files/ЧерепухоЛаб20_0.txt";
static const QString pathToTxtStruct
    = "/home/hines/Рабочий стол/Labs/LabWork_6/Task_2/files/ЧерепухоЛаб20_1.txt";
static const QString pathToBinStruct
    = "/home/hines/Рабочий стол/Labs/LabWork_6/Task_2/files/ЧерепухоЛаб20_2.bin";
static const QString pathToListSentences
    = "/home/hines/Рабочий стол/Labs/LabWork_6/Task_2/files/ЧерепухоЛаб20_3.txt";

class FileInputOutput
{
public:
    static void writeToFile(const QString &fileName, const QString &text);
    static QString readFromFile(const QString &fileName);

    static void writeArrayToFile(const QString &fileName, const QVector<float> &arr);
    static QString readArrayFromFile(const QString &fileName);

    static void writeStructToTxtFile(const QString &fileName, Notebook &notebook);
    static QVector<Notebook> readStructFromTxtFile(const QString &fileName);

    static void writeStructToBinFile(const QString &fileName, Notebook &notebook);
    static QVector<Notebook> readStructFromBinFile(const QString &fileName);

    static void appendSentenceToFile(const QString &fileName, const QString &text);

    static void clear(const QString &fileName);
};

#endif // FILEINPUTOUTPUT_H
