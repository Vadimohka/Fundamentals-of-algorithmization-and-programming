#include "Vis.h"
#include <QStack>
#include <QTimer>
#include <qgraphicsscene.h>

const int ROD_X[3] = {-240, 0, 240};
const float ROD_W = 8;
const float ROD_H = 480;
const float BASE_W = 200;
const float DISK_H = 25;
const QBrush brushes[] = {Qt::red, Qt::yellow, Qt::green, Qt::blue,
                          Qt::magenta};

Vis::Vis() : scene(new QGraphicsScene(this)), timer(new QTimer) {
    solution = nullptr;
    selectedRow = -1;
    currentAction = -1;
    timer->start(20);
    connect(timer, &QTimer::timeout, this, &Vis::updateVis);
}

void Vis::updateVis() {
    if (solution == nullptr)
        return;
    scene->clear();

    for (auto pos : ROD_X) {
        scene->addRect(pos - BASE_W / 2, 280, BASE_W, 40, Qt::NoPen, Qt::lightGray);

        scene->addRect(pos - ROD_W / 2, 280 - ROD_H, ROD_W, ROD_H, Qt::NoPen,
                       Qt::lightGray);
    }

    // int selectedRow = 0;
    // // if (selected.count() > 0)
    // // selectedRow = selected[0]->row();

    if (currentDisk != -1) {
        QRectF target = getDisk(currentDisk, targetRod, rods[targetRod].count());
        if (target.x() == currentRect.x() && target.y() == currentRect.y()) {
            rods[targetRod].push(currentDisk);
            currentDisk = -1;
        } else {
            if (target.x() != currentRect.x()) {
                if (currentRect.y() > -280) {
                    currentRect.moveTop(qMax(currentRect.y() - speed, -280.));
                } else {
                    int newX = 0;
                    if (target.x() < currentRect.x()) {
                        currentRect.moveLeft(qMax(currentRect.x() - speed, target.x()));
                    } else {
                        currentRect.moveLeft(qMin(currentRect.x() + speed, target.x()));
                    }
                }
            } else {
                currentRect.moveTop(qMin(currentRect.y() + speed, target.y()));
            }
        }
    } else {
        if (currentAction < selectedRow) {
            currentAction++;
            QPair<int, int> action = solution->at(currentAction);
            currentDisk = rods[action.first].pop();
            currentRect =
                getDisk(currentDisk, action.first, rods[action.first].count());
            targetRod = action.second;
        }

        if (currentAction > selectedRow) {
            QPair<int, int> action = solution->at(currentAction);
            currentAction--;
            currentDisk = rods[action.second].pop();
            currentRect =
                getDisk(currentDisk, action.second, rods[action.second].count());
            targetRod = action.first;
        }
    }

    for (int r = 0; r < 3; r++) {
        QStack<int> &rod = rods[r];
        for (int i = 0; i < rod.count(); i++) {
            int disk = rod[i];
            QRectF diskR = getDisk(disk, r, i);

            drawRect(diskR, disk);
        }
    }

    // if (selectedRow >= 0)
    //   drawArrow(selectedRow);

    if (currentDisk != -1) {
        drawRect(currentRect, currentDisk);
    }
}

QRectF Vis::getDisk(int disk, int rod, int fromTop) {
    float disk_w = 20 + disk * 11;

    return QRectF(ROD_X[rod] - disk_w / 2, 279 - (fromTop + 1) * DISK_H, disk_w,
                  DISK_H);
}

void Vis::drawRect(QRectF pos, int disk) {
    QBrush color = brushes[disk % (sizeof(brushes) / sizeof(brushes[0]))];
    QPen pen(Qt::darkGray, 2);
    pen.setJoinStyle(Qt::MiterJoin);

    scene->addRect(pos, pen, color);
}

void Vis::drawArrow(int actionI) {

    QPair<int, int> action = solution->at(actionI);
    int fromX = ROD_X[action.first];

    int toX = ROD_X[action.second];
    scene->addRect(fromX - 10, -300, 20, 50, Qt::NoPen, Qt::red);
    scene->addRect(qMin(fromX, toX) - 10, -300, qAbs(toX - fromX) + 20, 20,
                   Qt::NoPen, Qt::red);

    {

        QPolygonF arrow;
        arrow << QPoint(toX - 10, -280);
        arrow << QPoint(toX - 10, -260);
        arrow << QPoint(toX - 20, -260);

        arrow << QPoint(toX, -240);

        arrow << QPoint(toX + 20, -260);
        arrow << QPoint(toX + 10, -260);
        arrow << QPoint(toX + 10, -280);

        scene->addPolygon(arrow, Qt::NoPen, Qt::red);
    }
}

void Vis::resetVis(int _diskCount, QList<QPair<int, int>> *_solution) {
    currentAction = -1;
    diskCount = _diskCount;
    solution = _solution;

    rods[0].clear();
    rods[1].clear();
    rods[2].clear();

    for (int i = diskCount; i > 0; i--) {
        rods[0].push(i);
    }
}

void Vis::setSelection(int _selected) { selectedRow = _selected; }
