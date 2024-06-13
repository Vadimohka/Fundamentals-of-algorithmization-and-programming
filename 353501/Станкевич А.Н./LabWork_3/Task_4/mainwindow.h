#pragma once

#include <QMainWindow>
#include <QGraphicsScene>
#include "animate.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void setN(int arg1);
    int numDisks = 1;
    char sourcePeg = 'A';
    char auxiliaryPeg = 'B';
    char targetPeg = 'C';
        int N = 1;
            int cnt;

    void hanoi(int n, char source, char auxiliary, char target);
    void moveDisk(int n, char source, char target);

    HanoiTowers* towers;
    MainWindow();
    ~MainWindow();
private:
        void on_pushButton_clicked();
        void on_spinBox_valueChanged(int arg1);
        void on_pushButton_2_clicked();
    void drawTowers();

    QTimer *timer;

protected:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

};
