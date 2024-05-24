#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
#include <QMainWindow>
#include "Deque.h"

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

private:
    void keyPressEvent(QKeyEvent *event) override;
    void outputDeque();

private slots:
    void on_push_front_Button_clicked();

    void on_push_back_Button_clicked();

    void on_sizeButton_clicked();

    void on_clearButton_clicked();

    void on_emptyButton_clicked();

    void on_pop_front_Button_clicked();

    void on_pop_back_Button_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> deque;
};
#endif // MAINWINDOW_H
