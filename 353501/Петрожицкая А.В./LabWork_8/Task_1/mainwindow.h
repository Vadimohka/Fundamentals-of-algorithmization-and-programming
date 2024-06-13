#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QPainter>
#include "bsttree.h"

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
    void on_insert_clicked();
    void on_find_clicked();
    void on_print_forward_clicked();
    void on_clear_clicked();
    void on_delete_2_clicked();
    void on_MaxDepth_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    BSTTree bsttree;
};

#endif // MAINWINDOW_H
