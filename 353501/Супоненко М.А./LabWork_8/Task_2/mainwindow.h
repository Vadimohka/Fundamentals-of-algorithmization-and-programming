#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "array_heap.h"
#include "list_heap.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_arrayInsertButton_clicked();
    void on_arrayExtractButton_clicked();
    void on_arrayGetMaxButton_clicked();
    void on_listInsertButton_clicked();
    void on_listExtractButton_clicked();
    void on_listGetMaxButton_clicked();

private:
    Ui::MainWindow *ui;
    ArrayHeap arrayHeap;
    ListHeap listHeap;
};

#endif // MAINWINDOW_H
