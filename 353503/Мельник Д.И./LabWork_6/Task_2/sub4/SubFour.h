
#include "../sub3/SubThird.h"
#include <QFile>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

class SubFour : public SubThird {
  Q_OBJECT
public:
  SubFour(QWidget *parent = nullptr);
  ~SubFour();

  virtual void append(Cloth bm);
  virtual QVector<Cloth> load();
};
