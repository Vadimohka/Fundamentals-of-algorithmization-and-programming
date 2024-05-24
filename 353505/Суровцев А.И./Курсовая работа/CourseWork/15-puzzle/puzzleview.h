#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QGridLayout>
#include <QObject>
#include <QGridLayout>
#include <QGraphicsView>
#include <QPropertyAnimation>
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#include <QDir>
#include <QTimer>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <random>
#include <algorithm>
#include "tile.h"
#include "client_part.h"
#include "timsort.h"

class PuzzleView : public QWidget
{
    Q_OBJECT

public:
    explicit PuzzleView(QWidget *parent = nullptr);
    ~PuzzleView();
    void SetPuzzleView(QGridLayout* grid, QGraphicsView* view, long long field_size);
    void setClient(Client_Part *client, QString nickname);
    void setLabel(QLabel* label);
    void setSolving(bool isSolv);
    void setButtons(QPushButton* back, QPushButton* gen);
    bool getSolving();
    void generateInitialPuzzle();
    void generateInitialPicturePuzzle();
    void moveTile(Tile* tile, int row, int column);
    bool isMovebleLeft(int index);
    bool isMovebleRight(int index);
    bool isMovebleUp(int index);
    bool isMovebleDown(int index);
    void move(Tile* tile);
    void fisherYatesShuffle(QVector<int> &array);
    void shuffleTiles();
    bool isSolvable();
    bool checkSolved();
    void appendAttemptsToFile(int count_of_attempts);
    void readResultsFromFile();
    void showBestResults();
    void getListOfPictures();
    QVector<Tile*> get_buttons();
    void genInit();
    void removeWidgetAt(int row, int column);
    long long get_count_of_attempts();
    void solve(QVector<int> shifts);
private:
    QGridLayout* _grid;
    QGraphicsView* _view;
    long long _field_size;
    long long _cnt_tiles;
    QVector<Tile*> _buttons;
    QLabel* _label;
    QPushButton* _back;
    QPushButton* _gen;
    long long count_of_attempts = 0;
    QVector <long long> results;
    bool isPicture = false;
    QVector<QString> pictureList;
    Client_Part *_client = nullptr;
    QString _nickname;
    bool currSolving = false;
    bool isSolving = false;
};

#endif // PUZZLEVIEW_H
