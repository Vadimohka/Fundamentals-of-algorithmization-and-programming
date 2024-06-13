#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Keyboard : public QGraphicsScene
{
    Q_OBJECT
public:
    Keyboard();
    void initKeboard(int lan);
    void hightlight(QString letter);
    void antiHighlight();

    enum keyBoards { eng, arab, ger, fre, chin, heb, ru };

private:
    QString *keyboards;
    QVector<QGraphicsRectItem *> topKeys;
    QVector<QGraphicsRectItem *> topMidKeys;
    QVector<QGraphicsRectItem *> bottomMidKeys;
    QVector<QGraphicsRectItem *> bottomKeys;
    QVector<QGraphicsTextItem *> textItems;
    int currLanguage;

    // Constants
    static const int KEY_HEIGHT = 70;
    static const int KEY_BASE_WIDTH = 70;
    static const int KEY_LEFT_WIDTH = 50;
    static const int KEY_TAB_WIDTH = 90;
    static const int KEY_CAPSLOCK_WIDTH = 110;
    static const int KEY_LEFT_SHIFT_WIDTH = 150;
    static const int KEY_BACKSPACE_WIDTH = 170;
    static const int KEY_RIGHT_WIDTH = 130;
    static const int KEY_ENTER_WIDTH = 190;
    static const int KEY_RIGHT_SHIFT_WIDTH = 230;
    static const int KEY_SPACE_WIDTH = 400;
    static const int KEY_MARGIN = 10;

    void initKeys();
    void setTextToKey(QGraphicsRectItem *, QString);
    void clearText();
    QGraphicsRectItem *find(QString letter);
};

#endif // KEYBOARD_H


