#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "moving_rectangle.h"
#include <QMainWindow>

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
    QGraphicsScene * scene;
    moving_rectangle * rectangle;
};
#endif // MAINWINDOW_H
