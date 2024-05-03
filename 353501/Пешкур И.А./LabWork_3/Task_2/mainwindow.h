#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "answer.h"

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
    void on_pushButtonAnswer_clicked();

private:
    Ui::MainWindow *ui;

private:

    long long makeAnswer( long long M , long long N );

};
#endif // MAINWINDOW_H
