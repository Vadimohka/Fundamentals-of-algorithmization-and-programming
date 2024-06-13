#include "keyboard.h"

Keyboard::Keyboard()
    : keyboards(new QString[7])
{
    keyboards[eng] = "^1234567890ß´qwertyuiopü+#asdfghjklöäzxcvbnm,.-";
    keyboards[arab] = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوزظ";
    keyboards[ger] = "^1234567890ß´qwertzuiopü+#asdfghjklöäyxcvbnm,.-";
    keyboards[fre] = "²&é\"'(-è_çà)=azertyuiop^$*qsdfghjklmùwxcvbn,;:!";
    keyboards[chin] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    keyboards[heb] = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ.";
    keyboards[ru] = "ё1234567890-=йцукенгшщзхъ\\фывапролджэячсмитьбю.";

    initKeys();
    initKeboard(eng);
    currLanguage = eng;
}

void Keyboard::initKeboard(int lan)
{
    clearText();
    currLanguage = lan;
    QString temp = keyboards[lan];

    // установка текста на верхнем ряду клавиш
    for (int i = 0; i < 13; i++) {
        setTextToKey(topKeys[i], QString(temp[0]));
        temp.remove(0, 1);
    }
    setTextToKey(topKeys.last(), "Backspace");

    setTextToKey(topMidKeys[0], "Tab");
    for (int i = 1; i <= 13; i++) {
        setTextToKey(topMidKeys[i], QString(temp[0]));
        temp.remove(0, 1);
    }

    setTextToKey(bottomMidKeys[0], "CapsLock");
    for (int i = 1; i < 12; i++) {
        setTextToKey(bottomMidKeys[i], QString(temp[0]));
        temp.remove(0, 1);
    }
    setTextToKey(bottomMidKeys.last(), "Enter");

    setTextToKey(bottomKeys[0], "Shift");
    for (int i = 1; i < 11; i++) {
        setTextToKey(bottomKeys[i], QString(temp[0]));
        temp.remove(0, 1);
    }
    setTextToKey(bottomKeys[11], "Shift");
}

void Keyboard::initKeys()
{
    int curPosY = 0, curPosX = 0;
    QPen pen(Qt::black);
    pen.setWidth(2);

    topKeys.push_back((new QGraphicsRectItem(curPosX, curPosY, KEY_LEFT_WIDTH, KEY_HEIGHT)));
    curPosX += KEY_LEFT_WIDTH + KEY_MARGIN;
    for (int i = 0; i < 12; i++) {
        topKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_BASE_WIDTH, KEY_HEIGHT));
        curPosX += KEY_BASE_WIDTH + KEY_MARGIN;
    }
    topKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_BACKSPACE_WIDTH, KEY_HEIGHT));

    curPosX = 0;
    curPosY += KEY_HEIGHT + KEY_MARGIN;
    topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_TAB_WIDTH, KEY_HEIGHT));
    curPosX += KEY_TAB_WIDTH + KEY_MARGIN;
    for (int i = 0; i < 12; i++) {
        topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_BASE_WIDTH, KEY_HEIGHT));
        curPosX += KEY_BASE_WIDTH + KEY_MARGIN;
    }
    topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_RIGHT_WIDTH, KEY_HEIGHT));

    curPosX = 0;
    curPosY += KEY_HEIGHT + KEY_MARGIN;
    bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_CAPSLOCK_WIDTH, KEY_HEIGHT));
    curPosX += KEY_CAPSLOCK_WIDTH + KEY_MARGIN;
    for (int i = 0; i < 11; i++) {
        bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_BASE_WIDTH, KEY_HEIGHT));
        curPosX += KEY_BASE_WIDTH + KEY_MARGIN;
    }
    bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_ENTER_WIDTH, KEY_HEIGHT));

    curPosX = 0;
    curPosY += KEY_HEIGHT + KEY_MARGIN;
    bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_LEFT_SHIFT_WIDTH, KEY_HEIGHT));
    curPosX += KEY_LEFT_SHIFT_WIDTH + KEY_MARGIN;
    for (int i = 0; i < 10; i++) {
        bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_BASE_WIDTH, KEY_HEIGHT));
        curPosX += KEY_BASE_WIDTH + KEY_MARGIN;
    }
    bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_RIGHT_SHIFT_WIDTH, KEY_HEIGHT));

    curPosY += KEY_HEIGHT + KEY_MARGIN;
    curPosX = KEY_SPACE_WIDTH;
    bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, KEY_SPACE_WIDTH, KEY_HEIGHT));

    for (QGraphicsRectItem *rect : topKeys) {
        rect->setPen(pen);
        addItem(rect);
    }
    for (QGraphicsRectItem *rect : topMidKeys) {
        rect->setPen(pen);
        addItem(rect);
    }
    for (QGraphicsRectItem *rect : bottomMidKeys) {
        rect->setPen(pen);
        addItem(rect);
    }
    for (QGraphicsRectItem *rect : bottomKeys) {
        rect->setPen(pen);
        addItem(rect);
    }
}

void Keyboard::setTextToKey(QGraphicsRectItem *butt, QString text)
{
    QGraphicsTextItem *item = addText(text, QFont("Arial", KEY_MARGIN, 10));
    item->setPos(butt->boundingRect().x() + KEY_MARGIN, butt->boundingRect().y() + KEY_HEIGHT / 3.0f);
    textItems.push_back(item);
}

void Keyboard::clearText()
{
    for (QGraphicsTextItem *item : textItems) {
        removeItem(item);
    }
    textItems.clear();
}

QGraphicsRectItem *Keyboard::find(QString letter)
{
    if (letter.isEmpty()) {
        return bottomKeys.last();
    }

    int index = keyboards[currLanguage].indexOf(letter);
    if (index != -1) {
        if (index <= 12) {
            return topKeys[index];
        } else if (index <= 25) {
            return topMidKeys[index - 12];
        } else if (index <= 36) {
            return bottomMidKeys[index - 25];
        } else {
            return bottomKeys[index - 36];
        }
    }
    return nullptr;
}

void Keyboard::hightlight(QString letter)
{
    QGraphicsRectItem *lastKey = find(letter);
    if (lastKey != nullptr )
    if (lastKey != nullptr && !letter.isEmpty()) {
        QBrush brush(Qt::white);
        lastKey->setBrush(brush);
        update();
    }
}

void Keyboard::antiHighlight()
{
    QBrush brush(Qt::transparent);
    for (QGraphicsRectItem *rect : topKeys) {
        rect->setBrush(brush);
    }
    for (QGraphicsRectItem *rect : topMidKeys) {
        rect->setBrush(brush);
    }
    for (QGraphicsRectItem *rect : bottomMidKeys) {
        rect->setBrush(brush);
    }
    for (QGraphicsRectItem *rect : bottomKeys) {
        rect->setBrush(brush);
    }
    update();
}
