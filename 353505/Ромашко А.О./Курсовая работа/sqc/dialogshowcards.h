#ifndef DIALOGSHOWCARDS_H
#define DIALOGSHOWCARDS_H

#include <QDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include "bittonsort.h"

namespace Ui {
class DialogShowCards;
}

class DialogShowCards : public QDialog
{
    Q_OBJECT

public:
    explicit DialogShowCards(QWidget *parent = nullptr);
    ~DialogShowCards();
    void getPlayerAndDeck(Player *p);

    void enableCardsActivity();
private slots:
    void on_pushButton_HP_clicked();

    void on_pushButton_Energy_clicked();

    void on_pushButton_Attack_clicked();
public slots:
    void open();

private:
    Ui::DialogShowCards *ui;
    Player *player;
    QVector <Card*> deck;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    void paintElements(int num);
    void removeElements();
    QVector <int> energyCost;
    QVector <int> HP;
    QVector <int> Attack;
};

#endif // DIALOGSHOWCARDS_H
