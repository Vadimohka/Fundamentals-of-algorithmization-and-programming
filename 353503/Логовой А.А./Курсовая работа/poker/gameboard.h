#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include<QDialog>
#include<cards.h>
#include<QVector>
#include<QGraphicsPixmapItem>
#include<menu.h>
#include<dealer.h>

namespace Ui {
class GameBoard;
}

class GameBoard : public QDialog
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);

    ~GameBoard();

private:

    void openMenu();

    Menu *_menu;



    QVector<BotPlayer> _bots;
    Ui::GameBoard *ui;
};

#endif // GAMEBOARD_H
