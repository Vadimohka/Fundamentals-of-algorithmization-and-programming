#ifndef STOPBUTTON_H
#define STOPBUTTON_H

#include <QPixmap>
#include <QPushButton>

class StopButton : public QPushButton
{
public:
    StopButton(QWidget *parent = nullptr);

protected:
    QPixmap imgStop;
};

#endif // STOPBUTTON_H
