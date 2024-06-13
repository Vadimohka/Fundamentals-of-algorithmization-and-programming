#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->graphicsView->setFixedSize(800, 800);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->verticalLayoutWidget_3->hide();
    ui->graphicsView->hide();
    ui->verticalLayoutWidget_2->hide();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startGame(qint8 difficulty)
{
    this->killCount = 0;
    this->difficulty = difficulty;
    ui->verticalLayoutWidget->hide();
    ui->verticalLayoutWidget_3->show();
    ui->graphicsView->show();
    startRound();
}

void Widget::on_easyPushButton_clicked()
{
    startGame(1);
}


void Widget::on_mediumPushButton_clicked()
{
    startGame(2);
}


void Widget::on_hardPushButton_clicked()
{
    startGame(3);
}

void Widget::gameOver()
{
    scene->deleteLater();
    ui->verticalLayoutWidget_3->hide();
    ui->graphicsView->hide();
    ui->verticalLayoutWidget_2->show();
}

void Widget::nextRoundSlot()
{
    scene->deleteLater();
    startRound();
}

void Widget::changePlayerHp(qint8 hp)
{
    ui->healthLabel->setText(QString::number(hp));
    if (hp <= 0){
        gameOver();
    }
}

void Widget::increaseKillCount()
{
    ++killCount;
    ui->killsLabel->setText(QString::number(killCount));
}

void Widget::startRound()
{
    LevelScene* scene = new LevelScene(difficulty);
    this->scene = scene;
    scene->setSceneRect(0,0,800,800);
    ui->graphicsView->setScene(scene);
    connect(scene, &LevelScene::nextRoundSignal, this, &Widget::nextRoundSlot);
    connect(scene, &LevelScene::enemyDeathSignal, this, &Widget::increaseKillCount);
    connect(scene->getPlayer(), &Player::changePlayerHP, this, &Widget::changePlayerHp);
    changePlayerHp(10);
    ui->killsLabel->setText(QString::number(killCount));
}


void Widget::on_restartButton_clicked()
{
    ui->verticalLayoutWidget_2->hide();
    ui->verticalLayoutWidget->show();
}

