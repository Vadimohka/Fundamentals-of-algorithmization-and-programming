#ifndef PAINT_H
#define PAINT_H
#include <polygon.h>

class Paint : public GeometryShape
{
public:
    Paint();
private:
    void draw(QPainter&) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void deltaRotation(qreal) override;
    void deltaScale(qreal, qreal) override;
    void deltaShift(QPointF) override;
    void updateMassCenter() override;
    void PrintInfo() override;
    int amountOfUsedPoints;
    bool enabledPainting;
    bool isPainting;
    QCheckBox* isPaintingCheckBox;
    QPushButton* clearButton;
    QPointF* painting;
    int* newPaintings;
    int amountOfPaintings;
private slots:
    void on_checkBox_clicked();
    void on_clear_clicked();
};

#endif // PAINT_H
