#include <QVector>
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>
#include <qgraphicsitem.h>
#include <qpoint.h>
#include <qthread.h>

class Sorter{
public:

    static double interpolationSort(QVector<int> *array, QGraphicsScene *scene);
    static int binarySearch(QVector<int> *array, QGraphicsScene *scene, int target);

    static void visualize(QVector<int> *array, QGraphicsScene *scene, int swap_i = -1, int swap_j = -1, int mid = -1);

    static void setSpeed(int speed);
    static long long binpow(int digit, int power, int mod);


private:
    QVector<int> *array;
    QGraphicsScene *scene;
    QVector<QGraphicsRectItem *> columns;
    
    static double scene_W;
    static double scene_H;
    static int speed;

    double interpSortTime;
    
};