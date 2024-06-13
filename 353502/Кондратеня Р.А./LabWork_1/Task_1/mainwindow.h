#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Dump_truck.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool once_clicked;
    qreal x = 0;

private slots:
    void on_Body_up_clicked();

    void on_Body_down_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    Dump_Truck* dump_truck;
};
#endif // MAINWINDOW_H
