//
// Created by acryoz on 10.2.24.
//

#ifndef UNTITLED_PLANE_H
#define UNTITLED_PLANE_H

#include "rectangle.h"
#include <QDebug>
#include <QPolygon>


QT_BEGIN_NAMESPACE
namespace Ui { class plane; }
QT_END_NAMESPACE

class plane : public Rectangle {
    Q_OBJECT

public:
    explicit plane(QWidget *parent = nullptr);
    ~plane() override;

public slots:
    virtual void moveSideways();
    virtual void moveUpDown();

private slots:
    void moveTick() override;

private:
    Rectangle nose;
    Rectangle body;
    Rectangle iluminator;
    Rectangle chassis1;
    Rectangle chassis2;
    Rectangle tail;
    bool landing = false;
    bool taking_off = true;
    void extendChassis();
    void retractChassis();
    Ui::plane *ui;
};


#endif //UNTITLED_PLANE_H
