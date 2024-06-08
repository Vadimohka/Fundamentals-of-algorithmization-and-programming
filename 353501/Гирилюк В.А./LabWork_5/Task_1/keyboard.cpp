#include "keyboard.h"

Keyboard::Keyboard()
    : keyboards(new QString[8])
{
    keyboards[bel] = "ё1234567890-=йцукенгшўзх\'\\фывапролджэячсмітьбю.";
    keyboards[arab] = "ذ1234567890-=ضصثقفغعهخحجد\\شسيبلاتنمكطئءؤرلاىةوزظ";
    keyboards[ger] = "^1234567890ß´qwertzuiopü+#asdfghjklöäyxcvbnm,.-";
    keyboards[fre] = "²&é\"'(-è_çà)=azertyuiop^$*qsdfghjklmùwxcvbn,;:!";
    keyboards[chin] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    keyboards[heb] = ";1234567890-=/'קראטוןםפ][\\שדגכעיחלךף,זסבהנמצתץ.";
    keyboards[ru] = "ё1234567890-=йцукенгшщзхъ\\фывапролджэячсмитьбю.";
    keyboards[eng] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";

    initKeys();
    initKeboard(ru);
    currLanguage = ru;
}

void Keyboard::initKeboard(int lan)
{
    clearText();
    currLanguage = lan;
    QString temp = keyboards[lan];

    for (int i = 0; i < 13; i++) {
        setTextToKey(topKeys[i], QString(temp[0]));
        temp.remove(0, 1);
    }
    setTextToKey(topKeys.last(), "<--Backspace");

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
    setTextToKey(bottomKeys[11], "Space");
}

void Keyboard::initKeys()
{
    int curPosY = 10, curPosX = 10;
    QPen pen(Qt::black);
    pen.setWidth(2);

    topKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, LEFT_WIDTH, HEIGHT));
    curPosX += LEFT_WIDTH + MARGIN;
    for (int i = 0; i < 12; i++) {
        topKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, BASE_WIDTH, HEIGHT));
        curPosX += BASE_WIDTH + MARGIN;
    }
    topKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, BACKSPACE_WIDTH, HEIGHT));

    curPosX = 10;
    curPosY += HEIGHT + MARGIN;
    topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, TAB_WIDTH, HEIGHT));
    curPosX += TAB_WIDTH + MARGIN;
    for (int i = 0; i < 12; i++) {
        topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, BASE_WIDTH, HEIGHT));
        curPosX += BASE_WIDTH + MARGIN;
    }
    topMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, RIGHT_WIDTH, HEIGHT));

    curPosX = 10;
    curPosY += HEIGHT + MARGIN;
    bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, CAPSLOCK_WIDTH, HEIGHT));
    curPosX += CAPSLOCK_WIDTH + MARGIN;
    for (int i = 0; i < 11; i++) {
        bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, BASE_WIDTH, HEIGHT));
        curPosX += BASE_WIDTH + MARGIN;
    }
    bottomMidKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, ENTER_WIDTH, HEIGHT));

    curPosX = 10;
    curPosY += HEIGHT + MARGIN;
    bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, LEFT_SHIFT_WIDTH, HEIGHT));
    curPosX += LEFT_SHIFT_WIDTH + MARGIN;
    for (int i = 0; i < 10; i++) {
        bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, BASE_WIDTH, HEIGHT));
        curPosX += BASE_WIDTH + MARGIN;
    }

    curPosY += HEIGHT + MARGIN;
    curPosX = SPACE_WIDTH;
    bottomKeys.push_back(new QGraphicsRectItem(curPosX, curPosY, SPACE_WIDTH, HEIGHT));

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
    QGraphicsTextItem *item = addText(text, QFont("Arial", MARGIN, 10));
    item->setPos(butt->boundingRect().x() + MARGIN, butt->boundingRect().y() + HEIGHT / 3.0f);
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
    letter = letter.toLower();
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
    } else if (letter == " ") {
        return bottomKeys.last();
    }
    return nullptr;
}

void Keyboard::hightlight(QKeyEvent *e)
{
    QBrush brush(Qt::gray);
    if(e->key() == Qt::Key_Shift){
        bottomKeys.at(0)->setBrush(brush);
    }
    else if(e->key() == Qt::Key_Space){
        bottomKeys.last()->setBrush(brush);
    }
    else if(e->key() == Qt::Key_CapsLock){
        bottomMidKeys.at(0)->setBrush(brush);
    }
    else if(e->key() == Qt::Key_Backspace){
        topKeys.last()->setBrush(brush);
    }
    else if(e->key() == Qt::Key_Return){
        bottomMidKeys.last()->setBrush(brush);
    }
    else if(QGraphicsRectItem *lastKey = find(e->text())){
        if (lastKey != nullptr) {
            lastKey->setBrush(brush);
        }
    }
    else if(e->key() == Qt::Key_Tab){
        topMidKeys.at(0)->setBrush(brush);
    }
    update();
}

void Keyboard::antiHighlight()
{
    QBrush brush(Qt::black);
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
