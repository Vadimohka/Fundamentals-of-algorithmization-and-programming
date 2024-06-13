#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<HashTableTask.h>
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

    HashTableSolve<int> hash;
    Ui::MainWindow *ui;

    void addElement();

    void deleteElement();

    void containElement();

    void clear();

};
#endif // MAINWINDOW_H
