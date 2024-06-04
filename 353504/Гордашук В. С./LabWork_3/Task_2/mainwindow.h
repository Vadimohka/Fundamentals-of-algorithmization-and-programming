#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QRegularExpressionValidator>>
#include <ackermann.h>

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
    Ackermann *ack = new Ackermann;

private slots:
    void on_Solve_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
