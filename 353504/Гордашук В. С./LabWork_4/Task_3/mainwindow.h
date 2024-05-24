#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>

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
    QVector<int> nums;
    QVector<double> meds;
    void Splitting(QVector<int> nums);
    int median(int a, int b, int c);

private slots:
    void on_add_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
