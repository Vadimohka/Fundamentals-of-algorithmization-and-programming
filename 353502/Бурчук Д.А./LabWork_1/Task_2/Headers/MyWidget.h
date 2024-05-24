#ifndef LAB1TASK2_MYWIDGET_H
#define LAB1TASK2_MYWIDGET_H


#include <QtWidgets>


#include "../Headers/Circle.h"
#include "../Headers/Rectangle.h"
#include "../Headers/Square.h"
#include "../Headers/Rhombus.h"
#include "../Headers/Hexagon.h"
#include "../Headers/Octagon.h"
#include "../Headers/Line.h"
#include "../Headers/Star.h"
#include "../Headers/Triangle.h"
#include "../Headers/BernoulliLemniscate.h"


class MyWidget : public QWidget {
    Q_OBJECT

            QButtonGroup
    *
    figureGroup;
    QButtonGroup *choosingGroup;

    QRadioButton *triangleRadioButton;
    QRadioButton *circleRadioButton;
    QRadioButton *rhombusRadioButton;
    QRadioButton *rectangleRadioButton;
    QRadioButton *hexagonRadioButton;
    QRadioButton *squareRadioButton;
    QRadioButton *bernoulliLemniscateRadioButton;
    QRadioButton *starRadioButton;
    QSpinBox *starSpinBox;
    QRadioButton *octagonRadioButton;
    QRadioButton *lineRadioButton;

    QRadioButton *drawRadioButton;
    QRadioButton *moveRadioButton;

    QPushButton *increaseSizePushButton;
    QPushButton *diminishSizePushButton;

    QPushButton *rotateToLeftPushButton;
    QPushButton *rotateToRightPushButton;

    QLabel *centerLabel;
    QLabel *areaLabel;
    QLabel *perimeterLabel;

    QLabel *centerText;
    QLabel *areaText;
    QLabel *perimeterText;
/*
    QPushButton *nextButton;
    QPushButton *previousButton;
*/
    QPainter *painter;

    std::vector<Figure *> figures;

    QTimer *_timer;

    QTimer *tickTimer;

    int ID;

    int lastID;

    void setFigure();

    void connection();

    void disconnection();

public
    slots:

            void setData();

    void createFigure();

    void updating();

    void changeThorns();

    /*void chooseLeft();

    void chooseRight();*/

    void clear();

public:
    explicit MyWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
};


#endif //LAB1TASK2_MYWIDGET_H
