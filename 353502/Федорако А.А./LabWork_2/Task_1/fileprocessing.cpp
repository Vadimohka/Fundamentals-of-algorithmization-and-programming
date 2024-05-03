#include "fileprocessing.h"

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
        if (check_file.suffix() == "txt" && checkFileIsCorrect() == true) {
            isFileOpen = true;
setArrStrDate();
        }
        else {
           return false;
        }
    }
    return true;
}

void FileProcessing::setArrStrDate() {
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
          QTextStream in(&file);
          while(!in.atEnd()) {
             arrStrDate.push_back(in.readLine());
          }
    }
}

bool FileProcessing::checkFileIsCorrect() {
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly)) {
          QTextStream in(&file);
          while(!in.atEnd()) {
              if(isCorrectLine(in.readLine()) == false) {
                  return false;
              }
          }
          return true;

    }
    return false;
}

bool FileProcessing::isCorrectLine(QString line) {
    if(line.size() != CorrectSizeLine) {
        return false;
    }
    else {
        for(int i = 0; i < line.size(); i++)  {
            if(i == NumberCoordinateOfSpaceFirst || i == NumberCoordinateOfSpaceSecond) {
                if(line[i] != '.') {
                    return false;
                }
            }
            else {
                if(line[i].isDigit() == false) {
                    return false;
                }
            }
        }
        return true;
    }
}

bool FileProcessing::getIsFileOpen() {
    return isFileOpen;
}

void FileProcessing::closeFile() {
    filePath = "";
    isFileOpen = false;
    arrStrDate.clear();
}

void FileProcessing::saveFileAtFinishWork() {
    QFile file(filePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text))
        {

            QTextStream out(&file);
            out << getAllFile();
            closeFile();
            arrStrDate.clear();
            file.close();
        }
}

QString FileProcessing::getAllFile() {
    QString res = "";
    for(int i = 0; i < (int)arrStrDate.size(); i++) {
        res += arrStrDate[i] + '\n';
    }
    return res;
}
