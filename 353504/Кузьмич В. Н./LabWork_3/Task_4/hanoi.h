#ifndef HANOI_H
#define HANOI_H

#include <QGraphicsObject>

#include <QPainter>

#include <QVector>

#include <QTimer>

class col
{
public:
    double x = 0, y = 0, width = 0, height = 0;
};

class table{
public:
    int namber_kol = 0, namber_stolb_start = 0, namber_stolb_finish = 0;
};

class hanoi : public QGraphicsObject
{
public:
    QRectF boundingRect() const;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
    QVector <col> kol;
    void otr_col(int);
    double x = -500, y = 0, width = 220, height = 30, skr_x = 15, skr_y = 15, n = 0, ism_widht = 1;
    void animathion(int, int, int);
    bool per_vver(int);
    bool per_left_or_rith(int);
    bool per_vniz(int);
    QVector <table> vect;
    void qvector_table(QVector <table>&a);
    bool animate(int);
    int namber_operation = 1, namber_vector = 0;
    bool is_finish = false;
    bool vver = true, left_or_rigth = false, vniz = false;
    int kol_kol = 0;
    int kol_kol_1 = 0, kol_kol_2 = 0, kol_kol_3 = 0;
    void inis();
};

#endif // HANOI_H
