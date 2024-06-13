#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Shoes.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private slots:
    void slot1();
    void slot2();
    void slot3();
    void slot4();

public:
    QString printShoes(Shoes& shoes);
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
