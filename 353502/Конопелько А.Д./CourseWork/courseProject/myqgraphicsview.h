#ifndef MYQGRAPHICSVIEW_H
#define MYQGRAPHICSVIEW_H

#include <QGraphicsView>
#include "Headers.h"

class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);

signals:

public slots:
    void mousePressEvent(QMouseEvent* event);
private:
    QGraphicsScene* scene;
};

#endif // MYQGRAPHICSVIEW_H
