#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "sportik.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void initUserInput(Sportik);
    Sportik &getUserInitRef();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_print_clicked();

private:
    Sportik strInit;
    Sportik codeInit;
    Sportik ptrInit;
    Sportik refInit;
    Sportik *ptr = &ptrInit;
    Sportik &ref = refInit;

    Ui::MainWindow *ui;
    UserInputDialog* input;

    void initWithStr();
    void initWithCode();
    void initWithPtr();
    void initWithRef();
};
#endif // MAINWINDOW_H
