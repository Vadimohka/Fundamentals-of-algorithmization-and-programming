#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qapplication.h"
#include <QMainWindow>

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
    static void arrayToSceneCallback(QVector<int> data, QSet<int> look, QSet<int> good, unsigned read, unsigned write, unsigned compare);
    void arrayToScene(QVector<int> &, QSet<int> &, QSet<int> &, unsigned, unsigned, unsigned);
    static MainWindow * mw;
private slots:
    void on_spinBox_n_valueChanged(int arg1);

    void on_comboBox_rand_activated(int index);

    void on_pushButton_proc_clicked();

    void on_spinBox_delay_valueChanged(int arg1);

    void on_pushButton_pause_clicked();

    void on_pushButton_abort_clicked();

private:

    Ui::MainWindow *ui;
    QVector<int> generateVec(int, int);
    int size, rand = 0, sort = 0;
    unsigned delay = 10;
    bool pause = false, abort = false;

};
#endif // MAINWINDOW_H
