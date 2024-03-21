#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTableWidget>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QGraphicsItemAnimation>
#include <QVBoxLayout>
#include <QTimer>
#include <QTimeLine>
#include <QDebug>
#include <QMessageBox>
#include "disk.h"
#include "hanoi_solver.h"

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
    void fillTableWidget(QTableWidget *tableWidget);
    void moveDisk(const QString& sourceTowerName, const QString& destTowerName);
    void diskSetup();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int cnt_of_ring = 1;
    bool wasAnimation = false;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QVector<Disk*> tower1;
    QVector<Disk*> tower2;
    QVector<Disk*> tower3;
    Hanoi_solver hanoiSolver;
};
#endif // MAINWINDOW_H
