#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "StringDLL.h"

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
    void on_constructButton_clicked();

    void on_memcmpButton_clicked();

    void on_memmoveButton_clicked();

    void on_memcpyButton_clicked();

    void on_strcpyButton_clicked();

    void on_strncpyButton_clicked();

    void on_strcatButton_clicked();

    void on_strncatButton_clicked();

    void on_strcmpButton_clicked();

    void on_strcollButton_clicked();

    void on_strncmpButton_clicked();

    void on_strxfrmButton_clicked();

    void on_strtokButton_clicked();

    void on_memsetButton_clicked();

    void on_strerrorButton_clicked();

    void on_strlenButton_clicked();

private:
    Ui::MainWindow *ui;

    String s1, s2;

};
#endif // MAINWINDOW_H
