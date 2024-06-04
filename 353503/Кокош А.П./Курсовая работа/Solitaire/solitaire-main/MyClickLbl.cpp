
#include "MyClickLbl.h"

MyClickLbl::MyClickLbl(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent)
{
    Q_UNUSED(f);
}

void MyClickLbl::mousePressEvent(QMouseEvent *ev)
{
    Q_UNUSED(ev);

    // Simply emit the signal
    emit clicked();
}
