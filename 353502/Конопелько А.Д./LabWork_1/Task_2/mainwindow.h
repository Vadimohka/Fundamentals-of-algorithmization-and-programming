#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QTimer>
#include <QString>

#include "moveitem.h"
#include "star8.h"
#include "star5.h"
#include "star6.h"
#include "quadrate.h"
#include "rhomb.h"
#include "rectangle.h"
#include "ellipse.h"
#include "triangle.h"
#include "polygon.h"

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

 private slots:
    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_10_clicked();

    void getTypeOfMoving();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void removingItem(MoveItem* deleteItem);

//    void on_radioButton_clicked();

//    void on_radioButton_toggled(bool checked);

//    void on_radioButton_7_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;    
    MoveItem* item;

    void updateScene();
    void showPosition(QPointF pointPos);
    void clearMainFields();
    void signalFunctions();
    void slotReleaseOK();
    void slotBlockOK();
    void showPerimeterSquare(qreal perim, qreal square);
signals:
    void signalSetPosition(QPointF pointSetPos);
    void setAngleSpeed(qreal angleSpeedNew);
};
#endif // MAINWINDOW_H
