#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "paintscene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PaintScene *scene;
    QTimer *timer;
private:
// Переопределяем событие изменения размера окна
// для пересчёта размеров графической сцены

    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer ();
    void on_comboBox_activated(int index);
    void setPerimeter(double perimeter);
    void setArea(double area);
};

#endif // MAINWINDOW_H
