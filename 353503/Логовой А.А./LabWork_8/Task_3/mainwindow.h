#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<RedBlackTree.h>

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

    RedBlackTree<int, QString> tree;
};
#endif // MAINWINDOW_H
