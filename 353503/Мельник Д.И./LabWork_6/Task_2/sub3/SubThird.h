#pragma once

#include "Cloth.h"
#include <QFile>
#include <qtconfigmacros.h>
#include <qtmetamacros.h>
#include <qwidget.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class SubThird;
}
QT_END_NAMESPACE


class SubThird : public QWidget {
  Q_OBJECT
public:
  SubThird(QWidget *parent = nullptr);
  ~SubThird();

protected:
  virtual void append(Cloth bm);
  virtual QVector<Cloth> load();

private slots:
  void onSave();
  void onOpen();

protected:
  Ui::SubThird *ui;
};
