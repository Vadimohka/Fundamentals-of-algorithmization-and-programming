#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "bst.h"

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
    void on_insertButton_clicked();
    void on_directButton_clicked();
    void on_reverseButton_clicked();
    void on_printButton_clicked();
    void on_searchButton_clicked();
    void on_taskButton_clicked();
    void on_deleteButton_clicked();
    void on_balanceButton_clicked();

private:
    Ui::MainWindow *ui;
    BST tree;
};
#endif // MAINWINDOW_H
