#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   ui->setupUi(this);
    scene=new QGraphicsScene;
    scene->setSceneRect(QRectF(0,0,1300,600));
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setFocus();
    connect(this,SIGNAL(RectPainted()),this,SLOT(PlaceRect()));
    connect(this,SIGNAL(StartPaint()),this,SLOT(PaintRect()));
    connect(this,SIGNAL(StartGame()),this,SLOT(Start()));
    connect(this,SIGNAL(RectMoved()),this,SLOT(ColorBoard()));
    cardDeck->deck[0].x=0;
    cardDeck->deck[0].y=0;
    ui->label->hide();
    ui->enterButton->hide();
    ui->upButton->hide();
    ui->bottomButton->hide();
    ui->leftButton->hide();
    ui->rightButton->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MoveRect(QPointF angle)
{if(n!=0){
        int x=angle.x();
        int y=angle.y();

    if(cardDeck->deck[turnNumber].left==1){
            qDebug()<<cardDeck->deck[turnNumber].leftRect->rect().bottomLeft();
            cardDeck->deck[turnNumber].leftRect->setRect(x,y+20,30,10);
          cardDeck->deck[turnNumber].leftRect->setFlag(QGraphicsItem::ItemIsMovable,false);
            update();

    }
    if(cardDeck->deck[turnNumber].right==1){
        cardDeck->deck[turnNumber].rightRect->setRect(x+20,y+20,30,10);
            cardDeck->deck[turnNumber].rightRect->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].top==1){
        cardDeck->deck[turnNumber].topRect->setRect(x+20,y,10,25);
              cardDeck->deck[turnNumber].topRect->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].bottom==1){
        cardDeck->deck[turnNumber].bottomRect->setRect(x+20,y+25,10,25);
                cardDeck->deck[turnNumber].bottomRect->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].left==2){
                cardDeck->deck[turnNumber].leftCastle->setRect(x,y+10,10,30);
                cardDeck->deck[turnNumber].leftCastle->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].right==2){
                cardDeck->deck[turnNumber].rightCastle->setRect(x+40,y+10,10,30);
                cardDeck->deck[turnNumber].rightCastle->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].top==2){
                cardDeck->deck[turnNumber].topCastle->setRect(x+10,y,30,10);
                cardDeck->deck[turnNumber].topCastle->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    if(cardDeck->deck[turnNumber].bottom==2){
                cardDeck->deck[turnNumber].bottomCastle->setRect(x+10,y+40,30,10);
                cardDeck->deck[turnNumber].bottomCastle->setFlag(QGraphicsItem::ItemIsMovable,false);
    }
    }
    update();
    if(n!=0){
    turnNumber++;
    }
    n=1;
    emit RectMoved();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{


    switch(event->key()){
    case Qt::Key_A:

    for(int i=1;i<15;++i){

                if(exit==0){
                    break;
                }
                for(int j=0;j<15;++j){
                    if(cardDeck->deck[currentCard].x-cardDeck->deck[j].x==i&&cardDeck->deck[currentCard].y==cardDeck->deck[j].y){
                        cardDeck->deck[j].rect->setPen(QPen(Qt::white));
                        cardDeck->deck[currentCard].rect->setPen(QPen(Qt::black));
                        qDebug()<<"Cur="<<currentCard<<" j="<<j;
                        currentCard=j;
                        i=14;
                        break;
                    }
                }
    }
        break;
    case Qt::Key_D:
        for(int i=1;i<15;++i){

                if(exit==0){
                    break;
                }
                for(int j=0;j<15;++j){
                    if(cardDeck->deck[currentCard].x-cardDeck->deck[j].x==-i&&cardDeck->deck[currentCard].y==cardDeck->deck[j].y){
                        cardDeck->deck[j].rect->setPen(QPen(Qt::white));
                        cardDeck->deck[currentCard].rect->setPen(QPen(Qt::black));
                        qDebug()<<"Cur="<<currentCard<<" j="<<j;
                        currentCard=j;
                        i=14;
                        break;
                    }
                }
        }
        break;
    case Qt::Key_S:
        for(int i=1;i<15;++i){

                if(exit==0){
                    break;
                }
                for(int j=0;j<15;++j){
                    if(cardDeck->deck[currentCard].y-cardDeck->deck[j].y==-i&&cardDeck->deck[currentCard].x==cardDeck->deck[j].x){
                        cardDeck->deck[j].rect->setPen(QPen(Qt::white));
                        cardDeck->deck[currentCard].rect->setPen(QPen(Qt::black));
                        qDebug()<<"Cur="<<currentCard<<" j="<<j;
                        currentCard=j;
                        i=14;
                        break;
                    }
                }
        }
        break;
    case Qt::Key_W:
        for(int i=1;i<15;++i){

                if(exit==0){
                    break;
                }
                for(int j=0;j<15;++j){
                    if(cardDeck->deck[currentCard].y-cardDeck->deck[j].y==i&&cardDeck->deck[currentCard].x==cardDeck->deck[j].x){
                        cardDeck->deck[j].rect->setPen(QPen(Qt::white));
                        cardDeck->deck[currentCard].rect->setPen(QPen(Qt::black));
                        qDebug()<<"Cur="<<currentCard<<" j="<<j;
                        currentCard=j;
                        i=14;
                        break;
                    }
                }
        }
        break;
    }
}

void MainWindow::Start()
{
    cardDeck->deck[0].Paint(scene,0,0);
    emit RectPainted();
}

void MainWindow::PaintRect()
{
    cardDeck->deck[turnNumber].Paint(scene, turnNumber,turnNumber);
    emit RectPainted();
}
void MainWindow::PlaceRect()
{
    ui->enterButton->hide();
    ui->label->setText("Выберите, куда поставить свой квадрат");
    ui->upButton->show();
    ui->bottomButton->show();
    ui->leftButton->show();
    ui->rightButton->show();
}


void MainWindow::on_pushButton_clicked()
{
    emit StartGame();
}

void MainWindow::on_ClearButton_clicked()
{qDebug()<<"+";
scene->clear();
}

void MainWindow::on_enterButton_clicked()
{
emit RectChosen();
}

void MainWindow::on_upButton_clicked()
{
if(n!=0){
cardDeck->deck[turnNumber].x=cardDeck->deck[currentCard].x;
cardDeck->deck[turnNumber].y=cardDeck->deck[currentCard].y-1;
cardDeck->positionX[turnNumber]=cardDeck->deck[turnNumber].x;
cardDeck->positionY[turnNumber]=cardDeck->deck[turnNumber].y;
if(cardDeck->Check(1,currentCard,turnNumber)==true){
    QMessageBox::critical(nullptr,"ошибка", "Мегаошибка");
                return;

}
cardDeck->deck[turnNumber].rect->setPos(startPosX+cardDeck->deck[turnNumber].x*50,startPosY+cardDeck->deck[turnNumber].y*50);

}
QPointF angle;
if(n==0){
angle.setX(0);
angle.setY(0);
}
else{
angle=cardDeck->deck[turnNumber].rect->mapToScene(cardDeck->deck[turnNumber].rect->rect().topLeft());
}
MoveRect(angle);

}

void MainWindow::on_bottomButton_clicked()
{
if(n!=0){
cardDeck->deck[turnNumber].x=cardDeck->deck[currentCard].x;
cardDeck->deck[turnNumber].y=cardDeck->deck[currentCard].y+1;
cardDeck->positionX[turnNumber]=cardDeck->deck[turnNumber].x;
cardDeck->positionY[turnNumber]=cardDeck->deck[turnNumber].y;
if(cardDeck->Check(3,currentCard,turnNumber)==true){
                QMessageBox::critical(nullptr,"ошибка", "Мегаошибка");
                return;

}
cardDeck->deck[turnNumber].rect->setPos(startPosX+cardDeck->deck[turnNumber].x*50,startPosY+cardDeck->deck[turnNumber].y*50);

update();
}
QPointF angle;
if(n==0){
angle.setX(0);
angle.setY(0);
}
else{
angle=cardDeck->deck[turnNumber].rect->mapToScene(cardDeck->deck->rect->rect().bottomLeft());
angle.setY(angle.y()-50);
}
MoveRect(angle);
}

void MainWindow::on_rightButton_clicked()
{
if(n!=0){
cardDeck->deck[turnNumber].x=cardDeck->deck[currentCard].x+1;
cardDeck->deck[turnNumber].y=cardDeck->deck[currentCard].y;
cardDeck->positionX[turnNumber]=cardDeck->deck[turnNumber].x;
cardDeck->positionY[turnNumber]=cardDeck->deck[turnNumber].y;
if(cardDeck->Check(2,currentCard,turnNumber)==true){
                QMessageBox::critical(nullptr,"ошибка", "Мегаошибка");
                return;

}
cardDeck->deck[turnNumber].rect->setPos(startPosX+cardDeck->deck[turnNumber].x*50,startPosY+cardDeck->deck[turnNumber].y*50);

}
QPointF angle;
if(n==0){
angle.setX(0);
angle.setY(0);
}
else{
angle=cardDeck->deck[turnNumber].rect->mapToScene(cardDeck->deck[turnNumber].rect->rect().topRight());
angle.setX(angle.x()-50);
}
MoveRect(angle);

}

void MainWindow::on_leftButton_clicked()
{
if(n!=0){
cardDeck->deck[turnNumber].x=cardDeck->deck[currentCard].x-1;
cardDeck->deck[turnNumber].y=cardDeck->deck[currentCard].y;
cardDeck->positionX[turnNumber]=cardDeck->deck[turnNumber].x;
cardDeck->positionY[turnNumber]=cardDeck->deck[turnNumber].y;
if(cardDeck->Check(0,currentCard,turnNumber)==true){
                QMessageBox::critical(nullptr,"ошибка", "Мегаошибка");
                return;

}
cardDeck->deck[turnNumber].rect->setPos(startPosX+cardDeck->deck[turnNumber].x*50,startPosY+cardDeck->deck[turnNumber].y*50);

}
QPointF angle;
if(n==0){
angle.setX(0);
angle.setY(0);
}
else{
angle=cardDeck->deck[turnNumber].rect->mapToScene(cardDeck->deck[turnNumber].rect->rect().topLeft());
}
MoveRect(angle);

}

void MainWindow::ColorBoard()
{
cardDeck->ChangeColor();
update();
emit StartPaint();
}




