#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "Animal.h"
#include "inputdialog.h"

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

public slots:
    void onAnimalChanged(int index);

    void getInfo(Animal animal);

private:
    Ui::MainWindow *ui;
    InputDialog *inputDialog;

    Animal animal;
    Animal *animalPointer;
    Animal &animalRef;
};
#endif // MAINWINDOW_H
