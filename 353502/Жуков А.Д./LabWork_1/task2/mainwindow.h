#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <paintwindow.h>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "mwscene.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_paint_button_clicked();

    void on_buttRomb_toggled(bool checked);

    void on_buttRect_toggled(bool checked);

    void on_buttCircle_toggled(bool checked);

    void on_buttTriangle_toggled(bool checked);

    void on_buttClear_clicked();

    void on_buttSquare_toggled(bool checked);

    void on_buttDrag_toggled(bool checked);

    void on_buttSixStar_toggled(bool checked);

    void on_buttRotate_toggled(bool checked);

    void on_buttTransform_toggled(bool checked);

    void on_plusButt_clicked();

    void on_minusButt_clicked();

    void on_counterClockwiseButt_clicked();

    void on_ClockwiseButt_clicked();

    void on_deletItem_toggled(bool checked);

    void on_buttStar_toggled(bool checked);

    void on_hexagonButt_toggled(bool checked);

    void on_pointEdit_textEdited(const QString &arg1);

    void setPerimeterText(QString);
    void setAreaText(QString);

private:
    Ui::MainWindow *ui;
    paintWindow *wind;

    MWscene *scene = new MWscene;
    void CreateScene();

    QPushButton *tempButt;
    QPushButton *blankButt;

signals:
    //трансформирование
    void signal(int, int);
    bool buttDrag(bool);
    bool buttRotate(bool);
    bool buttScale(bool);
    void deleteI(bool);

    //фигуры
    bool blankFigure(bool);
    bool buttRect(bool);
    bool buttRomb(bool);
    bool buttCircle(bool);
    bool buttTriange(bool);
    bool buttSquare(bool);
    bool buttSixStar(bool);
    bool buttStar(bool);
    bool buttHexagon(bool);

    //параметры
    void scaleFact(double);
    void rotate(double);
    void setCorners(double);
};
#endif // MAINWINDOW_H
