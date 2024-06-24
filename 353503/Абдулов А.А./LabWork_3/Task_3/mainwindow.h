#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPoint>
#include "brick.h"

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
    std::vector<QGraphicsRectItem*> t1;
    std::vector<QGraphicsRectItem*> t2;
    std::vector<QGraphicsRectItem*> t3;
    int count;
    QGraphicsScene* scene;

private slots:
    void on_GO_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
