

#ifndef TASK3_MAINWINDOW_H
#define TASK3_MAINWINDOW_H

#include <QWidget>

#include "hashtableextension.h"

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
    TaskHash my_hash;

private slots:
    void add_clicked();
    void delete_clicked();
    void find_clicked();
    void do_task();
    void show_table();
};


#endif //TASK3_MAINWINDOW_H
