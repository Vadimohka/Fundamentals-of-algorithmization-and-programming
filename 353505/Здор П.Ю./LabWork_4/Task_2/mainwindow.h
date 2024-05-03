#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"sorts.h"
#include<QGraphicsScene>
#include<QRandomGenerator>
#include<QGraphicsRectItem>
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

private slots:
    void on_pushButton_clicked();

private:
    int inter(double*,int,int,double);
    Ui::MainWindow *ui;
    QGraphicsScene *scene=new QGraphicsScene;
    double *a=new double[100000];
    QVector <QGraphicsRectItem*>t1;
     QRandomGenerator gen=QRandomGenerator::securelySeeded();
    SortS *cc=new SortS;

};
#endif // MAINWINDOW_H
