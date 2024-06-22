#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "autorepair.h"
#include <QMainWindow>
#include <QTextStream>


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
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    QString text_in, text_out;
    void processMenuChoice(int choice);
    void func();
    QTextStream stream_in;
    QTextStream stream_out;
};
#endif // MAINWINDOW_H
