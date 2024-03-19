#ifndef FIGURES_H
#define FIGURES_H

#include <QGraphicsObject>

#include <math.h>

#include <QPainter>

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <cmath>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QtWidgets>

class figures : public QGraphicsObject
{
public:
    QRectF boundingRect() const;
    QPolygonF line_pol;
    bool is_t_vr = false;
    double scale = 1;
    const long double pi = 3.141592654;
    long double per = 0, pl = 0, center_x = 0, center_y = 0, x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0, y1 = 0, y2 = 0, y3 = 0, y4 = 0, y5 = 0, y6 = 0, y7 = 0, y8 = 0, x9 = 0, x10 = 0, x11 = 0, x12 = 0, x13 = 0, x14 = 0, x15 = 0, x16 = 0, y9 = 0, y10 = 0, y11 = 0, y12 = 0, y13 = 0, y14 = 0, y15 = 0, y16 = 0, s1 = 0, s2 = 0, s3 = 0, pol_pl = 0;
    int y_up = 0, y_down = 0, x_up = 0, x_down = 0, grad = 0, isk_y = 1, isk_x = 1, n = 0, rad_min = 100, rad_max = 200, t1_tri = 0, t2_tri = 0, t3_tri = 0, center_vr_x = 0, center_vr_y = 0;
    void scale_fun_up();
    void scale_fun_down();
    void per_y_up();
    void per_y_down();
    void per_x_up();
    void per_x_down();
    void pov_left();
    void pov_rait();
    void isk_fun_y_up();
    void isk_fun_x_up();
    void isk_fun_y_down_hexagon();
    void isk_fun_x_down_hexagon();
    void isk_fun_y_down_rectangle();
    void isk_fun_x_down_rectangle();
    void isk_fun_y_down_rhombus();
    void isk_fun_x_down_rhombus();
    void fun_n_5();
    void fun_n_6();
    void fun_n_8();
    void rad_min_up();
    void rad_min_down();
    void rad_max_up();
    void rad_max_down();
    void t1_tri_up();
    void t1_tri_down();
    void t2_tri_up();
    void t2_tri_down();
    void t3_tri_up();
    void t3_tri_down();
    long double fun_vosv_per();
    long double fun_vosv_pl();
    long double fun_vosv_center_x();
    long double fun_vosv_center_y();
    void vr_true();
    void vr_false();
    void x_up_point_vr();
    void x_down_point_vr();
    void y_up_point_vr();
    void y_down_point_vr();
    void prim_pol(QPolygonF);
};

#endif // FIGURES_H
