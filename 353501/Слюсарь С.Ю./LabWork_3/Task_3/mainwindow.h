#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QRegularExpressionValidator>

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
    long long reverse(int num, int c);
    int count(int num);
    long long reversed = 0;

private slots:
    void on_reverse_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
