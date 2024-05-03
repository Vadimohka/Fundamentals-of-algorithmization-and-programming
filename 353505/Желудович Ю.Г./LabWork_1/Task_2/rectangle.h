#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"

class Rectangle : public Polygon
{
public:
    Rectangle();
    ~Rectangle();
    QPointF TopLeftCorner;
    qreal width;
    qreal height;

    QLineEdit* newHeight;
    QLineEdit* newWidth;
    QWidget* ChangingSizeWidget;

    ClickableLabel* wrongInput;
private:
    void hideWindows() override;
private slots:
    void on_changeSizeRect_clicked();
    void on_confirmChangingSize_clicked();
};

#endif // RECTANGLE_H
