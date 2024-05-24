#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pair.h"
#include "vector.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_generateButton_clicked();

private:
    Ui::MainWindow *ui;
    Pair<Vector<int>, Vector<Pair<int, double>>> pair;
};
#endif // MAINWINDOW_H
