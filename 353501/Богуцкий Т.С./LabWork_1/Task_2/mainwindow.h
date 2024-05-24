#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include "shape.h"
#include <QGraphicsEllipseItem>
#include <QWidget>
#include "circle.h"
#include "triangle.h"
#include "star8.h"
#include "star5.h"
#include "hexagon.h"
#include "rectangle.h"
#include "rhombus.h"
#include "star6.h"
#include "square.h"
#include "shape.h"
#include "ellipse.h"
#include "paintscene.h"

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
    void Values();
    void size_slot();
    void moveup_slot();
    void movedown_slot();
    void moveleft_slot();
    void moveright_slot();
    void rotateleft_slot();
    void rotateright_slot();
    void plusxcentre_slot();
    void minusxcentre_slot();
    void plusycentre_slot();
    void minusycentre_slot();

    void on_triangle_clicked();

    void on_hexaggon_clicked();

    void on_cirrcle_clicked();

    void on_sqquare_clicked();

    void on_starfive_clicked();

    void on_starsix_clicked();

    void on_stareight_clicked();

    void on_rrhombus_clicked();

    void on_reectangle_clicked();

    void on_upsize_pressed();

    void on_upsize_released();

    void on_downsize_pressed();

    void on_downsize_released();

    void on_mooveup_pressed();

    void on_mooveup_released();

    void on_movedownn_pressed();

    void on_movedownn_released();

    void on_mmoveleft_pressed();

    void on_mmoveleft_released();

    void on_mmooveright_pressed();

    void on_mmooveright_released();

    void on_rrotateleft_pressed();

    void on_rrotateleft_released();

    void on_rrottateright_pressed();

    void on_rrottateright_released();

    void on_xpluscentre_clicked();

    void on_xmminuscentre_clicked();

    void on_tpluuscentre_clicked();

    void on_ymiinuscentre_clicked();

    void on_pushButton_clicked();

    void on_upsize_clicked();

    void on_xpluscentre_pressed();

    void on_movedownn_clicked();

    void on_ellipse_clicked();

    void on_paint_clicked();

    void on_stop_paint_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    paintScene *paintscene;
    QTimer *timer;
    Shape *item = nullptr;
};
#endif // MAINWINDOW_H

