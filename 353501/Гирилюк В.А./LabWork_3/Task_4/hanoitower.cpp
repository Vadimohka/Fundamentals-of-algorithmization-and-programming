#include "hanoitower.h"

HanoiTower::HanoiTower()
{
    QPen pen(Qt::white);
    QBrush brush(Qt::white);
    addRect(-350, 100, 10, 250, pen, brush);
    addRect(350, 100, 10, 250, pen, brush);
    addRect(-5, 100, 10 ,250, pen, brush);
    addRect(-450,350, 900, 15, pen, brush);
    addLine(-300,-150,-301, -150);
    for(int i = 0; i < 3; i++){
        Disk *disk = new Disk();
        disk->order = i;
        disk->moveTo(-350-width/disksCount * (disksCount-i)/2, 125 + (disksCount-1-i)*height/disksCount);
        disk->setPos(-350-width/3 * (disksCount-i)/2, 125 + (disksCount-1-i)*height/3);
        disk->setParams(height/3, 10 + width/3 * (disksCount-i));
        A.push_back(disk);
        addItem(disk);
    }
}

void HanoiTower::setHeight(int n)
{
    if(movable != nullptr){
        movable->timer->stop();
    }
    movable = nullptr;
    disksCount = n;
    QPen pen(Qt::white);
    QBrush brush(Qt::white);
    addRect(-350, 100, 10, 250, pen, brush);
    addRect(350, 100, 10, 250, pen, brush);
    addRect(-5, 100, 10 ,250, pen, brush);
    addRect(-450,350, 900, 15, pen, brush);
    addLine(-300,-150,-301, -150);
    A.clear();
    B.clear();
    C.clear();
    for(int i = 0; i < n; i++){
        Disk *disk = new Disk();
        disk->order = i;
        disk->moveTo(-350-width/n * (disksCount-i)/2, 125 + (disksCount-1-i)*height/n);
        disk->setPos(-350-width/n * (disksCount-i)/2, 125 + (disksCount-1-i)*height/n);
        disk->setParams(height/n, 10 + width/n * (disksCount-i));
        A.push_back(disk);
        addItem(disk);
    }
}

void HanoiTower::hanoi(int diskCount, QChar from, QChar to, QChar temp)
{
    if(running){
        if(diskCount != 0){
            hanoi(diskCount - 1, from, temp, to);

            if(from == 'A'){
                movable = A.at(A.size() - 1);
                A.pop_back();
            }
            else{
                movable = (from == 'B' ? B.at(B.size() - 1) : C.at(C.size() - 1));
                from == 'B' ? B.pop_back() : C.pop_back();
            }

            movable->moveTo(movable->pos().x(), 0);
            while(movable->timer->isActive()){
                if(movable == nullptr){
                    return;
                }
                QCoreApplication::processEvents();
                if(movable == nullptr){
                    return;
                }
            }


            if(to == 'A'){
                movable->moveTo(-350-width/disksCount * (disksCount-movable->order)/2, movable->pos().y());
            }
            else if(to == 'B'){
                movable->moveTo(-5-width/disksCount * (disksCount-movable->order)/2, movable->pos().y());
            }
            else if(to == 'C'){
                movable->moveTo(350-width/disksCount * (disksCount-movable->order)/2, movable->pos().y());
            }

            while(movable->timer->isActive()){
                if(movable == nullptr){
                    return;
                }
                QCoreApplication::processEvents();
                if(movable == nullptr){
                    return;
                }
            }
            if(to == 'A'){
                movable->moveTo(movable->pos().x(), 125 + height * (disksCount-A.size()-1)/disksCount);
                A.push_back(movable);
            }
            else if(to == 'B'){
                movable->moveTo(movable->pos().x(), 125 + height * (disksCount-B.size()-1)/disksCount);
                B.push_back(movable);
            }
            else if(to == 'C'){
                movable->moveTo(movable->pos().x(), 125 + height * (disksCount-C.size()-1)/disksCount);
                C.push_back(movable);
            }
            while(movable->timer->isActive()){
                if(movable == nullptr){
                    return;
                }
                QCoreApplication::processEvents();
                if(movable == nullptr){
                    return;
                }
            }
            hanoi(diskCount - 1, temp, to, from);
            if(A.isEmpty() && B.isEmpty()){
                running = false;
                return;
            }
        }
    }
    else{
        clear();
    }
}
