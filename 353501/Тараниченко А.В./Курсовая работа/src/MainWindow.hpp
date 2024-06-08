#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

// qt
#include <QMainWindow>
#include <QMessageBox>
#include <QGraphicsView>
#include <QTimer>

// std
#include <vector>

// connected four
#include "common.hpp"
#include "PlayerMenu.hpp"
#include "GameSquare.hpp"
#include "Disc.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    /*
     *
     *
     */

    Q_OBJECT

protected:
    // ui 
    Ui::MainWindow *ui_;
    enum FieldType {Player1, Player2, Empty};
    enum Winner {Nobody, Player1Wins, Player2Wins};

    FieldType gameField[GAME_BOARD_WIDTH][GAME_BOARD_HEIGHT];

    QString player1Name_;
    QString player2Name_;
    QColor player1Color_;
    QColor player2Color_;
    QPixmap player1Pixmap_;
    QPixmap player2Pixmap_;
    QPixmap transparentPixmap_;
    bool gameStarted_;
    bool player1Turn_;
    bool gameFinished_;
    QGraphicsScene *scene_;
    std::vector<QTimer*> timers_;

protected:
    void initGameField();
    void resetGameField();

    void startGame();
    void makeMove(int x);
    void finishGame();

    void changePlayerTurn();
    void setPlayerLabels();
    void setGameFinish();

    bool isGameFinished();
    int checkWhoWins();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNewGame_triggered();
    void on_actionGameHelp_triggered();
    void on_actionAbout_triggered();
    void on_actionContact_triggered();

    void gameFieldClickedPosition(int x);
    void animationHaveFinish();

};

#endif // MAINWINDOW_HPP
