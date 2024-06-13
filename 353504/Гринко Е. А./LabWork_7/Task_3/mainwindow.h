#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TaskTable.h"

#include <QMainWindow>
#include <QListWidget>
#include <QRandomGenerator>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


const uint8_t MIN_SIZE = 20;
const uint8_t MAX_SIZE = 30;
const uint8_t KEY_BOUNDS = 100;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_add_clicked();
    void on_random_clicked();
    void on_taskBtn_clicked();
    void on_clear_clicked();
    void on_indexBox_valueChanged(int arg1);
    void on_keyBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    TaskTable _table;

    template<typename T>
    void visualizeStack(const T& stack, QListWidget* view);
    void updateWidgets();
};
#endif // MAINWINDOW_H
