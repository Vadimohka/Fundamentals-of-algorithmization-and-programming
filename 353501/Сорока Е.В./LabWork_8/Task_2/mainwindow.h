#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "binaryheap.h"

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
    void on_On_insert_clicked();

    void on_On_Max_clicked();

    void on_On_delete_clicked();

    void on_On_print_clicked();

    void on_On_clear_clicked();

    void on_On_size_clicked();

private:
    Ui::MainWindow *ui;
    BinaryHeap<int> heap;
    QGraphicsScene* scene;
};
#endif // MAINWINDOW_H
