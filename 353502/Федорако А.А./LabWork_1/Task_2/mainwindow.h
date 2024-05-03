#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLabel>
#include <QMainWindow>
#include <QResizeEvent>
#include "paintscene.h"
#include "figure.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    void plusSize();
    void minusSize();
    void rotateLeft();
    void rotateRight();
    void changeValueLabel();

    Ui::MainWindow *ui;
    PaintScene *scene;
    Figure *figure;

    QTimer *timerForUpdateInformation;
    QTimer *timerForButtonsPlusSize;
    QTimer *timerForButtonsMinusSize;
    QTimer *timerForButtonsRotateLeft;
    QTimer *timerForButtonsRotateRight;

    void resizeEvent(QResizeEvent * event);

private slots:
    void updateLabel();
    void clearLabel();
    void slotTimer();
    void on_Rectangle_clicked();
    void on_Rhombus_clicked();
    void on_Square_clicked();
    void on_Close_clicked();
    void on_Clear_clicked();
    void on_Circle_clicked();
    void on_Triangle_clicked();
    void on_FivePointer_star_clicked();
    void on_SixPointer_star_clicked();
    void on_EightPointed_star_clicked();
    void on_Rotation_clicked();
    void on_nextFigure_clicked();
    void on_backFigure_clicked();
    void on_PlusSize_pressed();
    void on_PlusSize_released();
    void on_MinusSize_pressed();
    void on_MinusSize_released();
    void on_ChangeLeft_pressed();
    void on_ChangeLeft_released();
    void on_ChangeRight_pressed();
    void on_ChangeRight_released();
    void on_Hexagon_clicked();
    void on_deleteFigureButton_clicked();
};

#endif // MAINWINDOW_H
