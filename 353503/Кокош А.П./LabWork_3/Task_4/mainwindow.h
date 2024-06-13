#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void move(int from, int to, int via, int n);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QString output;
    int counter;
};
#endif // MAINWINDOW_H
