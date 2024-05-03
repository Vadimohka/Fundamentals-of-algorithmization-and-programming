#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "indexofarray.h"
#include "picturedarray.h"
#include "mergesort.h"

#include <QColor>
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

private slots:
    void on_buttonGenerate_clicked();

    void on_buttonSort_clicked();

    void on_buttonClose_clicked();

    void on_buttonBinSearch_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;

    PicturedArray* array;

};
#endif // MAINWINDOW_H
