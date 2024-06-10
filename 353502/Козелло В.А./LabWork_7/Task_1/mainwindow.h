#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "deque.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_pushBackButton_clicked();
    void on_pushFrontButton_clicked();
    void on_popBackButton_clicked();
    void on_popFrontButton_clicked();
    void on_swapButton_clicked();
    void on_atButton_clicked();
    void on_isEmptyButton_clicked();
    void on_clearButton_clicked();

    void showDeque();

private:
    Deque<int> deque;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
