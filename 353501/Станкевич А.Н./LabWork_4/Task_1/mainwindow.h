#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "Array.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();
        void updateScene();

private slots:
    void HeapSortFunction();
    void QuickSortFunction();
    void MergeSortFunction();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_2_clicked();

protected:
        int number;
            QTimer *timer;
    RectArray *array;
    int sortType;
    int numberToSearch;
    int cnt;
    bool isSearching = true;
private:
    Ui::MainWindow *ui;
    QMenu *m_menu;
    QGraphicsScene* scene;
        long long mod;
        bool sortAllowed = true;
};
#endif // MAINWINDOW_H
