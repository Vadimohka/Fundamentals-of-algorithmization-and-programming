#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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
    void Hanoi(int n, char, char, char);

private slots:
    void on_lineEdit_numberOfDiscs_returnPressed();

private:
    Ui::MainWindow *ui;
    QString str_info;
};
#endif // MAINWINDOW_H
