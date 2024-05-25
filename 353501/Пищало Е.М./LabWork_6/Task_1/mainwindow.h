#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "userinputdialog.h"
#include "ship.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initUserInput(Ship);
    Ship& getUserInitRef();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_print_clicked();

private:
    Ship strInit;
    Ship codeInit;
    Ship ptrInit;
    Ship refInit;
    Ship *ptr = &ptrInit;
    Ship &ref = refInit;

    Ui::MainWindow *ui;
    UserInputDialog* input;

    void initWithStr();
    void initWithCode();
    void initWithPtr();
    void initWithRef();
};
#endif // MAINWINDOW_H
