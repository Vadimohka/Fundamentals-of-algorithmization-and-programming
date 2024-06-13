#ifndef NUMBERVISUAL_H
#define NUMBERVISUAL_H

#include <QWidget>

class NumberVisual : public QWidget
{
    Q_OBJECT
public:
    explicit NumberVisual(int);

    void setHight(int);

    void setColor(Qt::GlobalColor);
signals:
};

#endif // NUMBERVISUAL_H
