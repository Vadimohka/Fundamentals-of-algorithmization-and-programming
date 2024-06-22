#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QMainWindow>
#include <QString>
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

private:
    Ui::MainWindow *ui;
    QPushButton *runButton;
    QLineEdit *input;
    int number10;
    int number2;
    int ost;
    QString calculate(int number10);
    QString result;
    QLabel *res;
private slots:
    void getNum();
};
#endif // MAINWINDOW_H
