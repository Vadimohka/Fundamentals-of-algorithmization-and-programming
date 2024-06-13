#ifndef FILEINPUTOUTPUT_H
#define FILEINPUTOUTPUT_H

#include <QString>
#include <QVector>
#include <Plant.h>

static const QString pathToSimpleParagraph
    = "/home/vlad/labs/LabWork_6/Task_2/file/lab6_1.txt";
static const QString pathToArray
    = "/home/vlad/labs/LabWork_6/Task_2/file/lab6_2.txt";
static const QString pathToTxtStruct
    = "/home/vlad/labs/LabWork_6/Task_2/file/lab6_3.txt";
static const QString pathToBinStruct
    = "/home/vlad/labs/LabWork_6/Task_2/file/lab6_4.bin";
static const QString pathToListSentences
    = "/home/vlad/labs/LabWork_6/Task_2/file/lab6_5.txt";

class FileInputOutput
{
public:
    static void writeToFile(const QString &fileName, const QString &text);
    static QString readFromFile(const QString &fileName);

    static void writeArrayToFile(const QString &fileName, const QVector<float> &arr);
    static QString readArrayFromFile(const QString &fileName);

    static void writeStructToTxtFile(const QString &fileName, const Plant &plant);
    static QVector<Plant> readStructFromTxtFile(const QString &fileName);

    static void writeStructToBinFile(const QString &fileName, const Plant &plant);
    static QVector<Plant> readStructFromBinFile(const QString &fileName);

    static void appendSentenceToFile(const QString &fileName, const QString &text);
};

#endif // FILEINPUTOUTPUT_H
