#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include "movingrect.h"
#include "plane.h"
#include "ground.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
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
    void on_UpButton_clicked();
    void on_rightButton_clicked();
    void on_downButton_clicked();
    void on_leftButton_clicked();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Plane* plane;
    movingRect* rectangle;
    Ground* ground;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
