#ifndef WIDGET_H
#define WIDGET_H

#include "levelscene.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void startGame(qint8 difficulty);
private slots:
    void nextRoundSlot();
    void on_easyPushButton_clicked();
    void on_mediumPushButton_clicked();
    void on_hardPushButton_clicked();
    void on_restartButton_clicked();

private:
    LevelScene *scene;
    Ui::Widget *ui;
    qint8 playerHP;
    qint8 difficulty;
    qint64 killCount=0;
    void changePlayerHp(qint8 hp);
    void increaseKillCount();
    void startRound();
    void gameOver();
};
#endif // WIDGET_H
