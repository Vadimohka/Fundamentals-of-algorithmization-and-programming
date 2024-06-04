#ifndef CIRCULARBUTTON_H
#define CIRCULARBUTTON_H

#include <QPushButton>
#include <QPainterPath>
#include <QPainter>
#include <QStyleOptionButton>

class CircularButton : public QPushButton {
    Q_OBJECT

public:
    CircularButton(const QString &text, const double width, const double height, QWidget *parent = nullptr);

    void setEllipseSize(double width, double height);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CIRCULARBUTTON_H
