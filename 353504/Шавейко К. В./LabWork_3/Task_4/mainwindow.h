#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "hanoi.h"

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
    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::MainWindow *_ui;
    Hanoi *_hanoi;

    const int MAX_LIMIT_OF_TOWER = 20;
    const int MIN_LIMIT_OF_TOWER = 2;
};
#endif // MAINWINDOW_H
