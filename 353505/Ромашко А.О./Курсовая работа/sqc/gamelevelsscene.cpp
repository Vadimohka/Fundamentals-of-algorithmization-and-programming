#include "gamelevelsscene.h"
#include "ui_gamelevelsscene.h"

GameLevelsScene::GameLevelsScene(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GameLevelsScene)
{
    ui->setupUi(this);
    DSV = new DialogShowCards;
    graphicsView =  new QGraphicsView;
    scene = new Graph(21);
    d = new DialogShop();
    d->setEnabled(0);
    DSV = new DialogShowCards;
    connect(this,&GameLevelsScene::openShop,d,&DialogShop::openSlot);
    player = scene->setPlayer();
    player->setDeck()->addCardsToGame();
    setWindowTitle("Игровые уровни");
    ui->graphicsView->setScene(scene);
    connect(scene, &Graph::forOpenGameScene,this,&GameLevelsScene::getInfoGameScene);
    connect(d,&DialogShop::showLines,scene,&Graph::easyPath);
    d->getPlayer(this->player);
    ui->pushButton_Shop->setEnabled(0);
    ui->pushButton_ShowCards->setEnabled(0);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->label->setStyleSheet(
        "QLabel { "
        "   color: gray; "     /* Зеленый цвет текста */
        "   font-size: 89px; "  /* Размер шрифта */
        "   font-weight: bold;" /* Жирный шрифт */
        "}"
        );
    graphicsView->setFixedSize(820, 720);
}

GameLevelsScene::~GameLevelsScene()
{
    if(player)
    player->~Player();
}

void GameLevelsScene::openSlot()
{
    qDebug() << "GameLevelsScene opened";
    this->setEnabled(true);
    this->setVisible(1);
    this->showFullScreen();
    if(flag){
    ui->pushButton_Shop->setEnabled(1);
    ui->pushButton_ShowCards->setEnabled(1);
    }
}

void GameLevelsScene::getInfoGameScene(GameScene *gameS)
{
    flag=1;
    gameScene= new GameScene();
    gameScene = gameS;
    d->setEnabled(1);
    gameScene->getPlayer(player);
    scene->getGameScene(gameScene);
    player->getEnergy(3);
    player = scene->setPlayer();
    gameScene->generateGraphicsView();
    connect(this->gameScene, &GameScene::goBack, this, &GameLevelsScene::openSlot);
    connect(this,&GameLevelsScene::openGameScene,this->gameScene,&GameScene::openSlot);
    connect(gameScene,&GameScene::lose,this,&GameLevelsScene::openMainMenu);
    DSV->getPlayerAndDeck(player);
    connect(this,&GameLevelsScene::openShowCards,DSV,&DialogShowCards::open);
    DSV->enableCardsActivity();
    DSV->hide();
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setScene(scene);
    qDebug() << "getInfoGameScene";
    emit openGameScene();
    this->setEnabled(false);
    this->hide();
}

void GameLevelsScene::openMainMenu()
{
    on_pushButton_Back_clicked();
}

void GameLevelsScene::on_pushButton_Back_clicked()
{
    emit GameLevelSceneExitSignal();
    QApplication::exit();
    this->close();
}

void GameLevelsScene::mousePressEvent(QMouseEvent *event)
{
}

void GameLevelsScene::on_pushButton_ShowCards_clicked()
{
    emit openShowCards();
}

void GameLevelsScene::on_pushButton_Shop_clicked()
{
    emit openShop();
}

