#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QVector>
#include <QTimer>
#include <QInputDialog>
#include <circle.h>
#include <ellipse.h>
#include <hexagone.h>
#include <rectangle.h>
#include <square.h>
#include <star.h>
#include <form.h>
#include <triangle.h>
#include <dialogtriangle.h>
#include <dialogsquare.h>
#include <dialogcircle.h>
#include <dialogellipse.h>
#include <dialoghexagone.h>
#include <dialogrectangle.h>
#include <dialogstar.h>
#include <canva.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public slots:
    void on_setParametrs_clicked();
    void getCircleData(int positionX, int positionY, int radius, QColor BrushColor, QColor PenColor);
    void getRectangleData(int positionX, int positionY, int width, int height, QColor BrushColor, QColor PenColor);
    void getEllipseData(int positionX, int positionY, int horisontalRadius, int verticalRadius, QColor BrushColor, QColor PenColor);
    void getSquareData(int positionX, int positionY, int side, QColor BrushColor, QColor PenColor);
    void getTriangleData(int positionX, int positionY, int base, int side, QColor BrushColor, QColor PenColor);
    void getStarData(int positionX, int positionY, int side, QColor BrushColor, QColor PenColor);
    void getHexagoneData(int positionX, int positionY, int sideSize, QColor BrushColor, QColor PenColor);
    void rotateLeft();
    void rotateRight();
private slots:
    void on_getFigure_clicked();
    void on_pushButton_LEFT_clicked();
    void on_pushButton_RIGHT_clicked();
    void on_pushButton_UP_clicked();
    void on_pushButton_DOWN_clicked();
    void on_perimetrFigure_clicked();
    void on_squareFigure_clicked();
    void on_scale_clicked();
    void on_rotateLeft_clicked();
    void on_rotateRight_clicked();
    void on_rotate_clicked();
    void on_Canva_clicked();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *rotatingTimer;
    Circle *circle;
    DialogCircle *cDialog;
    QVector<Circle*> circles;
    Rectangle *rectangle;
    DialogRectangle *rDialog;
    QVector<Rectangle*> rectangles;
    Ellipse *ellipse;
    DialogEllipse *eDialog;
    QVector<Ellipse*> ellipses;
    Square *square;
    DialogSquare *sqDialog;
    QVector<Square*> squares;
    Triangle *triangle;
    DialogTriangle *tDialog;
    QVector<Triangle*> triangles;
    Star *star;
    DialogStar *stDialog;
    QVector<Star*> stars;
    Hexagone *hexagone;
    DialogHexagone *hDialog;
    QVector<Hexagone*> hexagons;
    Canva *canva;
};
#endif // MAINWINDOW_H

