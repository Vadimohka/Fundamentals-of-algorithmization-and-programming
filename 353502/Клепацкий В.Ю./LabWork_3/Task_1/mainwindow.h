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
    void on_transformButton_clicked();

private:
    Ui::MainWindow *ui;
    QString number;
    //QString wholePart, fraction;
    int wholePart;
    double znachenie, fraction;
    void translateWhole(int whole);
    void translateFraction(double fraction);
};
#endif // MAINWINDOW_H
