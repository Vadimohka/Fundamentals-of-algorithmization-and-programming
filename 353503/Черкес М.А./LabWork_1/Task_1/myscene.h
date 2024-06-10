#ifndef MYSCENE_H
#define MYSCENE_H

#include <abstractfigure.h>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QMouseEvent>

class MyScene : public QGraphicsScene {
  Q_OBJECT

  //   Q_PROPERTY(int typeFigure
  //                READ typeFigure WRITE setTypeFigure
  //                    NOTIFY typeFigureChanged)
 public:
  explicit MyScene(QObject* parent = 0);
  void setTypeFigure(const int type);
 signals:
 private:
  abstractFigure* tempfigure;

 private:
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
  void keyPressEvent(QKeyEvent* event);
  void keyReleaseEvent(QKeyEvent* event);
  abstractFigure* item;
  abstractFigure* m_movingItem = nullptr;
  bool rKeyPressed = false;
  QPointF m_lastPos;
  QPointF lastMousePos;
};

#endif  // MYSCENE_H
