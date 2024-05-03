#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "heapsorter.h"
#include "qsorter.h"
#include "mergesorter.h"
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QThread>
#include "interpolationsorter.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_fillButton_clicked();

    void on_sortButton_clicked();

    void on_findButton_clicked();
protected:
    void showEvent(QShowEvent* event) override;
private:
    Ui::Widget *ui;

    QVector<int> vectForTime;
    QVector<int> vectForAniamtion;

    QTimer *animationTimer;
    QVector<QVector<int>> listOfStates;

    QGraphicsScene* scene;

    int amountOfElementsInArray;

    void drawArr();
    int currState;
    bool isSorted;

    QVector<QGraphicsRectItem*> rects;
    QVector<int> listOfSearch;

    int binarySearch(int, int, int);
    QTimer *searchAnimationTimer;
    int currStepOfSearch;
    void drawSearch();
    bool isElement;

    long long binpow(long long, long long, long long);
};
#endif // WIDGET_H
