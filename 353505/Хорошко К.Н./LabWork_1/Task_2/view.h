#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QWheelEvent>

class CustomGraphicsView : public QGraphicsView {
protected:
    void wheelEvent(QWheelEvent *event) override;
};

#endif // VIEW_H
