#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

#include "figure.h"
#include "ffrect.h"
#include "fftriangle.h"
#include "ffcircle.h"
#include "ffromb.h"
#include "ffsquare.h"
#include "ffstar.h"
#include "ffnanglyy.h"

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

    figure *fgr = nullptr;

    int scaleChange = 0;

    QPoint msBeg = QPoint(0, 0), msNow = QPoint(0, 0), msmBeg, msmNow;

    bool msPressed = false;

    QPointF rotatePoint = QPoint(200, 200);

    float gradBeg = 0, gradNow = 0;

    ffRect *rct = new ffRect;

private:
    Ui::Widget *ui;

private slots:
    void ticks();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

protected:
    virtual void paintEvent(QPaintEvent *pe);
    virtual void mousePressEvent(QMouseEvent *me);
    virtual void mouseReleaseEvent(QMouseEvent *me);
};
#endif // WIDGET_H
