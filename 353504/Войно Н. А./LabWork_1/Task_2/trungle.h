#ifndef TRUNGLE_H
#define TRUNGLE_H

#include "base.h"
#include <QMessageBox>

class trungle: public base
{
public:
    trungle();
    void draw(QGraphicsScene *scene, int width, int height, int a, int &h)override;
    void getParametrs(int &side1, int &side2, int &side3, int a) override;
    void perSquareMasse(int width, int height, int a)override;
    bool proverka(int side1, int side2, int side3);
};

#endif // TRUNGLE_H
