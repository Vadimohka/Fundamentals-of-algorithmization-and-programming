#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QMessageBox>
#include <QVBoxLayout>
#include "visual.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void hanoi(int n, char from_rod, char to_rod, char aux_rod);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Visual *scene;
    HanoiBrick *rod_a, *rod_b, *rod_c;
    std::vector<HanoiBrick*> hanoibricks;
    void showItems(int amount);
    void moveItems(int amount);
};
#endif // MAINWINDOW_H
