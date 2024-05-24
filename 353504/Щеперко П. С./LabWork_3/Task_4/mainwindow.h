#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>
#include <hanoitowers.h>

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

    void on_startPushButton_clicked();
    void on_restartPushButton_clicked();
    void on_inputLineEdit_textEdited(const QString &arg1);

private:

    int row = 1;

    void moveDisk(int number,char source,char target);
    void Hanoi(int n, char source, char buffer, char target);

    QGraphicsScene *scene;
    HanoiTowers* mainTower;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
