#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void stringInit();
    void separateInit();
    void pointerinit();
    void referenceInit();

    void on_initButton_clicked();

    void on_printButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
