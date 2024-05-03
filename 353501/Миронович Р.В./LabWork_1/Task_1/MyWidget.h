#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QPainter>
#include <QTimer>

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MyWidget(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void animateRibbon();
    void startRibbonAnimation();

private:
    bool m_ribbonVisible;
    bool m_ribbonAnimationStarted;
    QRectF m_ellipseRect;
    QPolygonF m_trianglePolygon;
    QPointF m_ribbonStartPoint;
    QPointF m_ribbonEndPoint;
    QTimer *ribbonAnimationTimer;
};

#endif // MYWIDGET_H
