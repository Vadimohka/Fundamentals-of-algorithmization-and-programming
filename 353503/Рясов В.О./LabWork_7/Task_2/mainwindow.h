#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "VisualAVLTree.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void update();

private slots:

    void on_treeButton_clicked();

    void on_backButton_clicked();

    void on_createButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_directInputButton_clicked();

    void on_reverseInputButton_clicked();

    void on_increseKeyButton_clicked();

    void on_findButton_clicked();

    void on_findMinButton_clicked();

    void on_findMaxButton_clicked();

    void on_findAverageButton_clicked();

private:
    Ui::MainWindow *ui;
    AVLTree<QString> *tree;

    QStandardItemModel model;
};
#endif // MAINWINDOW_H
