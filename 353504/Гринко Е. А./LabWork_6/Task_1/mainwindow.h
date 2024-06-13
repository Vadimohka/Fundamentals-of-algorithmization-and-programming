#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <city.h>


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

    void task();

private slots:
    void on_pushButton_clicked();

    void on_categoryBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    void write(const City& city, int n);
};
#endif // MAINWINDOW_H
