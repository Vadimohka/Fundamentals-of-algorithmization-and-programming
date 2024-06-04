#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <../myvector/myvector.h>

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
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    bool ok = true;
    int k = 0;
    Ui::MainWindow *ui;
    int n, i;
    double x;
    myvector<double> a, b;
};
#endif // MAINWINDOW_H
