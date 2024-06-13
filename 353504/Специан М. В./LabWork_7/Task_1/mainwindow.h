#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Queue.h>
#include <QMessageBox>
#include <QInputDialog>

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
    void on_pushButton_empty_clicked();

    void on_pushButton_size_clicked();

    void on_pushButton_front_clicked();

    void on_pushButton_back_clicked();

    void on_pushButton_pop_clicked();

    void on_pushButton_push_clicked();

    void on_pushButton_insertAt_clicked();

    void on_pushButton_deleteAt_clicked();

private:
    Ui::MainWindow *ui;

    Queue<QString> queue;
    void UpdateInfo();
};
#endif // MAINWINDOW_H
