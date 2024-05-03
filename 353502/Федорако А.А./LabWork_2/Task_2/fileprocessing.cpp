#include "fileprocessing.h"
#include <QDebug>
#include <iostream>
#include <QString>


FileProcessing::FileProcessing()
{

}

bool FileProcessing::setFilePath() {

    isFileOpen = false;

    filePath = QFileDialog::getOpenFileName();

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    else {
        QFileInfo check_file(filePath);
        if (check_file.suffix() == "txt") {
            isFileOpen = true;
            setArrTrainTrip();
            if(isNumberRepeated() == false) return false;
        }
        else {
           return false;
        }
    }
    return true;
}

bool FileProcessing::isNumberRepeated() {
    std::vector<QString> arrNumber(arrTrainTrip.size());
    for (unsigned long i = 0; i < arrTrainTrip.size(); i++) {
        arrNumber[i] = arrTrainTrip[i]->getFlightNumber();
    }

    std::sort(arrNumber.begin(), arrNumber.end());
    for (unsigned long i = 1; i < arrNumber.size() ;i++) {
        if(arrNumber[i] == arrNumber[i - 1]) return false;
    }
    qDebug() << "true";
    return true;
}


bool FileProcessing::isNewNumberRepeated(QString newFlightNumber) {
    for (unsigned long i = 0; i < arrTrainTrip.size(); i++) {
        if(newFlightNumber == arrTrainTrip[i]->getFlightNumber()) return false;
    }
    return true;
}

void FileProcessing::setArrTrainTrip() {
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
          QTextStream in(&file);
          while(!in.atEnd()) {
            TrainTrip* newTrainTrip = new TrainTrip();
            newTrainTrip->setFlightNumber(in.readLine());
            newTrainTrip->setTimeDeparture(QDateTime::fromString(in.readLine(),"dd-MM-yyyy HH:mm"));
            newTrainTrip->setTimeArrival(QDateTime::fromString(in.readLine(), "dd-MM-yyyy HH:mm"));
            newTrainTrip->setFinalDestination(in.readLine());
            newTrainTrip->setNumberOfCompartmentsSeats(in.readLine().toInt());
            newTrainTrip->setNumberOfReservedSeats(in.readLine().toInt());
            newTrainTrip->setNumberOfFreeCompartmentsSeats(in.readLine().toInt());
            newTrainTrip->setNumberOfFreeReservedSeats(in.readLine().toInt());
            arrTrainTrip.push_back(newTrainTrip);
            in.readLine();
          }
    }
}

QString FileProcessing::getFilePath() {
    return filePath;
}


bool FileProcessing::getIsFileOpen() {
    return isFileOpen;
}


QString FileProcessing::getInformationAboutOneTrip(TrainTrip* someTrainTrip) {
    QString textInformation;
    textInformation += "Номер рейса: " + someTrainTrip->getFlightNumber() + '\n';
    textInformation += "Дата и время отправления: " + (someTrainTrip->getTimeDeparture()).toString("dd-MM-yyyy HH:mm") + '\n';
    textInformation += "Дата и время прибытия: " + (someTrainTrip->getTimeArrival()).toString("dd-MM-yyyy HH:mm") + '\n';
    textInformation += "Конечный пункт: " + (someTrainTrip->getFinalDestination()) + '\n';
    textInformation += "Число купейных мест: " + QString::number(someTrainTrip->getNumberOfCompartmentSeats()) + '\n';
    textInformation += "Число плацкартных мест: " + QString::number(someTrainTrip->getNumberOfReservedSeats()) + '\n';
    textInformation += "Число свободных купейных мест: " + QString::number(someTrainTrip->getNumberOfFreeCompartmentSeats()) + '\n';
    textInformation += "Число свободных плацкартных мест: " + QString::number(someTrainTrip->getNumberOfFreeReservedSeats()) + "\n\n";
    return textInformation;
}

bool FileProcessing::isLineQDateTimeCorrect(QString line) {
    if(line[NumberFirstCoordinate].isDigit() && line[NumberSecondCoordinate].isDigit() && line[NumberThirdCoordinate] == '-' && line[NumberForthCoordinate].isDigit() && line[NumberFifthCoordinate].isDigit() && line[NumberSixthCoordinate] == '-' && line[NumberSeventhCoordinate].isDigit() && line[NumberEighthCoordinate].isDigit()&& line[NumberNinthCoordinate].isDigit()&& line[NumberTenthCoordinate].isDigit()&& line[NumberEleventCoordinate] == ' ' && line[NumberTwelvsCoordinate].isDigit() && line[NumberThirdsCoordinate].isDigit() && line[NumberForthCoordinate] == ':' && line[NumberFifteenCoordinate].isDigit()&& line[NumbeSixteenCoordinate].isDigit()) {
        return true;
    }
    else {
      return false;
    }
}


bool FileProcessing::isLineIntegerCorrect(QString line) {
    for(int i = 0; i < line.size(); i++) {
        if(line[i].isDigit() == false) {
           return false;
        }
    }
    return true;
}

bool FileProcessing::checkFlightNumberCorrect(QString line) {
    int ptrToCheck = 0;
    bool isDigit = false;
    bool isLetter = false;
    while(ptrToCheck < line.size() && line[ptrToCheck].isDigit() == 1) {
        ptrToCheck++;
        isDigit = true;
    }
    while(ptrToCheck < line.size() && (line[ptrToCheck] >= 'a' && line[ptrToCheck] <= 'z')) {
        ptrToCheck++;
        isLetter = true;
    }
    return (ptrToCheck == line.size() && isLetter && isDigit);
}

bool FileProcessing::checkIsCorrectFile() {
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
          QTextStream in(&file);
          while(!in.atEnd()) {
            QString flightNumber = in.readLine();
            if(checkFlightNumberCorrect(flightNumber) == false) {
                return false;
            }

            QString timeDeparture = in.readLine();
            if(isLineQDateTimeCorrect(timeDeparture) == false){
                return false;
            }

            QString timeArrival = in.readLine();
            if(isLineQDateTimeCorrect(timeArrival) == false) {
                return false;
            }

            QString finalDestination = in.readLine();
            QString numberOfCompartmentsSeats = in.readLine();
            QString numberOfReservedSeats = in.readLine();
            QString numberOfFreeCompartmentsSeats = in.readLine();
            QString numberOfFreeReservedSeats = in.readLine();

            in.readLine();

          }

          return true;
    }
    return false;
}

QString FileProcessing::getTextInformation() {
    QString textInformation;
        if(isSearchDate == 1 && isSearchFinalDestination == 1) {
            for(unsigned long i = 0; i < arrTrainTrip.size(); i++) {
                if(((arrTrainTrip[i]->getTimeDeparture()).date() == searchDate) && (arrTrainTrip[i]->getFinalDestination() == searchFinalDestination)) {
                    textInformation += getInformationAboutOneTrip(arrTrainTrip[i]);
                }
            }
        }
        else if(isSearchDate == 1) {
            for (unsigned long i = 0; i < arrTrainTrip.size(); i++) {
                if((arrTrainTrip[i]->getTimeDeparture()).date() == searchDate) {
                    textInformation += getInformationAboutOneTrip(arrTrainTrip[i]);
                }
            }
        }
        else if(isSearchFinalDestination== 1) {
            for (unsigned long i = 0; i < arrTrainTrip.size(); i++) {
                if(arrTrainTrip[i]->getFinalDestination() == searchFinalDestination) {
                    textInformation += getInformationAboutOneTrip(arrTrainTrip[i]);
                }
            }
        }
        else {
            for (int i = 0; i < arrTrainTrip.size();i++) {
                textInformation += getInformationAboutOneTrip(arrTrainTrip[i]);
            }
        }
    return textInformation;
}

void FileProcessing::setSearchFinalDestination(QString newSearchFinalDestination) {
    searchFinalDestination = newSearchFinalDestination;
    isSearchFinalDestination = true;
}

void FileProcessing::setSearchDate(QDate newSearchDate) {
    searchDate = newSearchDate;
    isSearchDate = true;
}

QString FileProcessing::getAllFile() {
    QString textInformation = "";
    for(unsigned long i = 0; i < arrTrainTrip.size(); i++) {
        textInformation += arrTrainTrip[i]->getFlightNumber() + '\n';
        textInformation += (arrTrainTrip[i]->getTimeDeparture()).toString("dd-MM-yyyy HH:mm") + '\n';
        textInformation += (arrTrainTrip[i]->getTimeArrival()).toString("dd-MM-yyyy HH:mm") + '\n';
        textInformation += (arrTrainTrip[i]->getFinalDestination()) + '\n';
        textInformation += QString::number(arrTrainTrip[i]->getNumberOfCompartmentSeats()) + '\n';
        textInformation += QString::number(arrTrainTrip[i]->getNumberOfReservedSeats()) + '\n';
        textInformation += QString::number(arrTrainTrip[i]->getNumberOfFreeCompartmentSeats()) + '\n';
        textInformation += QString::number(arrTrainTrip[i]->getNumberOfFreeReservedSeats()) + "\n\n";
    }
    return textInformation;
}

void FileProcessing::saveFileAtFinishWork() {
    QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QTextStream out(&file);
            out << getAllFile();
            closeFile();
            file.close();
        }
}

void FileProcessing::closeFile() {
    isSearchDate = false;
    searchFinalDestination = "";
    isSearchFinalDestination = false;
    arrTrainTrip.clear();
    filePath = "";
    isFileOpen = false;
}

void FileProcessing::setCanselAllSearchInformation() {
    isSearchDate = false;
    isSearchFinalDestination = false;
}

bool FileProcessing::deleteTrainTrip(QString deleteFlightNumber) {
    for (unsigned long i = 0; i < arrTrainTrip.size(); i++) {
        if(arrTrainTrip[i]->getFlightNumber() == deleteFlightNumber) {
            arrTrainTrip.erase(arrTrainTrip.begin() + i);
            return true;
            break;
        }
    }
    return false;
}

int FileProcessing::addNewTrainTrip(QString flightNumber, QDateTime timeDeparture, QDateTime timeArrival,
                                    QString finalDestination, int numberOfCompartmentsSeats, int numberOfReservedSeats,
                                    int numberOfFreeCompartmentsSeats, int numberOfFreeReservedSeats) {

    TrainTrip* newTrainTrip = new TrainTrip();
    newTrainTrip->setFlightNumber(flightNumber);
    newTrainTrip->setTimeDeparture(timeDeparture);
    newTrainTrip->setTimeArrival(timeArrival);
    newTrainTrip->setFinalDestination(finalDestination);
    newTrainTrip->setNumberOfCompartmentsSeats(numberOfCompartmentsSeats);
    newTrainTrip->setNumberOfReservedSeats(numberOfReservedSeats);
    newTrainTrip->setNumberOfFreeCompartmentsSeats(numberOfFreeCompartmentsSeats);
    newTrainTrip->setNumberOfFreeReservedSeats(numberOfFreeReservedSeats);

    if(checkFlightNumberCorrect(flightNumber) == false) return -1;
    else if(checkDatesCorrect(timeDeparture, timeArrival) == false) return -2;
    else if(checkFinalDestinationCorrect(finalDestination) == false) return -3;
    else if((numberOfCompartmentsSeats || numberOfReservedSeats) == false) return -4;
    else if(isNewNumberRepeated(flightNumber) == false) return -5;
    else {
    bool isTrainTripAddOrChange = false;
    for (unsigned long i = 0; i < arrTrainTrip.size() && !isTrainTripAddOrChange; i++) {
        if(newTrainTrip->getFlightNumber() == arrTrainTrip[i]->getFlightNumber()) {
            arrTrainTrip[i] = newTrainTrip;
            isTrainTripAddOrChange = true;
            break;
        }
    }
    if(isTrainTripAddOrChange == true) {
        return 1;
    }
    else {
        arrTrainTrip.push_back(newTrainTrip);
        return 2;
    }
    }
}

bool FileProcessing::checkDatesCorrect(QDateTime timeDeparture, QDateTime timeArrival) {
    if(timeArrival > timeDeparture) {
        return true;
    }
    else return false;
}

bool FileProcessing::checkFinalDestinationCorrect(QString line) {
    if(line[0] >= 'A' && line[0] <= 'Z' == false) {
        return false;
    }
    for (int i = 1; i < line.size() ; i++) {
        if((line[i] >= 'a' && line[i] <= 'z') == false) {
            return false;
        }
    }

    return true;
}
