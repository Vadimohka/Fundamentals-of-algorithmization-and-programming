#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPropertyAnimation>
#include <QTimer>
#include "inputdialogs.h"
#include "krug.h"
#include "myrectangle.h"
#include "mykvadrat.h"
#include "treugolnik.h"
#include "romb.h"
#include "shestiugolnik.h"
#include "ellips.h"
#include "zvezda.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_pressed();

    void on_pushButton_3_released();

    void on_pushButton_4_pressed();

    void on_pushButton_4_released();

    void on_pushButton_vverh_pressed();

    void on_pushButton_vverh_released();

    void on_pushButton_vniz_pressed();

    void on_pushButton_vniz_released();

    void on_pushButton_vlevo_pressed();

    void on_pushButton_vlevo_released();

    void on_pushButton_vpravo_pressed();

    void on_pushButton_vpravo_released();

    void on_pushButton_plus_pressed();

    void on_pushButton_plus_released();

    void on_pushButton_minus_pressed();

    void on_pushButton_minus_released();

    void on_pushButton_koords_clicked();

    void on_pushButton_drawRomb_clicked();

    void on_pushButton_drawKvadrat_clicked();

    void on_pushButton_drawTreugolnik_clicked();

    void on_pushButton_drawKrug_clicked();

    void on_pushButton_drawRect_clicked();

    void sceneupdate();

    void updateLabel(int x, int y);

    void on_pushButton_drawEllips_clicked();

    void on_pushButton_drawHex_clicked();

    void on_pushButton_drawZvezda_clicked();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;
    QTimer *timer, *timer2, *timer3,*timer4, *timer5, *timer6,*timer7,*timer8, *timerupd;
};

#endif // MAINWINDOW_H
