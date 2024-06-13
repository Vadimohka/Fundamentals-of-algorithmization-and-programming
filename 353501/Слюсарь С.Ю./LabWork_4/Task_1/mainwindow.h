#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QRegularExpressionValidator>
#include "sorter.h"

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
    Sorter *sorter;
    int *arr = new int[50];
    int numOfSort = 0;
    QRandomGenerator *rg = new QRandomGenerator;
    bool done = false;

private slots:
    void on_sort_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene = new QGraphicsScene;
};
#endif // MAINWINDOW_H
