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

    QString ConvertIntegerPart(long long decimNumber);
    QString ConvertFractionalPart(double decimNumber);
public slots:
    void ShowBinaryNum(QString input);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
