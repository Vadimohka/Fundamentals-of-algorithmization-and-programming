#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "tower.h"
#include <QTimer>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QMessageBox>
#include <QMovie>
#include <QPixmap>

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

    void hanoiTowerSolving(int n, int source, int auxiliary, int destination);
    void hanoiTowerAnimation(int time);
    void moveDisk(int disk, int source, int destination);

private slots:

    void on_buttonAnimate_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Tower *tower1, *tower2, *tower3;
    QVector <Ring*> ringsVector;

    QTimeLine* timeLine;

};
#endif // MAINWINDOW_H
