#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QElapsedTimer>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include "binsearch.h"
#include "bubblesort.h"
#include "heapsort.h"
#include "interpolationsort.h"
#include "mergesort.h"
#include "quicksort.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void visualizeSort();

    void on_startSort_clicked();

    void on_addElement_clicked();

    void on_deleteButton_clicked();

    void on_deleteAllButton_clicked();

private:
    void quickSort(QVector<int> &arr,
                   QVector<QGraphicsRectItem *> &rects,
                   QVector<QGraphicsTextItem *> &textNumbers,
                   int sceneHeight,
                   int maxNumber,
                   int sceneWidth,
                   int msleepTime,
                   QGraphicsScene *scene,
                   int low,
                   int high);

    int partition(QVector<int> &arr,
                  QVector<QGraphicsRectItem *> &rects,
                  QVector<QGraphicsTextItem *> &textNumbers,
                  int sceneHeight,
                  int maxNumber,
                  int sceneWidth,
                  int msleepTime,
                  QGraphicsScene *scene,
                  int low,
                  int high);
    void updateRectsAndText(QVector<QGraphicsRectItem *> &rects,
                            QVector<QGraphicsTextItem *> &textNumbers,
                            int sceneHeight,
                            int maxNumber,
                            int sceneWidth,
                            int i,
                            int j);
    void keyPressEvent(QKeyEvent *event);
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QElapsedTimer *timerElapsed;
    QVector<int> numbers;
    QVector<QGraphicsRectItem *> rects;
    QVector<QGraphicsTextItem *> textNumbers;
    bool vector_has_negative_number = false;
    bool completeSort = false;
    int sceneHeight;
    int sceneWidth;
    int maxNumber;
    qint64 elapsedTime;
};
#endif // MAINWINDOW_H
