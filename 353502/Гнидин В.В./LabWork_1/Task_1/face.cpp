//
// Created by volodya-petarda on 3/9/24.
//

#include "face.h"
#include <QTimer>

QRectF face::boundingRect() const {
    return {0, 0, 0, 0};
}

void face::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
}

face::face(int xPos, int yPos, QGraphicsScene *scene) {
    this->xPos = xPos;
    this->yPos = yPos;
    this->mainFace = new movingEllipse(xPos, yPos, 500, 500);
    this->leftEye = new movingEllipse(xPos + 125, yPos + 125, 75, 10);
    this->rightEye = new movingEllipse(xPos + 300, yPos + 125, 75, 10);
    this->mouth = new movingEllipse(xPos + 100, yPos + 300, 300, 30);
    scene->addItem(mainFace);
    scene->addItem(leftEye);
    scene->addItem(rightEye);
    scene->addItem(mouth);
    mainFace->setPenColor(Qt::black);
    mainFace->setBrushColor(Qt::yellow);
    leftEye->setPenColor(Qt::black);
    leftEye->setBrushColor(Qt::white);
    rightEye->setPenColor(Qt::black);
    rightEye->setBrushColor(Qt::white);
    mouth->setPenColor(Qt::black);
    mouth->setBrushColor(Qt::red);
    scaleEyes();
    auto *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(scaleEyes()));
    timer->setInterval(3000);
    timer->start();
}

void face::scaleEyes() {
    auto *mainTimer1 = new QTimer(this);
    auto *mainTimer2 = new QTimer(this);
    auto *tickTimer1 = new QTimer(this);
    auto *tickTimer2 = new QTimer(this);
    auto *tickTimer3 = new QTimer(this);
    auto *tickTimer4 = new QTimer(this);

    tickTimer1->setInterval(30);
    tickTimer2->setInterval(30);
    tickTimer3->setInterval(60);
    tickTimer4->setInterval(60);

    mainTimer1->setSingleShot(true);


    mainTimer2->setSingleShot(true);
    mainTimer1->setInterval(1500);
    mainTimer2->setInterval(3000);
    connect(tickTimer1, SIGNAL(timeout()), leftEye, SLOT(addH()));
    connect(tickTimer1, SIGNAL(timeout()), rightEye, SLOT(addH()));
    connect(tickTimer3, SIGNAL(timeout()), leftEye, SLOT(moveUp()));
    connect(tickTimer3, SIGNAL(timeout()), rightEye, SLOT(moveUp()));


    connect(tickTimer2, SIGNAL(timeout()), leftEye, SLOT(subH()));
    connect(tickTimer2, SIGNAL(timeout()), rightEye, SLOT(subH()));
    connect(tickTimer4, SIGNAL(timeout()), leftEye, SLOT(moveDown()));
    connect(tickTimer4, SIGNAL(timeout()), rightEye, SLOT(moveDown()));


    connect(mainTimer1, SIGNAL(timeout()), tickTimer1, SLOT(stop()));
    connect(mainTimer1, SIGNAL(timeout()), tickTimer3, SLOT(stop()));

    connect(mainTimer1, SIGNAL(timeout()), tickTimer2, SLOT(start()));
    connect(mainTimer2, SIGNAL(timeout()), tickTimer2, SLOT(stop()));
    connect(mainTimer1, SIGNAL(timeout()), tickTimer4, SLOT(start()));
    connect(mainTimer2, SIGNAL(timeout()), tickTimer4, SLOT(stop()));
    tickTimer3->start();
    tickTimer1->start();
    mainTimer1->start();
    mainTimer2->start();
}

void face::scaleMouth() {
    if (isMouthAnimation)
        return;
    isMouthAnimation = true;
    auto *mainTimer1 = new QTimer(this);
    auto *mainTimer2 = new QTimer(this);
    auto *tickTimer1 = new QTimer(this);
    auto *tickTimer2 = new QTimer(this);
    auto *tickTimer3 = new QTimer(this);
    auto *tickTimer4 = new QTimer(this);

    tickTimer1->setInterval(30);
    tickTimer2->setInterval(30);
    tickTimer3->setInterval(60);
    tickTimer4->setInterval(60);

    mainTimer1->setSingleShot(true);
    mainTimer2->setSingleShot(true);
    mainTimer1->setInterval(1500);
    mainTimer2->setInterval(3000);
    connect(tickTimer1, SIGNAL(timeout()), mouth, SLOT(addH()));
    connect(tickTimer3, SIGNAL(timeout()), mouth, SLOT(moveUp()));


    connect(tickTimer2, SIGNAL(timeout()), mouth, SLOT(subH()));
    connect(tickTimer4, SIGNAL(timeout()), mouth, SLOT(moveDown()));


    connect(mainTimer1, SIGNAL(timeout()), tickTimer1, SLOT(stop()));
    connect(mainTimer1, SIGNAL(timeout()), tickTimer3, SLOT(stop()));

    connect(mainTimer1, SIGNAL(timeout()), tickTimer2, SLOT(start()));
    connect(mainTimer2, SIGNAL(timeout()), tickTimer2, SLOT(stop()));
    connect(mainTimer1, SIGNAL(timeout()), tickTimer4, SLOT(start()));
    connect(mainTimer2, SIGNAL(timeout()), tickTimer4, SLOT(stop()));
    connect(mainTimer2, SIGNAL(timeout()), this, SLOT(setMouthAnimationFalse()));
    tickTimer3->start();
    tickTimer1->start();
    mainTimer1->start();
    mainTimer2->start();
}


void face::setMouthAnimationFalse() {
    this->isMouthAnimation = false;
}

void face::setEyesAnimationFalse() {
    this->isEyesAnimation = false;
}

void face::moveEyes() {
    if (isEyesAnimation)
        return;
    isEyesAnimation = true;
    auto *mainTimer1 = new QTimer(this);
    auto *mainTimer2 = new QTimer(this);
    auto *tickTimer1 = new QTimer(this);
    auto *tickTimer2 = new QTimer(this);

    tickTimer1->setInterval(50);
    tickTimer2->setInterval(50);


    mainTimer1->setSingleShot(true);
    mainTimer2->setSingleShot(true);
    mainTimer1->setInterval(1500);
    mainTimer2->setInterval(3000);
    connect(tickTimer1, SIGNAL(timeout()), leftEye, SLOT(moveLeft()));
    connect(tickTimer1, SIGNAL(timeout()), rightEye, SLOT(moveRight()));


    connect(tickTimer2, SIGNAL(timeout()), leftEye, SLOT(moveRight()));
    connect(tickTimer2, SIGNAL(timeout()), rightEye, SLOT(moveLeft()));


    connect(mainTimer1, &QTimer::timeout, tickTimer1, &QTimer::stop);

    connect(mainTimer1, SIGNAL(timeout()), tickTimer2, SLOT(start()));
    connect(mainTimer2, &QTimer::timeout, tickTimer2, &QTimer::stop);
    connect(mainTimer2, &QTimer::timeout, this, &face::setEyesAnimationFalse);
    tickTimer1->start();
    mainTimer1->start();
    mainTimer2->start();
}
