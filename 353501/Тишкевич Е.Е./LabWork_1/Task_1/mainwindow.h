#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <slider.h>
#include <QTimer>
#include <QPushButton>

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
    void changeSliderColor(int);
    void obnul();

private:
    Ui::MainWindow *ui;
    QGraphicsView* view;
    QGraphicsScene* scene;
    QSlider *slider;
    QPushButton* pushButton;

};
#endif // MAINWINDOW_H
