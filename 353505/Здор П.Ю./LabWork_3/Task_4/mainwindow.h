#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QVector>
#include"hanoi.h"
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
    void on_spinBox_valueChanged(int arg1);
    void create();

    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    hanoi *h;
    QGraphicsScene *sc=new QGraphicsScene;
    int t;
    QVector <QGraphicsRectItem*> t1;
    QVector <QGraphicsRectItem*> t2;
    QVector <QGraphicsRectItem*> t3;
    QGraphicsRectItem *l=new QGraphicsRectItem[15];
    bool fl1=0;
    int C=0;
    int B=0;
    int A=0;
};
#endif // MAINWINDOW_H
