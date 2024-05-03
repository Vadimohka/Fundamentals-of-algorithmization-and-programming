#pragma once

#ifndef MAINWINDOW_H
#define MAINWINDOW_H
 
#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QGraphicsView>
 
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
    PaintScene *scene;  // Объявляем кастомную графическую сцену
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                         * графической сцены
                         * */
    QTimer *updateValues;

private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);
 
private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void update_values();
    void on_clearscene_clicked();     // Очистка сцены
    void on_drawing_toggled(bool checked);
    void on_editing_toggled(bool checked);
    void on_comboBox_currentIndexChanged(int index);
    void on_spinBox_number_valueChanged(int arg1);
    void on_spinBox_number_2_valueChanged(int arg1);
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_spinBox_rotation_valueChanged(int arg1);
    void on_spinBox_rotationX_valueChanged(int arg1);
    void on_spinBox_rotationY_valueChanged(int arg1);
    void on_spinBox_outerR_valueChanged(int arg1);
    void on_spinBox_outerR_2_valueChanged(int arg1);
    void on_spinBox_innerR_valueChanged(int arg1);
    void on_spinBox_sideA_valueChanged(int arg1);
    void on_spinBox_sideB_valueChanged(int arg1);
    void on_spinBox_sideA_2_valueChanged(int arg1);
    void on_spinBox_sideB_2_valueChanged(int arg1);
    void on_spinBox_sideA_4_valueChanged(int arg1);
    void on_spinBox_sideB_4_valueChanged(int arg1);
    void on_spinBox_sideA_3_valueChanged(int arg1);
    void on_spinBox_angel_valueChanged(int arg1);
    // Треугольник
    void on_spinBox_A_x_valueChanged(int arg1);
    void on_spinBox_A_y_valueChanged(int arg1);
    void on_spinBox_B_x_valueChanged(int arg1);
    void on_spinBox_B_y_valueChanged(int arg1);
    void on_spinBox_C_x_valueChanged(int arg1);
    void on_spinBox_C_y_valueChanged(int arg1);


    void returnArea();
};
 
#endif // MAINWINDOW_H