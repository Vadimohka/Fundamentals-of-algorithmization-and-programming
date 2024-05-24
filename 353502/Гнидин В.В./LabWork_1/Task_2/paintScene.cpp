//
// Created by volodya-petarda on 3/10/24.
//

#include "paintScene.h"
#include "main_window.h"
#include <QDebug>
#include <QCursor>
#include <QWidget>
#include <QTimer>
#include <QKeyEvent>


paintScene::paintScene(QObject *parent, main_window *par_w) : QGraphicsScene(parent) {
    this->setSceneRect(0, 0, 0, 0);
    this->parentWindow = par_w;
    leftTimer = new QTimer(this);
    rightTimer = new QTimer(this);
    upTimer = new QTimer(this);
    downTimer = new QTimer(this);
    leftRotateTimer = new QTimer(this);
    rightRotateTimer = new QTimer(this);

    connect(leftTimer, SIGNAL(timeout()), parentWindow, SLOT(moveLeft()));
    connect(rightTimer, SIGNAL(timeout()), parentWindow, SLOT(moveRight()));
    connect(upTimer, SIGNAL(timeout()), parentWindow, SLOT(moveUp()));
    connect(downTimer, SIGNAL(timeout()), parentWindow, SLOT(moveDown()));
    connect(leftRotateTimer, SIGNAL(timeout()), parentWindow, SLOT(rotateLeft()));
    connect(rightRotateTimer, SIGNAL(timeout()), parentWindow, SLOT(rotateRight()));


    leftRotateTimer->setInterval(20);
    rightRotateTimer->setInterval(20);
    leftTimer->setInterval(20);
    rightTimer->setInterval(20);
    upTimer->setInterval(20);
    downTimer->setInterval(20);

    parentWindow->moveUp();
}

paintScene::~paintScene() = default;

void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    if (isSelected)
        return;
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    this->x1 = x;
    this->y1 = y;
}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (isSelected)
        return;
    QGraphicsScene::mouseMoveEvent(event);
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    this->x2 = x;
    this->y2 = y;
    parentWindow->setSizes(x1, y1, x2, y2);
    parentWindow->draw();
}

void paintScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (isSelected)
        return;
    qreal x = event->scenePos().x();
    qreal y = event->scenePos().y();
    this->x2 = x;
    this->y2 = y;
    isSelected = true;
    parentWindow->setSizes(x1, y1, x2, y2);
    parentWindow->draw();
}

void paintScene::setParentWindow(main_window *window) {
    this->parentWindow = window;
}

void paintScene::reset() {
    this->isSelected = false;
}

void paintScene::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
        case (Qt::Key::Key_W):
            if (!isUpTimer)
                upTimer->start();
            isUpTimer = true;
            break;
        case (Qt::Key::Key_D):
            if (!isRightTimer)
                rightTimer->start();
            isRightTimer = true;
            break;
        case (Qt::Key::Key_S):
            if (!isDownTimer)
                downTimer->start();
            isDownTimer = true;
            break;
        case (Qt::Key::Key_A):
            if (!isLeftTimer)
                leftTimer->start();
            isLeftTimer = true;
            break;
        case (Qt::Key::Key_Left):
            if (!isLeftRotateTimer)
                leftRotateTimer->start();
            isLeftRotateTimer = true;
            break;
        case (Qt::Key::Key_Right):
            if (!isRightRotateTimer)
                rightRotateTimer->start();
            isRightRotateTimer = true;
            break;
    }
}

void paintScene::keyReleaseEvent(QKeyEvent *event) {
    switch (event->key()) {
        case (Qt::Key::Key_W):
            upTimer->stop();
            isUpTimer = false;
            break;
        case (Qt::Key::Key_D):
            rightTimer->stop();
            isRightTimer = false;
            break;
        case (Qt::Key::Key_S):
            downTimer->stop();
            isDownTimer = false;
            break;
        case (Qt::Key::Key_A):
            leftTimer->stop();
            isLeftTimer = false;
            break;
        case (Qt::Key::Key_Left):
            leftRotateTimer->stop();
            isLeftRotateTimer = false;
            break;
        case (Qt::Key::Key_Right):
            rightRotateTimer->stop();
            isRightRotateTimer = false;
            break;
    }
}

