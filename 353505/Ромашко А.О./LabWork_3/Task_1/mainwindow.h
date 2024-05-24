#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSpinBox>
#include <QLabel>
#include <QString>
#include "doublechangetobinarycode.h"
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
    void on_doubleSpinBox_valueChanged(double arg1);

private:
    Ui::MainWindow *ui;
    QLabel *label;

    void fraction(double value);
    void wholep(int value);
};
#endif // MAINWINDOW_H
