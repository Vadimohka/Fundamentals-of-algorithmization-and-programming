#include "figures.h"

QRectF figures::boundingRect() const{
    return QRectF();
}

void figures::scale_fun_up(){
    if (scale < 100.00){
        scale += 0.01;
    }
}
void figures::scale_fun_down(){
    if (scale > 0.05){
        scale -= 0.01;
    }
}

void figures::per_x_up(){
    if (x_up < 4000){
        x_up += 2;
    }
}

void figures::per_x_down(){
    if (x_down > -4000){
        x_down -= 2;
    }
}

void figures::per_y_up(){
    if (y_up > -4000){
        y_up -= 2;
    }
}

void figures::per_y_down(){
    if (y_down < 4000){
        y_down += 2;
    }
}
void figures::pov_left(){
    if (grad > 360){
        grad -= 360;
    }
    grad += 2;
}

void figures::pov_rait(){
    if (grad < -360){
        grad += 360;
    }
    grad -= 2;
}

void figures::isk_fun_x_up(){
    if (isk_x < 4000){
        isk_x += 2;
    }
}

void figures::isk_fun_y_up(){
    if (isk_y < 4000){
        isk_y += 2;
    }
}
void figures::isk_fun_x_down_hexagon(){
    if (isk_x > -195){
        isk_x -= 2;
    }
}

void figures::isk_fun_y_down_hexagon(){
    if (isk_y > -160){
        isk_y -= 2;
    }
}

void figures::isk_fun_x_down_rectangle(){
    if (isk_x > -290){
        isk_x -= 2;
    }
}

void figures::isk_fun_y_down_rectangle(){
    if (isk_y > -140){
        isk_y -= 2;
    }
}

void figures::isk_fun_x_down_rhombus(){
    if (isk_x > -90){
        isk_x -= 2;
    }
}

void figures::isk_fun_y_down_rhombus(){
    if (isk_y > -190){
        isk_y -= 2;
    }
}

void figures::fun_n_5(){
    n = 5;
}

void figures::fun_n_6(){
    n = 6;
}

void figures::fun_n_8(){
    n = 8;
}

void figures::rad_min_up(){
    if (rad_min < 4000){
        rad_min += 2;
    }
}

void figures::rad_min_down(){
    if (rad_min > 8){
        rad_min -= 2;
    }
}

void figures::rad_max_up(){
    if (rad_max < 4000){
        rad_max += 2;
    }
}

void figures::rad_max_down(){
    if (rad_max > 16){
        rad_max -= 2;
    }
}

void figures::t1_tri_up(){
    t1_tri += 2;
}
void figures::t1_tri_down(){
    t1_tri -= 2;
}
void figures::t2_tri_up(){
    t2_tri += 2;
}
void figures::t2_tri_down(){
    t2_tri -= 2;
}
void figures::t3_tri_up(){
    if(t3_tri != -460){
        t3_tri += 2;
    }
    else{
        t3_tri += 20;
    }
}
void figures::t3_tri_down(){
    if(t3_tri != -440){
        t3_tri -= 2;
    }
    else{
        t3_tri -= 20;
    }
}

long double figures::fun_vosv_per(){
    return per;
}

long double figures::fun_vosv_pl(){
    return pl;
}

long double figures::fun_vosv_center_x(){
    return center_x;
}

long double figures::fun_vosv_center_y(){
    return center_y;
}

void figures::vr_true(){
    is_t_vr = true;
}

void figures::vr_false(){
    is_t_vr = false;
}

void figures::x_up_point_vr(){
    center_vr_x += 2;
}

void figures::x_down_point_vr(){
    center_vr_x -= 2;
}

void figures::y_up_point_vr(){
    center_vr_y += 2;
}

void figures::y_down_point_vr(){
    center_vr_y -= 2;
}

void figures::prim_pol(QPolygonF a){
        line_pol << QPoint(300, 300) <<  QPoint(-150, 4) <<  QPoint(-9, 0) << QPoint(-45, -100);
}

