#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mystring.h"
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
    void on_FirstString_returnPressed();

    void on_SecondString_returnPressed();

    void on_Btn_memcpy_clicked();

    void on_Btn_memmove_clicked();

    void on_Btn_strcpy_clicked();

    void on_Btn_strcmp_clicked();

    void on_Btn_strncmp_clicked();

    void on_Btn_strncpy_clicked();

    void on_Btn_strcat_clicked();

    void on_Btn_memcmp_clicked();

    void on_Btn_strcoll_clicked();

    void on_Btn_strtok_clicked();

    void on_Btn_strerror_clicked();

    void on_Btn_strxfrm_clicked();

    void on_Btn_memset_clicked();

    void on_Btn_strLen1_clicked();

    void on_Btn_strLen1_2_clicked();

private:
    Ui::MainWindow *ui;
    MyString str_1;
    MyString str_2;
};
#endif // MAINWINDOW_H
