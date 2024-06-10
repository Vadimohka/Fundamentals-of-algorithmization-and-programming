#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qgraphicsscene.h>
#include <iostream>


mainwindow::mainwindow(QWidget *parent) : QWidget(parent), ui(new Ui::mainwindow), scene(new paintScene(this, this)) {

    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    ui->circleButton->setIcon(QIcon("../images/circle.png"));
    ui->triangleButton->setIcon(QIcon("../images/triangle.png"));
    ui->rhombusButton->setIcon(QIcon("../images/rhombus.png"));
    ui->rectangleButton->setIcon(QIcon("../images/rectangle.png"));
    ui->hexagonButton->setIcon(QIcon("../images/hexagon.png"));
    ui->pentagonButton->setIcon(QIcon("../images/pentagon.png"));
    ui->squareButton->setIcon(QIcon("../images/square.png"));
    ui->star_5Button->setIcon(QIcon("../images/star_5.png"));
    ui->star_6Button->setIcon(QIcon("../images/star_6.png"));
    ui->star_8Button->setIcon(QIcon("../images/star_8.png"));

    /*xStart = scene->getxsStart();
    yStart = scene->getysStart();
    xFinish = scene->getxsFinish();
    yFinish = scene->getysFinish();
*/
    auto *rotateLeftTimer = new QTimer(this);
    auto *rotateRightTimer = new QTimer(this);
    auto *upRadiuseTimer = new QTimer(this);
    auto *downRadiuseTimer = new QTimer(this);

    connect(ui->rotateLeftButton, SIGNAL(pressed()), rotateLeftTimer, SLOT(start()));
    connect(ui->rotateRightButton, SIGNAL(pressed()), rotateRightTimer, SLOT(start()));
    connect(ui->upRadiusButton, SIGNAL(pressed()), upRadiuseTimer, SLOT(start()));
    connect(ui->downRadiusButton, SIGNAL(pressed()), downRadiuseTimer, SLOT(start()));

    connect(ui->rotateLeftButton, SIGNAL(released()), rotateLeftTimer, SLOT(stop()));
    connect(ui->rotateRightButton, SIGNAL(released()), rotateRightTimer, SLOT(stop()));
    connect(ui->upRadiusButton, SIGNAL(released()), upRadiuseTimer, SLOT(stop()));
    connect(ui->downRadiusButton, SIGNAL(released()), downRadiuseTimer, SLOT(stop()));


    connect(rotateLeftTimer, SIGNAL(timeout()), this, SLOT(leftRotate_button_clicked()));
    connect(rotateRightTimer, SIGNAL(timeout()), this, SLOT(rightRotate_button_clicked()));
    connect(upRadiuseTimer, SIGNAL(timeout()), this, SLOT(increaseRadiuse_button()));
    connect(downRadiuseTimer, SIGNAL(timeout()), this, SLOT(decreaseRadiuse_button()));


    connect(ui->triangleButton, SIGNAL(clicked()), this, SLOT(set3()));
    connect(ui->rhombusButton, SIGNAL(clicked()), this, SLOT(set4()));
    connect(ui->pentagonButton, SIGNAL(clicked()), this, SLOT(set5()));
    connect(ui->hexagonButton, SIGNAL(clicked()), this, SLOT(set6()));
    connect(ui->circleButton, SIGNAL(clicked()), this, SLOT(setcircle()));
    connect(ui->rectangleButton, SIGNAL(clicked()), this, SLOT(setrectangle()));
    connect(ui->squareButton, SIGNAL(clicked()), this, SLOT(setsquare()));
    connect(ui->star_5Button, SIGNAL(clicked()), this, SLOT(set5star()));
    connect(ui->star_6Button, SIGNAL(clicked()), this, SLOT(set6star()));
    connect(ui->star_8Button, SIGNAL(clicked()), this, SLOT(set8star()));
    connect(ui->customButton, SIGNAL(clicked()), this, SLOT(setCustom()));

    connect(ui->moveButton, SIGNAL(clicked()), this, SLOT(setMove()));
    connect(ui->equalButton, SIGNAL(clicked()), this, SLOT(makeEqual()));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close_clicked()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clear_clicked()));
    connect(ui->deleteButton, SIGNAL(clicked()), this, SLOT(delete_clicked()));

    connect(ui->moveLeftButton, SIGNAL(clicked()), this, SLOT(change_figure_left()));
    connect(ui->moveRightButton, SIGNAL(clicked()), this, SLOT(change_figure_right()));

}

void mainwindow::createFigure() {
    isMove = false;
    if (straight) {
        figure = new straightPolygon(numberPoints, xStart, yStart, xFinish, yFinish, square);
    } else if (stardraw) {
        figure = new star(numberPoints, xStart, yStart, xFinish, yFinish);
    } else {
        if (customhas) {
            figure = new custom(numberPoints, xStart, yStart, xFinish, yFinish);
        } else {
            figure = new polygon(numberPoints, xStart, yStart, xFinish, yFinish);
        }
    }
    scene->addItem(figure);
    hasFigure = true;
    has.push_back(figure);
    add.push_back({numberPoints, (straight << three) + (stardraw << two) + (square << one) + customhas});
    pos = has.size() - 1;
    showEverything();
}


void mainwindow::changeSize() {
    if (!hasFigure) {
        return;
    }
    figure->setX2(xFinish);
    figure->setY2(yFinish);
    showEverything();
}

void mainwindow::leftRotate_button_clicked() {
    if (hasFigure) {
        figure->rotateAll(-rotateAngle);
    }
}

void mainwindow::rightRotate_button_clicked() {
    if (hasFigure) {
        figure->rotateAll(+rotateAngle);
    }
}

void mainwindow::set3() {
    numberPoints = 3;
    isMove = false;
    straight = false;
    stardraw = false;
    square = false;
    customhas = false;
}

void mainwindow::set4() {
    numberPoints = 4;
    isMove = false;
    straight = false;
    stardraw = false;
    square = false;
    customhas = false;
}

void mainwindow::set5() {
    numberPoints = five;
    isMove = false;
    stardraw = false;
    straight = false;
    square = false;
    customhas = false;
}

void mainwindow::set6() {
    numberPoints = six;
    isMove = false;
    stardraw = false;
    straight = false;
    square = false;
    customhas = false;
}

void mainwindow::setcircle() {
    numberPoints = fivethousand;
    isMove = false;
    straight = false;
    stardraw = false;
    square = false;
    customhas = false;
}

void mainwindow::set5star() {
    isMove = false;
    numberPoints = five;
    straight = false;
    stardraw = true;
    square = false;
    customhas = false;
}

void mainwindow::set6star() {
    isMove = false;
    numberPoints = six;
    straight = false;
    stardraw = true;
    square = false;
    customhas = false;
}

void mainwindow::set8star() {
    isMove = false;
    numberPoints = eight;
    straight = false;
    stardraw = true;
    square = false;
    customhas = false;
}

void mainwindow::setrectangle() {
    isMove = false;
    numberPoints = four;
    straight = true;
    stardraw = false;
    square = false;
    customhas = false;
}

void mainwindow::setsquare() {
    isMove = false;
    numberPoints = four;
    straight = true;
    stardraw = false;
    square = true;
    customhas = false;
}


void mainwindow::setCustom() {
    isMove = false;
    numberPoints = five;
    straight = false;
    stardraw = false;
    square = false;
    customhas = true;

}

void mainwindow::setMove() {
    isMove = true;
    showEverything();
}

void mainwindow::moveCenter() {
    if (!hasFigure) {
        showEverything();
        return;
    }
    figure->setDeltaX(moveFinishX - moveStartX);
    figure->setDeltaY(moveFinishY - moveStartY);
    showEverything();
}

void mainwindow::increaseRadiuse_button() {
    if (!hasFigure) {
        showEverything();
        return;
    }
    if (stardraw) {
        figure->setRadiuse(delta);
    }
    showEverything();
}

void mainwindow::decreaseRadiuse_button() {
    if (hasFigure) {
        if (!stardraw) {}
        else {
            figure->setRadiuse(-delta);
        }
        showEverything();
    } else {
        showEverything();
    }
}

void mainwindow::makeEqual() {
    if (!hasFigure) {
        showEverything();
        return;
    }
    figure->setEqual();
    square = true;
    showEverything();
}

void mainwindow::showEverything() {
    if (!hasFigure) {
        ui->labelPerimeter->setText("0");
        ui->labelSquare->setText("0");
        ui->labelpointX->setText("0");
        ui->labelpointY->setText("0");

        return;
    }
    QString p;
    p = p.number(figure->getPerimeter());
    ui->labelPerimeter->setText(p);
    p = p.number(figure->getSquare());
    ui->labelSquare->setText(p);
    auto center = figure->getCenter();
    p = p.number(center.first);
    ui->labelpointX->setText(p);
    p = p.number(center.second);
    ui->labelpointY->setText(p);

}

void mainwindow::close_clicked() {
    close();
}

void mainwindow::clear_clicked() {
    isMove = true;
    hasFigure = false;
    for (auto x: has) {
        scene->removeItem(x);
    }
    ui->labelPerimeter->setText("0");
    ui->labelSquare->setText("0");
    ui->labelpointX->setText("0");
    ui->labelpointY->setText("0");
    pos = -1;
    has.clear();
}

void mainwindow::delete_clicked() {
    if (!hasFigure) {
        showEverything();
        return;
    }
    auto x = has[pos];
    scene->removeItem(x);
    has.erase(has.begin() + pos);
    add.erase(add.begin() + pos);
    pos--;
    std::cout << pos << std::endl;
    pos += add.size();
    if (add.size()) {
        pos %= add.size();
    }
    if (!has.empty()) {
        figure = has[pos];
        auto t = add[pos];
        numberPoints = t.first;
        straight = ((t.second >> three) & 1);
        stardraw = ((t.second >> two) & 1);
        square = ((t.second >> one) & 1);
        isMove = true;
        showEverything();
    } else {
        pos = -1;
        ui->labelPerimeter->setText("0");
        ui->labelSquare->setText("0");
        ui->labelpointX->setText("0");
        ui->labelpointY->setText("0");
        hasFigure = false;
        isMove = true;
    }
}

void mainwindow::change_figure_left() {
    if (!hasFigure) {
        return;
    }
    pos--;
    pos += add.size();
    pos %= add.size();
    figure = has[pos];
    auto t = add[pos];
    numberPoints = t.first;
    straight = ((t.second >> three) & 1);
    stardraw = ((t.second >> two) & 1);
    square = ((t.second >> one) & 1);
    customhas = (t.second & 1);
    isMove = true;
    showEverything();
}

void mainwindow::change_figure_right() {
    if (!hasFigure) {
        return;
    }
    pos++;
    pos %= add.size();
    figure = has[pos];
    auto t = add[pos];
    numberPoints = t.first;
    straight = ((t.second >> three) & 1);
    stardraw = ((t.second >> two) & 1);
    square = ((t.second >> one) & 1);
    customhas = (t.second & 1);
    isMove = true;
    showEverything();
}

bool mainwindow::getIsMove() {
    return isMove;
}

void mainwindow::setXStart(double a) {
    xStart = a;
}

void mainwindow::setYStart(double a) {
    yStart = a;
}

void mainwindow::setXFinish(double a) {
    xFinish = a;
}

void mainwindow::setYFinish(double a) {
    yFinish = a;
}

void mainwindow::setmoveXStart(double a) {
    moveStartX = a;
}

void mainwindow::setmoveYStart(double a) {
    moveStartY = a;
}

void mainwindow::setmoveXFinish(double a) {
    moveFinishX = a;
}

void mainwindow::setmoveYFinish(double a) {
    moveFinishY = a;
}