
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QIntValidator>
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
3
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Number_line_textChanged(const QString &arg1);

private:
    long long number;
    Ui::MainWindow *ui;

    bool isMinus;
    int count_of_digits;
    long long result;

    void Result_output();
    long long Calculate_result(long long&);
    long long Calculate_count_of_digits(long long);

};
#endif // MAINWINDOW_H
