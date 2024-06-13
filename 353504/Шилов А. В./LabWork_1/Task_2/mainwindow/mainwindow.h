#ifndef LAB_MAINWINDOW_H
#define LAB_MAINWINDOW_H

#include <QWidget>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QEvent>
#include <QPushButton>

#include "paintscene.h"

#include "../figures/baseFigure.h"
#include "../figures/polygon/polygon.h"
#include "../figures/straightPolygon/straightPolygon.h"
#include "../figures/star/star.h"
#include "../figures/custom/custom.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class mainwindow;
}
QT_END_NAMESPACE

class mainwindow : public QWidget {
Q_OBJECT


public:
    explicit mainwindow(QWidget *parent = nullptr);

    void createFigure();

    bool getIsMove();

    void setXStart(double a);

    void setYStart(double a);

    void setXFinish(double a);

    void setYFinish(double a);

    void setmoveXStart(double a);

    void setmoveYStart(double a);

    void setmoveXFinish(double a);

    void setmoveYFinish(double a);

    void moveCenter();

    void changeSize();

private:

    double xStart, xFinish, yStart, yFinish;
    double moveStartX, moveStartY, moveFinishX, moveFinishY;
    bool isMove;

    bool hasFigure = false;

    void showEverything();

    QVector<baseFigure *> has;
    QVector<std::pair<int, int> > add;
    int pos = -1;
    const qreal rotateAngle = 0.004;
    bool straight = false, square = false, stardraw = false, customhas = false;
    int numberPoints;
    const qreal delta = 0.01;
    const int one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, eight = 8, fivethousand = 5000;
    baseFigure *figure;

    Ui::mainwindow *ui;
    paintScene *scene;

protected:

private slots:

    void leftRotate_button_clicked();

    void rightRotate_button_clicked();

    void set3();

    void set4();

    void set5();

    void set6();

    void setcircle();

    void setrectangle();

    void setsquare();

    void setMove();

    void set5star();

    void set6star();

    void set8star();

    void setCustom();

    void increaseRadiuse_button();

    void decreaseRadiuse_button();

    void makeEqual();

    void close_clicked();

    void clear_clicked();

    void delete_clicked();

    void change_figure_left();

    void change_figure_right();


};

#endif //LAB_MAINWINDOW_H
