#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QButtonGroup>
#include <QMainWindow>
#include <QMouseEvent>
#include <QColorDialog>

#include "customscene.h"
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

public slots:
    void SetPoint(QPointF pos);
    void SetMove();
    void SetRotate(QPointF prev_pos, QPointF curr_pos);
    void SetScale(QPointF prev_pos, QPointF curr_pos);
    void SetDelete();
    void Selection(QGraphicsSceneMouseEvent *event);
    void UpdateInfo(qreal scale);
    void on_Choose_cl_clicked();

private:
    Ui::MainWindow *ui;
    QVector<QGraphicsItem*> figures;
    QVector<QPointF> temp_points;
    Figure *temp_figure{nullptr};
    Figure *current_figure{nullptr};
    CustomScene *scene;
};
#endif // MAINWINDOW_H
