#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "triangle.h"
#include "circle.h"
#include "romb.h"
#include "square.h"
#include "rectangle.h"
#include "fivestar.h"
#include "sixstar.h"
#include "hexagon.h"
#include "eightstar.h"
#include "regularpolygon.h"
#include "paint.h"

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
protected:
    void closeEvent(QCloseEvent*) override;
private:
    Ui::MainWindow *ui;
    QTabWidget* tabs;
    Triangle* triangle;
    Circle* circle;
    Romb* romb;
    Square* square;
    Rectangle* rect;
    FiveStar* star5;
    SixStar* star6;
    EightStar* star8;
    Hexagon* hex;
    RegularPolygon* regpol;
    Paint* paint;
};
#endif // MAINWINDOW_H
