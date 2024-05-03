#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QPainter>
#include "ring.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    void refresh();
    uint8_t ringsInRoads[3] {0,0,0};
    Ring movingRing;
    uint8_t sourseRoad = 0;
    uint8_t destinationRoad = 0;
    uint8_t phase;
    QTimer timer;
    uint16_t currentPosInTable = 0;
    QVector<QVector<Ring>> roads;
    void moveTower(int, char, char, char);
    void paintEvent(QPaintEvent *event) override;
    Ui::Widget *ui;
};
#endif // WIDGET_H
