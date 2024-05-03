#include "mainwindow.h"
#include "./ui_mainwindow.h"

void MainWindow::Up()
{
    int y = flag->Checky();

    if(y <= 0){
        flag->MovesUp = false;

        UpTimer->stop();
    }else{
        flag->MoveUp();
        scene->update();
    }
}

void MainWindow::Down()
{
    int y = flag->Checky();

    if(y > 165){
        flag->MovesDown = false;

        DownTimer->stop();
    }
    else{
        flag->MoveDown();
        scene->update();
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment( Qt::AlignLeft | Qt::AlignTop );
    scene->setBackgroundBrush(Qt::white);

    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap("/home/v/proga/Labs/Lab_1/Task_1/Ship.png"));
    ui->label->setAlignment(Qt::AlignHCenter);

    flag = new Flag();
    scene->addItem(flag);

    UpTimer = new QTimer(this);
    DownTimer = new QTimer(this);

    connect(DownTimer, SIGNAL(timeout()), this, SLOT(Down()));
    connect(UpTimer, SIGNAL(timeout()), this, SLOT(Up()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    flag->MovesUp = true;

    if(flag->MovesDown){
        flag->MovesDown = false;

        DownTimer->stop();
    }

    UpTimer->start(1000/60);
}


void MainWindow::on_pushButton_2_clicked()
{
    flag->MovesDown = true;

    if(flag->MovesUp){
        flag->MovesUp = false;

        UpTimer->stop();
    }

    DownTimer->start(1000/60);
}


void MainWindow::on_pushButton_3_clicked()
{
    DownTimer->stop();
    UpTimer->stop();
}

