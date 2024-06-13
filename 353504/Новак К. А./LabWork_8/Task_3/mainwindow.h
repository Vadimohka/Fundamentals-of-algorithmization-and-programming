#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "map.h"

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
    void on_AddButton_clicked();

    void on_EraseButton_clicked();

    void on_FindButton_clicked();

    void on_ClearButton_clicked();

private:
    Ui::MainWindow *ui;

    void Display();

    Map<int, QString> map;
};
#endif // MAINWINDOW_H
