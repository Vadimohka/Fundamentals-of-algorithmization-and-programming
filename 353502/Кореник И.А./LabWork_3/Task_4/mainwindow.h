#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hanoi.h"
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

private:
    Ui::MainWindow *ui;

    void setUpTable();

    int current;

    int n;

    bool check = true;

    Hanoi* solve;

    void Move(QString*);

private slots:

    void on_accept_clicked();
    void on_All_clicked();
    void on_One_clicked();
};
#endif // MAINWINDOW_H
