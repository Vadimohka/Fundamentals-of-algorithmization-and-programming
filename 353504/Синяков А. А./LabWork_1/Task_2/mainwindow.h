#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "custom.h"
#include <QMouseEvent>
#include<QLineEdit>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
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
    QLineEdit*coordinatesInput;
    ~MainWindow();
private slots:


    void on_Figures_clicked();
    void on_Clear_clicked();
void on_center_clicked();
    void on_plus_pressed();
    void on_plus_released();
    void on_minus_pressed();
    void on_minus_released();
    void on_counterclockwiserotation_pressed();
    void on_counterclockwiserotation_released();
    void on_rotateclockwise_pressed();
    void on_rotateclockwise_released();

    void calculateCircle();
    void calculateTriangle();
    void calculateRectangle();
    void calculateRhombus();
    void calculateSquare();
    void calculateHexagon();
    void calculateFivePointStar();
    void calculateSixPointStar();
    void calculateEightPointStar();




    void moveTriangleCenter();
    void moveCircleCenter();
    void moveRectangleCenter();
    void moveRhombusCenter();
    void moveSquareCenter();
    void moveHexagonCenter();
    void moveFivePointStarCenter();
    void moveSixPointStarCenter();
    void moveEightPointStarCenter();

    void onPlusScaleTimerTimeout();
    void onMinusScaleTimerTimeout();
    void scaleFigures(qreal scaleFactor);
    void scaleFigure(QVector<QPointF> &points, qreal scaleFactor,const QPointF &center);



    QVector<QPointF> getFigurePoints(QGraphicsItem *item);
    void startRotationTimer(qreal rotationSpeed);
    void stopRotationTimer();
    void rotateAllFigures(qreal rotationSpeed);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
     void paintEvent(QPaintEvent* event) override;
private:
    Ui::MainWindow *ui;


    Line *line;



    QTimer *rotationTimer;  // Таймер для вращения фигур
    qreal rotationSpeed;    // Скорость вращения в градусах
    int rotationInterval;   // Интервал между срабатываниями таймера

    QTimer *plusScaleTimer;
    QTimer *minusScaleTimer;

    QGraphicsScene *scene;
    QGraphicsView *view;

    double scaleFactor;

    QString currentFigure;
    void moveCenterOfMass(QVector<QPointF> &points);
    QPointF getNewCenterMass();

    QVector<QPointF> trianglePoints;
    QVector<QPointF> circlePoints;
    QVector<QPointF> rectanglePoints;
    QVector<QPointF> rhombusPoints;
    QVector<QPointF> squarePoints;
    QVector<QPointF> hexagonPoints;
    QVector<QPointF>fivePointstarPoints;
    QVector<QPointF>sixPointstarPoints;
    QVector<QPointF>eightPointstarPoints;
    QPointF centerMassPoint;
    QPointF getFigureCenter(const QVector<QPointF>&points);
};
#endif // MAINWINDOW_H




