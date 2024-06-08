#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_deleteButton_clicked();
    void on_insertButton_clicked();
    void on_searchButton_clicked();
    void on_preorderButton_clicked();
    void on_postorderButton_clicked();
    void on_inorderButton_clicked();
    void on_parentButton_clicked();
    void on_subButton_clicked();
    void on_leftButton_clicked();
    void on_rightButton_clicked();

private:
    Ui::MainWindow *ui;
    BST<int> tree;
};
#endif // MAINWINDOW_H
