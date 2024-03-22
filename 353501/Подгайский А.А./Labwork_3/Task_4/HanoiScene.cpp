#include "HanoiScene.h"
#include <qbrush.h>
#include <qcolor.h>
#include <qelapsedtimer.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qlogging.h>
#include <qpoint.h>
#include <qtimer.h>

HanoiScene::HanoiScene(const QRectF &sceneRect, QObject *parent)
    : QGraphicsScene(sceneRect, parent), baseHeight(r_baseHeight * height()),
      baseWidth(r_baseWidth * width()), ringHeight(r_ringHeight * height()),
      towerWidth(r_towerWidth * width()), towerHeight(r_towerHeight * height()),
      maxRingLength(r_maxRingLength * width()),
      dRingLength(r_deltaRingLength * width()), abovePos(r_abovePos * height()),
      baseBrush(Qt::darkGray, Qt::SolidPattern),
      towerBrush(Qt::darkGray, Qt::Dense5Pattern) {
  drawTowers();
  timerPtr.reset(new QTimer);
  elapsedTimerPtr.reset(new QElapsedTimer);
  connect(timerPtr.data(), &QTimer::timeout, this, &HanoiScene::update);
}

HanoiScene::HanoiScene(QObject *parent) : HanoiScene(defaultSize, parent) {}

void HanoiScene::drawTowers() {
  auto x = width() / 4;
  for (int i = 0, k = 1; i < 3; ++i, ++k) {
    auto base = new QGraphicsRectItem(-baseWidth / 2, 0, baseWidth, baseHeight);
    base->setBrush(baseBrush);
    base->setPos(k * x, 0);
    addItem(base);

    auto tower =
        new QGraphicsRectItem(-towerWidth / 2, 0, towerWidth, towerHeight);
    tower->setBrush(towerBrush);
    tower->setPos(k * x, baseHeight);
    addItem(tower);
  }
}

void HanoiScene::drawRings(int n) {
  auto yPos = baseHeight;
  auto length = maxRingLength;
  auto tower1Pos = width() / 4;

  auto r = 200, g = 0, b = 0;

  for (int i = n; i >= 1; --i) {
    QBrush brush({r, g, b});
    auto ring = new QGraphicsRectItem(-length / 2, 0, length, ringHeight);
    ring->setBrush(brush);
    ring->setPos(tower1Pos, yPos);
    addItem(ring);
    rings[0].push_back(ring);

    yPos += ringHeight;
    length -= dRingLength;

    r = 50 * std::cos(2 * M_PI / 10 * (10 - i)) + 100;
    g = 50 * std::cos(2 * M_PI / 10 * (10 - i) + M_PI / 2) + 100;
    b = 50 * std::cos(2 * M_PI / 10 * (10 - i) + M_PI) + 100;
  }
}

void HanoiScene::resetRings(int n){
  animation.isActive = false;
  for(int i = 0; i < 3; ++i){
    foreach(auto r, rings[i]){
      removeItem(r);
    }
    rings[i].clear();
  }
  drawRings(n);
}

void HanoiScene::startRingMove(short src, short dst) {
  if (animation.isActive) {
    return;
  }

  animation.isActive = true;
  animation.movingRing = rings[src].back();
  animation.phase = AnimPhase::Up;
  animation.dstX = width() / 4 * (dst+1);
  animation.dstY = rings[dst].size() * ringHeight + baseHeight;
  animation.aboveDirectionPositive = (dst > src);

  rings[src].pop_back();
  rings[dst].push_back(animation.movingRing);

  elapsedTimerPtr->start();
  timerPtr->start(1000.f / 60);
}

void HanoiScene::update() {

  if(!animation.isActive){
    return;
  }
  auto dPath = ringSpeed * elapsedTimerPtr->elapsed() / 1000;
  auto movingRing = animation.movingRing;

  switch (animation.phase) {
  case AnimPhase::Up: {
    auto newPos = movingRing->pos() + QPoint(0, dPath);
    if (newPos.y() > abovePos) {
      newPos.setX(newPos.x() + (newPos.y() - abovePos));
      newPos.setY(abovePos);
      animation.phase = AnimPhase::Above;
    }
    movingRing->setPos(newPos);
  } break;

  case AnimPhase::Above: {
    auto signedDPath = animation.aboveDirectionPositive ? dPath : -dPath;
    auto newPos = movingRing->pos() + QPoint(signedDPath, 0);
    if (animation.aboveDirectionPositive && newPos.x() > animation.dstX ||
        !animation.aboveDirectionPositive && newPos.x() < animation.dstX) {
      newPos.setY(abovePos - std::abs(animation.dstX - newPos.x()));
      newPos.setX(animation.dstX);
      animation.phase = AnimPhase::Down;
    }
    movingRing->setPos(newPos);
  } break;

  case AnimPhase::Down: {
    auto newPos = movingRing->pos() + QPointF(0, -dPath);
    if (newPos.y() < animation.dstY) {
      newPos.setY(animation.dstY);
      animation.isActive = false;
      timerPtr->stop();
      emit animationFinished();
    }
    movingRing->setPos(newPos);
  } break;
  }

  elapsedTimerPtr->restart();
  QGraphicsScene::update();
}

void HanoiScene::setSpeed(int s) {
  ringSpeed = s;
}
