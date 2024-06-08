#include "title.h"

#include <QMessageBox>

Title::Title(View *view, QWidget *parent) : QGraphicsScene(parent){

    viewer = view;
    viewer->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    scroll = new QScrollBar;
    scroll = viewer->horizontalScrollBar();
    foreground = new QGraphicsPixmapItem(QPixmap(":/images/fon.png"));
    logo = new QGraphicsPixmapItem(QPixmap(":/images/logo.png"));

    logo->setPos((width - logo->boundingRect().width()) / 2, height / 12);
    addItem(foreground);
    addItem(logo);
    this->setFocus();
    this->setSceneRect(0,0,1280,720);
    view->sceneSet(this);

    developerButton = new QPushButton(viewer);
    developerButton->setText("Start");
    developerButton->setToolTip("Please,press the button");
    developerButton->setGeometry(QRect(570, 420, 150, 45));
    connect(developerButton, SIGNAL(clicked()), this, SLOT(developerLogin()));

    generate = new QPushButton(viewer);
    generate->setText("Chellenge");
    generate->setToolTip("Please,press the button");
    generate->setGeometry(QRect(370, 420, 150, 45));
    connect(generate, SIGNAL(clicked()), this, SLOT(GenerateRandom()));

    coin = new QLineEdit(viewer);
    coin->setGeometry(QRect(370, 470, 40, 25));
    coin->setText("Coin :");
    coin->setReadOnly(true);

    timer = new QLineEdit(viewer);
    timer->setGeometry(QRect(450, 470, 50, 25));
    timer->setText("Timer :");
    timer->setReadOnly(true);

    quitButton = new QPushButton(viewer);
    quitButton->setText("Quit");
    quitButton->setToolTip("Quit program");
    quitButton->setGeometry(QRect(570, 470, 150, 45));
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));

}
void Title::quitProgram(){

    qApp->quit();
}

void Title::GenerateRandom(){
    int coinValue = random->getRandomValue(0,100);
    coin->setText(QString::number(coinValue));

    int timeValue = random->getRandomValue(25,60 );
    timer->setText(QString::number(timeValue));
}

void Title::developerLogin(){

    developerButton->close();
    coin->close();
    timer->close();
    generate->close();
    quitButton->close();
    scene = new MyScene(scroll,this);
    viewer->sceneSet(scene);
}
