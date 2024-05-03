#pragma once

#include <QLineEdit>
#include <qnamespace.h>
#include <qwidget.h>

class CatchyLineEdit: public QLineEdit {
  Q_OBJECT
public:
  CatchyLineEdit(QWidget *parent = nullptr);

signals:
  void keyCaught(Qt::Key key, bool pressed);
  void doBackspace();

protected:
  void keyPressEvent(QKeyEvent *e) override;
  void keyReleaseEvent(QKeyEvent *e) override;
  void inputMethodEvent(QInputMethodEvent *e) override;
};