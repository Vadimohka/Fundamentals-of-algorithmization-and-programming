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
private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);
 
private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void on_TEST_clicked();     // TEST TEST TEST TEST TEST TEST
    void on_clearscene_clicked();     // Очистка сцены
    void on_radioButton_toggled(bool checked);
    void on_radioButton_2_toggled(bool checked);
    void on_comboBox_currentIndexChanged(int index);
    void on_spinBox_number_valueChanged(int arg1);
    void on_spinBox_rotation_valueChanged(int arg1);
    void on_spinBox_rotationX_valueChanged(int arg1);
    void on_spinBox_rotationY_valueChanged(int arg1);
    void returnArea();
};
 
#endif // MAINWINDOW_H