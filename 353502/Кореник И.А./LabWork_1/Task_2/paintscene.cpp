#include "paintscene.h"

PaintScene::PaintScene(QWidget *parent)
    : QWidget{parent}
{
    this->setParent(parent);
}


void PaintScene::paintEvent(QPaintEvent *painter){

}
