#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QButtonGroup>
#include <QRandomGenerator>
#include <QMessageBox>
#include <QElapsedTimer>
#include <QThread>
#include <QTimer>
#include <QTime>
#include "rectangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

private slots:
    void on_Array_size_line_textChanged(const QString &arg1);


    void on_Sort_button_clicked();

    void on_Create_new_columns_button_clicked();

    void on_Bin_search_number_input_line_textChanged(const QString &arg1);

    void on_Bin_search_button_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene;
    QIntValidator* val;
    QButtonGroup* all_radio_buttons;

    QTimer* timer;
    int* current_array;
    int current_array_length;

    int time;

    void Array_input(int);
    void Array_to_scene(int);

    QList<Rectangle*> Rect_list;

    void QuickSort(int* &, int , int);

    void MergeSort(int* &, int , int);
    void Merge(int* &, int, int ,int);

    void Heapify(int* &, int , int);
    void HeapSort(int* &, int);

    void Swap_array_elements(int&, int&);

    void Swap_rectangles(int, int);
    void Set_rectangle(int, qreal);
    void Set_rectangle(int, qreal, QColor);

    int binarySearch(int* &, int, int, int);

    int index;

    void Debug_array();

    void Set_buttons_enabled(bool);

    bool is_sorted;

};
#endif // MAINWINDOW_H
