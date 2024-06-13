#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "rectangle.h"
#include "square.h"
#include "ellipse.h"
#include "triangle.h"
#include "diamond.h"
#include "hexagon.h"
#include "star5.h"
#include "star6.h"
#include "star8.h"
#include "figure.h"

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
    int R,G,B;

private slots:
    void on_btn_rectangle_clicked();
    void on_btn_square_clicked();
    void on_btn_ellipse_clicked();
    void on_btn_triangle_clicked();
    void on_btn_diamond_clicked();
    void on_btn_hexagon_clicked();
    void on_btn_star5_clicked();
    void on_btn_star6_clicked();
    void on_btn_star8_clicked();
    void on_Tgravity_clicked();
    void on_btn_fill_clicked();
    void on_btn_ResetScene_clicked();
};
#endif // MAINWINDOW_H
