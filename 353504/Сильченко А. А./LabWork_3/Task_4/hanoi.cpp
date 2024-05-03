#include "hanoi.h"

QRectF hanoi::boundingRect() const{
    return QRectF();
}

void hanoi::otr_col(int n){
    if (n <= 10){
         hanoi::n = n;
        height = 54;
    }
    else{
    hanoi::n = n;
    height = 540 / n;
    }
    ism_widht = (200 - (60 - n)) / n;
    y = 350 - height;
    skr_x = height / 2;
    skr_y = height / 2;
    kol.resize(n);
    kol_kol = n;
    for (int i = 0; i < n; i++){
        kol[i].x = x + (ism_widht / 2) * i;
        kol[i].y = y - height * i;
        kol[i].width = width - ism_widht * i;
        kol[i].height = height;
    }
    kol_kol_1 = n;
}

void hanoi::inis(){
    namber_vector = 0;
    is_finish = false;
    vver = true;
    left_or_rigth = false;
    vniz = false;
    kol_kol = 0;
    kol_kol_1 = 0;
    kol_kol_2 = 0;
    kol_kol_3 = 0;
}


void hanoi::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter -> setBrush(Qt::black);
    painter -> drawRect(-600, 350, 1200, 50);
    painter -> setBrush(Qt::black);
    painter -> drawRect(-400, -200, 20, 550);
    painter -> drawRect(0, -200, 20, 550);
    painter -> drawRect(400, -200, 20, 550);
    painter -> drawEllipse(-400, -210, 20, 20);
    painter -> drawEllipse(0, -210, 20, 20);
    painter -> drawEllipse(400, -210, 20, 20);
    if (n != 0){
        painter -> setRenderHint(QPainter::Antialiasing);
        painter -> setBrush(QColor(243,173,47));
        for(int i = 0; i < n; i++){
            painter -> drawRect(kol[i].x, kol[i].y, kol[i].width, kol[i].height);
        }
    }
}

void hanoi::qvector_table(QVector <table>&a){
    vect = a;
}

bool hanoi::animate(int n){
    if(vver){
        if (kol[kol_kol - vect[namber_vector].namber_kol].y < -300){
            vver = false;
            left_or_rigth = true;
        }
        kol[kol_kol - vect[namber_vector].namber_kol].y -= 5;
        return false;
    }
    else if(left_or_rigth){
        if (vect[namber_vector].namber_stolb_finish == 3 && vect[namber_vector].namber_stolb_start == 1){
            if (kol[kol_kol - vect[namber_vector].namber_kol].x > 290 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_1--;
                kol_kol_3++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x += 5;
            return false;
        }
        else if(vect[namber_vector].namber_stolb_finish == 2 && vect[namber_vector].namber_stolb_start == 1){
            if (kol[kol_kol - vect[namber_vector].namber_kol].x > -110 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_1--;
                kol_kol_2++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x += 5;
            return false;
        }
        else if(vect[namber_vector].namber_stolb_finish == 1 && vect[namber_vector].namber_stolb_start == 2){
            if (kol[kol_kol - vect[namber_vector].namber_kol].x < -490 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_2--;
                kol_kol_1++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x -= 5;
            return false;
        }
        else if(vect[namber_vector].namber_stolb_finish == 3 && vect[namber_vector].namber_stolb_start == 2){
            if (kol[kol_kol - vect[namber_vector].namber_kol].x > 290 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_2--;
                kol_kol_3++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x += 5;
            return false;
        }
        else if(vect[namber_vector].namber_stolb_finish == 2 && vect[namber_vector].namber_stolb_start == 3){
            if (kol[kol_kol - vect[namber_vector].namber_kol].x < -90 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_3--;
                kol_kol_2++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x -= 5;
            return false;
        }
        else {
            if (kol[kol_kol - vect[namber_vector].namber_kol].x < -490 + (ism_widht / 2) * (kol_kol - vect[namber_vector].namber_kol)){
                kol_kol_3--;
                kol_kol_1++;
                left_or_rigth = false;
                vniz = true;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].x -= 5;
            return false;
        }
    }
    else if (vniz){
        if(vect[namber_vector].namber_stolb_finish == 1){
            if (kol[kol_kol - vect[namber_vector].namber_kol].y > 342 - kol_kol_1 * height){
                vniz = false;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].y += 5;
            return false;

        }
        else if(vect[namber_vector].namber_stolb_finish == 2){
            if (kol[kol_kol - vect[namber_vector].namber_kol].y > 342 - kol_kol_2 * height){
                vniz = false;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].y += 5;
            return false;
        }
        else{
            if (kol[kol_kol - vect[namber_vector].namber_kol].y > 342 - kol_kol_3 * height){
                vniz = false;
            }
            kol[kol_kol - vect[namber_vector].namber_kol].y += 5;
            return false;
        }
    }
    else if(namber_vector == n){
        is_finish = true;
        return true;
    }
    else{
        namber_vector++;
        vver = true;
        return false;
    }
}
