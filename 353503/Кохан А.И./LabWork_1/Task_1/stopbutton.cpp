#include "stopbutton.h"

StopButton::StopButton(QWidget *parent) : QPushButton(parent)
{
    setCheckable(true);
    setStyleSheet("QPushButton:checked { background-color: black; }");
    imgStop = QPixmap(":/img/image/5766062.png");
    setIcon(imgStop);
    setIconSize(QSize(50, 75));
}
