#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QMessageBox>
#include <random>
#include <QTimer>
#include "mediantriples.h"

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

private slots:
    void on_bnt_random_clicked();

    void on_bnt_get_new_array_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *uptimer;
    QGraphicsScene *scene = new QGraphicsScene(this);
    QVector<long long> start_vector;
    QVector <QGraphicsRectItem*> vec_of_item;
    bool animationIsTrue = false;
};
#endif // MAINWINDOW_H
