#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "heaplist.h"
#include "heaparray.h"

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
    void on_insertArrayButton_clicked();
    void on_extractArrayButton_clicked();
    void on_insertListButton_clicked();
    void on_extractListButton_clicked();

private:
    Ui::MainWindow *ui;
    HeapArray heapArray;
    HeapList heapList;

    void updateArrayDisplay();
    void updateListDisplay();
};

#endif // MAINWINDOW_H
