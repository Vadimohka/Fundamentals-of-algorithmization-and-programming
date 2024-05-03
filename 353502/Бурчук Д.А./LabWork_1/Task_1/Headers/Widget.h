#ifndef WIDGET_H
#define WIDGET_H

#include "Rocket.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void paintEvent(QPaintEvent * event);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
