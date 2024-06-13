#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>

#include "Scenes/paintscene.h"

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
    QTimer *rotationTimerL;
    QTimer *rotationTimerR;
    QTimer *increaseTimer;
    QTimer *decreaseTimer;

private:
    /* Переопределяем событие изменения размера окна
     * для пересчёта размеров графической сцены
     * */
    void resizeEvent(QResizeEvent * event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();
    void pushButton_clicked();       // Ромб
    void pushButton_2_clicked();     // Квадрат
    void pushButton_3_clicked();     // Треугольник
    void pushButton_4_clicked();     // Прямоугольник
    void pushButton_5_clicked();     // Круг
    void pushButton_6_clicked();     // Звезда 5
    void pushButton_7_clicked();     // Звезда 6
    void pushButton_8_clicked();     // Звезда 8
    void pushButton_9_clicked();     // Шестиугольник
    void pushButton_10_clicked();     // Стрелка
    void SetLabelS(qreal S);
    void SetLabelP(qreal P);
    void rlButton_released();
    void rlButton_pressed();
    void rrButton_released();
    void rrButton_pressed();
    void increaseButton_released();
    void increaseButton_pressed();
    void decreaseButton_released();
    void decreaseButton_pressed();
    void increase_item();
    void decrease_item();
   // void increaseButton_clicked();
   //void decreaseButton_clicked();
    void rotateItemL();
    void rotateItemR();
};

#endif // MAINWINDOW_H
