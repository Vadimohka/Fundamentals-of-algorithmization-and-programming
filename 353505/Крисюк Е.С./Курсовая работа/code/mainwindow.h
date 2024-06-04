#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QIcon>

#include "registration_window.h"
#include "home_window.h"
#include "transactions.h"
#include "sha256.h"
#include "luna.h"
#include "blowfish.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Enter_button_clicked();

    void Open_Registration_window();

    void on_Login_line_textChanged(const QString &arg1);

    void on_Password_line_textChanged(const QString &arg1);

    void Open();

    void on_View_PassWord_button_toggled(bool checked);


    void on_Leave_button_clicked();

private:

    Ui::MainWindow *ui;

    Registration_window* registration_window;
    Home_window* home_window;


};
#endif // MAINWINDOW_H
