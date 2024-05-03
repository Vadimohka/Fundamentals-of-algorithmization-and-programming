#pragma once

#include <QMainWindow>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <QKeyEvent>

class Keyboard;
class LetterBox;
class PixArt;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

const int LIVES_COUNT = 8;

class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
  MainWindow();

private:
  void startGame(QString expected);
  void finishGame(bool victory);
  void updateOuts();
  void addEntered(QString c);
  void updateKeyboardHint();

private slots:
  void textEntered();
  void mainTime();
  void keyCaught(Qt::Key key, bool pressed);
  void selectedStart();
  void doBackspace();

protected:
  Ui::MainWindow *ui;
  QList<LetterBox*> boxes;
  int currentBox;
  
  QGraphicsScene *gameScene;
  QGraphicsItemGroup *boxGroup;
  QGraphicsTextItem *finalText;
  PixArt *lives[LIVES_COUNT];
  PixArt *ghost;

  QList<int> wordEnds;
  long long startedAt;
  long long prevUpdate;
  int livesLeft;
  bool playing;

  QTimer *mainTimer;

  QGraphicsScene *keyboardScene;
  Keyboard *keyboard;
  
  int preferredLang;
  bool isRTL;
};