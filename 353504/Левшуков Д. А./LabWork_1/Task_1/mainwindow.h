#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtWidgets>
#include "telega.h"
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
    void paintEvent(QPaintEvent *event);

protected:
    virtual void keyPressEvent(QKeyEvent *ke)override;
    virtual void keyReleaseEvent(QKeyEvent *ke)override;
private slots:



    void move_left();

    void move_right();
private:
    Ui::MainWindow *ui;
    telega *t=new telega;
    QTimer *timer = new QTimer;
    bool Left=false,Right=false;;
};
#endif // MAINWINDOW_H
