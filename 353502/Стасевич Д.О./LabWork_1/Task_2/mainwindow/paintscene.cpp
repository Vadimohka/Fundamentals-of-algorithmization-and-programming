#include "paintscene.h"
#include "mainwindow.h"

paintScene::paintScene(QObject *parent, mainwindow *parentWindow) : QGraphicsScene(parent), parentWindow(parentWindow) {
    this->setSceneRect(0, 0, 0, 0);
}


void paintScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    xsStart = event->scenePos().x();
    ysStart = event->scenePos().y();
    xsFinish = xsStart;
    ysFinish = ysStart;
    prevXStart = xsFinish;
    prevYStart = ysFinish;
    if (parentWindow->getIsMove()) {
        parentWindow->setmoveXStart(prevXStart);
        parentWindow->setmoveYStart(prevYStart);
        parentWindow->setmoveXFinish(xsFinish);
        parentWindow->setmoveYFinish(ysFinish);

        return;
    }

    parentWindow->setXStart(xsStart);
    parentWindow->setYStart(ysStart);
    parentWindow->setXFinish(xsFinish);
    parentWindow->setYFinish(ysFinish);

    parentWindow->createFigure();

}

void paintScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    xsFinish = event->scenePos().x();
    ysFinish = event->scenePos().y();

    if (parentWindow->getIsMove()) {
        parentWindow->setmoveXStart(prevXStart);
        parentWindow->setmoveYStart(prevYStart);
        parentWindow->setmoveXFinish(xsFinish);
        parentWindow->setmoveYFinish(ysFinish);
        prevXStart = xsFinish;
        prevYStart = ysFinish;
        parentWindow->moveCenter();
        return;
    }
    parentWindow->setXStart(xsStart);
    parentWindow->setYStart(ysStart);
    parentWindow->setXFinish(xsFinish);
    parentWindow->setYFinish(ysFinish);

    parentWindow->changeSize();
}

double paintScene::getxsFinish() {
    return xsFinish;
}

double paintScene::getysFinish() {
    return ysFinish;
}

double paintScene::getxsStart() {
    return xsStart;
}

double paintScene::getysStart() {
    return ysStart;
}
