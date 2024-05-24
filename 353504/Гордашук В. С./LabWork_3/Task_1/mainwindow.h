#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDebug>
#include <QRegularExpressionValidator>

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
    void intToBinary(int num);
    QString to2 = "";
    QString dto2 = "";
    void doubleToBinary(double num);
    QString inp = "";

private slots:
    void on_Conv_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
