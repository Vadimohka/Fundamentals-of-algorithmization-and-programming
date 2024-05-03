#include "hanoiGraphics.h"
#include <qpoint.h>

HanoiGraphics::HanoiGraphics(int num){
    numDisks = num;
    diskHeightDelta = disk_H * (10 - numDisks);
    for (int i = 9; i >= 0; i--) {
        disk_W[i] = 200 - (20 * i);
        pos_X[i] = tower_X[0] + (tower_W / 2) - (disk_W[i] / 2);
        pos_Y[i] = 250 - (i + 1) * disk_H + diskHeightDelta;
    }  
}
HanoiGraphics::~HanoiGraphics(){}

QRectF HanoiGraphics::boundingRect() const {
    return QRectF();
}

int HanoiGraphics::getNumDisks() { return numDisks; }
int HanoiGraphics::getDiskHeight() { return disk_H; }
void HanoiGraphics::setTable (QTableWidget *tableWidget) {table = tableWidget;}
void HanoiGraphics::setSpeed(int speed) { speed_ = speed; }

void HanoiGraphics::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(QPointF(0, 5));

    painter->setPen(Qt::gray);
    painter->setBrush(Qt::gray);

    painter->drawRect(tower_X[0], 30, tower_W, tower_H);
    painter->drawRect(tower_X[1], 30, tower_W, tower_H);
    painter->drawRect(tower_X[2], 30, tower_W, tower_H);


    for (int i = 10 - numDisks; i < 10; i++){

        double r = 100 * cos(2 * M_PI / 10 * (10 - i)) + 100;
        double g = 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI / 2) + 100;
        double b = 100 * cos(2 * M_PI / 10 * (10 - i) + M_PI) + 100;
        painter->setPen(QColor(r, g, b));
        painter->setBrush(QColor(r, g, b));
        
        painter->drawRect(pos_X[i], pos_Y[i], disk_W[i], disk_H);
    }
}

void HanoiGraphics::solve(int n, int src, int dst) {

    if (n == 1) {
        moveDisk(n, src, dst);
    } else {
        int aux = 6 - src - dst;
        solve(n - 1, src, aux);
        moveDisk(n, src, dst);
        solve(n - 1, aux, dst);
    }
}

void HanoiGraphics::moveDisk(int n, int src, int dst) {
    static int rows = 0;
    rows++;
    table->setRowCount(rows);
    table->setItem(table->rowCount() - 1, 0, new QTableWidgetItem(QString::number(src)));
    table->setItem(table->rowCount() - 1, 1, new QTableWidgetItem(QString::number(dst)));
    table->scrollToBottom();

    int firstCount = 1;
    int secondCount = 1;
    int thirdCount = 1;

    for(int i = 10 - numDisks; i < 10; i++) {
        if(pos_X[i] == tower_X[0] + (tower_W / 2) - (disk_W[i] / 2)) {
            firstCount++;
        } else if(pos_X[i] == tower_X[1] + (tower_W / 2) - (disk_W[i] / 2)) {
            secondCount++;
        } else if(pos_X[i] == tower_X[2] + (tower_W / 2) - (disk_W[i] / 2)) {
            thirdCount++;
        }
    }

    minDisk_H[0] = 250 - disk_H * firstCount;
    minDisk_H[1] = 250 - disk_H * secondCount;
    minDisk_H[2] = 250 - disk_H * thirdCount;

    animActive = true;
    reachedTop = false;
    reachedDst = false;
    while(animActive){
        animate(10 - n, src, dst);
        QCoreApplication::processEvents();
        QThread::msleep(1);
    }
    
    qDebug() << "anim complete";
    qDebug() << count;
}

void HanoiGraphics::animate(int n, int src, int dst) {
    count++;
    int srcTowerX = tower_X[src - 1]  + (tower_W / 2) - (disk_W[n] / 2);
    int dstTowerX = tower_X[dst - 1]  + (tower_W / 2) - (disk_W[n] / 2);

    if (!reachedTop) {  
        pos_Y[n] -= speed_;
        if (pos_Y[n] <= target_Top) {
            pos_Y[n] = target_Top;
            reachedTop = true;
        }
    }

    if (pos_X[n] < dstTowerX && reachedTop && !reachedDst) {
        pos_X[n] += speed_;
        if (pos_X[n] >= dstTowerX) {
            pos_X[n] = dstTowerX; 
            reachedDst = true; 
        }
    } else if (pos_X[n] > dstTowerX && reachedTop && !reachedDst) {
        pos_X[n] -= speed_;
        if (pos_X[n] <= dstTowerX) {
            pos_X[n] = dstTowerX; 
            reachedDst = true; 
        }
    }

    if (reachedDst) {
        pos_Y[n] += speed_;
        if (pos_Y[n] >= minDisk_H[dst-1]) {
            pos_Y[n] = minDisk_H[dst-1];
            animActive = false;
        }
    }

    update();
}