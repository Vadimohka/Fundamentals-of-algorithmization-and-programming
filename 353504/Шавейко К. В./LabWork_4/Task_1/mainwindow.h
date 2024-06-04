#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

#include "visualisesort.h"

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
    ~MainWindow() override;
    void ShuffleArray();
    void EnableClck();
private slots:
    void on_pushButton_Shuffle_clicked();

    void on_line_size_returnPressed();

    void on_pushButton_QuickSort_clicked();

    void on_pushButton_HeapSort_clicked();

    void on_pushButton_MergeSort_clicked();

    void on_line_search_returnPressed();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    int _size = 0;
    int* _arr = nullptr;
    bool IsArr = false;
    bool IsProcess = false;
    bool IsSorted = false;
    QTimer* _timer{};
};
#endif // MAINWINDOW_H
