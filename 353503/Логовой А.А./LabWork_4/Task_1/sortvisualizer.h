#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H

#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QApplication>
#include <QMessageBox>
#include<binpow.h>

class SortVisualizer : public QGraphicsView
{
    Q_OBJECT

public:
    explicit SortVisualizer(QGraphicsView* view, QWidget *parent = nullptr);

    void visualizeSort(int* arr, int size);

    void drawArray(int* arr, int size);

    void clearScene();

    void shuffle(int* arr, int size);

    void binarySearch(int* arr, int size, int target);

    void interpolationSearch(int* arr, int n, int x);

public slots:
    void updateArray(int* arr, int size);

private:
    QGraphicsView* view;
    QTimer* timer;
    QGraphicsScene* scene;
    QVector<QGraphicsRectItem*> bars;
};

#endif // SORTVISUALIZER_H
