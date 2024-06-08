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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;
    long long ReverseNum(long long num , int rev = 0);

private slots:
    void on_lineEdit_getNum_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
