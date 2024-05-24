#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QPainter>
#include <QMessageBox>
#include "heapsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "interpolationsort.h"
#include "binarysearch.h"


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
    void DisplayArr();
    long long binpow(long long, long long, long long);
private slots:
    void on_createArrButton_clicked();

    void on_sortButton_clicked();

    void on_searchElButton_clicked();

private:
    Ui::MainWindow *ui;
    QVector<int> arr;
    QVector<int> arrAnima;
    QVector<QVector<int> > list;
    QTimer *timer;
    int countElements;
    int sizeList;
    QVector<QRectF*> rectArr;
    QGraphicsScene *scene;
    bool sorted;

};
#endif // MAINWINDOW_H
