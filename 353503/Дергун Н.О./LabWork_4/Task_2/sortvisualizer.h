#ifndef SORTVISUALIZER_H
#define SORTVISUALIZER_H

#include <QWidget>
#include <QTimer>
#include <QVector>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

namespace Ui {
class SortVisualizer;
}

const int MIN_GREEN_TIMER = 10;
const int MAX_GREEN_TIMER = 1000;
const int HOR_TAB = 10;
const int VER_TAB = 10;
const int MIN_HOR_SIZE = 1;
const int VER_TAB_CNT = 5;


class SortVisualizer : public QWidget
{
    Q_OBJECT

    QVector<int> _sortingArray;
    int* _array;
    int _size;
    int _max;
    int _min;
    int _minElementTab;
    int _horSize;
    int _verMaxSize;
    int _horWidth;
    QGraphicsScene* _scene = nullptr;
    QVector<QGraphicsRectItem*> _visualArray;
    QTimer* timer = nullptr;
    int _endIndex;

    void visualizeArray();
    bool checkIfOutOfRange(int* firstElement, int* secondElement);
    int calcVerSize(int index);

public:
    explicit SortVisualizer(QWidget *parent = nullptr);
    ~SortVisualizer() override;

    void InitByArray(int* array, int size);

private slots:
    void slotSetComparison(int* firstElement, int* secondElement);
    void slotEndComparison(int* firstElement, int* secondElement);
    void slotSwapElements(int* firstElement, int* secondElement);
    void slotChangeElement(int* ptr, int value);
    void slotEndSorting();
    void slotMakeSortGreen();

private:
    Ui::SortVisualizer *ui;
};

#endif // SORTVISUALIZER_H
