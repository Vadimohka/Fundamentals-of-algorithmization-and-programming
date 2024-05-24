#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QMessageBox>

#include "rect.h"

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
    Rect** towers[3];
    int towerSizes[3] = {0, 0, 0};
    int count = 0;
    double speed = 1.0;

    QPointer<QPropertyAnimation> animation1;
    QPointer<QPropertyAnimation> animation2;
    QPointer<QPropertyAnimation> animation3;


protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_pushButton_clicked();
    void moveRect(Rect* rect, int x, int y);
    void hanoi(int n, Rect**& from, Rect**& to, Rect**& aux, int& sizeFrom, int& sizeTo, int& sizeAux, int x1, int x2, int x3);
    void on_end_button_clicked();
    void on_doubleSpinBox_valueChanged(double arg1);
};
#endif // MAINWINDOW_H
