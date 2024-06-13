#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QVector>
#include <QRegularExpressionValidator>
#include <QEventLoop>
#include <QTimer>
#include "hanoitower.h"
#include "ring.h"

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
    QVector<Ring*> rings;
    QVector<int> tower1;
    QVector<int> tower2;
    QVector<int> tower3;
    HanoiTower *hanoiTower = new HanoiTower(4);
    int n;
    int steps;

private slots:
    void on_move_clicked();

    void on_set_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};
#endif // MAINWINDOW_H
