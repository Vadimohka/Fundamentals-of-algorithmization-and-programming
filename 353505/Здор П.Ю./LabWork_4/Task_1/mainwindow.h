#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"sorts.h"
#include <QMainWindow>
#include<QGraphicsScene>
#include<QRandomGenerator>
#include<QGraphicsRectItem>
#include<QTimer>
#include<QThread>
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
    void change();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    void MergeSort(double*, int , int );
    void merge(double *, int, int, int) ;
    void sorting_q(QVector <QGraphicsRectItem*>,int,int);
    void heapify(double*,int,int);
    void heapSort(double *, int);
    int partition(int,int,double);
    int binarysearch(double*,int,int,double);
    Ui::MainWindow *ui;
    QGraphicsScene *scene=new QGraphicsScene;
    double *a=new double[100000];
    QVector <QGraphicsRectItem*>t1;
    QRandomGenerator gen=QRandomGenerator::securelySeeded();
    SortS *sortify=new SortS;
    int fl1=0;
    QTimer *timer=new QTimer(this);
    int i1 ;
    int j1 ;
    double *coordinates=new double[5000];
    double *coordinates1=new double[5000];
};
#endif // MAINWINDOW_H
