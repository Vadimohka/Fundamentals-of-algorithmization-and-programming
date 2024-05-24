#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QGraphicsRectItem>
#include <QQueue>
#include <QThread>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QDialogButtonBox>

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

    void Hanoi(int start, int end, int n);
    void Move(QGraphicsRectItem *disk, QGraphicsRectItem *fromRod, QGraphicsRectItem *toRod);
    void nextAnimation();

private slots:
    void on_pushButton_clicked();

private:
    QList<QGraphicsRectItem*> rods;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
