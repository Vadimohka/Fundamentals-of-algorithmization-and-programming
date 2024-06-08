#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "plane.h"
#include <QInputDialog>
#include <QMessageBox>
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
    void demonstrate();



private slots:
    void on_pushButton_clicked();





private:
    Ui::MainWindow *ui;
    PLANE plane;
    PLANE pl;
    PLANE pl1;
    PLANE *p;
    PLANE &pp=pl;
};
#endif // MAINWINDOW_H
