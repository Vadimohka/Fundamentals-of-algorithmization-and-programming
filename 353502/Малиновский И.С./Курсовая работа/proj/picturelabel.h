#ifndef PICTURELABEL_H
#define PICTURELABEL_H

#include <QWidget>
#include <QLabel>
#include "citybuttons.h"

class PictureLabel : public QLabel
{
public:
    PictureLabel(CityButtons *buttons, QWidget *parent = nullptr);

    CityButtons *buttons;
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // PICTURELABEL_H
