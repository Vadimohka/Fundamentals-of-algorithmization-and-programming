#include "picturelabel.h"

PictureLabel::PictureLabel(CityButtons *buttons, QWidget *parent)
    : QLabel(parent), buttons(buttons)
{
}

void PictureLabel::resizeEvent(QResizeEvent *event)
{
    QLabel::resizeEvent(event);
    buttons->handleResizeEvent(size());
}
