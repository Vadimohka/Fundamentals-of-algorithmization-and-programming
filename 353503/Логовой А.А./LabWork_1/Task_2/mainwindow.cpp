#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <abstractfigure.h>
#include <ellipse.h>
#include <rect.h>
#include <QMouseEvent>
#include <QPainter>
#include <QGraphicsView>
#include <QPushButton>
#include <QLayout>
#include <rect.h>
#include <rhomb.h>
#include <triangle.h>
#include <fivestar.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    cord_offset = QPoint(0, 0);
    past_cord = QPoint(0, 0);

    selected_figure = nullptr;

    is_draw = true;
    top_left = false;
    top_right = false;
    bottom_left = false;
    bottom_right = false;

    ui->setupUi(this);
    scene =  new Cinema(this);
    view = new QGraphicsView(scene);
    scene->setSceneRect(100, 100,800,800);
    setCentralWidget(view);
    equanity = 0;
    active_figure = -1;


    QPushButton* button1 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/cursor"), "",this);
    button1->setFixedSize(50,40);

    QPushButton* button2 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/triangle"), "",this);
    button2->setFixedSize(50,40);

    QPushButton* button3 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/square"), "",this);
    button3->setFixedSize(50,40);

    QPushButton* button4 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/circle"), "", this);
    button4->setFixedSize(50,40);

    QPushButton* button5 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/rhomb"), "", this);
    button5->setFixedSize(50,40);

    QPushButton* button6 = new QPushButton(QIcon("/home/blaugranas/Загрузки/icons/star"), "", this);
    button5->setFixedSize(50,40);


    QHBoxLayout* buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button1);
    buttonLayout->addWidget(button2);
    buttonLayout->addWidget(button3);
    buttonLayout->addWidget(button4);
    buttonLayout->addWidget(button5);
    buttonLayout->addWidget(button6);

    this->setLayout(buttonLayout);
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);

    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(view);

    setCentralWidget(mainWidget);

    items.resize(5);

    for (int i = 0; i < items.size(); i++) {
        items[i] = new FiveStar;
        items[i]->setPos(100 * i + 100, 100 * i + 100);
        scene->addItem(items[i]);
    }
    Rect* figure = new Rect;
    figure->setPos(250,250);
    scene->addItem(figure);

    setWindowTitle("Paint");


    connect(button1, &QPushButton::clicked, this, &MainWindow::onButtonClicked1);
    connect(button2, &QPushButton::clicked, this, &MainWindow::onButtonClicked2);
    connect(button3, &QPushButton::clicked, this, &MainWindow::onButtonClicked3);
    connect(button4, &QPushButton::clicked, this, &MainWindow::onButtonClicked4);
    connect(button5, &QPushButton::clicked, this, &MainWindow::onButtonClicked5);
    connect(button6, &QPushButton::clicked, this, &MainWindow::onButtonClicked6);

    connect(scene,&Cinema::signalMouseMoveEvent, this,&MainWindow::moveObject);
    connect(scene,&Cinema::signalMouseDoubleLeftClickEvent, this,&MainWindow::selectFigure);
    connect(scene,&Cinema::signalMouseReleaseLeftButtonEvent, this, &MainWindow::mouseLeftRelease);
    connect(scene,&Cinema::signalMousePressLeftButtonEvent, this, &MainWindow::mouseLeftPress);
};


MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::checkCorner(QPointF corner, QPointF itemPos, qreal tolerance)
{
    QRectF cornerRect(corner.x() - tolerance, corner.y() - tolerance, 2 * tolerance, 2 * tolerance);
    return cornerRect.contains(itemPos);
}

    void MainWindow::selectFigure(QGraphicsSceneMouseEvent *event) {

        QPointF scenePoint = event->scenePos();
        QGraphicsItem *clickedItem = view->scene()->itemAt(scenePoint, QTransform());
        AbstractFigure *item = dynamic_cast<AbstractFigure *>(clickedItem);

        if (selected_figure)
            selected_figure->setShowBorders(false);

        if (item && item != selected_figure) {
            selected_figure = item;
            for (auto &i: items) {
                i->setShowPoint(false);
                i->setZValue(0);
            }
            selected_figure->setShowBorders(true);
            selected_figure->setZValue(1);
            cord_offset = scenePoint - selected_figure->pos();
            is_draw = false;
        }
                else
            selected_figure = nullptr;
    }

    void MainWindow::mouseLeftPress(QGraphicsSceneMouseEvent *event){
        if(selected_figure !=nullptr){

        QPointF mousePos = event->scenePos();
        QPointF item_pos = selected_figure->mapFromScene(mousePos);

        QRectF rect = selected_figure->boundingRect();
        qreal tolerance = 5.0;

        top_right = checkCorner(rect.topRight(), item_pos, tolerance);
        bottom_right = checkCorner(rect.bottomRight(), item_pos, tolerance);
        bottom_left = checkCorner(rect.bottomLeft(), item_pos, tolerance);
        top_left = checkCorner(rect.topLeft(), item_pos, tolerance);
        }
        QPointF scenePoint = event->scenePos();
        start_x = scenePoint.x();
        start_y = scenePoint.y();
    }


    void MainWindow::mouseLeftRelease(QGraphicsSceneMouseEvent *event){
        top_right = bottom_left = bottom_right = top_left = false;

        QPointF scenePoint = event->scenePos();
        end_x = scenePoint.x();
        end_y = scenePoint.y();

        if(start_y>100 && end_y-start_y>50 && end_x-start_x>50 && is_draw){
        equanity++;
        items.resize(5 + equanity);

        switch (active_figure){

        case 1:
            items[4+equanity] = new Triangle(start_x, start_y, end_x, end_y);
            break;
        case 2:
             items[4+equanity] = new Rect(start_x, start_y, end_x, end_y);
            break;
        case 3:
            items[4+equanity] = new Ellipse(start_x, start_y, end_x, end_y);
            break;
        case 4:
            items[4+equanity] = new Rhomb(start_x, start_y, end_x, end_y);
            break;
        case 5:
            items[4+equanity] = new FiveStar(start_x, start_y, end_x, end_y);
            break;
        default:
            qDebug() << "not working";
            break;
        }
        scene->addItem(items[4+equanity]);
        }
        scene->update();


    }



    void MainWindow::moveObject(QGraphicsSceneMouseEvent *event) {
      if (ctrl_press && selected_figure) {

            QPointF center = selected_figure->boundingRect().center();
            QPointF centerSceneCord = selected_figure->mapToScene(center);

            double dx = centerSceneCord.x() - event->scenePos().x();
            double dy = centerSceneCord.y() - event->scenePos().y();

            double angle_rotate = ((atan2(dx, -dy) * 180.0) / M_PI) - start_angle;

            selected_figure->setTransformOriginPoint(center);
            selected_figure->setRotation(angle_rotate);
        }

        else if (selected_figure && shift_press) {

            QPointF mousePos = event->scenePos();
            QPointF item_pos = selected_figure->mapFromScene(mousePos);

            double dx = (item_pos.x() - past_cord.x());
            double dy = (item_pos.y() - past_cord.y());

            past_cord = item_pos;
            if(top_right){

                 selected_figure->setRect(0, dy, dx, 0);
            }
            else if(bottom_right){
                selected_figure->setRect(0, 0, dx, dy);
            }
            else if(bottom_left){
                selected_figure->setRect(dx, 0 ,dy ,0);
            }
            else if(top_left){
                selected_figure->setRect(dx,dy, 0 ,0);
            }

        }


        else if (selected_figure)
            selected_figure->setPos(event->scenePos() - cord_offset);

        scene->update();
    }


    void MainWindow::keyPressEvent(QKeyEvent *event) {
        if (event->modifiers() & Qt::ShiftModifier)
            shift_press = true;

        if (selected_figure)
            selected_figure->setShowPoint(shift_press);


        if (event->modifiers() & Qt::ControlModifier)
            ctrl_press = true;

    }

    void MainWindow::keyReleaseEvent(QKeyEvent *event) {
        ctrl_press = false;
        shift_press = false;

        for (auto &i: items)
            i->setShowPoint(false);

        scene->update();
    }


    void MainWindow::onButtonClicked1(){
        is_draw = false;
    }

    void MainWindow::onButtonClicked2(){
        active_figure = 1;
        is_draw = true;
    }
    void MainWindow::onButtonClicked3(){
        active_figure = 2;
        is_draw =true;
    }

    void MainWindow::onButtonClicked4(){
        active_figure = 3;
        is_draw = true;
    }
    void MainWindow::onButtonClicked5(){
        active_figure = 4;
        is_draw = true;
    }
    void MainWindow::onButtonClicked6(){
        active_figure = 5;
        is_draw = true;
    }






