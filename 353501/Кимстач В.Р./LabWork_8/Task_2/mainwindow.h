#ifndef TASK2_MAINWINDOW_H
#define TASK2_MAINWINDOW_H

#include <QWidget>

#include "HeapArray.h"
#include "HeapList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget {
    Q_OBJECT

public:
    explicit mainwindow(QWidget *parent = nullptr);

    ~mainwindow() override;

private:
    Ui::mainwindow *ui;
    HeapArray heapArray;
    HeapList heapList;

    bool type = 0;
    void Display();

public slots:
    void do_init(int t);
    void add_item();
    void get_max();
    void extract_max();
    void increase_position();
    void decrease_position();
    void increase_value();
    void decrease_value();
};


#endif //TASK2_MAINWINDOW_H
