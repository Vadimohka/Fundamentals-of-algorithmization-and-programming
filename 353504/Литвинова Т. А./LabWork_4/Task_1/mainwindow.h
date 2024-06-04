#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>

class VisVector;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
  MainWindow();

  void Redraw();

private slots:
  void onClick();
  void fullUpdateVisVector();
  void searchUpdateVisVector();
  void updateVisVector();
  void playClicked();
  void playTicked();

protected:
  Ui::MainWindow *ui;
  VisVector *visvec;
  QGraphicsScene *scene;
  QTimer *playTimer;

  bool isPlaying = false;
};