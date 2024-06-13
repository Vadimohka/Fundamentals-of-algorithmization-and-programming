#include "levelscene.h"

LevelScene::LevelScene(qint8 difficulty) {
    this->setBackgroundBrush(QBrush(Qt::black));
    QRandomGenerator64 generator(QDateTime::currentDateTime().toMSecsSinceEpoch());

    randomGenerateField(generator);

    qint32 playerX = generator.bounded(0, 20);
    qint32 playerY = generator.bounded(0, 20);
    while(!(*field)[playerY][playerX]){
        playerX = generator.bounded(0, 20);
        playerY = generator.bounded(0, 20);
    }

    Player* obj = new Player(playerX,playerY);
    player = obj;
    this->addItem(obj);
    obj->grabKeyboard();
    connect(obj, &Player::updatePos, this, &LevelScene::onPlayerChangeCell);

    randomGenerateEnemies(generator, difficulty, playerX, playerY);

    powerUpTimer = new QTimer();
    connect(powerUpTimer, &QTimer::timeout, this, &LevelScene::onPowerUpTimeout);
    powerUpTimer->start(10000 + 5000*(difficulty-1));
}

LevelScene::~LevelScene(){}

Player *LevelScene::getPlayer()
{
    return this->player;
}

void LevelScene::randomGenerateField(QRandomGenerator64 generator)
{
    field = new QVector<QVector<bool>>(20);

    for (QVector<bool>& row : *field) {
        row.fill(true, 20);
    }

    int randomNumber = generator.bounded(0, 5);
    QString mapLocation("resources/map");
    mapLocation.append(randomNumber+'0').append(".txt");
    QFile file(QDir::current().filePath(mapLocation));
    file.open(QIODevice::ReadWrite);
    QTextStream s(&file);


    for (int y = 0; y < 20; ++y) {
        QString current = s.readLine();
        for (int x = 0; x < 20; ++x) {

            if((current.at(x).unicode() - '0') == 1){
                SteelWall* wall = new SteelWall(x,y);
                this->addItem(wall);
                (*field)[y][x] = false;
            }
            if((current.at(x).unicode() - '0') == 2){
                BrickWall* wall = new BrickWall(x,y);
                this->addItem(wall);
                (*field)[y][x] = false;
                connect(wall, &BrickWall::onDeath, this, &LevelScene::onWallDestroy);
            }
        }
    }
}

void LevelScene::randomGenerateEnemies(QRandomGenerator64 generator, qint8 difficulty, qint8 playerX, qint8 playerY)
{
    QList<Square::Cell> freePoints;
    for (qint8 y = 0; y < 20; ++y) {
        for (qint8 x = 0; x < 20; ++x) {
            if((*field)[y][x]){
                Square::Cell point(x,y);
                if(x != playerX && y != playerY){
                    freePoints.append(point);
                }
            }
        }
    }

    QSet<qint32> set;
    qint32 left=0, right=freePoints.size();
    while(set.size() < difficulty+1){
        qint32 randomNumber;
        randomNumber = generator.bounded(left, right);
        set.insert(randomNumber);
    }

    foreach (auto i, set) {
        Square::Cell p = freePoints.at(i);
        Enemy *enemy = new Enemy(p.x,p.y,field);
        enemy->onPlayerCellUpdate(Square::Cell(playerX, playerY));
        connect(this, &LevelScene::updatePlayerPos, enemy, &Enemy::onPlayerCellUpdate);
        connect(enemy, &Enemy::enemyDeathSignal, this, &LevelScene::onEnemyDeathSlot);
        this->addItem(enemy);
        ++currentEnemiesCount;
    }
}

void LevelScene::onPowerUpTimeout()
{
    QList<Square::Cell> freePoints;

    for (qint8 y = 0; y < 20; ++y) {
        for (qint8 x = 0; x < 20; ++x) {
            Square::Cell cell(x, y);
            if ((*field)[y][x]){
                freePoints.append(cell);
            }
        }
    }

    foreach(auto item, this->items()){
        if(Tank *tank = dynamic_cast<Tank*>(item)){
            for(qint8 y = tank->getCell().y - 1; y <= tank->getCell().y + 1; ++y){
                for(qint8 x = tank->getCell().x - 1; x <= tank->getCell().x + 1; ++x){
                    Square::Cell cell(x, y);
                    if (freePoints.contains(cell)){
                        freePoints.removeOne(cell);
                    }
                }
            }
        }
    }

    if(freePoints.size() == 0){
        return;
    }

    QRandomGenerator64 generator(QDateTime::currentDateTime().toMSecsSinceEpoch()/2);
    int randomNumber;
    randomNumber = generator.bounded(0, freePoints.size());
    Square::Cell freePoint = freePoints.at(randomNumber);

    PowerUp *pup = new PowerUp(freePoint.x, freePoint.y);
    this->addItem(pup);
}

void LevelScene::onWallDestroy(Square::Cell cell)
{
    (*field)[cell.y][cell.x] = true;
}

void LevelScene::onPlayerChangeCell(Square::Cell cell)
{
    emit updatePlayerPos(cell);
}

void LevelScene::onEnemyDeathSlot()
{
    --currentEnemiesCount;
    emit enemyDeathSignal();
    if(currentEnemiesCount <= 0){
        emit nextRoundSignal();
    }
}
