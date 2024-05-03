#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QGraphicsScene *scene;

private slots:
    void on_pushButtonMoveLeft_clicked();

    void on_pushButtonRight_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
