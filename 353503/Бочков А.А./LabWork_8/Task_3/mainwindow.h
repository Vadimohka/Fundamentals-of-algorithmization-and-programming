#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <RedBlackTree.h>
#include <Unordered_Map.h>

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
    Unordered_Map<int, QString> test2;
    Unordered_Map<int, int> test1;
    Set<int> test;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
