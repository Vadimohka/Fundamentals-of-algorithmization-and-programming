#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "airport.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QMessageBox>

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

    void on_Create_button_clicked();

private:
    Ui::MainWindow *ui;
    bool Is_all_fields_empty();
    void set_struct_to_window(Airport);

};
#endif // MAINWINDOW_H
