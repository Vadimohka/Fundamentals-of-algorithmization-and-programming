#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    void on_executeButton_clicked();

private:
    Ui::MainWindow *ui;
    void hanoi(int n, QString &ans, char first, char second, char third);
};
#endif // MAINWINDOW_H
