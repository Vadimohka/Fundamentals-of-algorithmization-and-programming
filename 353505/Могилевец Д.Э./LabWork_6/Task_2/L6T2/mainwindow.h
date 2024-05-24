#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QEventLoop>
#include <QMainWindow>
#include <QTimer>
#include<QMessageBox>
#include <fstream>
#include <string>
#include "qscrollarea.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    const std::string surname = "МогилевецЛаб20";
    const std::string paragraphFile = surname + ".txt";
    const std::string arrayFile = surname + "_0.txt";
    const std::string structFile = surname + "_1.txt";
    const std::string binaryFile = surname + "_2.bin";
    const std::string sentenceFile = surname + "_3.txt";

    QString input();
    void print(QString);

    void printMenu();

    void writeParagraphToFile(const std::string& filename);
    void readAndPrintParagraphFromFile(const std::string& filename);
    void writeArrayToFile(const std::string& filename, char delimiter);
    void readAndPrintArrayFromFile(const std::string& filename, char delimiter);
    void writeStructToFile(const std::string& filename);
    void readAndPrintStructsFromFile(const std::string& filename);
    void writeSentenceToFile(const std::string& filename);
    void readAndPrintSentencesFromFile(const std::string& filename);

    void saveShipToBinaryFile(const std::string& filename);
    void printShipsFromBinaryFile(const std::string& filename);

    Ui::MainWindow *ui;

    QEventLoop loop;
    QScrollArea *scrollArea;
};
#endif // MAINWINDOW_H
