#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <random>
#include <QTimer>
#include "quick_sort.h"
#include "heap_sort.h"
#include "merge_sort.h"
#include "interpolation_sort.h"
#include "binary_search.h"
#include "binary_power.h"

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
    void fillVectorWithRandom(QVector<long long>& vec, int count);
    void createRectArray(const QVector<long long> &data);
    void paintSearchTarget(long long ind, bool isSearched);
    void buttonsSetup();

private slots:
    void on_bnt_random_filling_clicked();

    void on_bnt_sort_clicked();

    void on_bnt_search_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *uptimer;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QVector<long long> start_vector;
    QVector<long long> copy_start_vector;
    QVector <QGraphicsRectItem*> vec_of_item;
    QVector<QVector<long long>> sort_result;
    QVector<long long> search_result;
    long long ind_of_last_paint = -1;
    bool sortIsActive = false;
    bool isSorted = false;
};
#endif // MAINWINDOW_H
