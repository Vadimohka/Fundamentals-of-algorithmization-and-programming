#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "akermannfunction.h"

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
    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *_ui;
    AkermanFunction *_akerman;

    const int FIRST_ARG_LIMIT = 4;
    const int SECOND_ARG_LIMIT = 12;
};
#endif // MAINWINDOW_H
