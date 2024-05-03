#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <player.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_pushButton_add_clicked();

    void on_pushButton_edit_clicked();

    void on_pushButton_delete_clicked();

    void on_pushButto_task1_clicked();

    void on_pushButton_task2_clicked();

    void on_pushButton_task3_clicked();

    void on_pushButton_show_clicked();

    void on_spinBox_count_valueChanged(int);

private:
    Ui::MainWindow *ui;
    Player *players;
    int count = 0;
    QString sourseFile;
    const int TOP = 10;

    void showTable();
};
#endif // MAINWINDOW_H
