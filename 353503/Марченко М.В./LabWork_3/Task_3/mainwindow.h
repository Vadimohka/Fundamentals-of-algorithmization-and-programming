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
void lineEdit_userTextChanged(const QString &text);
bool contains0(long long number);
long long reverse_number(long long number, long long reversed_number = 0);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
