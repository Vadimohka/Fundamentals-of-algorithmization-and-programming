#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QPainter>
#include <QSpinBox>
#include <QVector>
#include <QTableWidget>
#include <QRectF>
#include <QRandomGenerator>

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

    QPushButton* nextpushButton = new QPushButton;

    QSpinBox* spinBox = new QSpinBox;
    QTimer* timer;

    QTableWidget* table = new QTableWidget;
    QVector <QRectF*> circleFigure;

    QVector <QVector <int>> vec;
    QVector <QColor> colorVec;

    void hanoi(int n, int firstPost, int secondPost, QVector <QVector <int>>& vec);
    bool* upd;
    bool* mainUpd;

    int size = 0;

    int index = 0;
    void paintEvent(QPaintEvent *event);
    int numberOnFirstColumn, numberOnSecondColumn, numberOnThirdColumn;
    void moveUp(int index);
    void renul();

private slots:
    void on_NextpushButton_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
