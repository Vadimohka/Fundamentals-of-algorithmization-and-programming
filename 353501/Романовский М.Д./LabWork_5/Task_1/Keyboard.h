#pragma once

#include <QGraphicsObject>
#include <QObject>
#include <qbrush.h>
#include <qgraphicsitem.h>



class KeyboardKey : public QGraphicsObject {
  Q_OBJECT

public:
  KeyboardKey(int width = 64, QGraphicsItem *parent = nullptr);

  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget) override;

  QRectF boundingRect() const override;

  void setColor(QBrush color);

private:
  QBrush color;
  int width;
};

const int MAIN_KEYS_COUNT = 33;

class Keyboard: public QGraphicsItemGroup {
public: 
  Keyboard();
  
  void setCombo(QString keyName, int preferredLang);
  void setAllColor(QBrush color);

private:
  KeyboardKey *mainKeys[MAIN_KEYS_COUNT];
  KeyboardKey *shifts[2];
  KeyboardKey *space;
  KeyboardKey *curCombo;
};