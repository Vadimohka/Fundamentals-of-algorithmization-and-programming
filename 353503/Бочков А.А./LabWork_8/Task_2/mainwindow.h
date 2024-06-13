#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <BinaryHeapArray.h>
#include <BinaryHeapList.h>

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
    BinaryHeapList test1;
    BinaryHeapArray test2;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
