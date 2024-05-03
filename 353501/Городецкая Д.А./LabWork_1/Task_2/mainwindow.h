#pragma once

#include <QMainWindow>
#include <qgraphicsscene.h>
#include <qwidget.h>
#include "paintscene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
  
public:
   explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
/*Переобределяем событие изменения размера окна
для перерасчёта размеров графической сцены */
void resizeEvent(QResizeEvent* event);

private slots:
    // Таймер для изменения размеров сцены при изменении размеров Окна приложения
    void slotTimer();

protected:
  Ui::MainWindow *ui;
 PaintScene *scene;  // Объявляем кастомную графическую сцену
    QTimer *timer;      /* Определяем таймер для подготовки актуальных размеров
                          графической сцены */
private slots:
    void on_pushButton_clicked();       // Включаем отрисовку Ромба
    void on_pushButton_2_clicked();     // Включаем отрисовку Квадрата
    void on_pushButton_3_clicked();     // Включаем отрисовку Треугольника
    void on_pushButton_4_clicked();     // Включаем отрисовку Круга
    void on_pushButton_5_clicked();     // Включаем отрисовку Прямоугольника
    void on_pushButton_6_clicked();     // Включаем отрисовку star5
    void on_pushButton_7_clicked();     // Включаем отрисовку star6
    void on_pushButton_8_clicked();     // Включаем отрисовку star8
    void on_pushButton_9_clicked();     // Включаем отрисовку многоугольника
    void on_pushButton_10_clicked();    // Включаем отрисовку другое
    void on_pushButton_11_clicked();
    void on_spinBox_valueChanged(int x);  // право или лево
    void on_spinBox_2_valueChanged(int x);// вверх или вниз
    void on_spinBox_3_valueChanged(int x);//угол
    void on_doubleSpinBox_valueChanged(qreal x);   // масштаб
};