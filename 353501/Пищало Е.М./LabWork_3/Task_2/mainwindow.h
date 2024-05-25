#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <cstdint>//>
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

private:
    uint_least64_t Akermanfunc(uint_least64_t n,uint_least64_t m);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
