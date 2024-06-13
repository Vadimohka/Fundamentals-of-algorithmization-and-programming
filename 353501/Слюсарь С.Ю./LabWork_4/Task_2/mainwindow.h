#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include <QElapsedTimer>
#include <QRegularExpressionValidator>
#include <vector>
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
    std::vector<int> arr;
    QRandomGenerator *rg = new QRandomGenerator;
    bool done = false;

private slots:
    void on_sort_clicked();
    void on_find_clicked();

private:
    QGraphicsScene *scene = new QGraphicsScene;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
