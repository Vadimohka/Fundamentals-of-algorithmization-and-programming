#include "MyWidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    m_ribbonVisible = true;

    m_ellipseRect = QRectF(300, 250, 100, 100);
    m_trianglePolygon << QPointF(350, 350) << QPointF(340, 375) << QPointF(360, 375);

    m_ribbonStartPoint = QPointF((m_trianglePolygon[1].x() + m_trianglePolygon[2].x()) / 2, m_trianglePolygon[2].y());
    m_ribbonEndPoint = QPointF(m_ribbonStartPoint.x(), m_ribbonStartPoint.y() + 100);

    QPushButton *button = new QPushButton("Лопнуть", this);
    button->setGeometry(300, 500, 100, 30);

    ribbonAnimationTimer = new QTimer(this);
    connect(button, &QPushButton::clicked, this, &MyWidget::startRibbonAnimation);
    connect(ribbonAnimationTimer, &QTimer::timeout, this, &MyWidget::animateRibbon);
}

void MyWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);

    if (m_ribbonVisible)
    {
        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        painter.drawEllipse(m_ellipseRect);

        painter.setPen(Qt::black);
        painter.setBrush(Qt::red);
        painter.drawPolygon(m_trianglePolygon);
    }

    painter.setPen(Qt::black);
    painter.drawLine(m_ribbonStartPoint, m_ribbonEndPoint);
}

void MyWidget::animateRibbon()
{
    const int ribbonFallSpeed = 2;

    if (m_ribbonEndPoint.y() < height())
    {
        m_ribbonStartPoint.setY(m_ribbonStartPoint.y() + ribbonFallSpeed);
        m_ribbonEndPoint.setY(m_ribbonEndPoint.y() + ribbonFallSpeed);
        update();
    }
    else
    {
        ribbonAnimationTimer->stop();
    }
}

void MyWidget::startRibbonAnimation()
{
    ribbonAnimationTimer->start(5);
    m_ribbonVisible = false; // Установка флага в false
    update(); // Перерисовка виджета
}
