#include "TTKeyboard.h"
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QTimer>
#include <qnamespace.h>
#include <qtextoption.h>
#include <qtransform.h>

TTKeyboard::TTKeyboard(QWidget* par) :  QGraphicsView(par) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    keyItems.resize(KEYS_SZ);
    textItems.resize(KEYS_SZ);
    for(int i = 0; i < KEYS_SZ; ++i){
        keyItems[i] = nullptr;
        textItems[i] = nullptr;
    }
    scale(0.8, 0.8);
}

TTKeyboard::~TTKeyboard() {
    delete scene;    
}

void TTKeyboard::showEvent(QShowEvent*) {
    drawKeys();   
}

void TTKeyboard::drawKeys() {

    auto keyAndSpanWidth = width() / (KEYS_IN_RAW[0]-1);
    auto span = keyAndSpanWidth * 0.2;
    auto halfSpan = span/2;
    auto keyWidth = keyAndSpanWidth - span;
    auto keyAndSpanH = height() / ROWS;
    auto keyHeight = keyAndSpanH - span;

    float x = halfSpan;
    float y = halfSpan;
    int row = 0, key = 0;
    for(int i = 0; i < KEYS_SZ; ++i, ++key) {
        
        if(key == KEYS_IN_RAW[row]){
            x = halfSpan + (row+1)*(keyWidth/2);
            y += keyHeight + span;
            ++row;
            key = 0;
        }


        QPainterPath roundedRect;
        roundedRect.addRoundedRect(x, y, keyWidth, keyHeight, 10,10);

        if(keyItems[i]){
            scene->removeItem(keyItems[i]);
        }
        keyItems[i] = new QGraphicsPathItem(roundedRect);
        keyItems[i]->setBrush(Qt::white);
        scene->addItem(keyItems[i]);

        if(textItems[i]){
            scene->removeItem(textItems[i]);
        }
        textItems[i] = new QGraphicsTextItem(kboardChars[i]);
        textItems[i]->setFont(QFont("Monospace", 20));
        textItems[i]->setDefaultTextColor(Qt::black);
        textItems[i]->setPos(x + keyWidth/2, y + keyHeight/2);
        scene->addItem(textItems[i]);;

        x += keyWidth + span;
    }

}

void TTKeyboard::highlightKey(int key){
    if(key >= KEYS_SZ || key < 0){
        return;
    }

    qDebug() << "index: " << key;
    keyItems[key]->setBrush(Qt::yellow);
    keyItems[key]->update();
    QTimer::singleShot(KEY_HIGHLIGHT_TIME, [=]{
        keyItems[key]->setBrush(Qt::white);
    });
}

void TTKeyboard::TTKeyboard::setKeyboardChars(const QString& new_s) {
    if(new_s.isEmpty()){
        kboardChars = defaultKboard;
    } else {
        kboardChars = new_s.split(' ');
    }
    drawKeys();
}
