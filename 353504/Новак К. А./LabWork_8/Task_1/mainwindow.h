#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "avltree.h"


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
    void on_Add_clicked();

    void on_Remove_clicked();

    void on_Find_clicked();

private:
    AVLTree<QString> tree = AVLTree<QString>(20, "BASA");

    void display();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
