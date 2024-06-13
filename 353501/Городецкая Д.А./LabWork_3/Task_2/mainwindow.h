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
    void computeAckermann();

private:
    Ui::MainWindow *ui;
    QLineEdit *input1LineEdit;
    QLineEdit *input2LineEdit;
    QLabel *resultLabel;

    int ackermann(int m, int n);
};

#endif // MAINWINDOW_H
