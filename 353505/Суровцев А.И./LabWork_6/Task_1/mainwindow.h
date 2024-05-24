#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animal.h"
#include "input.h"

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
    void on_bnt_printCurrRes_clicked();

    void on_bnt_input_clicked();

public slots:
    void handleButtonClicked(Animal an);

private:
    Ui::MainWindow *ui;
    Input *input;
    Animal animal1;
    Animal animal2;
    Animal animal3;
    Animal *animalPtr = &animal2;
    Animal &animalRef = animal3;
};
#endif // MAINWINDOW_H
