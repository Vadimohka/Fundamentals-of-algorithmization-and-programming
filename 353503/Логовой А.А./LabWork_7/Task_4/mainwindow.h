#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<OpenHashTable.h>

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

    size_t size = 64;

    OpenHashModTable<QString> hash;
};

#endif // MAINWINDOW_H
