#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <towers.h>

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

    void on_StartButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_RestartBut_clicked();

private:
    int row = 1;
    void move_disc(int number,char source,char target);
    void start(int n, char source, char auxiliary, char target);
    QGraphicsScene *scene;
    towers* htowers;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
