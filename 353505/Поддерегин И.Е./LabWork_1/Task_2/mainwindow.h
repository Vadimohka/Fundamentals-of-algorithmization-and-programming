#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QMessageBox>

#include "mainscene.h"

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
    MainScene *scene;
    QTimer *scaleIncreaseTimer, *scaleDecreaseTimer;
    QTimer *rotateLeftTimer, *rotateRightTimer;
    QTimer *moveTopTimer, *moveDownTimer, *moveLeftTimer, *moveRightTimer;
    QTimer *timer;
    QTimer *ShapeTimer;
    QTimer *checkingTypeShapeTimer;

    void stopAllTimers();
    void activateButtons();
    void activateSpecialTypeButtons();

    void resizeEvent(QResizeEvent * event);

private slots:
    void slotTimer();
    void on_createRombButton_clicked();
    void on_createRectangleButton_clicked();
    void on_createTriangleButton_clicked();
    void on_createParallelogramButton_clicked();
    void on_createEllipseButton_clicked();
    void on_createStarButton_clicked();
    void on_createHexagonButton_clicked();
    void on_changeSizeButton_clicked();
    void on_objectInformationButton_clicked();
    void on_decreaseButton_clicked();
    void on_stopScaleButton_clicked();
    void on_increaseButton_clicked();
    void on_rotateLeftButton_clicked();
    void on_rotateRightButton_clicked();
    void on_stopRotateButton_clicked();
    void on_moveTopButton_clicked();
    void on_moveDownButton_clicked();
    void on_stopMoveButton_clicked();
    void on_moveLeftButton_clicked();
    void on_moveRightButton_clicked();
    void on_changeVertexValue_valueChanged(int arg1);
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_doubleSpinBox_2_valueChanged(double arg1);
    void on_doubleSpinBox_3_valueChanged(double arg1);
    void on_doubleSpinBox_4_valueChanged(double arg1);
    void on_doubleSpinBox_5_valueChanged(double arg1);
    void on_doubleSpinBox_6_valueChanged(double arg1);
    void on_doubleSpinBox_7_valueChanged(double arg1);
    void on_doubleSpinBox_8_valueChanged(double arg1);
    void on_doubleSpinBox_9_valueChanged(double arg1);
    void on_doubleSpinBox_10_valueChanged(double arg1);
};

#endif // MAINWINDOW_H
