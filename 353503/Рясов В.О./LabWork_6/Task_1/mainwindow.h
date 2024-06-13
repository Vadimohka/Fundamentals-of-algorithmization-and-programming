#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Plant.h>

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
    ~MainWindow();

private slots:
    void on_nextButton_4_clicked();

    void on_nextButton_3_clicked();

    void on_nextButton_2_clicked();

    void on_nextButton_clicked();

    void on_pushInputButton_clicked();

    void on_pushInputButton_2_clicked();

    void on_pushInputButton_3_clicked();

    void on_pushInputButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Plant plant1, plant2, *plant3, plant4, &refPlant;
};
#endif // MAINWINDOW_H
