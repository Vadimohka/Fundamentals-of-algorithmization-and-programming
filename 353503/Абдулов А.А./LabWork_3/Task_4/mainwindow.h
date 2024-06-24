#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QMessageBox>

#include "ring.h"

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
    Ring** towers[3];
    int towerSizes[3] = {0, 0, 0};
    int count = 0;
    double speed = 1.0;

    QPointer<QPropertyAnimation> animationUp;
    QPointer<QPropertyAnimation> animationLeftOrRight;
    QPointer<QPropertyAnimation> animationDown;


protected:
    void paintEvent(QPaintEvent*) override;
private slots:

    void moveRing(Ring* ring, int x, int y);
    void hanoi(int n, Ring**& from, Ring**& to, Ring**& aux, int& sizeFrom, int& sizeTo, int& sizeAux, int x1, int x2, int x3);

    void on_pushButton_clicked();
    void on_spinBox_valueChanged(int n);
    void on_doubleSpinBox_valueChanged(double n);
};
#endif // MAINWINDOW_H
