#include "SortVisualiser.h"
#include <algorithm>


SortVisualiser::SortVisualiser(QRectF initialSize, QObject* parent, const SVector& vect) : 
        QGraphicsScene(initialSize, parent), size (vect.size()),
         towerLength(width()/size), heightPerUnit(height() / (*std::max_element(vect.begin(), vect.end()))),
         elements(vect) {

    rectItems = new QGraphicsRectItem*[size];
    for(int i = 0; i < size; ++i){
        auto cur = new QGraphicsRectItem();
        cur->setBrush(Qt::white);
        cur->setRect(i*towerLength, 0, towerLength,  vect[i] * heightPerUnit);
        addItem(cur);
        rectItems[i] = cur;
    }
}

void SortVisualiser::updateItem(size_t i) {
    auto updated = rectItems[i];
    updated->setRect(i*towerLength, 0, towerLength,  elements[i] * heightPerUnit);
}

void SortVisualiser::highligtItem(long i){
    if(highlited){
        delete highlited;
    }

    if(i == -1){
        highlited = nullptr;
    } else {

        auto rect = rectItems[i];


        highlited = new QGraphicsRectItem;
        highlited->setRect(i * towerLength, 0, width()/100, rect->rect().height());
        highlited->setBrush(Qt::red);
        addItem(highlited);
    }
}

SortVisualiser::~SortVisualiser() {
    for(int i = 0; i < size; ++i){
        delete rectItems[i];
    }    
    delete[] rectItems;
}
