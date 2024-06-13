#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Deque.h>
#include <QInputDialog>
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
    void on_pushButton_pushBack_clicked();

    void on_pushButton_pushFront_clicked();

    void on_pushButton_popBack_clicked();

    void on_pushButton_popFront_clicked();

    void on_pushButton_clear_clicked();

private:
    Ui::MainWindow *ui;
    Deque<QString> deque;
    void UpdateDeque();
};
#endif // MAINWINDOW_H
