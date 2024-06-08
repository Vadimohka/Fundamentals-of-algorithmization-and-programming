#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextStream>
#include <QTimer>
#include <QInputDialog>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include "plane.h"
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
    void start();

private:
    Ui::MainWindow *ui;
    QTimer timer;
    PLANE pl1;
};
#endif // MAINWINDOW_H
