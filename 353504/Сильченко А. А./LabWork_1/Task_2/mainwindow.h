#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QLabel>
#include <figure.h>

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
    void on_StarButton_clicked();
    void on_TriangleButton_clicked();
    void on_CircleButton_clicked();
    void on_LineButton_clicked();
    void on_ClearButton_clicked();
    void on_BrushButton_clicked();
    void on_SquareButton_clicked();
    void on_RectangleButton_clicked();
    void on_RhombusButton_clicked();
    void on_HexagonButton_clicked();
    void on_EllipseButton_clicked();

    void updateAreaDisplay(QString newArea);
    void updatePerimetrDisplay(QString newP);
    void updateCenterDisplay(QString newX, QString newY);
    void infoFigure(Figure* figure);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer* timer;
    QLabel *label;
};
#endif // MAINWINDOW_H
