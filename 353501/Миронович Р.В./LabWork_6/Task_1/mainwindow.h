#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "plant.h"
#include <QMainWindow>

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
    void on_explicitInit_clicked();
    void on_userInput_clicked();
    void on_pointerInit_clicked();
    void on_referenceInit_clicked();
    void on_print_clicked();






private:
    Ui::MainWindow *ui;
    Plant plant;           // Переменная типа Continent
    Plant* plantPointer;   // Указатель на объект типа Continent
    Plant& plantReference; // Ссылка на объект типа Continent
};
#endif // MAINWINDOW_H
