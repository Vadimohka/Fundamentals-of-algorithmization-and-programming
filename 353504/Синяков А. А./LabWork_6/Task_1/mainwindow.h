#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "continent.h"
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
    Continent continent;           // Переменная типа Continent
    Continent* continentPointer;   // Указатель на объект типа Continent
    Continent& continentReference; // Ссылка на объект типа Continent
};
#endif // MAINWINDOW_H
