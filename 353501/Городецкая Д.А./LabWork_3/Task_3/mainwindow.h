#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

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
    void reverseNumber();

private:
    Ui::MainWindow *ui;
    QLineEdit *inputEdit;
    QLabel *answer;

    int reverse(int n, int reversed);
};

#endif // MAINWINDOW_H
