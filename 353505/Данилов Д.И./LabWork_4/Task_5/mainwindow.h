#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector.h>
#include <pair.h>
#include <QStandardItemModel>
#include <QMessageBox>

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
    void on_pushButton_clicked();

    void on_pushButton_at_clicked();

    void on_pushButton_capacity_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_empty_clicked();

    void on_pushButton_maxSize_clicked();

    void on_pushButton_popBack_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_data_clicked();

    void on_pushButton_pushBack_clicked();

    void on_pushButton_resize_clicked();

    void on_pushButton_reserve_clicked();

    void on_pushButton_erase_clicked();

private:
    Ui::MainWindow *ui;

    Vector<Pair<Vector<int>, Vector<Pair<int, double>>>> pair;
    Vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    void updateVec();
};
#endif // MAINWINDOW_H
