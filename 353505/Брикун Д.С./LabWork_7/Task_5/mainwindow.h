#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "deque.h"
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
    void on_pushButton_pushb_clicked();

    void on_pushButton_pushf_clicked();

    void on_pushButton_popf_clicked();

    void on_pushButton_popb_clicked();

private:
    Ui::MainWindow *ui;
    void displayDeque();
    Deque<int> d;
};
#endif // MAINWINDOW_H
