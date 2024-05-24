#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>>
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    MyString s;
    char *str1;
    char *str2;
    int n;

private slots:
    void on_set_clicked();

    void on_memcpy_clicked();

    void on_memmove_clicked();

    void on_strcpy_clicked();

    void on_strncpy_clicked();

    void on_memcmp_clicked();

    void on_strcmp_clicked();

    void on_strcat_clicked();

    void on_strncmp_clicked();

    void on_strncat_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
