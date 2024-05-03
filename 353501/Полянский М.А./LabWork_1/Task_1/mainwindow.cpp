#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "truck.h"
//#include "body.h"

MainWindow::MainWindow(): ui(new Ui::MainWindow) {
    ui->setupUi(this);
    
    scene = new QGraphicsScene(this);
    
    Truck *truck = new Truck(0, 0, 200, 100);
    scene->addItem(truck);
    int x = 100; //100 , 400
    int y = -75; //-75 , 75
    int width = 300;
    int height = 150;
    body = new Body(x, y, width, height);
    scene->addItem(body);
    view = ui->graphicsView;
    view->setScene(scene);
    
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::rotateBody);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::rotateDown);

}

void  MainWindow::rotateBody(){
    if(body!= nullptr){
        body->rotate();
        ui->graphicsView->viewport()->update();
    }
   
}

void MainWindow::rotateDown(){
    if(body!=nullptr){
        body->rotateDown();
        ui->graphicsView->viewport()->update();
    }
}



