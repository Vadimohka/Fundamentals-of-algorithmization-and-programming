#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

#include "shapeMove.h"
#include "Daughter_shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    void paintEvent(QPaintEvent* event) override;

private:
    Ui::MainWindow *ui;

    ParentShape *shape = new ParentShape;
    DaughterShape *shape2 = new DaughterShape;
};
#endif // MAINWINDOW_H
