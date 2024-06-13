#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QElapsedTimer>

#include "graphicsort.h"

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
    void on_pushButtonSort_clicked();

    void on_pushButtonReset_clicked();

    void on_spinBoxSize_valueChanged(int arg1);

    void on_pushButtonBinPow_clicked();

private:
    GraphicSort *graphicSort = nullptr;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
