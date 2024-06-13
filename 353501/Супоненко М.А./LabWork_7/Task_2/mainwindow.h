#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "derivedbst.h"

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
    void on_loadButton_clicked();
    void on_balanceButton_clicked();
    void on_addButton_clicked();
    void on_findButton_clicked();
    void on_deleteButton_clicked();
    void on_printButton_clicked();
    void on_countButton_clicked();

private:
    Ui::MainWindow *ui;
    DerivedBST bst;

    void updateTreeView();
};

#endif // MAINWINDOW_H
