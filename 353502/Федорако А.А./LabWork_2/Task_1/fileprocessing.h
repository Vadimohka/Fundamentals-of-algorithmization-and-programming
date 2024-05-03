#ifndef FILEPROCESSING_H
#define FILEPROCESSING_H
#include <QWidget>
#include <QFileDialog>
#include <QTextStream>
#include <QDebug>
#include <QVector>
#include <QFileDialog>
#include <QFileInfo>
#include <QDateTime>
#include <vector>
#include <QTableWidget>
#include "vector"

class FileProcessing
{
public:
    FileProcessing();
    bool setFilePath();
    bool isCorrectLine(QString line);
    bool getIsFileOpen();
    void closeFile();
    void saveFileAtFinishWork();
    std::vector<QString> arrStrDate;
private:
    int const NumberCoordinateOfSpaceFirst = 2;
    int const NumberCoordinateOfSpaceSecond = 5;
    void setArrStrDate();
    int const CorrectSizeLine = 10;
    QString getAllFile();
    bool isFileOpen = false;
    QString filePath = "";
    bool checkFileIsCorrect();
};

#endif // FILEPROCESSING_H
