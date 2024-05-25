#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "cstring.h"

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
    void on_button_memcpy_clicked();

    void on_button_memmove_clicked();

    void on_button_strcpy_clicked();

    void on_button_strncpy_clicked();

    void on_button_strcat_clicked();

    void on_button_memset_clicked();

    void on_button_strtok_clicked();

    void on_button_strcoll_clicked();

    void on_button_strxfrm_clicked();

    void on_button_strlen_clicked();

    void on_button_strcmp_clicked();

    void on_button_strncmp_clicked();

    void on_button_memcmp_clicked();

    void on_button_strncat_clicked();

private:
    Ui::MainWindow *ui;
    CString* cstring;
};
#endif // MAINWINDOW_H
