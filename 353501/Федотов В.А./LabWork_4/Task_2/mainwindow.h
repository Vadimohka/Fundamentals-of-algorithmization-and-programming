#pragma once

#include <QMainWindow>
#include "sorter.h"
#include <qtablewidget.h>
#include <QtAlgorithms> 
#include <qcontainerfwd.h>
#include <qgraphicsscene.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
    MainWindow();

private slots:
    void setArray();
    void start();
    void search();
    void changeSpeed(int speed);

private:
    QGraphicsScene *scene;
    QVector<int> array;
    Sorter *sorter;

    int scene_W;
    int scene_H;

    int arraySize;
    int max;

protected:
    Ui::MainWindow *ui;
};
