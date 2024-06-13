#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "mydeque.h"

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
    void on_Size_Edit_editingFinished();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    MyDeque<int> dq;


    QString display;
};
#endif // MAINWINDOW_H
