#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include "rectangle.h"
#include "ellipse.h"
#include "figure.h"
#include "rhombus.h"
#include "trianglee.h"
#include "circle.h"
#include "sqare.h"
#include "polygon.h"
#include "star.h"
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
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;


private slots:
    void on_btn_rectangle_clicked();
    void on_btn_ellipse_clicked();
    void on_btn_circle_clicked();
    void on_btn_rhombus_clicked();
    void on_btn_triangle_clicked();
    void on_btn_sqare_clicked();
    void on_btn_polygon_clicked();
    void on_btn_star_clicked();
    void on_Tgravity_clicked();
    void on_btn_ResetScene_clicked();
};
#endif // MAINWINDOW_H
