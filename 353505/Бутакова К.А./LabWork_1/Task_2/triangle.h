#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "polygon.h"

class Triangle : public Polygon
{

public:
    Triangle();
    ~Triangle();
private:
    void draw(QPainter&) override;
    void hideWindows() override;

    QPushButton* selectVertexButton;
    QGridLayout* selectVertexLayout;
    QWidget* selectVertexWidget;
    QLineEdit* VertexNumber;
    QLineEdit* newX;
    QLineEdit* newY;
    QPushButton* confirmNewCoord;
    ClickableLabel* wronginput;
public slots:
    void on_selectVertexButton_clicked();
    void on_confirmNewCoord_clicked();
};

#endif // TRIANGLE_H
