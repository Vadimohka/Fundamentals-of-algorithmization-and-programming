#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iterator.h"
#include "mvector.h"
#include "dialoginputpushback.h"

#include <QMessageBox>

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

    void updateListWidget();

private slots:
    void on_buttonClear_clicked();

    void on_buttonPopBack_clicked();

    void on_buttonPushBack_clicked();

    void on_buttonAt_clicked();

    void on_buttonReserve_clicked();

    void on_buttonResize_clicked();

private:
    Ui::MainWindow *ui;
    Mvector<int> vector;
};
#endif // MAINWINDOW_H
