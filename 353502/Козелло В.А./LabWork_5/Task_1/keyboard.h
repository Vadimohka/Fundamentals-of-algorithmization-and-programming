#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include "constants.h"

class Keyboard : public QGraphicsScene
{
    Q_OBJECT
public:
    Keyboard();
    void initKeboard(int lan);
    void hightlight(QString letter);
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
