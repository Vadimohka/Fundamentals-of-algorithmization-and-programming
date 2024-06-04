//
// Created by volodya-petarda on 3/10/24.
//

#ifndef RISOVALKA_MAIN_WINDOW_H
#define RISOVALKA_MAIN_WINDOW_H


#include <QWidget>
#include "paintScene.h"
#include "figures/base_figure.h"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class main_window : public QWidget {
Q_OBJECT
public slots:

    void moveLeft();

    void moveRight();

    void moveDown();

    void moveUp();

    void rotateLeft();

    void rotateRight();

public:
    explicit main_window(QWidget *parent = nullptr);

    ~main_window() override;

    void setSizes(qreal x1, qreal y1, qreal x2, qreal y2);

    void draw();

private slots:

    void setPerimentr();

    void setSquare();

    void setCircle();

    void set5polygon();

    void set6polygon();

    void set8polygon();

    void setRhombus();

    void setTriangle();

    void set5Star();

    void set8Star();

    void setMultiStar();

private:
    base_figure *figure;
    paintScene *scene;
    qreal x1, x2, y1, y2;
    Ui::main_window *ui;
};


#endif //RISOVALKA_MAIN_WINDOW_H
