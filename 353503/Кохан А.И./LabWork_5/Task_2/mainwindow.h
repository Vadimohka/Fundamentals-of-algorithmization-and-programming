#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mystring.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_memcpyButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_MemmoveButton_clicked();

    void on_resetButton_clicked();

    void on_strcpyButton_clicked();

    void on_strncpyButton_clicked();

    void on_strcatButton_clicked();

    void on_strncatButton_clicked();

    void on_memcmpButton_clicked();

    void on_strcmpButton_clicked();

    void on_strncmpButton_clicked();

    void on_strcollButton_clicked();

    void on_strxfrmButton_clicked();

    void on_strtokButton_clicked();

    void on_memsetButton_clicked();

private:
    Ui::MainWindow *ui;
    MyString strochenka1 = "Hello World!";
    MyString strochenka2 = "World of Tanks!";
    char *buffer;
};
#endif // MAINWINDOW_H
