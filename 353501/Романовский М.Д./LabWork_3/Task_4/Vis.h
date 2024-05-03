#include <QGraphicsScene>
#include <QList>
#include <QStack>
#include <QTimer>
#include <qobject.h>
#include <qpoint.h>
#include <qtmetamacros.h>

class Vis : public QObject {
  Q_OBJECT

public:
  Vis();
  void resetVis(int diskCount, QList<QPair<int, int>> *solution);
  void setSelection(int selected);

private:
  void updateVis();
  void drawArrow(int action);
  QRectF getDisk(int disk, int rod, int fromTop);
  void drawRect(QRectF pos, int disk);

private:
  int diskCount;
  int selectedRow;
  QList<QPair<int, int>> *solution;
  QTimer *timer;

  QStack<int> rods[3];
  int currentAction;
  int currentDisk = -1;
  int targetRod = 0;
  float speed = 20;

  QRectF currentRect;

public:
  QGraphicsScene *scene;
};