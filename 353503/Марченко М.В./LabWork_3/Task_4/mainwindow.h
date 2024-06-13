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
    void hanoi(int n, char One = 'A', char Two = 'B', char Three = 'C');
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int moveCount = 0;
private slots:
    void GetHanoi();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
