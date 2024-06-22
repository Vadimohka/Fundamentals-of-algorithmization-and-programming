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
    void on_btn_memcpy_clicked();
    void on_btn_memmove_clicked();
    void on_btn_strcpy_clicked();
    void on_btn_strncpy_clicked();
    void on_btn_strcat_clicked();
    void on_btn_memset_clicked();
    void on_btn_strtok_clicked();
    void on_btn_strcoll_clicked();
    void on_btn_strxfrm_clicked();
    void on_btn_strlen_clicked();
    void on_btn_strcmp_clicked();
    void on_btn_strncmp_clicked();
    void on_btn_memcmp_clicked();
    void on_btn_strncat_clicked();

private:
    Ui::MainWindow *ui;
    CString* cstring;
};
#endif // MAINWINDOW_H
