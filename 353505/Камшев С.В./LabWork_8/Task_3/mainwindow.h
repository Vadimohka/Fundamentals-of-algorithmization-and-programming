#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <limits.h>
#include <stdexcept>
#include "map.h"
#include "set.h"

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
    void display();

private slots:
    void on_bnt_set_add_clicked();

    void on_bnt_set_remove_clicked();

    void on_bnt_set_clear_clicked();

    void on_spb_map_add_clicked();

    void on_spb_map_remove_clicked();

    void on_spb_map_clear_clicked();

    void on_spb_map_getValue_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Set<int> set;
    Map<int, int> map;
};
#endif // MAINWINDOW_H
