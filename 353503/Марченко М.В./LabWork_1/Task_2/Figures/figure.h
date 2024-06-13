#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>
#include <QGraphicsItem>
#include <QCursor>
#include <QDebug>

//без QObject не работают сигналы и слоты
class Figure : public QObject,  public QGraphicsItem
{
    Q_OBJECT

public:
    enum { Type = UserType + 1 };

    int type() const override { //?
        return Type;
    }

    explicit Figure(QPointF point, QObject *parent = 0);
    ~Figure();

    QPointF startPoint() const; // Стартовая точка
    QPointF endPoint() const;   // Конечная точка
    QPointF centerPoint() const;

    void setStartPoint(const QPointF point);    // Установка стартовой точки
    void setEndPoint(const QPointF point);      // Установка конечной точки

    //Эти методы будут переопределены у наследников
    //Тем самым, получат собственную реализацию
   virtual long double GetArea();
   virtual long double GetPerimeter();

    void setScale(qreal delta);

signals:
    void pointChanged();    // Сигнал об изменении точки

private:
    QPointF m_startPoint;   // Стартовая точка
    QPointF m_endPoint;     // Конечная точка
    QPointF cursorOffset;
    bool m_bResizing;
    bool isMoving;
    QRectF boundingRect() const;    // Область, в которой содержится фигура
public slots:
    void updateFigure();     // Слот обновления области, в которой содержится фигура

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseHoverEvent(QGraphicsSceneMouseEvent* event);
    bool contains(const QPointF& point) const override;

    QPointF m_centerPoint;
};

#endif // FIGURE_H
