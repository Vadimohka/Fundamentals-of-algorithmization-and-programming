#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsRotation>
#include <QComboBox>
#include <QtWidgets>

#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "circle.h"
#include "triangle.h"
#include "rhombus.h"
#include "hexagon.h"
#include "custom.h"
#include "star6.h"
#include "star5.h"
#include "star8.h"
#include "arrow.h"

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

public:
    QGraphicsScene *scene;
    Figure *item=nullptr;

    Figure *item1 = new Rectangle;
    void rotateFigure(int arg1);
    void scaleFigure(int arg1);

private slots:
    void on_comboBox_activated(int index);
    void on_radioButton_2_clicked();
   void on_radioButton_3_clicked();
    void on_radioButton_clicked();
    //void on_spinBox_5_valueChanged(int arg1);
    void SetValueP();
    void SetValueA();
   //void on_spinBox_4_valueChanged(int arg1);


    //void on_label_10_linkActivated(const QString &link);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
};
#endif // MAINWINDOW_H
