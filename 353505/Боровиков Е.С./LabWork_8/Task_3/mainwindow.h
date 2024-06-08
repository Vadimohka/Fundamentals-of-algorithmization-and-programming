#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "map.h"
#include "set.h"
#include <QMainWindow>

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
    void on_pushButton_s_add_clicked();

    void on_pushButton_s_check_clicked();

    void on_pushButton_s_clear_clicked();

    void on_pushButton_s_remove_clicked();

    void on_pushButton_m_add_clicked();

    void on_pushButton_m_check_clicked();

    void on_pushButton_m_get_clicked();

    void on_pushButton_m_clear_clicked();

    void on_pushButton_m_remove_clicked();

    void on_pushButton_m_set_clicked();

private:
    Ui::MainWindow *ui;
    Set<int> set;
    Map<int, int> map;
    void display();
};
#endif // MAINWINDOW_H
