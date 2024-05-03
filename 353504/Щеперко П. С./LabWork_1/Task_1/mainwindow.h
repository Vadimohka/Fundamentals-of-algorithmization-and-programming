#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QMainWindow>
#include <QTimer>
#include "cart.h"

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

    void paintEvent(QPaintEvent*) override;

private:
    Ui::MainWindow *ui;
    Cart *cart;
    QMainWindow *window;
    QSize size1;

    QTimer *animationTimer;
    QTimer *animationTimer2;

private slots:
    void on_moveCart_clicked();
    void on_moveCartBackward_clicked();
};
#endif // MAINWINDOW_H
