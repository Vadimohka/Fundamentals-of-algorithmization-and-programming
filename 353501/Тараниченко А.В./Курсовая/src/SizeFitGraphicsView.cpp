#include "SizeFitGraphicsView.hpp"

SizeFitGraphicsView::SizeFitGraphicsView(QWidget *parent)
    :QGraphicsView(parent)
{}

void SizeFitGraphicsView::resizeEvent(QResizeEvent *event){
    this->fitInView(this->sceneRect(), Qt::KeepAspectRatio);
}

void SizeFitGraphicsView::mousePressEvent(QMouseEvent *event)
{
    auto p = mapToScene(event->pos());
    double x = p.x();
    emit graphicsViewClicked(x);
}
