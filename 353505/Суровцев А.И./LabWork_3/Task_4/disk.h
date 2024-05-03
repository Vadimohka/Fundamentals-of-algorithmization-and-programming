#ifndef DISK_H
#define DISK_H
#include <QGraphicsRectItem>
#include <QColor>
#include <QBrush>

class Disk : public QGraphicsRectItem {
public:
    Disk(int width, int height, int number) : QGraphicsRectItem(0, 0, width, height), diskNumber(number) {
        setBrush(QBrush(QColor((diskNumber * 40) % 256, (diskNumber * 80) % 256, (diskNumber * 120) % 256)));
    }
    int getDiskNumber() const {
        return diskNumber;
    }
private:
    int diskNumber;
};

#endif // DISK_H
