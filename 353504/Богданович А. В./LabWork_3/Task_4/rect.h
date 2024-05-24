#ifndef RECT_H
#define RECT_H

#include <QWidget>
#include <QPainter>
#include <QPropertyAnimation>
#include <QThread>
#include <QTimer>
#include <QEventLoop>

class Rect : public QWidget {
    Q_OBJECT

public:
    Rect(int size, QWidget *parent = nullptr);

    void setPosition(int x, int y);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    int m_size;
    QColor m_color;
};

#endif // RECT_H
