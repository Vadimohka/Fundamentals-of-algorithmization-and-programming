#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "fish.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <qrandom.h>

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
    //Fish *F=new Fish;

protected:
    //void paintEvent(QPaintEvent *)override;
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;

private slots:
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
