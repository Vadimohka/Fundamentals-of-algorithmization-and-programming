#include "mainwindow.h"
#include "ui_mainwindow.h"
// #include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    scene -> setItemIndexMethod(QGraphicsScene::NoIndex);
    ui -> graphicsView -> setScene(scene);
    scene -> setSceneRect(-100, -100, 400, 400);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_7_clicked()
{
    item = new Star8();
    signalFunctions();
    item -> setPos(110, 110);
    emit signalSetPosition(QPointF(110, 110));
    item -> setItem("star8");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_6_clicked()
{
    item = new Star6();
    signalFunctions();
    item -> setPos(1, 2);
    emit signalSetPosition(QPointF(1, 2));
    item -> setItem("star6");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_5_clicked()
{
    item = new Star5();
    signalFunctions();
    item -> setPos(-170, -100);
    emit signalSetPosition(QPointF(-170, -100));
    item -> setItem("star5");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_4_clicked()
{
    item = new Quadrate();
    signalFunctions();
    item -> setPos(-170, 190);
    emit signalSetPosition(QPointF(-170, 190));
    item -> setItem("quadrate");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_2_clicked()
{
    item = new Rectangle();
    signalFunctions();
    item -> setPos(140, -100);;
    emit signalSetPosition(QPointF(140, -100));
    item -> setItem("rectangle");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_10_clicked()
{
    item = new Rhomb();
    signalFunctions();
    item -> setPos(390, -150);
    emit signalSetPosition(QPointF(390, -150));
    item -> setItem("rhomb");
    scene -> addItem(item);
}

void MainWindow::getTypeOfMoving()
{
    if(ui -> radioButton_7 -> isChecked()){
        item -> setMoving("move");
    }
    else if(ui -> radioButton -> isChecked()){
        item -> setMoving("rotate");
        if((ui -> lineEdit -> text()).toDouble() > 10)
            ui -> lineEdit -> setText("10");
        if((ui -> lineEdit -> text()).toDouble() < -10)
            ui -> lineEdit -> setText("-10");
        emit setAngleSpeed((ui -> lineEdit -> text()).toDouble());
    }
    else if(ui -> radioButton_2 -> isChecked()){
        item -> setMoving("moveTo");
        item -> setYPos((ui -> lineEdit_2 -> text()).toDouble());
        item -> setXPos((ui -> lineEdit_3 -> text()).toDouble());
    }
    else if(ui -> radioButton_3 -> isChecked()){
        item -> setMoving("changeSize");
    }

    else if(ui -> radioButton_8 -> isChecked()){
        item -> setMoving("deleteItem");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    item = new Ellipse();
    signalFunctions();
    item -> setPos(300, 290);
    emit signalSetPosition(QPointF(300, 290));
    item -> setItem("ellipse");
    scene -> addItem(item);
}

void MainWindow::on_pushButton_clicked()
{
    item = new Triangle();
    signalFunctions();
    item -> setPos(340, 100);
    emit signalSetPosition(QPointF(340, 100));
    item -> setItem("triangle");
    scene -> addItem(item);
}


void MainWindow::on_pushButton_8_clicked()
{
    QString stringPolygon = ui -> lineEdit_6 -> text();
    int sizeStringPolygon = stringPolygon.size();
    int newAmount = 0;
    for(int i = 0; i < sizeStringPolygon; i++){
        if(stringPolygon[i] < '0' || stringPolygon[i] > '9'){
            ui -> lineEdit_6 -> setText("Error");
            break;
        }
    }
    if(stringPolygon == '0' || stringPolygon == '1' || stringPolygon == '2')
        ui -> lineEdit_6 -> setText("Error");
    if(ui -> lineEdit_6 -> text() != "Error"){
        sizeStringPolygon = stringPolygon.size();
        newAmount = ((ui -> lineEdit_6 -> text()).toInt());
        if(sizeStringPolygon >= 3)
            newAmount = 100;
        item = new Polygon(newAmount);
        signalFunctions();
        item -> setPos(70, 300);
        emit signalSetPosition(QPointF(70, 300));
        item -> setItem("polygon");
        scene -> addItem(item);
    }
}

void MainWindow::removingItem(MoveItem *deleteItem)
{
    item = deleteItem;
    scene->removeItem(item);
    item = nullptr;
}

void MainWindow::updateScene()
{
    //qDebug() << "UPDATE";
    scene->update();
}

void MainWindow::showPosition(QPointF pointPos)
{
    //qDebug() << "SHOW_POS";
    ui -> lineEdit_7 -> setText(QString::number(pointPos.rx()));
    ui -> lineEdit_8 -> setText(QString::number(pointPos.ry()));
}

void MainWindow::clearMainFields()
{
    ui -> lineEdit_4 -> setText("");
    ui -> lineEdit_5 -> setText("");
    ui -> lineEdit_7 -> setText("");
    ui -> lineEdit_8 -> setText("");
}

void MainWindow::signalFunctions()
{
    connect(item, &MoveItem::signalChangeScene, this, &MainWindow::updateScene);
    connect(item, &MoveItem::deleteItem, this, &MainWindow::removingItem);
    connect(item, &MoveItem::sharePosition, this, &MainWindow::showPosition);
    connect(item, &MoveItem::deleteItem, this, &MainWindow::clearMainFields);
    //connect(item, &MoveItem::signalBlockOK, this, &MainWindow::slotBlockOK);
    //connect(item, &MoveItem::signalReleaseOK, this, &MainWindow::slotReleaseOK);
    connect(this, &MainWindow::signalSetPosition, item, &MoveItem::slotGetPosition);
    disconnect(this, &MainWindow::signalSetPosition, item, &MoveItem::slotGetPosition);
    connect(this, &MainWindow::setAngleSpeed, item, &MoveItem::getAngleSpeed);
    connect(item, &MoveItem::signalAskForTypeOfMoving, this, &MainWindow::getTypeOfMoving);
    connect(item, &MoveItem::sharePerimeterSquare, this, &MainWindow::showPerimeterSquare);
}

void MainWindow::showPerimeterSquare(qreal perim, qreal square)
{
    ui -> lineEdit_4 -> setText(QString::number(perim));
    ui -> lineEdit_5 -> setText(QString::number(square));
}

// void MainWindow::slotReleaseOK()
// {
//     ui -> pushButton_start -> setEnabled(true);
// }

// void MainWindow::slotBlockOK()
// {
//     ui -> pushButton_start -> setEnabled(false);
// }
