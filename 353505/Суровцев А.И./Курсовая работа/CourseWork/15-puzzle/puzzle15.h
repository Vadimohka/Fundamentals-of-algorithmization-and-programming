#ifndef PUZZLE15_H
#define PUZZLE15_H

#include <QWidget>
#include <QMainWindow>
#include <QTimer>
#include <QGridLayout>
#include <QApplication>
#include <QGraphicsScene>
#include <QPropertyAnimation>
#include <random>
#include "tile.h"
#include "puzzleview.h"
#include "datainput.h"
#include "client_part.h"
#include <QtConcurrent/QtConcurrent>
#include "puzzlesolver.h"
#include "chain15.h"

namespace Ui {
class Puzzle15;
}

class Puzzle15 : public QWidget
{
    Q_OBJECT

public:
    explicit Puzzle15(int size, QMainWindow *mainWindow, Client_Part *client, QString nick, QWidget *parent = nullptr);
    ~Puzzle15();

private slots:
    void on_bnt_generation_clicked();

    void on_bnt_get_my_result_clicked();

    void on_bnt_servr_result_clicked();

    void handleServerResponse(const QByteArray& data);

    void on_bnt_goBackToMainMenu_clicked();

    void on_bnt_close_clicked();

    void on_bnt_solve_clicked();

    void handleSolution(const Chain15 &result);

private:
    Ui::Puzzle15 *ui;
    QGridLayout* _grid;
    QMainWindow* _mainWindow;
    QVector<Tile*> _buttons;
    PuzzleView *pv;
    int _fieldSize;
    QTimer *timer;
    DataInput *dataInput;
    Client_Part* _client;
    QString nickname;
    PuzzleSolver _solver;
    QVector<QVector<int>> solver_matrix;
    QVector<int> solver_shifts;
    bool isSolving = false;
};

#endif // PUZZLE15_H
