#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QKeyEvent>

enum keyBoards { bel, arab, ger, fre, chin, heb, ru, eng };

const int HEIGHT = 50;
const int BASE_WIDTH = 50;
const int LEFT_WIDTH = 50;
const int TAB_WIDTH = 90;
const int CAPSLOCK_WIDTH = 110;
const int LEFT_SHIFT_WIDTH = 130;
const int BACKSPACE_WIDTH = 100;
const int RIGHT_WIDTH = 60;
const int ENTER_WIDTH = 100;
const int SPACE_WIDTH = 300;
const int MARGIN = 10;

class Keyboard : public QGraphicsScene
{
    Q_OBJECT
public:
    Keyboard();
    void initKeboard(int lan);
    void hightlight(QKeyEvent *e);
    void antiHighlight();

private:
    QString *keyboards;
    QVector<QGraphicsRectItem *> topKeys;
    QVector<QGraphicsRectItem *> topMidKeys;
    QVector<QGraphicsRectItem *> bottomMidKeys;
    QVector<QGraphicsRectItem *> bottomKeys;
    QVector<QGraphicsTextItem *> textItems;
    int currLanguage;

    void initKeys();
    void setTextToKey(QGraphicsRectItem *, QString);
    void clearText();
    QGraphicsRectItem *find(QString letter);
};

#endif // KEYBOARD_H
