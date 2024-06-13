#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>
#include <cinema.h>
#include <QVector>
#include <abstractfigure.h>
#include <QMouseEvent>
#include <QKeyEvent>

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

    QPointF cord_offset {};
    QPointF past_cord {};
    QGraphicsView* view;
    Cinema* scene;
    QBrush brush;
    QPainter* painter;

    bool ctrl_press{};
    bool shift_press{};
    int start_angle{};


    double end_x;
    double end_y;
    double start_x;
    double start_y;
    int active_figure;
    bool is_draw;
    bool top_right;
    bool bottom_right;
    bool bottom_left;
    bool top_left;

    bool checkCorner(QPointF corner, QPointF itemPos, qreal tolerance);

    void moveObject(QGraphicsSceneMouseEvent *event);

    void selectFigure(QGraphicsSceneMouseEvent* event);

    AbstractFigure *selected_figure;

    QVector<AbstractFigure *> items;

    int equanity;

    void mouseLeftPress(QGraphicsSceneMouseEvent* event);

    void mouseLeftRelease(QGraphicsSceneMouseEvent* event);

    void keyPressEvent(QKeyEvent *event) override;

    void keyReleaseEvent(QKeyEvent *event) override;

    void createFigure(double end_x,double end_y,double start_x,double start_y);

    void onButtonClicked1();

    void onButtonClicked2();

    void onButtonClicked3();

    void onButtonClicked4();

    void onButtonClicked5();

    void onButtonClicked6();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
