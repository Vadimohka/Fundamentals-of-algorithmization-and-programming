#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QtWidgets>
#include "gamescene.h"
#include "player.h"

enum Difficulty
{
    EASY,
    MEDIUM,
    HARD
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

#define FRAME_RATE 60

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;

    void updateGame();
    void setupGame();
    void beginGame();
    void returnToMenu();
    void enableEscKey();
    void disableEscKey();
    void on_gameOver();

private slots:
    void repeatMusic(QMediaPlayer::MediaStatus status);
    void askToQuit();
    void on_startButton_clicked();
    void on_quitButton_clicked();

    void on_radioButton_Easy_clicked(bool checked);

    void on_radioButton_Medium_clicked(bool checked);

    void on_radioButton_Hard_clicked(bool checked);

    void on_comboBox_currentIndexChanged(int index);

private:
    QMediaPlayer *menuMusic;
    QMediaPlayer *gameMusic;
    QShortcut *esc;
    Player *player;
    GameScene *scene;
    QGraphicsView *view;
    QPixmap logo;
    QTimer *timer;
    Ui::MainWindow *ui;
    Difficulty diff;
    int selectedLevel;

    QElapsedTimer dtTimer;
};
#endif // MAINWINDOW_H
