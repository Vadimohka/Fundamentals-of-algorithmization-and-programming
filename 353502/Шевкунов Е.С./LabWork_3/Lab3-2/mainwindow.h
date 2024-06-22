#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

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
    void click();

private:
    Ui::MainWindow *ui;
    QLabel *res;
    QLineEdit *mEdit;
    QLineEdit *nEdit;
    int calc(int m, int n);
    int m, n;
};
#endif // MAINWINDOW_H
