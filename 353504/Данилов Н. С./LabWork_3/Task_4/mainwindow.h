#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_pushButton_P_clicked();

    void on_pushButton_N_clicked();

    void on_spinBox_2_valueChanged(int arg1);

private:
    void showStep(QVector<QVector<int>>);
    Ui::MainWindow *ui;
    void hanoi(int, int, int, int);
    void addRow();
    int on[3];
    QVector<QVector<QVector<int>>> rings;
    int sh;
};
#endif // MAINWINDOW_H
