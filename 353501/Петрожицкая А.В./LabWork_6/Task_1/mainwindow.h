#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Airport.h"

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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(int index);

private:
    Ui::MainWindow *ui;
    bool isParking;
    Airport airport1;
    Airport airport2;
    Airport airport3;
    Airport *air3 = &airport3;
    Airport airport4;
    Airport &air4 = airport4;
};
#endif // MAINWINDOW_H
