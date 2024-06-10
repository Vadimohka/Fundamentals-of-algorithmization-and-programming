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
    void on_bnt_memcpy_clicked();

    void on_bnt_memmove_clicked();

    void on_bnt_strcpy_clicked();

    void on_bnt_strncpy_clicked();

    void on_bnt_strcat_clicked();

    void on_bnt_memset_clicked();

    void on_bnt_strtok_clicked();

    void on_bnt_strcoll_clicked();

    void on_bnt_strxfrm_clicked();

    void on_bnt_strlen_clicked();

    void on_bnt_strcmp_clicked();

    void on_bnt_strncmp_clicked();

    void on_bnt_memcmp_clicked();

    void on_bnt_strncat_clicked();

private:
    Ui::MainWindow *ui;
    CString* cstring;
};
#endif // MAINWINDOW_H
