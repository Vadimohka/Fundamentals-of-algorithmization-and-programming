#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDoubleValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_System_10_line_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QString number_str;

    long long number_int;
    double number_double;

    QString result_2_double_str;
    QString result_2_int_str;

    long long Convert_int(long long );
    double Convert_double (double);

    int count;
};
#endif // MAINWINDOW_H
