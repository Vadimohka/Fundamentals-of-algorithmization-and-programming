#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QRadioButton>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include "all_figures.h"
#include "scene.h"


enum SelectedType
{
    triangle = 0,
    circle,
    rhombus,
    square,
    rectangle,
    hexagon,
    ellipse,
    star_5,
    star_6,
    star_8,
    none_type
};

enum SelectedAction
{
    createA = 0,
    moveA,
    rotateA,
    scaleA,
    deleteA,
    none_action
};

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
    void createFigure();
    void updateInfo();
    void updateParameters();

private:

    //all figures
    QVector<Figure*>all_figures[10];
    QPair<short,short> selected_figure;
    SelectedType selected_type;

    //change
    SelectedAction selected_action;

    //creation
    short has_points_now;
    QVector<QPoint> points_for_creation;
    short require_to_create[10] =
        {
            3,
            2,
            2,
            2,
            2,
            2,
            2,
            2,
            2,
            2
        };

    QColor brush;

    Scene *scene;
    QGraphicsItem* drawing_lines[10];

    QPair<QPoint, QPoint> temp;

    QIntValidator* validator;

private slots:
    void setSelectedFigure(QPair<short,short>);
    void slotFigureChanged();
    void slotActionChanged();
    void slotColorChanged();

    void slotMousePress(QGraphicsSceneMouseEvent*);
    void slotMouseRelease(QGraphicsSceneMouseEvent*);
    void slotMouseMove(QGraphicsSceneMouseEvent*);
    void slotKeyPress(QKeyEvent*);

    void slotChangeParameter(const QString &);

private:
    Ui::MainWindow *ui;

signals:
    void signalIsSelected();
    void signalNotSelected();
};
#endif // MAINWINDOW_H
