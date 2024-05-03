#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once

#include <QMainWindow>
#include <QtMultimedia>
#include <QMediaPlayer>
#include <QPointF>
#include <QSizeF>
#include <QTimer>
#include <QPainter>
#include <QFile>
#include "hum_move.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);
    void changeTrack(const QString &filePath);

private slots:
    void on_bntStart_clicked();

    void on_bntDown_clicked();

    void on_bntRight_clicked();

    void on_bntHandUp_clicked();

    void on_bntHonor_clicked();

    //void on_bntEnd_clicked();

    void on_pushButton_clicked();

    void on_bntHpS_clicked();

    void on_bntRect_clicked();

    void on_bnt_prikol_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QAudioOutput *audioOutput;
    QMediaPlayer *player;
    hum_move *hum;
    hum_move *head;
    movement *rect;
    bool b2 = false;
    bool b1 = false;
    bool arr[6];
    QString music_path1 = "/home/fort3mio/Downloads/Labs_qt/first_lab/first_task/multi/background_music.mp3";
    QString music_path2 = "/home/fort3mio/Downloads/Labs_qt/first_lab/first_task/multi/background_music_prikol.mp3";
    int cnt_mus = 0;
};
#endif // MAINWINDOW_H
