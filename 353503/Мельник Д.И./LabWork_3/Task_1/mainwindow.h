#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "translation.h"
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *_ui;
    double _currentNumber = 0;
    Translation *_translation;
};
#endif // MAINWINDOW_H
