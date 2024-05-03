#include <QtWidgets>
#include "figures.h"
#include "triangle.h"
#include "square.h"
#include "circle.h"
#include "rhombus.h"
#include "star_5.h"
#include "star_6.h"
#include "star_8.h"
#include "hexagon.h"
#include "polyline.h"

class mainwindow : public QWidget {
    Q_OBJECT
public:
    explicit mainwindow(QWidget *obj = nullptr);

private:
    figures **figuresArray = new figures *[10];

    QRadioButton *triangleButton;
    QRadioButton *circleButton;
    QRadioButton *starButton;
    QRadioButton *star5Button;
    QRadioButton *star6Button;
    QRadioButton *star8Button;
    QRadioButton *rhombusButton;
    QRadioButton *rectangleButton;
    QRadioButton *starButton1;
    QRadioButton *starButton2;
    QRadioButton *starButton3;
    QRadioButton *hexagonButton;
    QRadioButton *polylineButton;
    QRadioButton *drawButton;
    QRadioButton *changeButton;
    QPushButton *sizeP;
    QPushButton *sizeM;
    QPushButton *rotateL;
    QPushButton *rotateR;

    QLabel *textCenter;
    QLabel *textSquare;
    QLabel *textPerimeter;

    QTimer *timer = new QTimer;

    figureTriangle *triangle = new figureTriangle;
    figureCircle *circle = new figureCircle;
    figureRhombus *rhombus = new figureRhombus;
    figureSquare *square = new figureSquare;
    figureHexagon *hexagon = new figureHexagon;
    figurePolyline *polyline = new figurePolyline;
    star_5 *star5 = new star_5;
    star_6 *star6 = new star_6;
    star_8 *star8 = new star_8;

    bool isShift = false;
    int figureNum = 0;
    int cnt = 0;

    void setInfo();

private slots:

    void selectFigure();
    void upSize();
    void downSize();
    void rotateLeft();
    void rotateRight();
    void star();
    void onSizePRressed();
    void onSizePReleased();
    void onSizeMPressed();
    void onSizeMReleased();
    void onRotateLPressed();
    void onRotateLReleased();
    void onRotateRPressed();
    void onRotateRReleased();

protected:
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *me) override;
    void mouseMoveEvent(QMouseEvent *me) override;
    void mouseReleaseEvent(QMouseEvent *me) override;

    void keyPressEvent(QKeyEvent *ke) override {
        if (ke->modifiers() & Qt::ShiftModifier) {
            isShift = true;
        }
    }

    void keyReleaseEvent(QKeyEvent *ke) override {
        if (!(ke->modifiers() & Qt::ShiftModifier)) {
            isShift = false;
        }
    }

};

