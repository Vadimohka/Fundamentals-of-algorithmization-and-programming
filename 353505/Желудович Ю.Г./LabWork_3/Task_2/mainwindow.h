#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QIntValidator>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    bool one, second;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Number_1_line_textChanged(const QString &arg1);

    void on_Number_2_line_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void Result_output();
    long long Calculate_Result(long long , long long);

    int max_length;

};
#endif // MAINWINDOW_H
