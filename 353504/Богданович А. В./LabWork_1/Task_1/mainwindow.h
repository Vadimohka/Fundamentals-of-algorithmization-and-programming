#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Wagon.h"
#include <QTimer>

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

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_2_pressed();

    void on_pushButton_2_released();



private:
    Ui::MainWindow *ui;
    Wagon *wagon;
    QTimer *timerRight;
    QTimer *timerLeft;
    QMainWindow *window;
    QSize sz;

protected:
    void paintEvent(QPaintEvent*) override;

};
#endif // MAINWINDOW_H
