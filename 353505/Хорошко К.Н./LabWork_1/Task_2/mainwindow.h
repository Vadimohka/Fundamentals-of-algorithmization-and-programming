#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QResizeEvent>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QRadioButton>
#include <QPushButton>
#include <paintscene.h>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    qreal x;
    qreal y;
    QLabel *Label1_1;
    QLabel *Label2_1;
    QLabel *Label3_1;



private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QTimer *timer1;
    QGraphicsView *graphicsView;
    PaintScene *graphicsScene;

    QRadioButton *CircleButton;
    QRadioButton *ElipsButton;
    QRadioButton *HexagonButton;
    QRadioButton *RectangleButton;
    QRadioButton *RombButton;
    QRadioButton *SquareButton;
    QRadioButton *Star_sixButton;
    QRadioButton *Star_fiveButton;
    QRadioButton *Star_eightButton;
    QRadioButton *TriangleButton;
    QRadioButton *DrawButton;

    QLabel *Label1;
    QLabel *Label2;
    QLabel *Label3;

    QPushButton *Clear;


private:
    void resizeEvent(QResizeEvent *event);
    void wheelEvent(QWheelEvent *event);

private slots:
    void labelResize();
    void resizeTimer();
    void button_circle();
    void button_elips();
    void button_hexagon();
    void button_rectangle();
    void button_romb();
    void button_square();
    void button_star_five();
    void button_star_six();
    void button_star_eight();
    void button_triangle();
    void button_draw();
    void clearScene();
};
#endif // MAINWINDOW_H
