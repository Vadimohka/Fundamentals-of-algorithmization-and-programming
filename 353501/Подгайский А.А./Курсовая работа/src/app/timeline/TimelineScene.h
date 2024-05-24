#ifndef AEDIT_TIMELINESCENE_H
#define AEDIT_TIMELINESCENE_H

#include "EffectSelection.h"
#include <QGraphicsScene>
#include <qcontainerfwd.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>
#include <qpixmap.h>
#include <qscopedpointer.h>
#include <qtmetamacros.h>
#include <qvariant.h>
#include <qwidget.h>


enum class MouseBehaviour{
  Selection,
  Navigation
};

class TimelineScene : public QGraphicsScene {
  Q_OBJECT

public:
  static constexpr QColor SELECTION_COLOR = QColor(100, 100, 100, 100);
  static constexpr QColor LEFT_WAVEFORM_COLOR = QColor(200, 200, 240, 255);
  static constexpr QColor RIGHT_WAVEFORM_COLOR = QColor(240, 200, 200, 255);

  const QPen posPtrPen = {Qt::white, 4, Qt::SolidLine, Qt::RoundCap};

private:
  //StereoAudioBuffer buffer;
  QTimer* updater;

  QGraphicsRectItem *selectionRect = nullptr;
  QGraphicsPixmapItem *leftPixmap = nullptr, *rightPixmap = nullptr;
  QGraphicsLineItem *posPointer = nullptr;

  int selectionStart = 0, selectionEnd = 0;
  int viewWidth = 0;
  int viewHeight = 0; 

  MouseBehaviour mBehaviour = MouseBehaviour::Navigation;

  QVector<EffectSelection*> effects;
  EffectSelection* selectedEffect = nullptr;

  bool pressed = false;


private slots:
  void updatePosPointer();

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

  void selectionPress(QGraphicsSceneMouseEvent *event);
  void selectionMove(QGraphicsSceneMouseEvent *event);
  void navigate(QGraphicsSceneMouseEvent *event);

public:
  TimelineScene(QWidget *widget = nullptr);
  ~TimelineScene();

  // void setBuffer(StereoAudioBuffer buffer);
  void drawWaveform();
  void drawSelection();
  void selectAll();

  const QColor& getLastEffectColor();


  void pushEffect(int beg, int end);
  void selectEffect(int i);
  void resetEffects();

  std::pair<int, int> getSelection() const;
  void setMouseBehaviour(MouseBehaviour mb);

  signals:
    void posPointerChanged();
    void selectionChanged(int beg, int end);
};

#endif // AEDIT_TIMELINESCENE_H