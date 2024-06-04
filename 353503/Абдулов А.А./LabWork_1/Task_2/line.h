#ifndef LINE_H
#define LINE_H

#include "figure.h"
#include <vector>

using namespace std;

class Line : public Figure{
public:
    vector <QPoint> points;

    Line();
    void setPoints(QMouseEvent *me);

};

#endif // LINE_H
