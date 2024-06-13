#ifndef QGAMEBOARD_H
#define QGAMEBOARD_H

#include "observer.h"
#include "qgameoverwindow.h"

#include <QWidget>
#include <QVector>



class QResetButton;
class Game;
class QKeyEvent;
class QBrick;
class QGridLayout;
class QVBoxLayout;
class QLabel;

class QGameBoard : public QWidget, public Observer
{
    Q_OBJECT
public:
    explicit QGameBoard(QWidget *parent = 0);
    ~QGameBoard();

    void notify();

signals:

public slots:
    void resetGame();

private:
    Game *game;
    QVector<QVector<QBrick*> > gui_board;
    QVBoxLayout *mainLayout;
    QGridLayout *boardLayout;
    QLabel *scoreLabel;
    qGameOverWindow gameOverWindow;
    QLabel *winLabel;

    void drawBoard();

protected:
    void keyPressEvent(QKeyEvent *event);

};


#endif // QGAMEBOARD_H
