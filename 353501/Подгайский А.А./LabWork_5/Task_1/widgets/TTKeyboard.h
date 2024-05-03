#ifndef DB143960_FA9C_48E6_BD47_F5EABD439421
#define DB143960_FA9C_48E6_BD47_F5EABD439421

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVector>
#include <numeric>
#include <qevent.h>
#include <qgraphicsscene.h>
#include <qnamespace.h>

class TTKeyboard : public QGraphicsView {

  QGraphicsScene *scene;

  const int ROWS = 3;
  const int KEYS_IN_RAW[3] = {12, 11, 10};
  const int KEYS_SZ =
      std::accumulate(std::begin(KEYS_IN_RAW), std::end(KEYS_IN_RAW), 0);
  const int KEY_BIAS = -Qt::Key_A;
  const int KEY_HIGHLIGHT_TIME = 200;
  const double KEY_SPAN_RATIO = 0.2;

  QStringList defaultKboard = {"q", "w", "e", "r", "t", "y", "u", "i", "o",
                             "p", "[", "]", "a", "s", "d", "f", "g", "h",
                             "j", "k", "l", ";", "'", "z", "x", "c", "v",
                             "b", "n", "m", ",", ".", "/"};

  QStringList kboardChars = defaultKboard;
  void drawKeys();

  QVector<QGraphicsPathItem *> keyItems;
  QVector<QGraphicsTextItem *> textItems;

public:
  TTKeyboard(QWidget *par = nullptr);
  ~TTKeyboard();
  void showEvent(QShowEvent *) override;
  void highlightKey(int);
  void setKeyboardChars(const QString & = {});
};

#endif /* DB143960_FA9C_48E6_BD47_F5EABD439421 */
