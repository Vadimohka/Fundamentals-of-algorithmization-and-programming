#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "flag.h"

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
    Flag *flag;
    bool isFlagUp;
    QPoint flagUpPosition;
    QPoint flagDownPosition;
protected:
    void paintEvent(QPaintEvent*) override;
private slots:
    void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
