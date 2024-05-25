//
// Created by zgdarya on 4/27/24.
//

#ifndef NONOGRAM_PICTURESERVICE_H
#define NONOGRAM_PICTURESERVICE_H


#include <QWidget>
#include <QTableWidget>
#include <QImage>
#include <QFileDialog>
#include <QTimer>
#include <QTime>
#include <QColor>
#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QDebug>

#include <fstream>
#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
#include <unordered_map>

const long WHITE_NUMBER = 4294967295;
const int MAX_SIZE = 40;
const int TIMER_INTERVAL = 5000;
const QString USER_DATA_PATH = "../Score.txt";


QT_BEGIN_NAMESPACE
namespace Ui { class PictureService; }
QT_END_NAMESPACE

class PictureService : public QWidget {
Q_OBJECT

public:
    explicit PictureService(QWidget *parent = nullptr);

    ~PictureService() override;

    void createNonogram(QImage image);

    QTableWidget nonogram;

private:
    Ui::PictureService *ui;

    int _matrix40[MAX_SIZE][MAX_SIZE];
    int _coloredCellsRow[MAX_SIZE]{0};
    int _coloredCellsColumns[MAX_SIZE]{0};
    int _filledCellsRow[MAX_SIZE]{0};
    int _filledCellsColumn[MAX_SIZE]{0};
    int _coloredCells;
    int _filledCells;
    int _mistakes;
    int _seconds;
    int _gameScore;
    int _profileScore;
    double _gameComplexity;
    QImage _image;
    QSize _size;
    QTimer *_timer;
    QTimer *_successMessageTimer;
    QWidget *_gameOver;
    QWidget *_nonogramSolved;
    QPushButton *ok_button;
    QPushButton *yep_button;
    QLineEdit *_singleSolution_lineEdit;
    QLineEdit *_gameComplexity_lineEdit;
    std::ifstream input;
    std::ofstream output; //write
    QString _scoreFile = USER_DATA_PATH;

    void calculateGameScore();

    void calculateProfileScore();

    void calculateGameComplexity();

    std::vector<std::bitset<MAX_SIZE>> imageToNonogram(const QImage& image, int upBoard, int downBoard, int leftBoard, int rightBoard);

    std::vector<std::bitset<MAX_SIZE>> countGroups(const std::bitset<MAX_SIZE>& row);

    bool isUniqueSolution(const std::vector<std::bitset<MAX_SIZE>>& nonogram);

private slots:

    void on_nonogram_cellClicked(int row, int column);

    void showTime();

    void on_ok_button_clicked();

    void showSuccessMessage();
};


#endif //NONOGRAM_PICTURESERVICE_H
