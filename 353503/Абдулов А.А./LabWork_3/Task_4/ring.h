#ifndef RING_H
#define RING_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QThread>
#include <QTimer>
#include <QEventLoop>

class Ring: public QWidget {
    Q_OBJECT

public:
    Ring(int size, QWidget *parent = nullptr);

    void setPosition(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_size;
    QColor m_color;
};


#endif // RING_H
