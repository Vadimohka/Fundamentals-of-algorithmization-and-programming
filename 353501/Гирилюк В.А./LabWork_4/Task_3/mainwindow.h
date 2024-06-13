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
    void on_pushButtonAddDigit_clicked();

    void on_pushButtonCalc_clicked();

    void on_pushButtonClear_clicked();

private:
    QString vecA = "(";
    QString vecB = "(";
    QVector<int> vector;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
