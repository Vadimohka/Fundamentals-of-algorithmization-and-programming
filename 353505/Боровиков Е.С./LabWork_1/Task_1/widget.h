#ifndef WIDGET_H
#define WIDGET_H
#include"circle.h"
#include"glaz_with_srachok.h"
#include <QWidget>
#include<QGraphicsScene>
#include<QGraphicsEllipseItem>
#include<QTimer>
#include<QGraphicsView>
#include<QGraphicsEllipseItem>



QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QGraphicsView
{
    Q_OBJECT

public:
    Widget();
    ~Widget();
private:
    int vadb = 0;

    Ui::Widget *ui;
    QGraphicsScene * scene;


    QGraphicsEllipseItem * gyba1;
    QGraphicsEllipseItem * gyba2;

    QTimer * time_rot1;
    QTimer * time_rot2;

    QTimer * up_date;




    Circle circle;
    glaz_with_srachok object;

private slots:

    void myOpenRot();

    void myCloseRot();

    void on_glaza_in_right_clicked();

    void on_glaza_in_left_clicked();

    void on_open_rot_clicked();

    void on_close_rot_clicked();
};
#endif // WIDGET_H
