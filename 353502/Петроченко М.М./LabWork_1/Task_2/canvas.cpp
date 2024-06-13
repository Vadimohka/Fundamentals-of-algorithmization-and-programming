//
// Created by acryoz on 15.2.24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Canvas.h" resolved

#include "../headers/canvas.h"
#include "ui_canvas.h"


const int FPS = 60;



Canvas::Canvas(QWidget *parent) :
        QFrame(parent), ui(new Ui::Canvas) {
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    QObject::connect(&this->glob_timer, SIGNAL(timeout()), this, SLOT(tick()));
    this->glob_timer.start(1000/FPS);
    figure* testfig = new figure;
    testfig->addPoint(QPointF{1, 1});
    testfig->addPoint(QPointF{1, 1});
    testfig->addPoint(QPointF{1, 1});
    this->figures.push_back(testfig);
}


void Canvas::tick() {
    this->update();
}


void Canvas::paintEvent(QPaintEvent* qPaintEvent) {
    QPainter* painter = new QPainter;
    painter->begin(this);
    painter->setPen(QPen{Qt::black, 3, Qt::SolidLine});
    painter->setRenderHint(QPainter::Antialiasing);
    for(int i = 1; i < this->figures.size(); ++i){
        this->figures[i]->draw(painter);
    }
    painter->end();
    delete painter;
}


void Canvas::mousePressEvent(QMouseEvent *mouseEvent) {
    this->figures[this->cur_figure]->mousePress(mouseEvent);
    this->update();
}


void Canvas::mouseMoveEvent(QMouseEvent *mouseEvent) {
    this->figures[this->cur_figure]->mouseMove(mouseEvent);
    this->update();
}


void Canvas::mouseReleaseEvent(QMouseEvent *mouseEvent) {

}


void Canvas::newFigure() {
    if(this->selected_id == 0){
        Triangle* new_tri = new Triangle;
        this->figures.push_back((figure*)new_tri);
    }
    else if(this->selected_id == 1){
        Rectangle* new_rect = new Rectangle;
        this->figures.push_back((figure*)new_rect);
    }
    else if(this->selected_id == 2){
        Circle* new_circ = new Circle;
        this->figures.push_back((figure*)new_circ);
    }
    else if(this->selected_id == 3){
        Square* new_square = new Square;
        this->figures.push_back((figure*)new_square);
    }
    else if(this->selected_id == 4){
        Hexagon* new_hexagon = new Hexagon;
        this->figures.push_back((figure*)new_hexagon);
    }
    else if(this->selected_id == 5){
        Rhombus* new_rhombus = new Rhombus;
        this->figures.push_back((figure*)new_rhombus);
    }
    else if(this->selected_id == 6){
        Pentagram* new_pentagram = new Pentagram;
        this->figures.push_back((figure*)new_pentagram);
    }
    else if(this->selected_id == 7){
        Hexagram* new_hexagram = new Hexagram;
        this->figures.push_back((figure*)new_hexagram);
    }
    else if(this->selected_id == 8){
        Octagram* new_octagram = new Octagram;
        this->figures.push_back((figure*) new_octagram);
    }
    else if(this->selected_id == 9){
        Pentagon* new_pentagon = new Pentagon;
        this->figures.push_back((figure*) new_pentagon);
    }
}

Canvas::~Canvas() {
    delete ui;
}
