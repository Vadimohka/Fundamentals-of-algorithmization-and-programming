#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAbstractScrollArea>
#include <random>
MainWindow::MainWindow(int col,QString login,QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//scroll bar
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); //scroll bar
    //setWindowFlags(Qt::FramelessWindowHint);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    scene->setSceneRect(0, 0, 4000, 4000);
    back = new QGraphicsRectItem(0, 0, 4000, 4000);
    back->setBrush(QPixmap(":/images/back.jpg"));
    back->setZValue(-100);
    scene->addItem(back);
    float Startx = ui->graphicsView->scene()->width() / 2;
    float Starty = ui->graphicsView->scene()->height() / 2;
    snakeName = login;
    snakeColorIndex = col;
    snake = new Snake(scene, Startx, Starty, login, col + 1);
    scoreBoard = new QGraphicsTextItem();
    scoreBoard->setPos(ui->graphicsView->scene()->width() / 2 - 620, ui->graphicsView->scene()->height() / 2 - 270);
    scoreBoard->setDefaultTextColor(Qt::white);
    scoreBoard->setFont(QFont("calibri", 12));
    calculateScores();
    scene->addItem(scoreBoard);
    scoreBoard->setZValue(10);
    startGame();
    ui->pauseFrame->hide();
    ui->gameOver->hide();
    connect(snake, &Snake::moveSignal, this, &MainWindow::moveScreen);
    connect(snake, &Snake::gameOverSignal, this, &MainWindow::gameOver);
    connect(ui->pauseButton, &QPushButton::clicked, this, &MainWindow::pauseGame);
    connect(ui->continueButton, &QPushButton::clicked, this, &MainWindow::continueGame);
    connect(ui->quit_but,&QPushButton::clicked, this,&MainWindow::quitToMenu);
    connect(ui->quit_but_2,&QPushButton::clicked, this,&MainWindow::quitToMenu);
}

void MainWindow::startGame() {
    numberOfAiSnakes = 10;
    ItemsContainer::allSnakesAI.clear();
    for (int i = 0; i < numberOfAiSnakes; ++i) {
        addNewSnakeAI();
    }
    spawnPeppers();
    spawnFood();
    //spawnStones();
}

void MainWindow::spawnFood() {
    ItemsContainer::allFoods.clear();
    for (int i = 0; i < 3000; ++i) {
        Food *food = new Food();
        scene->addItem(food);
        ItemsContainer::allFoods.push_back(food);
    }
}

void MainWindow::spawnStones() {
    ItemsContainer::allStones.clear();
    for (int i = 0; i < 20; ++i) {
        Stone *stone = new Stone();
        scene->addItem(stone);
        ItemsContainer::allStones.push_back(stone);
    }
}

void MainWindow::spawnPeppers() {
    ItemsContainer::allPeppers.clear();

    for (int i = 0; i < 500; ++i) {
        Pepper *pepper = new Pepper(scene);
        ItemsContainer::allPeppers.push_back(pepper);
    }
}

MainWindow::~MainWindow() {
    delete back;
    delete scene;
    delete ui;
    delete snake;
    for (int i = 0; i < ItemsContainer::allSnakesAI.size(); ++i) {
        delete ItemsContainer::allSnakesAI[i];
    }
    for (int i = 0; i < ItemsContainer::allFoods.size(); ++i) {
        delete ItemsContainer::allFoods[i];
    }
    for (int i = 0; i < ItemsContainer::allPeppers.size(); ++i) {
        delete ItemsContainer::allPeppers[i];
    }
    ItemsContainer::allSnakesAI.clear();
    ItemsContainer::allFoods.clear();
    ItemsContainer::allPeppers.clear();
    ItemsContainer::allStones.clear();
    //ItemsContainer::allInfoForScoreboard.clear();
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_A || event->key() == Qt::Key_Left) {
        snake->setDirection("left");
    }
    if (event->key() == Qt::Key_D || event->key() == Qt::Key_Right) {
        snake->setDirection("right");
    }
    if (event->key() == Qt::Key_W || event->key() == Qt::Key_Up) {
        snake->setDirection("up");
    }
    if (event->key() == Qt::Key_S || event->key() == Qt::Key_Down) {
        snake->setDirection("down");
    }
}

void MainWindow::moveScreen() {
    if(snake->getHeadPos().x() > 4000 || snake->getHeadPos().x() < 0 || snake->getHeadPos().y() > 4000 || snake->getHeadPos().y() < 0){
        snake->destroySnake();
    }
    scoreBoard->setPos(snake->getHeadPos().x() - 620, snake->getHeadPos().y() - 270);
    calculateScores();
    QPointF pos = snake->getHeadPos();
    ui->graphicsView->setSceneRect(pos.x() - 256, pos.y() - 256, 512, 512);
}

void MainWindow::pauseGame() {
    snake->pause_snake();
    for (int i = 0; i < ItemsContainer::allSnakesAI.size(); ++i) {
        ItemsContainer::allSnakesAI[i]->pause_snakeAI();
    }
    ui->pauseFrame->show();
    ui->pauseButton->hide();
}

void MainWindow::continueGame() {
    snake->continue_snake();
    ui->pauseFrame->hide();
    ui->pauseButton->show();
    for (int i = 0; i < ItemsContainer::allSnakesAI.size(); ++i) {
        ItemsContainer::allSnakesAI[i]->continue_snakeAI();
    }
}

void MainWindow::calculateScores() {
    info.clear();
    for (SnakeAI *i: ItemsContainer::allSnakesAI) {
        info.push_back({i->getName(), i->getLength()});
    }
    info.push_back({snake->getName(), snake->getLength()});
    std::sort(info.begin(), info.end(),
              [](const SnakeInfo &info1, const SnakeInfo &info2) {
                  return info1.length > info2.length;
              });
    QString text;
    for (int i = 0; i < qMin(10, (int) info.length()); ++i) {
        text += "#" + QString::number(i + 1) + info[i].name + " " + QString::number(info[i].length) + "\n";
    }
    if (!scoreBoard->collidesWithItem(back)) scoreBoard->setDefaultTextColor(Qt::black);
    else scoreBoard->setDefaultTextColor(Qt::white);
    scoreBoard->setPlainText(text);
}

void MainWindow::addNewSnakeAI() {
    if (ItemsContainer::allSnakesAI.size() < 25) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<int> xPosDistribution(0, 4000 - 15);
        std::uniform_int_distribution<int> yPosDistribution(0, 4000 - 15);
        std::uniform_int_distribution<int> nameDistribution(0, ItemsContainer::allNames.size() - 1);
        int Startx = xPosDistribution(generator);
        int Starty = yPosDistribution(generator);
        int nameIndex = nameDistribution(generator);
        snakeAI = new SnakeAI(scene, Startx, Starty, ItemsContainer::allNames[nameIndex]);
        connect(snakeAI, &SnakeAI::addNewSnakeAiSignal, this, &MainWindow::addNewSnakeAI);
        ItemsContainer::allSnakesAI.push_back(snakeAI);
    }
}

void MainWindow::gameOver() {
    for (int i = 0; i < ItemsContainer::allSnakesAI.size(); ++i) {
        ItemsContainer::allSnakesAI[i]->pause_snakeAI();
    }
    ui->pauseFrame->show();
    ui->gameOver->show();
    ui->score_label->setText(QString::number(snake->getLength()));
    database.db.open();
    database.addToTable(snake->getName(),snake->getLength());
    database.db.close();
    disconnect(snake, &Snake::gameOverSignal, this, &MainWindow::gameOver);
}

void MainWindow::quitToMenu() {
    this->close();
    menuwindow = new MenuWindow(snakeColorIndex,snakeName);
    menuwindow->show();
}