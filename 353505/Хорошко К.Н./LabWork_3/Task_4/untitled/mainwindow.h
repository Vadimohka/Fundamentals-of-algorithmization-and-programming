#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <rect.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    Rect* fund;
    Rect* pal_1;
    Rect* pal_2;
    Rect* pal_3;

    QVector<Rect*> mas1;
    QVector<Rect*> mas2;
    QVector<Rect*> mas3;

    int max1;
    int max2;
    int max3;
    int buf_max1;
    int buf_max2;
    int buf_max3;

    QVector<int> begin;
    QVector<int> end;

    void hanoi(int n, int i, int k, int l);

    int index = -1;

    QTimer time;
    QTimer time1;
    QTimer time2;
    QMetaObject::Connection timeConnection;
    QMetaObject::Connection timeConnection1;
    QMetaObject::Connection timeConnection2;

    int mas_x[3];

private slots:
    void next_cl();
    void build();
};
#endif // MAINWINDOW_H
