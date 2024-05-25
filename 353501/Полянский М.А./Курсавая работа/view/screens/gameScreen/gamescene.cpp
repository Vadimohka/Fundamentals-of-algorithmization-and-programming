#include "view/screens/gameScreen/gamescene.h"

#include "view/hud/gametitle.h"
#include "view/screens/gameScreen/modals/lostwonmodal.h"
#include "view/screens/gameScreen/modals/pausemodal.h"

using std::vector;

namespace view {

GameScene::GameScene(const SP<model::GameModel>& model) : _model(model) {
    // Performance optimization
    setItemIndexMethod(QGraphicsScene::NoIndex);

    setSceneRect(0, 0, 1920, 1080);

    drawBackground();
    createHUD();

    gridField = new GridField(QSize(96 * 16, 96 * 9), _model->getMap(), _model->getBlockedCellsMap());
    gridField->setPos(0, 1080 - gridField->boundingRect().height());
    addItem(gridField);
    connect(gridField, &GridField::cellPressed, this, &GameScene::gridCellPressed);
    connect(gridField, &GridField::turretHovered, this, &GameScene::showTurretInfos);
    connect(gridField, &GridField::turretHoverLeave, this, &GameScene::hideTurretInfos);
    connect(gridField, &GridField::spawnGranadeExplosion, this, &GameScene::spawnGranadeExplosion);

    turretSelector = new TurretSelector();
    connect(turretSelector, &TurretSelector::losedFocusSignal, this, &GameScene::closeTurretSelector);
    connect(turretSelector, &TurretSelector::turretHovered, this, [=](model::TurretType type) { emit showTurretInfos(type, gridField->getSelectedCellPosition()); });
    connect(turretSelector, &TurretSelector::turretHoverLeave, this, &GameScene::hideTurretInfos);
    connect(turretSelector, &TurretSelector::turretSelected, this, &GameScene::addTurret);
    addItem(turretSelector);

    turretRadiusPreview = new TurretRadiusPreview();
}

void GameScene::drawBackground() {
    QBrush brush = QBrush(QColor::fromRgb(50, 50, 50));
    setBackgroundBrush(brush);
}

void GameScene::createHUD() {
    creditsInfo = new InfoBox(":/assets/images/hud/coin.png", QString::number(_model->getCredits()));
    creditsInfo->setPos(10, 15);
    addItem(creditsInfo);

    lifeInfo = new InfoBox(":/assets/images/hud/heart.png", QString::number(_model->getLife()));
    lifeInfo->setPos(10, 110);
    addItem(lifeInfo);

    pauseButton = new IconButton(":/assets/images/hud/pause-button-idle.png", ":/assets/images/hud/pause-button-pressed.png");
    pauseButton->setPos(1650, 50);
    addItem(pauseButton);
    connect(pauseButton, &IconButton::pressed, this, &GameScene::pauseButtonPressed);

    fastForwardButton = new IconButton(":/assets/images/hud/fast-forward-button-idle.png", ":/assets/images/hud/fast-forward-button-pressed.png");
    fastForwardButton->setPos(1800, 50);
    addItem(fastForwardButton);
    connect(fastForwardButton, &IconButton::pressed, this, &GameScene::fastForwardGame);

    turretInfosPanel = new TurretInfosPanel();
    turretInfosPanel->setPos(96 * 16 + 10, 1080 - 96 * 9);
    addItem(turretInfosPanel);

    GameTitle* title = new GameTitle();
    title->setPos(
        1920 / 2 - title->boundingRect().width() / 2,
        (1080 - 96 * 9) / 2 - title->boundingRect().height() / 2);
    addItem(title);
}

void GameScene::tick() {
    // Update info
    creditsInfo->setText(QString::number(_model->getCredits()));
    lifeInfo->setText(QString::number(_model->getLife()));
    turretSelector->updateAvailability(_model->getCredits());

    gridField->tick();

    // Tick explosions
    auto i = explosions.begin();
    while (i != explosions.end()) {
        if ((*i)->tick()) {
            removeItem(*i);
            i = explosions.erase(i);
        } else {
            i++;
        }
    }

    // Enemies tick
    auto j = enemies.begin();
    while (j != enemies.end()) {
        if ((*j)->isDead()) {
            // Spawn explosion

            Explosion* explosion = new Explosion(ExplosionType::EnemyExplosion);
            explosion->setPos(gridField->mapToScene((*j)->pos()));
            explosions.push_back(explosion);
            addItem(explosion);

            // Delete enemy
            removeItem(*j);
            j = enemies.erase(j);

        } else {
            (*j)->tick();
            ++j;
        }
    }

    update();
}

void GameScene::spawnEnemy(const SP<model::Enemy>& enemy) {
    EnemyItem* en = new EnemyItem(gridField, enemy, 96);
    enemies.push_back(en);
}

void GameScene::turretsAttack(const vector<SP<model::Turret>>& attackingTurrets) {
    gridField->turretsAttack(attackingTurrets, enemies);
}

void GameScene::addTurretItem(const SP<model::Turret>& turret, model::TurretType turretType) {
    closeTurretSelector();
    gridField->addTurretItem(turret, turretType);
}

void GameScene::gridCellPressed(GridCellType cellType, const model::Position& cellPosition) {
    if (cellType == GridCellType::Free) {
        turretSelector->setPos(
            qMax(cellPosition.x * 96 + 48 - turretSelector->boundingRect().width() / 2, 0.0),
            cellPosition.y * 96 - turretSelector->boundingRect().height() + 1080 - gridField->boundingRect().height());

        // TODO: set fixed cell size
        turretSelector->setVisible(true);
        turretSelector->setFocus();
    } else if (cellType == GridCellType::Occupied) {
        hideTurretInfos();
        emit removeTurretSignal(cellPosition);
    }
}

void GameScene::closeTurretSelector() {
    turretSelector->setVisible(false);
    gridField->selectCell(nullptr);
}

void GameScene::showTurretInfos(model::TurretType turretType, const model::Position& cellPosition) {
    turretInfosPanel->setTurretType(turretType);

    U_INT radius = model::turretTypes.at(turretType).attackRadius;
    turretRadiusPreview->setRadius(radius);
    turretRadiusPreview->setPos(cellPosition.x * 96 - radius * 96, cellPosition.y * 96 - radius * 96 + 1080 - gridField->boundingRect().height());
    addItem(turretRadiusPreview);
}

void GameScene::hideTurretInfos() {
    turretInfosPanel->hideInfos();
    removeItem(turretRadiusPreview);
}

void GameScene::addTurret(model::TurretType turretType) {
    // Get selected cell position
    model::Position position = gridField->getSelectedCellPosition();

    emit addTurretSignal(position, turretType);
}

void GameScene::showModal(model::Game::State stato) {
    view::LostWonModal* modal = new view::LostWonModal(stato, QSize(width(), height()));
    addItem(modal);
    connect(modal, &LostWonModal::restart, this, &GameScene::restart);
    connect(modal, &LostWonModal::returnToMenu, this, &GameScene::returnToMenu);
}

void GameScene::spawnGranadeExplosion(const QPointF& position) {
    Explosion* explosion = new Explosion(ExplosionType::GranadeExplosion);
    QPointF tempPos = gridField->mapToScene(position);
    explosion->setPos(tempPos.x() - explosion->boundingRect().width() / 2, tempPos.y() - explosion->boundingRect().height() / 2);
    explosions.push_back(explosion);
    addItem(explosion);
}

void GameScene::pauseButtonPressed() {
    emit playPauseGame();

    PauseModal* modal = new PauseModal(QSize(width(), height()));
    addItem(modal);
    connect(modal, &Modal::close, this, [=]() {
        removeItem(modal);
        delete modal;
        emit playPauseGame();
    });

    connect(modal, &PauseModal::returnToMenu, this, [=]() {
        removeItem(modal);
        delete modal;
        enemies.clear();
        emit returnToMenu();
    });
}

void GameScene::changeFastForwardIcon(bool isFastForward) {
    if (isFastForward) {
        fastForwardButton->changeImages(
            ":/assets/images/hud/play-button-idle.png",
            ":/assets/images/hud/play-button-pressed.png");
    } else {
        fastForwardButton->changeImages(
            ":/assets/images/hud/fast-forward-button-idle.png",
            ":/assets/images/hud/fast-forward-button-pressed.png");
    }
}

}  // namespace view
