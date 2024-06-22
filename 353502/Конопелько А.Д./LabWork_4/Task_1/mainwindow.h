#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_sortButton_clicked();
    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;
    int *arr;
    int n;
};

#endif // MAINWINDOW_H
