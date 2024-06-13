//
// Created by darina on 3/10/24.
//

#ifndef REDLINE_PAINTSCENE_H
#define REDLINE_PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QTimer>
#include <QDebug>

class mainwindow;

class paintScene : public QGraphicsScene {

    Q_OBJECT

public:
    explicit paintScene(QObject *parent = nullptr, mainwindow *parentWindow = nullptr);

    double getxsStart();

    double getysStart();

    double getxsFinish();

    double getysFinish();


private:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) final;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) final;

    mainwindow *parentWindow;

    double xsStart, ysStart, xsFinish, ysFinish;
    qreal prevXStart, prevYStart;

};

#endif //REDLINE_PAINTSCENE_H
