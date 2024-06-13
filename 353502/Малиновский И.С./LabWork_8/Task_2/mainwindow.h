#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

#include "BinaryHeap.h"

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
    void on_exBMin_clicked();

    void on_getBMin_clicked();

    void on_insBMin_clicked();

    void on_prBMin_clicked();

    void on_exBMax_clicked();

    void on_getBMax_clicked();

    void on_insBMax_clicked();

    void on_prBMax_clicked();

private:
    Ui::MainWindow *ui;
    BinaryHeap heap;

};
#endif // MAINWINDOW_H
