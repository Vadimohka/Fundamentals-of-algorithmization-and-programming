#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <extanded_ht.h>

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

    void on_On_remove_clicked();

    void on_On_search_clicked();

    void on_On_print_clicked();

    void on_On_LoadFactor_clicked();

    void on_On_clear_clicked();

    void on_On_search_min_clicked();

    void on_On_Fill_clicked();

private:
    Ui::MainWindow *ui;
    Extanded_HT<int> HT;
};
#endif // MAINWINDOW_H
