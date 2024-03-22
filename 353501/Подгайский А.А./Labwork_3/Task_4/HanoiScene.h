#ifndef HANOI_SCENE
#define HANOI_SCENE

#include <QElapsedTimer>
#include <QGraphicsWidget>
#include <QTimer>
#include <qbrush.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qscopedpointer.h>
#include <qtmetamacros.h>
#include <qwidget.h>

enum class AnimPhase { Up, Above, Down };

struct HanoiAnimation {
  bool isActive = false;
  QGraphicsItem *movingRing = nullptr;
  AnimPhase phase = AnimPhase::Up;

  float dstX, dstY;
  bool aboveDirectionPositive;
  float totalPath;
};

class HanoiScene : public QGraphicsScene {

  Q_OBJECT

public:
  explicit HanoiScene(QObject *parent = nullptr);
  explicit HanoiScene(const QRectF &sceneRect, QObject *parent = nullptr);

  static constexpr QRectF defaultSize = {0, 400, 400.f, 500.f};
  static constexpr float r_towerWidth = 0.05;
  static constexpr float r_towerHeight = 0.74;
  static constexpr float r_baseWidth = 0.23;
  static constexpr float r_baseHeight = 0.12;
  static constexpr float r_ringHeight = 0.06;
  static constexpr float r_maxRingLength = 0.200;
  static constexpr float r_deltaRingLength = 0.01;
  static constexpr int r_maxRingRank = 10;
  static constexpr float r_abovePos = 0.9;

  void startRingMove(short src, short dst);
  void resetRings(int n);
  void setSpeed(int s);

private:
  const float towerWidth;
  const float baseWidth;
  const float baseHeight;
  const float ringHeight;
  const float maxRingLength;
  const float dRingLength;
  const float towerHeight;
  const float abovePos;

  float ringSpeed = 6000;

  QBrush baseBrush;
  QBrush towerBrush;

  QVector<QGraphicsItem *> rings[3];
  HanoiAnimation animation;

  QScopedPointer<QTimer> timerPtr;
  QScopedPointer<QElapsedTimer> elapsedTimerPtr;

private:
  void drawTowers();
  void drawRings(int n);
  void update();

signals:
  void animationFinished();
};

#endif