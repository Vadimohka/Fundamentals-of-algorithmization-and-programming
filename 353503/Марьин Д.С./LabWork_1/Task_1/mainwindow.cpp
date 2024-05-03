#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   scene = new CustomScene();
   setUpdatesEnabled(true);

   setWindowTitle("\"Danil Mariyn\"Lab_1_1");

   ui->graphicsView->setScene(scene);
   ui->graphicsView->setMouseTracking(true);

   ui->graphicsView->setRenderHint(QPainter::Antialiasing);

   head = new QGraphicsItemGroup();

   face = new Face(QRectF(90,50,270,290),QColor(227,188,154));
   head->addToGroup(face);

   Reye_ball = new Eyes(QRectF(113,127,60,60),QColor(Qt::white));
   Leye_ball = new Eyes(QRectF(274,127,60,60),QColor(Qt::white));
   head->addToGroup(Reye_ball);
   head->addToGroup(Leye_ball);

   b_r = new Black_eye(QRectF(119,133,35,35),QColor(161, 202, 241));
   b_r->set_center(QRectF(113,127,60,60).center());
   head->addToGroup(b_r);

   b_l = new Black_eye(QRectF(280,133,35,35),QColor(161, 202, 241));
   b_l->set_center(QRectF(274,127,60,60).center());
   head->addToGroup(b_l);

   mouth = new Mouth(QRectF(183,270,90,20),QColor(158, 19, 24));
   mouth->setPos(0,0);
   head->addToGroup(mouth);
   head->setFlag(QGraphicsItem::ItemIsMovable);

   scene->addItem(head);

   connect(scene,&CustomScene::signalTargetCoordinate,b_r,&Black_eye::action_move);
   connect(scene,&CustomScene::signalTargetCoordinate,b_l,&Black_eye::action_move);

   connect(scene,&CustomScene::signalBlink,Reye_ball,&Eyes::action_transform);
   connect(scene,&CustomScene::signalBlink,Leye_ball,&Eyes::action_transform);

   connect(scene,&CustomScene::signalBlink,b_l,&Black_eye::action_transform);
   connect(scene,&CustomScene::signalBlink,b_r,&Black_eye::action_transform);

   connect(scene,&CustomScene::signalTransform,mouth,&Mouth::action_transform);

}

MainWindow::~MainWindow()
{
    delete head;
    delete ui;
    delete face;
    delete Reye_ball;
    delete Leye_ball;;
    delete b_r;
    delete b_l;
}
