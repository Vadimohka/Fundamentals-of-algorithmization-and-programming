#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool isSorted = false;
    int size = 0;
    QGraphicsScene* scene;
    QVector<QGraphicsRectItem*> arrayRect;
    QVector<int> array;

public:
    MainWindow();

    void printArray(QVector<int>& arr, int n);
    void initArray();

    void heapify(QVector<int> &arr, int N, int i);
    void heap_sort();

    void merge(QVector<int>& arr, int left, int mid, int right);
    void merge_sort(QVector<int> &arr, int const begin, int const end);

    void quick_sort(QVector<int> &arr, int low,int high);

    void visualize(int ind1toSwap = -1, int ind2toSwap = -1);
    int partition(QVector<int> &arr, int low,int high);

    int binary_search(int left, int right, int target);

public slots:
    void merge_go();
    void quick();
    void heap();
    void search();

protected:
    Ui::MainWindow *ui;
};
