#ifndef WIDGET_H
#define WIDGET_H

#include "cart.h"

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

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

private slots:
    void on_Stop_clicked();

    void on_Go_clicked();

    void on_speedBox_valueChanged(int arg1);

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    QGraphicsView *graphicsView;
    Cart *cart;
    QGraphicsItemGroup *group;

};
#endif // WIDGET_H
