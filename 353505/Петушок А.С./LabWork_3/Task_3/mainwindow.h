#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "unoreverse.h"
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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    bool CheckInput();
    void on_SolutionButton_clicked();

private:
    Ui::MainWindow *ui;
    UnoReverse number;
};
#endif // MAINWINDOW_H
