#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "elevator.h"
#include "passenger.h"

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
protected:
    void paintEvent(QPaintEvent *);
private slots:

    void on_Floor1Button_clicked();

    void on_Floor2Button_clicked();

    void on_Floor3Button_clicked();


    void on_onfloor_clicked();

    void on_outfloor_clicked();

    void on_inelevator_clicked();

    void on_outelevator_clicked();

    void on_callElevator_clicked();

private:
    void enableDisableButtons();
    void setObjects();
    Ui::MainWindow *ui;
    Elevator* elevator;
    QTimer* animationTimer;
    Passenger* passenger;
    QTimer* resetTimer;
    bool wasreseted;
};
#endif // MAINWINDOW_H
