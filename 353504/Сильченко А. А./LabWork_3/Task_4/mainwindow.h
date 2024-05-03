#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QString>

#include "hanoi.h"

#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int bimage =0;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    hanoi *obgect;
    QGraphicsScene* scene;
    int n = 0, n_vver = 0, kol_el_table = 0;
    QTimer *timer = new QTimer;
    void Hanoi(int, int, int);
    bool is_finish = false;
    QString str;
    QVector <table> vect;
private slots:

    void on_pushButton_clicked();

    void on_spinBox_textChanged(const QString &arg1);

    void fun();

    void on_pushButton_3_clicked();

    void on_pushAlarm_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
