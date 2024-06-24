#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinputdialog.h"
#include "car.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUserInput(Car);
    Car& getUserInitRef();
private slots:
    void on_pushButton_clicked();

private:
    Car strInit;
    Car codeInit;
    Car ptrInit;
    Car refInit;
    Car *ptr = &ptrInit;
    Car &ref = refInit;

    Ui::MainWindow *ui;
    UserInputDialog* input;

    void initWithStr();
    void initWithCode();
    void initWithPtr();
    void initWithRef();
};
#endif // MAINWINDOW_H
