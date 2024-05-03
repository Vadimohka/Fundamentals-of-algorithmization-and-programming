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
#include "traintrip.h"
#include "vector"

class FileProcessing
{
public:
    FileProcessing();
    bool setFilePath();
    QString getFilePath();
    bool getIsFileOpen();
    QString getAllFile();
    void setArrTrainTrip();
    QString getTextInformation();
    void saveFileAtFinishWork();
    void setSearchDate(QDate newSearchDateTime);
    void setSearchFinalDestination(QString newSearchFinalDestination);
    void closeFile();
    void setCanselAllSearchInformation();
    bool deleteTrainTrip(QString deleteFlightNumber);
    int addNewTrainTrip(QString flightNumber, QDateTime timeDeparture, QDateTime timeArrival, QString finalDestination, int numberOfCompartmentsSeats, int numberOfReservedSeats, int numberOfFreeCompartmentsSeats, int numberOfFreeReservedSeats);
    bool checkIsCorrectFile();
private:
    bool isNumberRepeated();
    bool isNewNumberRepeated(QString newFlightNumber);
    QString getInformationAboutOneTrip(TrainTrip* someTrainTrip);
    QDate searchDate;
    bool isLineQDateTimeCorrect(QString line);
    bool isLineIntegerCorrect(QString line);
    bool checkFlightNumberCorrect(QString line);
    bool checkFinalDestinationCorrect(QString line);
    bool checkDatesCorrect(QDateTime timeDeparture, QDateTime timeArrival);
    bool isSearchDate = false;
    QString searchFinalDestination;
    bool isSearchFinalDestination = false;
    std::vector<TrainTrip*> arrTrainTrip = std::vector<TrainTrip*> (0);
    QString filePath;
    bool isFileOpen;
    int const NumberFirstCoordinate = 0;
    int const NumberSecondCoordinate = 1;
    int const NumberThirdCoordinate = 2;
    int const NumberForthCoordinate = 3;
    int const NumberFifthCoordinate = 4;
    int const NumberSixthCoordinate = 5;
    int const NumberSeventhCoordinate = 6;
    int const NumberEighthCoordinate = 7;
    int const NumberNinthCoordinate = 8;
    int const NumberTenthCoordinate = 9;
    int const NumberEleventCoordinate = 10;
    int const NumberTwelvsCoordinate = 11;
    int const NumberThirdsCoordinate = 12;
    int const NumberFourteenCoordinate = 13;
    int const NumberFifteenCoordinate = 14;
    int const NumbeSixteenCoordinate = 15;

};

#endif // FILEPROCESSING_H
