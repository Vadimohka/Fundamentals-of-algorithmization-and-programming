#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QGraphicsRectItem>
#include <QTimer>

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

    void resizeEvent(QResizeEvent *event) override;
    void prepareScene();
    void changeColumnColor(int index, const QColor &color);
    void swapColumns(QGraphicsRectItem &item1, QGraphicsRectItem &item2);
    void swapColumns(QGraphicsRectItem &item, qreal height);

public slots:
    void sorting();
    void drawColumns();
    void randomize();
    int binSearch();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QVector<QGraphicsRectItem*> columns;

    QVector<int> array;
    QVector<QPair<int, int>> steps;

    int findedIndex = -1;
    bool isSorted = false;

    void inititalizeArray();
    void initializeColumns();

    void swap(int i, int j);

    long long binPow(long long digit, long long powder, long long mod);

    void interpolationSort();
    void divide(QVector<int> &divideSide, int& end);
};
#endif // MAINWINDOW_H
