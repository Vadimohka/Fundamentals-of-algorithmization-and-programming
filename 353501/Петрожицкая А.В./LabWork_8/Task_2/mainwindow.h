#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMessageBox>
#include "customheap.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_insert_clicked();
    void on_Max_clicked();
    void on_ExtractMax_clicked();
    void on_delete_2_clicked();
    void on_print_clicked();
    void on_clear_clicked();
    void on_size_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    CustomHeap heap;
};

#endif // MAINWINDOW_H
