#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "sorter.h"
#include "elements.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QVector>
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
    void updateslot();

    void on_numberofelemspin_valueChanged(int arg1);

    void on_bubbesortbut_clicked();

    void on_heapsortbut_clicked();

    void on_mergesortbut_clicked();

    void on_quicksortbut_clicked();

    void on_searchbut_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_stopsearchbut_clicked();

    void on_interpolationsortbut_clicked();

private:
    Elements* elements;
    Sorter* sort;
    QGraphicsScene* scene;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
