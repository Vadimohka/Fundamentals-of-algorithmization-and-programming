#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include "queue.h"

const int DEFAULT_QUEUE_SIZE = 15;

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
    Queue* queue = new Queue();
    QString answer = "";
    int indMax = 0;
    int indMin = 0;

    void createQueue();
    void deleteElements();
};
#endif // MAINWINDOW_H
